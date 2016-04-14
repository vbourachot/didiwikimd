/* 
 *  DidiWiki - a small lightweight wiki engine. 
 *
 *  Parts of this http and util code based on cvstrac sources. 
 *  See http://www.cvstrac.org
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

#include "didi.h"

char *
util_mprintf(const char *format, ...)
{
  va_list ap;
  char   *buf = NULL;

  va_start(ap,format);
  vasprintf(&buf, format, ap);
  va_end(ap);

  return buf;
}


/*
 * Convert a single HEX digit to an integer
 */
int 
util_ascii_to_hex(int c)
{
  if( c>='a' && c<='f' ){
    c += 10 - 'a';
  }else if( c>='A' && c<='F' ){
    c += 10 - 'A';
  }else if( c>='0' && c<='9' ){
    c -= '0';
  }else{
    c = 0;
  }
  return c;
}

/*
 * Remove the HTTP encodings from a string.  The conversion is done
 * in-place.
 */
void 
util_dehttpize(char *z)
{
  int i = 0, j = 0;

  while(z[i])
    {
      switch(z[i])
	{
	case '%':
	  if( z[i+1] && z[i+2] ){
	    z[j] = util_ascii_to_hex(z[i+1]) << 4;
	    z[j] |= util_ascii_to_hex(z[i+2]);
	    i += 2;
	  }
	  break;
	case '+':
	  z[j] = ' ';
	  break;
	default:
	  z[j] = z[i];
	  break;
	}
      i++; j++;
    }
  z[j] = 0;
}

/*
 * Remove the first space-delimited token from a string and return
 * a pointer to it.  Add a NULL to the string to terminate the token.
 * Make *zLeftOver point to the start of the next token.
 *
 */
char *
util_extract_token(char *input, char **leftOver)
{
  char *result = 0;

  if (input == 0)
    {
      if( leftOver ) *leftOver = 0;
      return 0;
    }

  while( isspace(*input) ) 
    input++; 

  result = input;

  while( *input && !isspace(*input) )
    input++; 

  if (*input)
    {
      *input = 0;
      input++;
      while( isspace(*input) ){ input++; }
    }

  if( leftOver )
    *leftOver = input; 

  return result;
}


int validURIchar(char c)
{
    return 
        (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        c == '.' || c == '-' || c == '_' || c == '~' || c == '?';
    /* question mark isn't allowed character, but I'm not going
       to encode it */
}

/*
 * Encodes character which aren't allowed in URIs
 * like %D0
 */
char urienc[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char * util_httpize(const char* url)
{
    /* Find length of result string */
    int i;
    int len = 0;
    for(i = 0; url[i]; ++i) {
        if( validURIchar(url[i]) )
            len++;
        else 
            len += 3;
    }
    char * out = malloc(sizeof(char)*(len + 1));
    if( out == 0 ) return 0;
    
    out[len]=0;
    int j = 0;
    for( i = 0; url[i]; ++i ) {
        if( validURIchar(url[i]) )
            out[j++] = url[i];
        else {
            out[j++] = '%';
            out[j++] = urienc[ (url[i]&0xF0) >> 4 ];
            out[j++] = urienc[ url[i]&0x0F ];
        }
    }
    return out;
}

