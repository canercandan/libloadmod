/* loadmod_add_comp_version.c --- 
 * 
 * Filename: loadmod_add_comp_version.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Wed Mar  4 10:45:56 2009 (+0200)
 * Version: 
 * Last-Updated: Wed Mar  4 10:53:14 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 2
 * URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301, USA.
 */

/* Code: */

#ifdef __cplusplus
extern "C"
{
#endif /* !__cplusplus */

#include <string.h>
#include <stdlib.h>
#include "loadmod.h"

  void			loadmod_add_comp_version(t_module *t, double version,
						 const char *comment)
  {
    t_comp_version	*cv;

    cv = malloc(sizeof(*cv));
    cv->version = version;
    if (comment != NULL)
      strcpy(cv->comment, comment);
    list_push(&(t->comp_version_list), (void*)cv);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* loadmod_add_comp_version.c ends here */
