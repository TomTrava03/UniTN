// NEEDED
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long mtype;
    char mtext[100]; // PAYLOAD
} msg; 

int main(int argc, char *argv[]) {
    // QUEUEs
    // CREATE
    int id;
    char *path = "/tmp/queue";
    key_t queueKey = id;
    // OR
    queueKey = ftok(path, id);

    int queueId = msgget(queueKey, 0666 | IPC_CREAT | IPC_EXCL); // IPC_PRIVATE instead of 'key' to use in the same process group 

    // COMMUNICATION
    msg.mtype = 20;
    strcpy(msg.mtext, "MESSAGE", 0);
    int result = msgsnd(queueId, &msg, sizeof(msg.mtext), 0);

    int type = 0; // 0 -> FIRST msg of queue, > 0 : FIRST msg where type == msg.mtype, < 0
    msgrcv(queueId, &msg, sizeof(msg.mtext), type, 0);

    // MODIFICATIONs
    int command; // IPC_STAT, IPC_SET (msqid_ds *buf needed instead of NULL), IPC_RMID(remove queue), IPC_INFO(general info), MSG_INFO(~IPC_INFO), MSG_STAT(~IPC_STAT)
    msgctl(queueId, command, NULL);
    return 0;
}

