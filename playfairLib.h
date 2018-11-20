#ifndef PLAYFAIRLIB_H_INCLUDED
#define PLAYFAIRLIB_H_INCLUDED

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

char key[10];
char keymatrix[5][5];
char plaintext[100];
char ciphertext[100];
char decryptedtext[100];

void decrypt(void);
void encrypt(void);
void keydisplay(void);
int display(void);
int select(int c);
#endif // PLAYFAIRLIB_H_INCLUDED
