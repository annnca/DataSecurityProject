#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caesarLib.h"

void criptareCuvant(int k, char word[]){
    int i;
    char temp[50];
    for(i = 0; i < strlen(word); i++){
        if(word[i] + k > 'z'){
            temp[i] = 'a' + k - ('z' - word[i]) - 1;
        }
		else
		{
            temp[i] = word[i] + k;
        }
    }
    printf("%s ", temp);
}
void decriptareCuvant(int k, char word[]){
    int i;
    char temp[50];
    for(i = 0; i < strlen(word); i++){
        if(word[i] - k < 'a' )
		{
                temp[i] = 'z' - k + ( word[i] - 'a') + 1;
        }
		else
		{
            temp[i] = word[i] - k;
        }
    }
    printf("%s ", temp);
}
void mainAppCaesarTastatura(void){
    char optiune;
    int k, n;
    char word[255][50];
	int i;

    printf("Introduceti: \n c - pentru criptare \n d - pentru decriptare .");
    scanf("%c", &optiune);
    printf("Introduceti ofsetul : ");
    scanf("%d",&k);
    printf("Introduceti nr de cuvinte :");
    scanf("%d",&n);
    printf("Introduceti mesajul: ");

    for(i = 0 ; i < n; i++)
        scanf("%s",word[i]);

    if( k  < 0 )
	{
        k = 26 + k;
    }
    if('c' == optiune)
	{
        for(i = 0 ;  i < n; i++)
		{
			criptareCuvant (k, word[i]);
		}
    }
	else
	{
		if('d' == optiune)
		{
			for(i= 0 ; i < n; i++)
			{
				decriptareCuvant (k, word[i]);
			}
		}
    }
}

void mainAppCaesarFisier(void){
    int k,n;
    char optiune;
    char word[50];
	FILE* f;

    printf("Introduceti: \n c - pentru criptare \n d - pentru decriptare .");
    scanf("%c", &optiune);
    printf("Introduceti ofsetul : ");
    scanf("%d",&k);

	f = fopen("text.in", "r");

    if( k  < 0 )
	{
        k = 26 + k;
    }

    while (!feof (f))
	{
        fscanf (f, "%s", word);
        if(optiune == 'c')
		{
			criptareCuvant (k, word);
		}
        else
		{
			if (optiune == 'd')
			{
				decriptareCuvant (k, word);
			}
		}
    }

    fclose(f);
}

