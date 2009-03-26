/* loadmod_set_module_callback.c --- 
 * 
 * Filename: loadmod_set_module_callback.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sun Jan  4 16:14:20 2009 (+0200)
 * Version: 
 * Last-Updated: Mon Jan  5 10:50:36 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 8
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

#include "loadmod.h"

  void	loadmod_set_module_callback(t_module* t,
				    loadmod_load load_fct,
				    loadmod_unload unload_fct)
  {
    t->load_fct = load_fct;
    t->unload_fct = unload_fct;
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* loadmod_set_module_callback.c ends here */
