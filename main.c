#include <stdio.h>
#include <string.h>
#include "decrypt0.h"

int char_occurences(char* fileName, size_t fileLen, char constVal){
    int rtn = 0;

    for(size_t i = 0; i < fileLen; i++){
        if(constVal == fileName[i]){
            rtn++;
        }
    }

    return rtn;
}


int main(int argc, char* argv[]) {

    FILE* fp;

    if (argc != 2){
        fprintf(stderr, "Usage: %s <file to decrypt>\n", argv[0]);
        return -1;
    }

    fp = fopen(argv[1],"rb+");

    if (fp == NULL){
        fprintf(stderr,"Failed to open file %s\n", argv[1]);
        return -1;
    }

    int fileType = char_occurences(argv[1], strlen(argv[1]),'s');

    switch (fileType) {
        case 0 :
            decrypt0(fp);
            break;
        case 1:
            //decrypt1(fp);
            break;
        default:
            //decrypt2(fp);
    }

    fclose(fp);
    return 0;
}
