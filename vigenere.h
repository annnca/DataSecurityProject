#ifndef VIGENERE_H_INCLUDED
#define VIGENERE_H_INCLUDED
#include <string.h>
char* vigenereEncrypt(char*  text, char*  key);
char*  vigenereDecrypt(char*  text, char*  key);
char*  vigenereKey(char*  text, char*  oneWordKey);

#endif // VIGENERE_H_INCLUDED
