/* loadmod_init.c --- 
 * 
 * Filename: loadmod_init.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sat Jan  3 18:30:05 2009 (+0200)
 * Version: 
 * Last-Updated: Wed Mar  4 11:02:47 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 209
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
#include <string.h>
#include <dirent.h>
#include <dlfcn.h>
#include <stdio.h>
#include "loadmod.h"

  static double		version = 0;

  static void		init_files(t_list **t, const char *path)
  {
    struct dirent	*dp;
    DIR			*dirp;
    char		*tmp;
    int			len;
    char		pathfile[1024];

    if ((dirp = opendir(path)) != NULL)
      {
	while ((dp = readdir(dirp)) != NULL)
	  {
	    if ((len = strlen(dp->d_name)) < 3)
	      continue;
	    tmp = dp->d_name + len - 3;
	    if (strcmp(tmp, FILE_MOD_EXT) != 0)
	      continue;
	    pathfile[0] = 0;
	    strcat(pathfile, path);
	    strcat(pathfile, "/");
	    strcat(pathfile, dp->d_name);
#ifdef DEBUG
	    printf("*** add file [%s]\n", pathfile);
#endif /* !DEBUG */
	    list_push(t, (void*)strdup(pathfile));
	  }
	closedir(dirp);
      }
  }

  static t_module	*new_module()
  {
    t_module		*t;

    t = malloc(sizeof(*t));
    t->name[0] = 0;
    t->version = 0;
    t->load_fct = NULL;
    t->unload_fct = NULL;
    list_init(&(t->hook_list));
    return (t);
  }

  static t_res		check_version(void *data_list)
  {
    t_comp_version	*t;

    t = data_list;
#ifdef DEBUG
    printf("*** program version [%.2f] and module compatible version [%.2f]\n",
	   version, t->version);
#endif /* !DEBUG */
    return ((t->version == version) ? R_FOUND : R_CONTINUE);
  }

  static t_res		init_module_list(void *data_list, void *data)
  {
    char		*filename;
    t_loadmod		*t;
    t_module		*mod;
    loadmod_call	create;

    filename = data_list;
    t = data;
#ifdef DEBUG
    printf("*** init module [%s]\n", filename);
#endif /* !DEBUG */
    if ((t->handle = dlopen(filename, RTLD_NOW)) == NULL)
      {
#ifdef DEBUG
	perror(dlerror());
#endif /* !DEBUG */
	return (R_CONTINUE);
      }
    if ((create = (loadmod_call)dlsym(t->handle, "call")) == NULL)
      {
	dlclose(t->handle);
	return (R_CONTINUE);
      }
    mod = new_module();
    create(mod);
    if (list_all(mod->comp_version_list, check_version) == R_FOUND)
      if (mod->load_fct != NULL && (*(mod->load_fct))() >= 0)
	{
	  list_push(&(t->module_list), (void*)mod);
	  return (R_CONTINUE);
	}
    free(mod);
    return (R_CONTINUE);
  }

  static void	init_modules(t_loadmod *t)
  {
    list_all_data(t->file_list, init_module_list, (void*)t);
  }

  t_loadmod	*loadmod_init(const char *module_path, double program_version)
  {
    t_loadmod	*t;

    version = program_version;
    t = malloc(sizeof(*t));
    list_init(&(t->file_list));
    list_init(&(t->module_list));
    init_files(&(t->file_list), module_path);
    init_modules(t);
    return (t);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* loadmod_init.c ends here */
