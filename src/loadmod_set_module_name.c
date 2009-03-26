/* loadmod_set_module_name.c --- 
 * 
 * Filename: loadmod_set_module_name.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sun Jan  4 16:10:18 2009 (+0200)
 * Version: 
 * Last-Updated: Mon Jan  5 10:50:44 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 12
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
#include "loadmod.h"

  void	loadmod_set_module_name(t_module *t, const char *name, double version)
  {
    strncpy(t->name, name, NAME_SIZE);
    t->version = version;
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* loadmod_set_module_name.c ends here */
