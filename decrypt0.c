//
// Created by alexandre on 15/10/24.
//

#include "decrypt0.h"
#include <stdio.h>

void decrypt0(FILE* fp){

    int xorValue;
    int fileChar;

    while ((fileChar = fgetc(fp)) != EOF ){
        fseek(fp,-1,1);
        if(!( (fileChar^0xef) & 2)){
            xorValue = (int)((char)fileChar ^ 0xef);
        }
        else{
            xorValue = (int)((char)fileChar ^ 0xbe);
        }

        fputc(xorValue,fp);
    }
}
