/* 
 *  DidiWiki - a small lightweight wiki engine. 
 *
 *  Copyright 2004 Matthew Allum <mallum@o-hand.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#include <mkdio.h>

#include "didi.h"
#include "wikitext.h"

static char* CssData = STYLESHEET;

static char *
file_read(char *filename)
{
  struct stat st;
  FILE*       fp;
  char*       str;
  int         len;

  /* Get the file size. */
  if (stat(filename, &st)) 
    return NULL;

  if (!(fp = fopen(filename, "rb"))) 
    return NULL;
  
  str = (char *)malloc(sizeof(char)*(st.st_size + 1));
  len = fread(str, 1, st.st_size, fp);
  if (len >= 0) str[len] = '\0';
  
  fclose(fp);

  return str;
}


static int
file_write(char *filename, char *data)
{
  FILE*       fp;
  int         bytes_written = 0;
  int         len           = strlen(data)+1;

  if (!(fp = fopen(filename, "wb"))) 
    return -1;
 
  while ( len > 0 )
    {
      bytes_written = fwrite(data, sizeof(char), len, fp);
      len = len - bytes_written;
      data = data + bytes_written;
    }

  fclose(fp);

  return 1;
}

void
wiki_print_data_as_html(HttpResponse *res, char *raw_page_data)
{
  MMIOT *doc;
  char *buffer;
  
  doc = mkd_string(raw_page_data, strlen(raw_page_data), \
				   MKD_TOC | MKD_EXTRA_FOOTNOTE );
  mkd_compile(doc, MKD_TOC | MKD_EXTRA_FOOTNOTE);
  mkd_document(doc, &buffer);
  http_response_printf(res, buffer);
  mkd_cleanup(doc);
}

int
wiki_redirect(HttpResponse *res, char *location)
{
  char *location_enc = util_httpize(location);
  
  int   header_len = strlen(location_enc) + 14; 
  char *header = alloca(sizeof(char)*header_len);

  snprintf(header, header_len, "Location: %s\r\n", location_enc);
  free(location_enc);
  
  http_response_append_header(res, header);
  http_response_printf(res, "<html>\n<p>Redirect to %s</p>\n</html>\n", 
		       location);
  http_response_set_status(res, 302, "Moved Temporarily");
  http_response_send(res);

  exit(0);
}

void
wiki_show_page(HttpResponse *res, char *wikitext, char *page)
{
  http_response_printf_alloc_buffer(res, strlen(wikitext)*2);

  wiki_show_header(res, page, TRUE);

  wiki_print_data_as_html(res, wikitext);

  wiki_show_footer(res);

  http_response_send(res);

  exit(0);
}

void
wiki_show_edit_page(HttpResponse *res, char *wikitext, char *page)
{
  wiki_show_header(res, page, FALSE);

  if (wikitext == NULL) wikitext = "";
  http_response_printf(res, EDITFORM, page, wikitext);
		       
  wiki_show_footer(res);

  http_response_send(res);
  exit(0);
}

void
wiki_show_create_page(HttpResponse *res)
{
  wiki_show_header(res, "Create New Page", FALSE);
  http_response_printf(res, "%s", CREATEFORM);
  wiki_show_footer(res);

  http_response_send(res);
  exit(0);
}

static int 
changes_compar(const struct dirent **d1, const struct dirent **d2)
{
    struct stat st1, st2;

    stat((*d1)->d_name, &st1);

    stat((*d2)->d_name, &st2);

    if (st1.st_mtime > st2.st_mtime)
      return 1;
    else
      return -1;
}

