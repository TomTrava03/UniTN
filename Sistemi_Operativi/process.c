#include <unistd.h>
#include <sys/types.h>

void main() {
    pid_t pid = getpid();
    pid_t parentPid = getppid(); // using sys/types.h -> pid_t = int

    int child = fork();

    if(child == 0) {
        // CHILDREN PROCESS
    } else {
        // PARENT PROCESS
    }

    int childStatus;
    wait(&childStatus);
    while(wait(NULL) > 0); // Aspetta TUTTI i figli
    
    waitpid(-1, &childStatus, 0);
    /*
     * -n (aspetta un figlio qualsiasi nel gruppo |-n|) (prossime lezioni)
     * -1 (aspetta un figlio qualsiasi)
     *  0 (aspetta un figlio qualsiasi appartenente allo stesso gruppo)
     *  n (aspetta il figlio con PID=n)
     *options:
     *  WNOHANG: ritorna immediatamente se nessun figlio è terminato → non si resta in attesa!
     *  WUNTRACED: ritorna anche se un figlio si è interrotto senza terminare.
     *  WCONTINUED: ritorna anche se un figlio ha ripreso l’esecuzione.
     */  
    // BOTH PROCESSES
}

