#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vigenereLib.h"

char* vigenereEncrypt(char* text, char* key)
{
    char* cipher_text;

    for (int i = 0; i < strlen(text); i++)
    {
        int x = (text[i] + key[i]) %26 + 'A';

        cipher_text[i] = x;
    }
    return cipher_text;
}

char* vigenereDecrypt(char* text, char* key)
{
    char* orig_text;

    for (int i = 0 ; i < strlen(text); i++)
    {
        int x = (text[i] - key[i] + 26) %26 + 'A';

        orig_text[i] = x;
    }
    return orig_text;
}

/*This function multiplies the key in order to have the same length as the message*/
char* vigenereKey(char* text, char* oneWordKey)
{
    int x = strlen(oneWordKey);
    char key[50];

    int  i = 0, j=0;
    while(strlen(text) > strlen(key)){
        if (strlen(oneWordKey) == i){
            i = 0;
        }
        key[j] = oneWordKey[i];
        i++;
        j++;
    }
    key[j]= '\n';
    return key;
}
