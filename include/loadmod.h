// loadmod.h --- 
// 
// Filename: loadmod.h
// Description: 
// Author: Caner Candan
// Maintainer: 
// Created: Sat Jan  3 18:29:49 2009 (+0200)
// Version: 
// Last-Updated: Wed Mar  4 10:52:47 2009 (+0200)
//           By: Caner Candan
//     Update #: 143
// URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change log:
// 
// 
// 
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; see the file COPYING.  If not, write to
// the Free Software Foundation, Inc., 51 Franklin Street, Fifth
// Floor, Boston, MA 02110-1301, USA.
// 
// 

// Code:

#ifndef __LOADMOD_H__
# define __LOADMOD_H__

#ifdef __cplusplus
extern "C"
{
#endif

# include <list.h>

  /*
  ** defines
  */

# define NAME_SIZE	128

# define FILE_MOD_EXT	".so"

# define N_POSITIONS	5

  /*
  ** type definitions
  */

  struct	s_module;
  struct	s_hook_result;

  typedef t_res	(*loadmod_hook)(struct s_hook_result*);

  typedef void	(*loadmod_call)(struct s_module*);

  typedef int	(*loadmod_load)(void);
  typedef void	(*loadmod_unload)(void);

  /*
  ** enumerators
  */

  typedef enum
    {
      VERY_FIRST,
      FIRST,
      MIDDLE,
      LAST,
      VERY_LAST
    }	t_hook_position;

  /*
  ** structures
  */

  typedef struct	s_loadmod
  {
    t_list		*file_list;
    t_list		*module_list;
    void		*handle;
  }			t_loadmod;

  typedef struct	s_comp_version
  {
    double		version;
    char		comment[NAME_SIZE];
  }			t_comp_version;

  typedef struct	s_hook
  {
    char		point[NAME_SIZE];
    t_hook_position	position;
    loadmod_hook	hook_fct;
  }			t_hook;

  typedef struct	s_module
  {
    char		name[NAME_SIZE];
    double		version;
    loadmod_load	load_fct;
    loadmod_unload	unload_fct;
    t_list		*hook_list;
    t_list		*comp_version_list;
  }			t_module;

  typedef struct	s_hook_result
  {
    t_loadmod		*loadmod;
    t_module		*module;
    void		*data;
  }			t_hook_result;

  /*
  ** variables
  */

  /*
  ** functions
  */

  t_loadmod	*loadmod_init(const char *module_path, double program_version);

  void	loadmod_add_comp_version(t_module*, double version, const char *comment);

  void	loadmod_add_hook_point(t_module*, const char *point,
			       t_hook_position, loadmod_hook);
  t_res	loadmod_exec_hook_point(t_loadmod*, char *point, void *data);

  void	loadmod_set_module_name(t_module*, const char *name, double version);
  void	loadmod_set_module_callback(t_module*, loadmod_load, loadmod_unload);

  void	loadmod_free(t_loadmod*);
  void	loadmod_set_signal(t_loadmod*);

#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !__LOADMOD_H__ */

// 
// loadmod.h ends here
