#include "syscall.h"

void print(int i) {
    if (i %2)
{

        SynchPutString("And I'm Steven\n");
//          SynchPutChar('A');
}
else
{
        SynchPutString("I'm Even\n");
          //SynchPutChar('B');
}
        UserThreadExit();
}
int main() {
        SynchPutString("let's begin\n");
        UserThreadCreate(print,(void *) 12);
        UserThreadCreate(print,(void *) 23 );
        return 0 ;
}