WikiPageList**
wiki_get_pages(int  *n_pages, char *expr)
{
  WikiPageList  **pages;
  struct dirent **namelist;
  int             n, i = 0;
  struct stat     st;

  n = scandir(".", &namelist, 0, (void *)changes_compar);
  
  pages = malloc(sizeof(WikiPageList*)*n);

  while(n--) 
    {
      if ((namelist[n]->d_name)[0] == '.' 
	  || !strcmp(namelist[n]->d_name, "styles.css"))
	goto cleanup;

      if (expr != NULL) 
	{ 			/* Super Simple Search */
	  char *data = NULL;
	  if ((data = file_read(namelist[n]->d_name)) != NULL)
	    if (strcasestr(data, expr) == NULL)
	      if (strcmp(namelist[n]->d_name, expr) != 0) 
		goto cleanup; 
	}


      stat(namelist[n]->d_name, &st);

      /* ignore anything but regular readable files */
      if (S_ISREG(st.st_mode) && access(namelist[n]->d_name, R_OK) == 0)
	{
	  pages[i]        = malloc(sizeof(WikiPageList));
	  pages[i]->name  = strdup (namelist[n]->d_name);
	  pages[i]->mtime = st.st_mtime;

	  i++;
	}

    cleanup:
      free(namelist[n]);
    }

  *n_pages = i;

  free(namelist);

  if (i==0) return NULL;

  return pages;
}

void
wiki_show_changes_page(HttpResponse *res)
{
  WikiPageList **pages = NULL;
  int            n_pages, i;

  wiki_show_header(res, "Changes", FALSE);

  pages = wiki_get_pages(&n_pages, NULL);

  for (i=0; i<n_pages; i++)
    {
      struct tm   *pTm;
      char   datebuf[64];

      pTm = localtime(&pages[i]->mtime);
      strftime(datebuf, sizeof(datebuf), "%Y-%m-%d %H:%M", pTm);
      http_response_printf(res, "<a href='%s'>%s</a> %s<br />\n", 
			   pages[i]->name, 
			   pages[i]->name, 
			   datebuf);
    }

  wiki_show_footer(res);
  http_response_send(res);
  exit(0);
}

void
wiki_show_search_results_page(HttpResponse *res, char *expr)
{
  WikiPageList **pages = NULL;
  int            n_pages, i;

  if (expr == NULL || strlen(expr) == 0)
    {
      wiki_show_header(res, "Search", FALSE);
      http_response_printf(res, "No search terms supplied.");
      wiki_show_footer(res);
      http_response_send(res);
      exit(0);
    }

  pages = wiki_get_pages(&n_pages, expr);

  if (pages)
    {
      wiki_show_header(res, "Search", FALSE);

      /* if only one page is found, redirect to it */
      if (n_pages == 1)
        wiki_redirect(res, pages[0]->name);

      for (i=0; i<n_pages; i++)
	{
	  http_response_printf(res, "<a href='%s'>%s</a><br />\n", 
			       pages[i]->name, 
			       pages[i]->name);
	}
    }
  else 
    {
      wiki_show_header(res, "Search", FALSE);
      http_response_printf(res, "No matches");
    }

  wiki_show_footer(res);
  http_response_send(res);

  exit(0);
}

void 
wiki_show_template(HttpResponse *res, char *template_data)
{
  /* 4 templates - header.html, footer.html, 
                   header-noedit.html, footer-noedit.html

     Vars;

     $title      - page title. 
     $include()  - ?
     $pages 

  */

}

void
wiki_show_header(HttpResponse *res, char *page_title, int want_edit)
{
  http_response_printf(res, 
                       "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n"
                       "<html xmlns='http://www.w3.org/1999/xhtml'>\n"
		       "<head>\n"
                       "<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />\n" 
		       "<link rel='SHORTCUT ICON' href='/favicon.ico' />\n"
		       "<link media='all' href='/styles.css' rel='stylesheet' type='text/css' />\n"
		       "<title>%s</title>\n"

		       "</head>\n"
		       "<body>\n", page_title
		       );

  http_response_printf(res, PAGEHEADER, page_title, 
		       (want_edit) ? " ( <a href='?edit' title='Edit this wiki page contents. [alt-j]' accesskey='j'>Edit</a> ) " : "" );     
}

void
wiki_show_footer(HttpResponse *res)
{
  http_response_printf(res, "%s", PAGEFOOTER);

  http_response_printf(res, 
		       "</body>\n"
		       "</html>\n"
		       );
}

