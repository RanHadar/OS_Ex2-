#ifndef EX2_SCHEDULER_H
#define EX2_SCHEDULER_H

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <list>

#define MAX_THREADS 100




class Scheduler {


public:

    Scheduler();
    ~Scheduler();



private:

    int currentThreadID;
    std::list<int> blockedThreadsList;
    std::list<int> readyThreadsList;


};


#endif //EX2_SCHEDULER_H
