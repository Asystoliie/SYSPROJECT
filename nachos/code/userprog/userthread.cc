#include "userthread.h"
#include "machine.h"
#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "thread.h"
#include "syscall.h"

extern Machine *machine;
extern Thread *currentThread;

static void StartUserThread(int f){

  forkArgs *farg = (forkArgs *)f;

   currentThread->space->InitRegisters();
   currentThread->space->RestoreState();

   machine->WriteRegister (PCReg, farg->f);
   machine->WriteRegister (NextPCReg, farg->f + 4);

   machine->WriteRegister(4, farg->arg);
   //machine->WriteRegister (StackReg, currentThread->space->getFloorAdress() - 16);

   machine->Run ();		// jump to the user progam

}


int do_UserThreadCreate(int f, int arg){

  //the current kernel thread must create a new thread newThread
  Thread *newThread = new Thread ("new Thread");
  forkArgs *farg = new forkArgs;

  farg->f = f;
  farg->arg = arg;
//  currentThread->space->UpdateThreadCount(1);

  newThread->space = currentThread->space; // NOT SURE
  //initialize it and place it in the threads queue
  newThread->Fork(StartUserThread,(int)farg);
  return 0;

}

void do_UserThreadExit(){
  //delete currentThread->space;
  //un thread de moins
  /*currentThread->space->UpdateThreadCount(-1);
  // si c'est le dernier thread Halt
  currentThread->space->semLiveThreads->P();
  if(currentThread->space->GetThreadCount() == 0){
  currentThread->space->semLiveThreads->V();
    interrupt->Halt();
  }
  else{*/
    currentThread->Finish();
  //}

}
