/* loadmod_add_hook_point.c --- 
 * 
 * Filename: loadmod_add_hook_point.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sun Jan  4 15:48:01 2009 (+0200)
 * Version: 
 * Last-Updated: Wed Mar  4 10:43:24 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 23
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

  void		loadmod_add_hook_point(t_module *t, const char *point,
				       t_hook_position position,
				       loadmod_hook hook_fct)
  {
    t_hook	*hook;

    if (point == NULL)
      return;
    hook = malloc(sizeof(*hook));
    strcpy(hook->point, point);
    hook->position = position;
    hook->hook_fct = hook_fct;
    list_push(&(t->hook_list), (void*)hook);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* loadmod_add_hook_point.c ends here */
