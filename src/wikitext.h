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

#ifndef _HAVE_WIKI_TEXT_HEADER
#define _HAVE_WIKI_TEXT_HEADER


#define PAGEHEADER                                                       \
                                                                         \
"<div id='header'>\n"                                                    \
"<form method='get' action='/Search'>\n"                                 \
"<table border='0' width='100%%'>\n"                                      \
"<tr>\n"                                                                 \
"<td align='left' ><strong>%s</strong> %s</td>\n"         \
"<td align='right' >\n"                                    \
"<a href='/WikiHome' title='Visit Wiki home page. [alt-z]' accesskey='z'>Home</a> |\n"  \
"<a href='/Index' title='List pages in the wiki. [alt-i]' accesskey='i' >Index</a> | \n"                                    \
"<a href='/Changes' title='List recent changes in the wiki. [alt-r]' accesskey='r' >Changes</a> | \n"                                    \
"<a href='/Create' title='Create a new wiki page by title. [alt-c]' accesskey='c'>New</a> | \n"                                         \
"<a href='/WikiHelp' title='Get help on wiki usage and formatting.'>Help</a> |\n"                                       \
"<input type='text' name='expr' size='15' title='Enter text to search for and press return.' /> </td>\n"                               \
"</tr>\n"                                                                \
"</table>\n"                                                             \
"</form>\n"                                                              \
"</div>\n"                                                               \
"<div id='wikidata'>\n"


#define PAGEFOOTER                                                       \
                                                                         \
"</div><div id='footer'>DidiWiki, Version: " VERSION "</div>\n"


#define CREATEFORM                                                       \
                                                                        \
"<form method=POST action='/Create'>\n"                                  \
"<input type='text' name='title' />\n"                                   \
"<p><input type='submit' value='Create' /></p>\n"                        \
"</form>\n" 


#define EDITFORM                                                         \
                                                                         \
"<form method=POST action='%s' name='editform'>\n"                        \
"<textarea name='wikitext' rows='35' cols='80' wrap='virtual'>%s</textarea>\n" \
"<p><input type='submit' value='Save' title='[alt-k]' accesskey='k'></p>\n"                            \
"</form>\n"             \
"<script language='JavaScript'>\n"   \
"/* Give the textarea focus ...less mouse usage but may annoy people ?*/ \n" \
"document.editform.wikitext.focus()\n" \
"</script>\n"


#define HOMETEXT ""                                                      \
                                                                         \
"==Welcome to !DidiWiki\n"                                               \
"/!DidiWiki / is a small and simple [http://en.wikipedia.org/wiki/Wiki WikiWikiWeb]\n" \
"implementation. It's intended for personal note-taking, \"to do\" lists, and any other uses you can think of.\n"                               \
"\n"                                                                        \
"To learn more about what a [http://www.c2.com/cgi/wiki?WikiWikiWeb WikiWikiWeb] is, read about [http://www.c2.com/cgi/wiki?WhyWikiWorks WhyWikiWorks] and the [http://www.c2.com/cgi/wiki?WikiNature WikiNature]. Also, consult the [http://www.c2.com/cgi/wiki?WikiWikiWebFaq WikiWikiWebFaq].\n"                      \
"\n"                                                                        \
"For an example of how a !DidiWiki entry looks in text form you can [?edit edit] this page. Also see WikiHelp for infomation on usage and formatting rules. Use The WikiSandbox to experiment.\n" \
"\n"                                                                        \
"/!DidiWiki / is written by [mailto://mallum@o-hand.com Matthew Allum] in C and is free software, released under the [http://www.gnu.org GNU] [http://www.gnu.org/copyleft/gpl.html GPL]. It uses a formatting style similar to that of [http://www.kwiki.org kwiki] and some webserver code from [http://www.cvstrac.org cvstrac].\n"


#define HELPTEXT ""                                                      \
                                                                         \
