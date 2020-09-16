//
//  readerswriters.hpp
//  Concurrency
//
//  Created by Ilan Rozen on 16/09/2020.
//  Copyright © 2020 Ilan Rozen. All rights reserved.
//

#ifndef readerswriters_hpp
#define readerswriters_hpp

#include <stdio.h>
#include <mutex>
#include <thread>

using namespace std;


class ReadersWriters
{
    int readers_count, waiting_writers;
    bool is_writing;

    mutex mtx;
    condition_variable cv;
    
public:
    ReadersWriters();
    void StartRead();
    void EndRead();
    void StartWrite();
    void EndWrite();
};

#endif /* readerswriters_hpp */
