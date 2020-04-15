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
    Thread();
    ~Thread();





private:
    char stack1[STACK_SIZE];
    int threadID;
    int quantumCounter;
    static address_t translate_address(address_t address);

    void setup();



};


#endif //EX2_THREAD_H
