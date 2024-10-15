//
// Created by alexandre on 15/10/24.
//

#include "decrypt0.h"
#include <stdio.h>
#include <stdlib.h>

void decrypt0(FILE* fp){

    int xorValue;
    u_int32_t fileChar;

    while ((fileChar = fgetc(fp)), fileChar != EOF ){

        fseek(fp,-1,1);
        if((fileChar & 2) == 0){
            xorValue = (int)((char)fileChar ^ 0xef);
        }
        else{
            xorValue = (int)((char)fileChar ^ 0xbe);
        }

        fputc(xorValue,fp);
    }
}
