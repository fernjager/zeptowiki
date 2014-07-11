/*
 *      wikiashtml.c
 *      
 *      Copyright 2010 jp <inphilly@gmail.com>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */
/************************************************************************/
/*  Here we translate the page in html and 'print' it. 
 * The main function for this job is wiki_print_data_as_html()
 * HttpResponse *res contains the vars passed to the server.
 * char *raw_page_data contains the text to translate.
 * int autorized is TRUE if logged.
 * char *page is the page name.
 */
 
#include "didi.h"
#include "discount-2.1.6/markdown.h"

int
wiki_print_data_as_html(
HttpResponse *res, char *raw_page_data, int autorized, char *page)
{
  Document *doc;
  char *buffer;

  doc = mkd_string( raw_page_data, strlen(raw_page_data), MKD_TOC | MKD_EXTRA_FOOTNOTE );
  mkd_compile( doc, MKD_TOC | MKD_EXTRA_FOOTNOTE );
  mkd_document( doc, &buffer );

  http_response_printf( res, buffer );
  mkd_cleanup( doc );
  return 0;
}
