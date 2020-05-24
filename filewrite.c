#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// PROJECT ACCOMPLISHED

void writer(char *filename, char *text){
    char *_filename = *(&filename);
    char *textfile = ".txt";
    strcat(*(&_filename), *(&textfile));

    char *_text = *(&text);
    
    FILE *newfile = fopen(*(&_filename), "w");

    if (newfile == NULL){
        printf("The file couldn't be opened!\n");
        fclose(newfile);
        exit(-1);
    }
    fputs(*(&_text), newfile);
    fclose(newfile);
}


int main(int argc, char **argv){
    char *name;
    char *text;

    if (argc < 3){
        printf("Not enough arguments!\n");
        exit(-1);
    }
    else if (argc == 3){
        name = argv[1];
        text = argv[2];
    }

    void (*WRITER)(char*, char*);
    WRITER = writer;

    WRITER(*(&name), *(&text));

    return 0;
}
