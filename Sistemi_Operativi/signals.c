#include <signal.h>

void custom_handler(int sigNum) {
    if(sigNum == SIGALRM) {
        printf("CUSTOM SIGNAL HANDLER"):
    }
}

void custom_handler_payload(int signo, siginfo_t *info, void *empty) {
    
}

void main() {

    // CUSTOM SIGNAL HANDLER, 2 METHODS:
    // 1. sighandler_t signal(int signum, sighandler_t handler)
    signal(SIGINT, SIG_IGN);            // Ignore 
    signal(SIGCHLD, SIG_DFL);           // Default handler
    signal(SIGALRM, custom_handler);    // Custom function
                             
    // 2. sa_sigaction
    struct sigaction sa;
    sa.sa_handler = custom_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL); // SIG, NEW_MASK, OLD_MASK

    // SENDING A SIGNAL
    int pid;
    kill(pid, SIGALRM);

    int findP;
    if(kill(findP, 0) == 0) {
        printf("The process %d is running!", findP);
    }

    // WITH A PAYLOAD
    union sigval payload; // either a pointer or int -> payload.sival_int || payload.sival_ptr
    payload.sival_int = 10;
    sigqueue(pid, SIGALRM, payload);
    
    // RECIEVE PAYLOAD
    sa.sa_sigaction = custom_handler_payload; // sa_sigaction instead of sa_handler
    sa.sa_flags = SA_SIGINFO; // Use sa_sigaction to receive payload

    // WAITING FOR A SIGNAL
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGCONT);
    sigprocmask(SIG_BLOCK, &mask, NULL); // SIG_UNBLOCK, SIG_SETMASK (&new_mask, &old_mask) 

    while(1) {
        pause();
        // OR
        sigsuspend(&mask); // or NULL 
    }
}

