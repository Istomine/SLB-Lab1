#include <stdio.h>
#include <unistd.h> // for ftruncate

void decrypt2(FILE *file) {
    unsigned char keystream[16] = {0x07, 0xD3, 0x01, 0x00, 0x00, 0x0A, 0x6B, 0x07,
                                   0xD3, 0xBB, 0x00, 0x00, 0x0A, 0x6B, 0x15, 0xF7};
    unsigned char XORvalue;
    int currChar;
    long pos;
    unsigned int indexModifier = 0;

    fseek(file, -1, SEEK_END);

    XORvalue = fgetc(file);

    pos = ftell(file) - 2;

    while (pos >= 0) {
        fseek(file, pos, SEEK_SET);
        currChar = fgetc(file);
        XORvalue -= 4;
        currChar ^= XORvalue;
        fseek(file, pos, SEEK_SET);
        fputc(currChar, file);
        --pos;
    }

    fseek(file, 0, SEEK_SET);

    while (1) {
        currChar = fgetc(file);
        if (currChar == EOF) break;

        fseek(file, -1, SEEK_CUR);
        
        indexModifier = (indexModifier + 5) & 0xe;
        currChar += keystream[indexModifier + 1];
        fputc(currChar, file);
    }

    // remove the last byte
   ftruncate(fileno(file), ftell(file) - 1);
}