"=Quick Guide \n"                                                    \
"Top toolbar usage\n"                                                    \
"* [?edit Edit] Allows you to edit pages ( see below for rules )\n"       \
"* [/WikiHome Home] Takes you to the wiki front page\n"                \
"* [/Changes Changes] Lists the pages changed by date\n"                  \
"* [/Create New] Creates a new wiki page by title\n"                      \
"* [/WikiHelp Help] Takes you to this help page\n"                            \
"\n"                                                                     \
"Use the text entry box to perform a very simple keyword search on the\n" \
"Wiki contents. Hit return to activate the search.\n"                    \
"\n"                                                                     \
"Use the WikiSandbox to practice formatting.\n"                         \
"\n"                                                                     \
"----\n"                                                                 \
"=Formatting rules\n"                                                    \
"\n"                                                                     \
"=Top Level Heading\n"                                                   \
"  =Top Level Heading (H1)\n"                                            \
"==Second Level Heading\n"                                               \
"  ==Second Level Heading (H2)\n"                                        \
"More levels \n"                                                         \
"  === (H3), ==== (H4) etc\n"                                            \
"----\n"                                                                 \
"The horizontal lines in this page are made with 4 or more dashes:\n"     \
" ---- Horizonal line\n"                                                 \
"----\n"                                                                 \
"\n"                                                                     \
"Paragraphs are separated by an empty line\n"                            \
"\n"                                                                     \
"Like this. Another paragraph.\n"                                        \
"\n"                                                                     \
" Paragraphs are separated by a blank line.\n"                           \
"\n"                                                                     \
" Like this. Another paragraph.\n"                                       \
"----\n"                                                                 \
"*Bold text*, /italic text/, _underscore text_ and -strikethrough-.\n"    \
"  *Bold text*, /italic text/, _underscore text_ and -strikethrough-.\n"  \
"/*Combination of bold and italics*/\n"                                  \
"  /*Combination of bold and italics*/\n"                                \
"----\n"                                                                 \
"\n"                                                                     \
"WikiLinks are formed by two or more words in /camelcase/.\n"           \
" WikiLinks are formed by two or more words in /camelcase/.\n"          \
"External links begin with http://, like http://www.freepan.org\n"       \
" External links begin with http://, like http://www.freepan.org\n"      \
"Forced wiki [links] are a alphanumeric string surrounded by square brackets.\n" \
" Forced wiki [links] are a alphanumeric string surrounded by square brackets.\n" \
"Named http links have text with an !http:// link inside, like [http://www.freepan.org FreePAN]\n" \
" Named http links have text with an !http:// link inside, like [http://www.freepan.org FreePAN]\n" \
"Sometimes !WordsShouldNotMakeAWikiLink so put a '! ' beforehand.\n"      \
" Sometimes !WordsShouldNotMakeAWikiLink so put a '! ' beforehand.\n"     \
"Same thing with !http://foobar.com\n"                                   \
" Same thing with !http://foobar.com\n"                                  \
"----\n"                                                                 \
"\n"                                                                     \
"Links to images display the image:\n"                                   \
"\n"                                                                     \
"http://www.google.com/images/logo.gif\n"                                \
" http://www.google.com/images/logo.gif\n"                               \
"----\n"                                                                 \
"Unordered lists begin with a '* '. The number of asterisks determines the level:\n" \
"* foo\n"                                                                \
"* bar\n"                                                                \
"** boom\n"                                                              \
"** bam\n"                                                               \
"* baz\n"                                                                \
"\n"                                                                     \
"  * foo\n"                                                              \
"  * bar\n"                                                              \
"  ** boom\n"                                                            \
"  ** bam\n"                                                             \
"  * baz\n"                                                              \
"\n"                                                                     \
"Ordered lists work the same, but use a '#'\n"                           \
"----\n"                                                                 \
"Tables begin the line with a '|' and before every new column after.\n"  \
"\n"                                                                     \
"| row:1,col:1 | row:1,col:2\n"                                          \
"| row:2,col:1 | row:2,col:2\n"                                          \
" | row:1,col:1 | row:1,col:2\n"                                         \
" | row:2,col:1 | row:2,col:2\n"                                         \
"---\n"                                                                  \
"<Inline> <html> <is> <escaped>.\n"                                      \
"\n"                                                                     \
"----\n"                                                                 \
"Lines prefixed with a space are unformatted ( Like examples on this page )\n" \
"\n"                                                                     \
"----\n"                                                                 \


#define STYLESHEET                                                       \
                                                                         \
"body {\n" \
"  font-family: Verdana, Arial, Helvetica, sans-serif;\n" \
"  font-size: 90%;  \n" \
"  color: #333333;\n" \
"  margin: 2px;\n" \
"  padding: 2px;\n" \
"}\n" \
"\n" \
"#header {\n" \
"    font-size: 90%;\n" \
"    background-color: #eef;\n" \
"    border: 1px solid #aaa;\n" \
"    font-family: Verdana, Arial, Helvetica, sans-serif;\n" \
"    padding: 5px;\n" \
"    margin-bottom:20px;\n" \
"}\n" \
"#header input {\n" \
"    margin:0px;\n" \
"    padding: 0;\n" \
"    background-color: White;\n" \
"    border: 1px solid #aaaaaa;\n" \
"    font-size: 90%;\n" \
"}\n" \
"\n" \
"#footer {\n" \
"    font-size: 10px;\n" \
"    color: #ddd;\n" \
"    margin-top:40px;\n" \
"    width: 100%;\n" \
"    text-align: center;\n" \
"}\n" \
"table.wikitable { background-color: #fff; border: 1px solid #aaa; }\n" \
"table.wikitable td { background-color: #fff; border: 1px solid #aaa; }\n" \
"\n" \
"pre {\n" \
"    font-family: monospace;\n" \
"    background-color: #eee;\n" \
"    padding: 2px;\n" \
"    padding-left: 10px;\n" \
"    margin-left: 20px;\n" \
"    margin-right: 20px;\n" \
"}\n" \
"\n" \
"hr {\n" \
" height: 1px;\n" \
" color: #aaaaaa;\n" \
" background-color: #aaaaaa;\n" \
" border: 0;\n" \
" margin: 0.2em 5px 0.2em 5px;\n" \
"}\n" \
"\n" \
"form {\n" \
"    border: none;\n" \
"    margin: 0;\n" \
"}\n" \
"\n" \
"textarea {\n" \
"    border: 1px solid #aaaaaa;\n" \
"    color: Black;\n" \
"    background-color: white;\n" \
"    width: 100%;\n" \
"    padding: 0.1em;\n" \
"    overflow: auto;\n" \
"}\n" \
"\n" \
"input {\n" \
"    margin-top:1px;\n" \
"    padding: 0 0.4em !important;\n" \
"    background-color: White;\n" \
"    border: 1px solid #aaaaaa;\n" \
"}\n" \
"\n" \
"a, ulink{\n" \
"   color: #333;\n" \
"   text-decoration:none;\n" \
"   border-bottom: 1px #333 dotted;\n" \
"   display: inline;\n" \
" }\n" \
"\n" \
"a:hover {\n" \
"   color: #333;\n" \
"   text-decoration: None;\n" \
"   border-bottom: 1px #000 solid;\n" \
"   }\n" \
"\n" \
"a:visited {\n" \
"   color: #333;\n" \
"}\n" \
"\n" \

