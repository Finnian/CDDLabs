/* Barrier.h --- Barrier.h
 * 
 * Filename: Barrier.h
 * Description: 
 * Author: Finnian
 * Maintainer: 
 * Created: Tue 5 March 17:15:02 2019 (+0000)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: Tue 5 March 17:15:02 2019 (+0000)
 *           By: Finnian
 *     Update #: 2
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
#include "Semaphore.h"
#pragma once

class Barrier{
  int numThreads;
  int count = 0;

  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> turnstile;
  std::shared_ptr<Semaphore> turnstile2;
   
 public:
  Barrier(int numThreads);
  virtual ~Barrier();
  void wait();  
};


/* Barrier.h ends here */
