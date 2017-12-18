/* halt.c
 *	Simple program to test whether running a user program works.
 *	
 *	Just do a "syscall" that shuts down the OS.
 *
 * 	NOTE: for some reason, user programs with global data structures 
 *	sometimes haven't worked in the Nachos environment.  So be careful
 *	out there!  One option is to allocate data structures as 
 * 	automatics within a procedure, but if you do this, you have to
 *	be careful to allocate a big enough stack to hold the automatics!
 */

#include "syscall.h"

/*#ifdef CHANGED

void print(char c, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		PutChar(c+i);
	}
	PutChar(’\n’);
}

#endif // CHANGED*/

int
main ()
{
    Halt ();

    /* not reached */
    return 0;
}
