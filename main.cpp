//
//  main.cpp
//  Concurrency
//
//  Created by Ilan Rozen on 16/09/2020.
//  Copyright © 2020 Ilan Rozen. All rights reserved.
//

#include <iostream>
#include "readerswriters.hpp"
#include <semaphore.h>
#include "tests.hpp"

using namespace std;


sem_t a1_done, b1_done;

void a(){
    cout<<"a1"<<endl;
    sem_post(&a1_done);
    sem_wait(&b1_done);
    cout<<"a2"<<endl;
}

void b(){
    cout<<"b1"<<endl;
    sem_post(&b1_done);
    sem_wait(&a1_done);
    cout<<"b2"<<endl;
}





int main(int argc, const char * argv[]) {
    
    //test_readers_writers();
    sem_init(&a1_done, 0, 0);
    sem_init(&b1_done, 0, 0);
    
    thread t1(a);
    thread t2(b);
    
    t1.join();
    t2.join();
    
    return 0;
}
