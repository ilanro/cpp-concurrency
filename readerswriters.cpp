//
//  readerswriters.cpp
//  Concurrency
//
//  Created by Ilan Rozen on 16/09/2020.
//  Copyright © 2020 Ilan Rozen. All rights reserved.
//

#include "readerswriters.hpp"

using namespace std;
ReadersWriters::ReadersWriters(): readers_count(0), waiting_writers(0),is_writing(false) {}

void ReadersWriters::StartRead()
{
    unique_lock<mutex> lk(this->mtx);
    while(this->is_writing/* || this->waiting_writers>0*/)
        this->cv.wait(lk);
    
    this->readers_count++;
    
    // READING can begin
    
    
    lk.unlock();
    cv.notify_all();
}

void ReadersWriters::EndRead()
{
    unique_lock<mutex> lk(this->mtx);
    
    this->readers_count--;
    
    lk.unlock();
    cv.notify_all();
}

void ReadersWriters::StartWrite()
{
    unique_lock<mutex> lk(mtx);
    this->waiting_writers++;
    while(is_writing || this->readers_count>0)
        this->cv.wait(lk);
    
    this->is_writing = true;
    this->waiting_writers--;
    
    // Writing can begin
    
    lk.unlock();
    cv.notify_all();
}

void ReadersWriters::EndWrite()
{
    unique_lock<mutex> lk(mtx);
    
    this->is_writing = false;
    
    lk.unlock();
    cv.notify_all();
}
