#include <stdio.h>
#include <thread.c>
#include <unistd.h>

pthread_mutex_t lock;

void * thread_func(void * param) {
    int lockResult = pthread_mutex_trylock(&lock);
    if(lockResult == 0) pthread_mutex_lock(&lock);
    // MUTEX LOCK
    pthread_mutex_locK(&lock);
    // ---

    printf("Thread: %ld, value: %d", pthread_self(), (int)param);
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL); // int state, int *oldstate
    /* PTHREAD_CANCEL_ENABLE
     * PTHREAD_CANCEL_DISABLE
     * */
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL); // int type, int *oldtype
    /* PTHREAD_CANCEL_DEFERRED (default) -> after cancellation point 
     * PTHREAD_CANCEL_ASYNCHRONOUS -> now
     * */
    
    // SIGNAL handling
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1); // BLOCK signal SIGUSR1
    pthread_sigmask(SIG_SETMASK, &set, NULL);

    // MUTEX UNLOCK
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char *argv[]) {
// --- THREADs --- //
    // CREATION
    pthread_t t_id;
    int arg = 10;
    
    pthread_create(&t_id, NULL, thread_func, (void *)arg);
    
    // PTHREAD_CANCEL_DEFERRED (default) -> after cancellation point 
    // TERMINATION
    pthread_cancel(t_id);

    // WAIT A THREAD TO FINISH
    void *retval;
    pthread_join(t_id, &retval);
    // int retval
    // pthread_join(t_id, (void **)retval);
    
    // ATTRIBUTES
    // join -> detach, NOT detach -> join
    //t releases resources INSTANTLY on termination (detach)
    pthread_attr_t attr;
    pthread_attr_init(&attr);:

    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_attr_getdetachstate(&attr, &detachSTate);// -> detach
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE); // Doesn't work!
                                                  
    pthread_attr_destroy(&attr);

    // SIGNAL handling is done for EACH thread
    sigset_t all;
    sigfillset(&all); // BLOCK EVERY SIGNAL for EVERY THREAD
    pthread_sigmask(SIG_BLOCK, &all, NULL);
    // Send SIGNAL to Thread, ONLY from the creator
    pthread_kill(t_id, SIGUSR2);

// --- MUTEX --- //
    pthread_mutex_init(&lock, NULL); // DEFAULT attrs.
    pthread_mutex_destroy(&lock);
    return 0;
}

