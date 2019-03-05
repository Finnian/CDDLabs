// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: 
// Author: Finnian Fanning
// Maintainer: 
// Created: Tue 5 March 17:15:02 2019 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Tue Jan  8 12:15:21 2019 (+0000)
//           By: Finnian
//     Update #: 2
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>

Barrier::~Barrier(){}

Barrier::Barrier(int numThreads)
{
  this->numThreads = numThreads;
  std::shared_ptr<Semaphore> turnstile( new Semaphore(0));
  std::shared_ptr<Semaphore> turnstile2( new Semaphore(1));
  std::shared_ptr<Semaphore> mutex ( new Semaphore(1));
}

void Barrier::wait()
{
  mutex->Wait();
  count++;
  
  if(count == numThreads) 
  {
    turnstile2->Wait();
    turnstile->Signal();
  }
  mutex->Signal(); 
  turnstile->Wait();
  turnstile->Signal();
  mutex->Wait();
  count--;
  if(count == 0) 
  {
    turnstile->Wait();
    turnstile2->Signal();
  }

  mutex->Signal();
  turnstile2->Wait();
  turnstile2->Signal();
}
// 
// Barrier.cpp ends here
