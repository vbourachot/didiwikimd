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
"## Welcome to DidiWiki\n" \
"**DidiWiki** is a small and simple [WikiWikiWeb](http://en.wikipedia.org/wiki/Wiki) implementation. It's intended for personal note-taking, \"to do\" lists, and any other uses you can think of.\n" \
"\n" \
"To learn more about what a [WikiWikiWeb](http://www.c2.com/cgi/wiki?WikiWikiWeb) is, read about [WhyWikiWorks](http://www.c2.com/cgi/wiki?WhyWikiWorks) and the [WikiNature](http://www.c2.com/cgi/wiki?WikiNature). Also, consult the [WikiWikiWebFaq](http://www.c2.com/cgi/wiki?WikiWikiWebFaq).\n" \
"\n" \
"For an example of how a DidiWiki entry looks in text form you can [edit](?edit) this page. Also see [WikiHelp](/WikiHelp) for information on usage and formatting rules. Use the [WikiSandbox](/WikiSandbox) to experiment.\n" \
"\n" \
"**DidiWiki** is written by Matthew Allum in C and is free software, released under the [GNU](http://www.gnu.org) [GPL](http://www.gnu.org/copyleft/gpl.html). It uses ~~a formatting style similar to that of kwiki~~ Markdown formatting, rendered via [Discount](http://www.pell.portland.or.us/~orc/Code/discount/), and some webserver code from [cvstrac](http://www.cvstrac.org).\n"


#define HELPTEXT ""                                                      \
                                                                         \
