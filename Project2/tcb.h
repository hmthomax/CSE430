/* CSE 430 Project 1
Hailee Thomas & Sean Slamka*/

#include <ucontext.h>

//Type to store next and previous pointers and the context thread
//Type def to create TCB_t structure
typedef struct TCB_t {
	struct TCB_t     *next;
	struct TCB_t     *prev;
	ucontext_t      context;
} TCB_t;


//initializes routine
void init_TCB(TCB_t *tcb, void *function, void *stackP, int stack_size)
{
	memset(tcb, '\0', sizeof(TCB_t));       // wash, rinse
	getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
	tcb->context.uc_stack.ss_sp = stackP;
	tcb->context.uc_stack.ss_size = (size_t)stack_size;
	makecontext(&tcb->context, function, 0);// context is now cooked
}

