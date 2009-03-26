/* call.c --- 
 * 
 * Filename: call.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sun Jan  4 17:37:50 2009 (+0200)
 * Version: 
 * Last-Updated: Wed Mar  4 11:07:30 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 32
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

static int	on_load(void)
{
  printf("test on load\n");
  return (0);
}

static void	on_unload(void)
{
  printf("test on unload\n");
}

static t_res	run(t_hook_result *t)
{
  (void)t;
  printf("test on run\n");
  return (R_CONTINUE);
}

void	call(t_module *t)
{
  loadmod_set_module_name(t, "test", 0.1);
  loadmod_set_module_callback(t, on_load, on_unload);
  loadmod_add_hook_point(t, "end", FIRST, run);
  loadmod_add_comp_version(t, 0.1, NULL);
  loadmod_add_comp_version(t, 0.2, NULL);
  loadmod_add_comp_version(t, 0.3, NULL);
  loadmod_add_comp_version(t, 0.4, NULL);
}

/* call.c ends here */
