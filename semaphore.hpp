//
//  semaphore.hpp
//  Concurrency
//
//  Created by Ilan Rozen on 20/09/2020.
//  Copyright © 2020 Ilan Rozen. All rights reserved.
//

#ifndef semaphore_hpp
#define semaphore_hpp

#include <stdio.h>
#include <mutex>

class Semaphore
{
    std::mutex mtx;
    std::condition_variable cv;
    int counter;
public:
    Semaphore(int n);
    void wait();
    void post();
    
};


#endif /* semaphore_hpp */
