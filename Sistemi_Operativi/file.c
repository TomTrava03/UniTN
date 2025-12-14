#include <stdio.h>

void main() {
    // FILE stream
    FILE *pFile;
    pFile = fopen("path.txt", "r+"); // r, w(overwrite), r+, w+(create and overwrite), a, a+(append and create) // create if does NOT exist
    // line of file example: Tommaso Travalia 2003 -> string string int
    char str1[10], str2[10];
    int num;
    char line[90];
    while(!feof(pFile) { // till EndOfFile, line by line with format
        int numOfVar = fscanf(pFile,"%s %s %d", str1, str2, &num); // (FILE *stream. char *format, <var1>...)
        fgets(line, 90, pFile);
    }
    fclose(pFile); // REMEMBER to close stream

    char tempChar = fgetc(pFile);
    while(tempChar != EOF){ // char by char
        tempChar = fgetc(pFile);
    }

    fprintf(pFile, "STRINGA", 7); // FILE *stream, string, len(string)
    fflush(pFile); // fflush(stdout); se bisogna scrivere molto a terminale
    
    // FILE DESCRIPTORS -fd
    int fd = open("path.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    /*
     * flags O_RDONLY, O_WRONLY, O_RDWR (uno e obbligatorio), O_CREAT, O_EXCL, O_APPEND, O_TRUNC
     * modes S_S_IRUSR, S_IWUSR, S_IXUSR, S_IRWXU, S_IRGRP, …, S_IROTH
     * */

    write(fd, "STRINGA", strlen("STRINGA"));

    int bytesRead;
    char content[10];
    do {
        bytesread = read(fd, content, strlen(content)-1);
    } while(bytesRead > 0);

    close(fd);
}

