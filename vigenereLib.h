#ifndef VIGENERELIB_H_INCLUDED
#define VIGENERELIB_H_INCLUDED

char* vigenereEncrypt(char*  text, char*  key);
char*  vigenereDecrypt(char*  text, char*  key);
char*  vigenereKey(char*  text, char*  oneWordKey);

#endif // VIGENERELIB_H_INCLUDED
