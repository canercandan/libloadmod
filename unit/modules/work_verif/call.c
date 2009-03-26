/* call.c --- 
 * 
 * Filename: call.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Mon Jan  5 14:09:53 2009 (+0200)
 * Version: 
 * Last-Updated: Mon Jan  5 18:41:05 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 17
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
  return (0);
}

static t_res	run(void *data)
{
  (void)data;
  printf("run work verif\n");
  return (R_CONTINUE);
}

void	call(t_module *t)
{
  loadmod_set_module_name(t, "work_verif", 0.2);
  loadmod_set_module_callback(t, on_load, NULL);
  loadmod_add_hook_point(t, "work", MIDDLE, run);
}

/* call.c ends here */
