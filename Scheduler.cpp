#include "Scheduler.h"


Scheduler::Scheduler():blockedThreadsList(),readyThreadsList()
{
    for(int i = 0; i < MAX_THREADS ; ++i)
    {
    }
}

Scheduler::~Scheduler()  = default;

void Scheduler::addNewThread(int threadID)
{


}

int Scheduler::quantumChange() {

    readyThreadsList.push_back(runningThreadID);
    runningThreadID = readyThreadsList.front();
    readyThreadsList.pop_front();
    return runningThreadID;
}

int Scheduler::terminateThread(int threadID) {

    readyThreadsList.remove(threadID);
    blockedThreadsList.remove(threadID);

}

int Scheduler::blockThread(int threadID) {
    blockedThreadsList.push_back(threadID);
    if(runningThreadID == threadID)
    {
        popFrontReady();
    } else{
        readyThreadsList.remove(threadID);
    }
    return runningThreadID;
}

void Scheduler::resumeThread(int threadID) {
    if(runningThreadID != threadID){
        runningThreadID = threadID;
    }
}

void Scheduler::popFrontReady(){
    runningThreadID = readyThreadsList.front();
    readyThreadsList.pop_front();
}