"#Quick Guide\n" \
"\n" \
"Top toolbar usage:\n" \
"\n" \
"* [Edit](?edit) Allows you to edit pages (see below for rules)\n" \
"* [Home](/WikiHome) Takes you to the wiki front page\n" \
"* [Index](/Index) Lists all pages alphabetically\n" \
"* [Changes](/Changes) Lists the pages changed by date\n" \
"* [New](/Create) Creates a new wiki page by title\n" \
"* [Help](/WikiHelp) Takes you to this help page\n" \
"\n" \
"Use the text entry box to perform a very simple keyword search on the Wiki contents. Hit return to activate the search.\n" \
"\n" \
"Use the [WikiSandbox](/WikiSandbox) to practice formatting.\n" \
"\n" \
"----\n" \
"\n" \
"#Markdown Cheatsheet\n" \
"\n" \
"Based on: [https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)\n" \
"\n" \
"## Headers\n" \
"\n" \
"```\n" \
"# H1\n" \
"## H2\n" \
"### H3\n" \
"#### etc\n" \
"```\n" \
"\n" \
"# H1\n" \
"## H2\n" \
"### H3\n" \
"#### etc\n" \
"\n" \
"## Emphasis\n" \
"\n" \
"```\n" \
"Emphasis, aka italics, with *asterisks* or _underscores_.\n" \
"\n" \
"Strong emphasis, aka bold, with **asterisks** or __underscores__.\n" \
"\n" \
"Combined emphasis with **asterisks and _underscores_**.\n" \
"\n" \
"Strikethrough uses two tildes. ~~Scratch this.~~\n" \
"```\n" \
"\n" \
"Emphasis, aka italics, with *asterisks* or _underscores_.\n" \
"\n" \
"Strong emphasis, aka bold, with **asterisks** or __underscores__.\n" \
"\n" \
"Combined emphasis with **asterisks and _underscores_**.\n" \
"\n" \
"Strikethrough uses two tildes. ~~Scratch this.~~\n" \
"\n" \
"## Code Blocks\n" \
"Code blocks are part of the Markdown spec, but syntax highlighting isn’t. However, many renderers – like Github’s and Markdown Here – support syntax highlighting. \n" \
"\n" \
"*Note: No JS highlighting provided to keep things light.* \n" \
"\n" \
"```\n" \
"Inline `code` has `back-ticks around` it.\n" \
"```\n" \
"\n" \
"Inline `code` has `back-ticks around` it.\n" \
"\n" \
"Blocks of code are either fenced by lines with three back-ticks <code>```</code>, or are indented with four spaces. I recommend only using the fenced code blocks.\n" \
"\n" \
"<pre lang=\"no-highlight\"><code>```javascript\n" \
"var s = \"JavaScript syntax highlighting\";\n" \
"alert(s);\n" \
"```\n" \
"\n" \
"```python\n" \
"s = \"Python syntax highlighting\"\n" \
"print s\n" \
"```\n" \
"\n" \
"```\n" \
"No language indicated, so no syntax highlighting.\n" \
"```\n" \
"</code></pre>\n" \
"\n" \
"\n" \
"\n" \
"```javascript\n" \
"var s = \"JavaScript syntax highlighting\";\n" \
"alert(s);\n" \
"```\n" \
"\n" \
"```python\n" \
"s = \"Python syntax highlighting\"\n" \
"print s\n" \
"```\n" \
"\n" \
"```\n" \
"No language indicated, so no syntax highlighting.\n" \
"```\n" \
"\n" \
"## Lists\n" \
"\n" \
"\n" \
"```\n" \
"1. First ordered list item\n" \
"2. Another item\n" \
"3. And another item\n" \
"\n" \
"A paragraph to break the previous list\n" \
"\n" \
"* Unordered list can use asterisks\n" \
"- Or minuses\n" \
"+ Or pluses\n" \
"```\n" \
"\n" \
"1. First ordered list item\n" \
"2. Another item\n" \
"3. And another item\n" \
"\n" \
"A paragraph to break the previous list\n" \
"\n" \
"* Unordered list can use asterisks\n" \
"- Or minuses\n" \
"+ Or pluses\n" \
"\n" \
"## Links\n" \
"\n" \
"There are two ways to create links.\n" \
"\n" \
"```\n" \
"[I\'m an inline-style link](https://www.google.com)\n" \
"\n" \
"[I\'m an inline-style link with title](https://www.google.com \"Google\'s Homepage\")\n" \
"\n" \
"[I'm a reference-style link][Arbitrary case-insensitive reference text]\n" \
"\n" \
"URLs in angle brackets will automatically get turned into links: <http://www.example.com>\n" \
"\n" \
"[arbitrary case-insensitive reference text]: https://www.mozilla.org\n" \
"\n" \
"\n" \
"```\n" \
"\n" \
"[I\'m an inline-style link](https://www.google.com)\n" \
"\n" \
"[I\'m an inline-style link with title](https://www.google.com \"Google\'s Homepage\")\n" \
"\n" \
"[I'm a reference-style link][Arbitrary case-insensitive reference text]\n" \
"\n" \
"URLs in angle brackets will automatically get turned into links: <http://www.example.com>\n" \
"\n" \
"[arbitrary case-insensitive reference text]: https://www.mozilla.org\n" \
"\n" \
"## Images\n" \
"\n" \
"```\n" \
"\n" \
"Inline-style:\n" \
"\n" \
"![alt text](https://upload.wikimedia.org/wikipedia/commons/2/2f/Google_2015_logo.svg \"Logo Title Text 1\")\n" \
"\n" \
"Reference-style:\n" \
"\n" \
"![alt text][logo]\n" \
"\n" \
"[logo]: https://upload.wikimedia.org/wikipedia/commons/2/2f/Google_2015_logo.svg \"Logo Title Text 2\"\n" \
"```\n" \
"\n" \
"Inline-style:\n" \
"\n" \
"![alt text](https://upload.wikimedia.org/wikipedia/commons/2/2f/Google_2015_logo.svg \"Logo Title Text 1\")\n" \
"\n" \
"Reference-style:\n" \
"\n" \
"![alt text][logo]\n" \
"\n" \
"[logo]: https://upload.wikimedia.org/wikipedia/commons/2/2f/Google_2015_logo.svg \"Logo Title Text 2\"\n" \
"\n" \
"## Tables\n" \
"\n" \
"Tables aren't part of the core Markdown spec, but they are part of GFM and *Markdown Here* supports them. They are an easy way of adding tables to your email -- a task that would otherwise require copy-pasting from another application.\n" \
"\n" \
"```\n" \
"Colons can be used to align columns.\n" \
"\n" \
"| Tables        | Are           | Cool  |\n" \
"| ------------- |:-------------:| -----:|\n" \
"| col 3 is      | right-aligned | $1600 |\n" \
"| col 2 is      | centered      |   $12 |\n" \
"| zebra stripes | are neat      |    $1 |\n" \
"\n" \
"There must be at least 3 dashes separating each header cell.\n" \
"The outer pipes (|) are optional, and you don't need to make the\n" \
"raw Markdown line up prettily. You can also use inline Markdown.\n" \
"\n" \
"Markdown | Less | Pretty\n" \
"--- | --- | ---\n" \
"*Still* | `renders` | **nicely**\n" \
"1 | 2 | 3\n" \
"```\n" \
"\n" \
"Colons can be used to align columns.\n" \
"\n" \
"| Tables        | Are           | Cool |\n" \
"| ------------- |:-------------:| -----:|\n" \
"| col 3 is      | right-aligned | $1600 |\n" \
"| col 2 is      | centered      |   $12 |\n" \
"| zebra stripes | are neat      |    $1 |\n" \
"\n" \
"There must be at least 3 dashes separating each header cell. The outer pipes (|) are optional, and you don't need to make the raw Markdown line up prettily. You can also use inline Markdown.\n" \
"\n" \
"Markdown | Less | Pretty\n" \
"--- | --- | ---\n" \
"*Still* | `renders` | **nicely**\n" \
"1 | 2 | 3\n" \
"\n" \
"## Blockquotes\n" \
"\n" \
"```\n" \
"> Blockquotes are very handy in email to emulate reply text.  \n" \
"> This line is part of the same quote.\n" \
"\n" \
"Quote break.\n" \
"\n" \
"> This is a very long line that will still be quoted properly when it wraps. Oh boy let's keep writing to make sure this is long enough to actually wrap for everyone. Oh, you can *put* **Markdown** into a blockquote.\n" \
"```\n" \
"\n" \
"> Blockquotes are very handy in email to emulate reply text.  \n" \
"> This line is part of the same quote.\n" \
"\n" \
"Quote break.\n" \
"\n" \
"> This is a very long line that will still be quoted properly when it wraps. Oh boy let's keep writing to make sure this is long enough to actually wrap for everyone. Oh, you can *put* **Markdown** into a blockquote.\n" \
"\n" \
"## Horizontal Rule\n" \
"\n" \
"```\n" \
"Three or more...\n" \
"\n" \
"---\n" \
"\n" \
"Hyphens\n" \
"\n" \
"***\n" \
"\n" \
"Asterisks\n" \
"\n" \
"___\n" \
"\n" \
"Underscores\n" \
"```\n" \
"\n" \
"Three or more...\n" \
"\n" \
"---\n" \
"\n" \
"Hyphens\n" \
"\n" \
"***\n" \
"\n" \
"Asterisks\n" \
"\n" \
"___\n" \
"\n" \
"Underscores\n" \
"\n" \
"## Line Breaks\n" \
"\n" \
"Basic rules: \n" \
"\n" \
"* Two newlines create a new paragraph\n" \
"* Two spaces at the end of a line create a line break within the same paragraph\n" \
"* A single newline is ignored\n" \
"\n" \
"```\n" \
"Here's a line for us to start with.\n" \
"\n" \
"This line is separated from the one above by two newlines, so it will be a *separate paragraph*.\n" \
"\n" \
"This line also begins a separate paragraph, but ends with two spaces ..  \n" \
"And this line is only separated by a single newline, so it's a separate line in the *same paragraph*.\n" \
"\n" \
"This line also begins a separate paragraph, but does NOT end with two spaces\n" \
"The single newline is ignored and the line is appended to the current paragraph.\n" \
"\n" \
"```\n" \
"\n" \
"Here's a line for us to start with.\n" \
"\n" \
"This line is separated from the one above by two newlines, so it will be a *separate paragraph*.\n" \
"\n" \
"This line also begins a separate paragraph, but ends with two spaces  \n" \
"And this line is only separated by a single newline, so it's a separate line in the *same paragraph*.\n" \
"\n" \
"This line also begins a separate paragraph, but does NOT end with two spaces\n" \
"The single newline is ignored and the line is appended to the current paragraph.\n" \
"\n" \
"---\n" \
"\n" \
"Cheatsheet license: [CC-BY](https://creativecommons.org/licenses/by/3.0/)\n"