int page_name_is_good(char* page_name)
{
/* We should give access only to subdirs of didiwiki root.
   I guess that check for absense of '/' is enough.

   TODO: Use realpath()
*/
    if (!page_name)
        return FALSE;

    if (page_name[0] == '/')
        return FALSE;

    if (strncmp(page_name, "../", 3) == 0)
        return FALSE;

    if (strstr(page_name, "/../"))
        return FALSE;

    return TRUE;
}

void
wiki_handle_rest_call(HttpRequest  *req, 
		      HttpResponse *res,
		      char         *func)
{

  if (func != NULL && *func != '\0')
    {
      if (!strcmp(func, "page/get"))
	{
	  char *page = http_request_param_get(req, "page");

	  if (page == NULL)
	    page = http_request_get_query_string(req);

    if (page && page_name_is_good(page) && (access(page, R_OK) == 0))
	    {
	      http_response_printf(res, "%s", file_read(page));
	      http_response_send(res);
	      return;
	    }  
	}
      else if (!strcmp(func, "page/set"))
	{
	  char *wikitext = NULL, *page = NULL;
	  if( ( (wikitext = http_request_param_get(req, "text")) != NULL)
	      && ( (page = http_request_param_get(req, "page")) != NULL))
	    {
    if (page_name_is_good(page))
	    {
	      file_write(page, wikitext);
	      http_response_printf(res, "success");
	      http_response_send(res);
	      return;
	    }
        }
	}
      else if (!strcmp(func, "page/delete"))
	{
	  char *page = http_request_param_get(req, "page");

	  if (page == NULL)
	    page = http_request_get_query_string(req);

    if (page && page_name_is_good(page) && (unlink(page) > 0))
	    {
	      http_response_printf(res, "success");
	      http_response_send(res);
	      return;  
	    }
	}
      else if (!strcmp(func, "page/exists"))
	{
	  char *page = http_request_param_get(req, "page");

	  if (page == NULL)
	    page = http_request_get_query_string(req);

    if (page && page_name_is_good(page) && (access(page, R_OK) == 0))
	    {
	      http_response_printf(res, "success");
	      http_response_send(res);
	      return;  
	    }
	}
      else if (!strcmp(func, "pages") || !strcmp(func, "search"))
	{
	  WikiPageList **pages = NULL;
	  int            n_pages, i;
	  char          *expr = http_request_param_get(req, "expr");

	  if (expr == NULL)
	    expr = http_request_get_query_string(req);
	  
	  pages = wiki_get_pages(&n_pages, expr);

	  if (pages)
	    {
	      for (i=0; i<n_pages; i++)
		{
		  struct tm   *pTm;
		  char   datebuf[64];
		  
		  pTm = localtime(&pages[i]->mtime);
		  strftime(datebuf, sizeof(datebuf), "%Y-%m-%d %H:%M", pTm);
		  http_response_printf(res, "%s\t%s\n", pages[i]->name, datebuf);
		}

	      http_response_send(res);
	      return;  
	    }
	}
    }

  http_response_set_status(res, 500, "Error");
  http_response_printf(res, "<html><body>Failed</body></html>\n");
  http_response_send(res);

  return;  
}



