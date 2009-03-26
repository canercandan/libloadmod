/* loadmod_exec_hook_point.c --- 
 * 
 * Filename: loadmod_exec_hook_point.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Mon Jan  5 10:03:38 2009 (+0200)
 * Version: 
 * Last-Updated: Wed Mar  4 08:39:26 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 117
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
#include <stdio.h>
#include "loadmod.h"

  static char			*pt = NULL;
  static void			*dt = NULL;
  static t_loadmod		*lm = NULL;
  static t_hook_position	pos = 0;

  static t_res		hook_list(void *data_list, void *data)
  {
    t_hook		*hook;
    t_res		res;
    t_hook_result	hook_res;

    hook = data_list;
    res = R_CONTINUE;
    if (strcmp(hook->point, pt) == 0 && hook->position == pos)
      if (hook->hook_fct != NULL)
	{
	  hook_res.loadmod = lm;
	  hook_res.module = data;
	  hook_res.data = dt;
	  res = (*(hook->hook_fct))(&hook_res);
	}
    return (res);
  }

  static t_res		module_list(void *data_list)
  {
    t_module		*t;

    t = data_list;
    return (list_all_data(t->hook_list, hook_list, (void*)t));
  }

  t_res		loadmod_exec_hook_point(t_loadmod *t, char *point, void *data)
  {
    t_res	res;

    pt = point;
    dt = data;
    lm = t;
    res = R_CONTINUE;
    for (pos = 0; pos < N_POSITIONS; pos++)
      if ((res = list_all(t->module_list, module_list)) != R_CONTINUE)
	return (res);
    return (res);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* loadmod_exec_hook_point.c ends here */