#define STYLESHEET                                                       \
                                                                         \
"body {\n" \
"    font-family: \"Helvetica Neue\", Helvetica, sans-serif;\n" \
"    font-size: 90%;\n" \
"    color: #444;\n" \
"    padding: 0 20px 0 20px;\n" \
"}\n" \
"\n" \
"#header {\n" \
"    font-size: 90%;\n" \
"    background-color: #eee;\n" \
"    border: 1px solid #eee;\n" \
"    border-radius: 4px;\n" \
"    font-family: \"Helvetica Neue\", Helvetica, sans-serif;\n" \
"    padding: 5px;\n" \
"    margin-bottom:20px;\n" \
"}\n" \
"\n" \
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
"\n" \
"table.wikitable { background-color: #fff; border: 1px solid #aaa; }\n" \
"table.wikitable td { background-color: #fff; border: 1px solid #aaa; }\n" \
"\n" \
"code {\n" \
"    font-size: 110%;\n" \
"    background-color: #fffddc;\n" \
"}\n" \
"\n" \
"pre {\n" \
"    font-family: monospace;\n" \
"    background-color: #fffddc;\n" \
"    padding: 4px 10px 4px 10px;\n" \
"    margin-left: 20px;\n" \
"    margin-right: 20px;\n" \
"    border: 1px solid #e1e1e1;\n" \
"    border-radius: 4px;\n" \
"    white-space: pre-wrap;\n" \
"}\n" \
"\n" \
"hr {\n" \
"    height: 1px;\n" \
"    color: #aaaaaa;\n" \
"    background-color: #aaaaaa;\n" \
"    border: 0;\n" \
"    margin: 0.2em 5px 0.2em 5px;\n" \
"}\n" \
"\n" \
"form {\n" \
"    border: none;\n" \
"    margin: 0;\n" \
"}\n" \
"\n" \
"textarea {\n" \
"    font-family: \"Helvetica Neue\", Helvetica, sans-serif;\n" \
"    font-size: 90%;\n" \
"    border: 1px solid #e1e1e1;\n" \
"    border-radius: 4px;\n" \
"    color: #444;\n" \
"    background-color: white;\n" \
"    width: 100%;\n" \
"    padding: 0.4em;\n" \
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
"a, ulink {\n" \
"    color: #337ab7;\n" \
"    text-decoration:none;\n" \
"    display: inline;\n" \
"}\n" \
"\n" \
"a:hover {\n" \
"    color: #337ab7;\n" \
"    text-decoration: None;\n" \
"    border-bottom: 1px #000 solid;\n" \
"}\n" \
"\n" \
"a:visited {\n" \
"    color: #337ab7;\n" \
"}\n"

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
