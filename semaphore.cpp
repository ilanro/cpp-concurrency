//
//  semaphore.cpp
//  Concurrency
//
//  Created by Ilan Rozen on 20/09/2020.
//  Copyright © 2020 Ilan Rozen. All rights reserved.
//

#include "semaphore.hpp"
using namespace std;


Semaphore::Semaphore(int n): counter(n) {}

void Semaphore::wait()
{
    unique_lock<mutex> lk(this->mtx);
    while(this->counter <= 0)
    {
        this->cv.wait(lk);
    }
    
    this->counter--;
    
}

void Semaphore::post()
{
    unique_lock<mutex> lk(this->mtx);
    this->counter++;
    this->cv.notify_one();
}




