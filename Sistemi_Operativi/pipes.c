int main(int argc, char *argv[]) {
// PIPE ANONIME
    int fdPipe[2];
    pipe(fdPipe); // Create pipe, fdPipe[0] -> read, fdPipe[1] -> write
    
    char data[10];
    write(fd[1], &data, sizeof(data));

    int bytes_read = read(fd[0], &data, 10); // sizeof(data) -> a variable is better
    
    // PIPE NON BLOCCANTE
    fctnl(fd[0], F_SETFL, O_NONBLOCK);

    close(fd[0]);
    close(fd[1]);

// 2. FIFO (PIPE CON NOME)
    char *pathFifo = "/tmp/fifo";
    mkfifo(pathFifo, S_IRUSR|S_IWUSR); // mode come fd
    
    // READ
    int fd = open(pathFifo, O_RDONLY);
    bytes_read = read(fd, data, 10);
    data[bytes_read] = '/0';
    close(fd);

    // WRITE
    char *msg = "message";
    int fd = open(pathFifo, O_WRONLY);
    write(fd, msg, strlen(msg));
    close(fd);

    return 0;
}

