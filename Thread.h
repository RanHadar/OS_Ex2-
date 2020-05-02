#ifndef EX2_THREAD_H
#define EX2_THREAD_H

#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>


#define SECOND 1000000
#define STACK_SIZE 4096

typedef unsigned long address_t;

class Thread {

public:
    sigjmp_buf env;
    sigset_t mask;
    Thread(int threadID, void (*f)(void), int stackSize);
    ~Thread();


    int getThreadID(){
        return threadID;
    }

    int getQuantumCounter(){
        return quantumCounter;
    }

    void incQuantumConter(){
        quantumCounter++;
    }


private:
    char stack1[STACK_SIZE];
    int threadID;
    int quantumCounter;
    static address_t translate_address(address_t address);

    void setup(void (*f)(void), int stackSize);

};

#endif //EX2_THREAD_H
