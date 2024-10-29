#include "decrypt1.h"

void decrypt1(FILE *file)
{
  unsigned char partialDecryptedChar;
  unsigned char decryptedChar;
  int readChar;
  unsigned char key = 7;

  while (1)
  {
    readChar = fgetc(file);
    if (readChar == EOF)
      break;

    // Annuler l'ajout de key
    partialDecryptedChar = (unsigned char)(readChar - key);

    // Reconstruct decryptedChar en récupérant les bits
    decryptedChar = ((unsigned char)partialDecryptedChar >> 2) | ((unsigned char)partialDecryptedChar << 6);

    // Mettre à jour key pour la prochaine itération
    key = (readChar >> 2) | (readChar * '@');

    // Revenir à la position du dernier caractère
    fseek(file, -1, SEEK_CUR);
    // Remplacer le caractère dans le fichier
    fputc((unsigned)decryptedChar, file);
  }
}
