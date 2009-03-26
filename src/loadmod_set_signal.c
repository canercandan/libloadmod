/* loadmod_set_signal.c --- 
 * 
 * Filename: loadmod_set_signal.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Mon Jan  5 19:06:14 2009 (+0200)
 * Version: 
 * Last-Updated: Mon Jan  5 19:07:21 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 7
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

#include <stdio.h>
#include <signal.h>
#include "loadmod.h"

  static void	*signal_data = 0;

  static void	signal_fct(int signal)
  {
    (void)signal;
    loadmod_free(signal_data);
#ifdef DEBUG
    printf("Loadmod stopped.\n");
#endif /* !DEBUG */
  }

  void	loadmod_set_signal(t_loadmod *t)
  {
    signal_data = t;
    signal(SIGINT, signal_fct);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* loadmod_set_signal.c ends here */