/* use xdd -i favicon.ico to generate */

unsigned char FaviconData[] = {
  0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
  0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10,
  0x08, 0x03, 0x00, 0x00, 0x00, 0x28, 0x2d, 0x0f, 0x53, 0x00, 0x00, 0x00,
  0xc0, 0x50, 0x4c, 0x54, 0x45, 0x00, 0x00, 0x00, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0x33,
  0x7a, 0xb7, 0x33, 0x7a, 0xb7, 0xf7, 0xd8, 0xf8, 0x6e, 0x00, 0x00, 0x00,
  0x3f, 0x74, 0x52, 0x4e, 0x53, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x07,
  0x08, 0x09, 0x0b, 0x0c, 0x0e, 0x14, 0x15, 0x23, 0x27, 0x28, 0x29, 0x2e,
  0x35, 0x37, 0x3c, 0x3f, 0x44, 0x47, 0x4d, 0x4e, 0x50, 0x56, 0x7b, 0x85,
  0x8b, 0x8c, 0xa0, 0xa3, 0xa6, 0xab, 0xb0, 0xb2, 0xb5, 0xb9, 0xba, 0xbe,
  0xc1, 0xc3, 0xc5, 0xc8, 0xca, 0xce, 0xcf, 0xd5, 0xd9, 0xda, 0xdc, 0xde,
  0xe2, 0xe8, 0xe9, 0xf5, 0xf7, 0xf9, 0xfb, 0xfd, 0x2d, 0x80, 0x0f, 0xf4,
  0x00, 0x00, 0x00, 0x90, 0x49, 0x44, 0x41, 0x54, 0x18, 0x19, 0x05, 0xc1,
  0x07, 0x22, 0x43, 0x41, 0x00, 0x05, 0xc0, 0xd9, 0xf5, 0x97, 0xe0, 0x6b,
  0xd1, 0x6b, 0xf4, 0x4e, 0x10, 0x44, 0x7f, 0xf7, 0xbf, 0x95, 0x19, 0x30,
  0x3c, 0xf9, 0xce, 0xdf, 0xc5, 0x66, 0x01, 0xb4, 0xf3, 0x24, 0x49, 0xf2,
  0xb8, 0x00, 0xba, 0xf7, 0x4c, 0x77, 0xe6, 0xeb, 0xdc, 0xfa, 0x38, 0x5f,
  0x8b, 0x70, 0x9a, 0xab, 0x06, 0xca, 0x71, 0x9e, 0x0a, 0xcb, 0xf9, 0x68,
  0x80, 0xf2, 0x90, 0x6d, 0x8e, 0x72, 0x00, 0x60, 0x98, 0x7b, 0x26, 0x59,
  0x02, 0xd0, 0x25, 0xc5, 0x4f, 0x06, 0x00, 0x24, 0xcd, 0x5b, 0x7a, 0x00,
  0x5d, 0x52, 0x8d, 0xb2, 0x07, 0x60, 0x2d, 0x63, 0x56, 0x33, 0xed, 0x00,
  0x6e, 0xb2, 0x8b, 0xcb, 0x9c, 0x55, 0xe0, 0x30, 0x93, 0x8a, 0xd9, 0xcf,
  0xbc, 0x6c, 0x34, 0x33, 0x2b, 0xd7, 0xf9, 0xed, 0xc1, 0xe0, 0x2e, 0x49,
  0x92, 0xbc, 0xf6, 0x80, 0xb2, 0x75, 0x9b, 0xe4, 0x79, 0xbf, 0x02, 0xa0,
  0xb4, 0x0a, 0xf8, 0x07, 0xcc, 0x2e, 0x13, 0x37, 0xbb, 0xa8, 0x86, 0xd6,
  0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

unsigned int FaviconDataLen = 480;

#endif
