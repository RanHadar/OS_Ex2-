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

    void addNewThread(int threadID);

    int quantumChange();

    int getRunningTid() { return runningThreadID; }

    int terminateThread(int theadID);

    int blockThread(int threadID);

    void resumeThread(int treadID);


private:

    int runningThreadID;
    std::list<int> blockedThreadsList;
    std::list<int> readyThreadsList;
    void popFrontReady();
};


#endif //EX2_SCHEDULER_H
