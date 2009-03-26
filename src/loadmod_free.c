/* loadmod_free.c --- 
 * 
 * Filename: loadmod_free.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sun Jan  4 16:54:38 2009 (+0200)
 * Version: 
 * Last-Updated: Thu Mar 12 11:50:55 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 60
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

#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>
#include "loadmod.h"

  static t_res	list(void *data_list)
  {
    free(data_list);
    return (R_CONTINUE);
  }

  static t_res	module_list(void *data_list)
  {
    t_module	*t;

    t = data_list;
#ifdef DEBUG
    printf("*** free module [%s]\n", t->name);
#endif /* !DEBUG */
    if (t->unload_fct != NULL)
      (*(t->unload_fct))();
    list_all(t->hook_list, list);
    list_free(&(t->hook_list));
    list_all(t->comp_version_list, list);
    list_free(&(t->comp_version_list));
    return (list(data_list));
  }

  void	loadmod_free(t_loadmod *t)
  {
    list_all(t->module_list, module_list);
    list_free(&(t->module_list));
    dlclose(t->handle);
    list_all(t->file_list, list);
    list_free(&(t->file_list));
    free(t);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* loadmod_free.c ends here */
