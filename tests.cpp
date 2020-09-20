//
//  tests.cpp
//  Concurrency
//
//  Created by Ilan Rozen on 20/09/2020.
//  Copyright © 2020 Ilan Rozen. All rights reserved.
//

#include "tests.hpp"

using namespace std;

int shared = 0;
mutex g;

void write_to_shared(ReadersWriters *rw)
{
    rw->StartWrite();
    cout<<"Thread" << this_thread::get_id()<<" is writing to shared. Value after write: "<< (++shared) <<endl;
    rw->EndWrite();
}

void read_from_shared(ReadersWriters *rw)
{
    rw->StartRead();
    g.lock();
    cout<<"Thread" << this_thread::get_id()<<" is reading from shared. Value after write: "<< shared <<endl;
    g.unlock();
    rw->EndRead();
}

void test_readers_writers()
{
    vector<thread> threads;
    ReadersWriters rw;
    
    
    for (int i=0; i<10; i++) {
        threads.push_back(thread(write_to_shared, &rw));
        threads.push_back(thread(read_from_shared, &rw));
    }
    
    for(auto &th : threads)
    {
        th.join();
    }
}
