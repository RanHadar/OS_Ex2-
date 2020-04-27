#include <iostream>

#include "uthreads.h"
#include "Scheduler.h"
#include "Thread.h"

#define SUCCESS 0
#define FAILURE -1

Scheduler scheduler;
Thread *threads[MAX_THREADS];
int quantumCounter = 0;

struct sigaction sigAction;
struct itimerval timer;
sigset_t alarmSignal;

int uthread_init(int *quantum_usecs, int size)
{
    if(quantum_usecs <= 0)
    {
        std::cerr << "thread library error: Wrong input - quantum_usecs";
    }
    for(auto &thread: threads)
    {
        thread = nullptr;
    }

    threads[0] = new Thread(0, nullptr,STACK_SIZE);
    scheduler.addNewThread(0);
    threads[0]->incQuantumConter();
    quantumCounter++;


    return SUCCESS;



}

int uthread_spawn(void (*f)(void), int priority)
{
    if()


}