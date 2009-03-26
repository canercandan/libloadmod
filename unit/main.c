/* main.c --- 
 * 
 * Filename: main.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sun Jan  4 16:50:19 2009 (+0200)
 * Version: 
 * Last-Updated: Wed Mar  4 11:05:00 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 22
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

#include <loadmod.h>

int		main(void)
{
  t_loadmod	*t;

  t = loadmod_init("modules", 0.1);
  loadmod_exec_hook_point(t, "init", NULL);
  loadmod_exec_hook_point(t, "work", NULL);
  loadmod_exec_hook_point(t, "end", NULL);
  loadmod_free(t);
  return (0);
}

/* main.c ends here */
