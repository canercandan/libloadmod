/* call.c --- 
 * 
 * Filename: call.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Mon Jan  5 09:31:20 2009 (+0200)
 * Version: 
 * Last-Updated: Mon Jan  5 14:06:03 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 50
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

#include <stdio.h>
#include <loadmod.h>

static t_module	*mod = NULL;

static int	on_load(void)
{
  printf("test2 on load\n");
  return (0);
}

static void	on_unload(void)
{
  printf("test2 on unload\n");
}

static t_res	run(void *data)
{
  (void)data;
  printf("test2 on run\n");
  return (R_CONTINUE);
}

void	call(t_module *t)
{
  mod = t;
  loadmod_set_module_name(t, "test2", 111.1);
  loadmod_set_module_callback(t, on_load, on_unload);
  loadmod_add_hook_point(t, "init", VERY_FIRST, run);
}

/* call.c ends here */