void
wiki_handle_http_request(HttpRequest *req)
{
  HttpResponse *res      = http_response_new(req);
  char         *page     = http_request_get_path_info(req); 
  char         *command  = http_request_get_query_string(req); 
  char         *wikitext = "";

  util_dehttpize(page); 	/* remove any encoding on the requested
				   page name.                           */

  if (!strcmp(page, "/"))
    {
      if (access("WikiHome", R_OK) != 0)
	wiki_redirect(res, "/WikiHome?create");
      page = "/WikiHome";
    }

  if (!strcmp(page, "/styles.css"))
    {
      /*  Return CSS page */
      http_response_set_content_type(res, "text/css");
      http_response_printf(res, "%s", CssData);
      http_response_send(res);
      exit(0);
    }

  if (!strcmp(page, "/favicon.ico"))
    {
      /*  Return favicon */
      http_response_set_content_type(res, "image/ico");
      http_response_set_data(res, FaviconData, FaviconDataLen);
      http_response_send(res);
      exit(0);
    }


  page = page + 1; 		/* skip slash */

  if (!strncmp(page, "api/", 4))
    {
      char *p;

      page += 4; 
      for (p=page; *p != '\0'; p++)
	if (*p=='?') { *p ='\0'; break; }
      
      wiki_handle_rest_call(req, res, page); 
      exit(0);
    }

  /* A little safety. issue a malformed request for any paths,
   * There shouldn't need to be any..
   */
  if (!page_name_is_good(page))
    {
      http_response_set_status(res, 404, "Not Found");
      http_response_printf(res, "<html><body>404 Not Found</body></html>\n");
      http_response_send(res);
      exit(0);
    }

  if (!strcmp(page, "Changes"))
    {
      /* TODO list recent changes */
      wiki_show_changes_page(res);
    }
  else if (!strcmp(page, "Search"))
    {
      wiki_show_search_results_page(res, http_request_param_get(req, "expr"));
    }
  else if (!strcmp(page, "Create"))
    {
      if ( (wikitext = http_request_param_get(req, "title")) != NULL)
	{
	  /* create page and redirect */
	  wiki_redirect(res, http_request_param_get(req, "title"));
	}
      else
	{
	   /* show create page form  */
	  wiki_show_create_page(res);
	}
    }
  else
    {
      /* TODO: dont blindly write wikitext data to disk */
      if ( (wikitext = http_request_param_get(req, "wikitext")) != NULL)
	{
	  file_write(page, wikitext);

      /* log modified page name and IP address */
      syslog(LOG_LOCAL0|LOG_INFO, "page %s modified from %s", page ,http_request_get_ip_src(req));
	}

      if (access(page, R_OK) == 0) 	/* page exists */
	{
	  wikitext = file_read(page);

	  /* log read page name and IP address */
      syslog(LOG_LOCAL0|LOG_INFO, "page %s viewed from %s", page, http_request_get_ip_src(req));

	  if (!strcmp(command, "edit"))
	    {
	      /* print edit page */
	      wiki_show_edit_page(res, wikitext, page);
	    }
	  else
	    {
	      wiki_show_page(res, wikitext, page);
	    }
	}
      else
	{
	  if (!strcmp(command, "create"))
	    {
	      wiki_show_edit_page(res, NULL, page);
	    }
	  else
	    {
	      char buf[1024];
	      snprintf(buf, 1024, "%s?create", page);
	      wiki_redirect(res, buf);
	    }
	}
    }

}

int
wiki_init(char *didiwiki_home)
{
  char datadir[512] = { 0 };
  struct stat st;  

  if (didiwiki_home)
    {
      snprintf(datadir, 512, "%s", didiwiki_home);
    }
  else 
    {
      if (getenv("DIDIWIKIHOME"))
	{
	  snprintf(datadir, 512, "%s", getenv("DIDIWIKIHOME"));
	}
      else
	{
	  if (getenv("HOME") == NULL)
	    {
	      fprintf(stderr, "Unable to get home directory, is HOME set?\n");
	      exit(1);
	    }
	  
	  snprintf(datadir, 512, "%s/.didiwiki", getenv("HOME"));
	}
    }
  
  /* Check if ~/.didiwiki exists and create if not */
  if (stat(datadir, &st) != 0 )
    {
      if (mkdir(datadir, 0755) == -1)
	{
	  fprintf(stderr, "Unable to create '%s', giving up.\n", datadir);
	  exit(1);
	}
    }

  chdir(datadir);

  /* Write Default Help + Home page if it doesn't exist */

  if (access("WikiHelp", R_OK) != 0) 
    file_write("WikiHelp", HELPTEXT);

  if (access("WikiHome", R_OK) != 0) 
    file_write("WikiHome", HOMETEXT);

  /* Read in optional CSS data */

  if (access("styles.css", R_OK) == 0) 
    CssData = file_read("styles.css");
  
  return 1;
}

