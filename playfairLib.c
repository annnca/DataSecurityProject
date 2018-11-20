#include"playfairLib.h"

char key[10];
char keymatrix[5][5];
char plaintext[100];
char ciphertext[100];
char decryptedtext[100];

void decrypt(void)
{
    printf("\n ciphertxt: %s\n",ciphertext);
    printf("\n plaintext: ");
    int i, x, y, j = 1;
    for(i = 0; i < strlen(plaintext)-1;)
    {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0, p = 0, q = 0;
        x = ciphertext[i];
        y = ciphertext[j];
        if(x == 'j') ciphertext[i] = 'i';
        if(y == 'j') ciphertext[j] = 'i';
        for(p = 0; p < 5; p++)
        {
            for(q = 0; q < 5; q++)
            {
                if(keymatrix[p][q] == x)
                {
                    r1 = p;
                    c1 = q;
                }
                if(keymatrix[p][q] == y)
                {
                    r2 = p;
                    c2 = q;
                }
            }
        }
        if(r1 == r2)
        {
            decryptedtext[i] = keymatrix[r1][(c1-1)%5];
            decryptedtext[j] = keymatrix[r2][(c2-1)%5];
            printf("%c%c",decryptedtext[i],decryptedtext[j]);
        }
        else if(c1 == c2)
        {
            decryptedtext[i] = keymatrix[(r1-1)%5][c1];
            decryptedtext[j] = keymatrix[(r2-1)%5][c2];
            printf("%c%c",decryptedtext[i],decryptedtext[j]);
        }
        else
        {
            decryptedtext[i] = keymatrix[r1][c2];
            decryptedtext[j] = keymatrix[r2][c1];
            printf("%c%c",decryptedtext[i],decryptedtext[j]);
        }
        i += 2;
        j += 2;
    }

    getch();

}
void encrypt(void)
{
    printf("\n plaintext: %s\n",plaintext);
    printf("\n ciphertext: ");
    int i, x, y, j = 1;
    for(i = 0; i < strlen(plaintext)-1;)
    {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0, p = 0, q = 0;
        x = plaintext[i];
        y = plaintext[j];
        if(x == 'j') plaintext[i] = 'i';
        if(y == 'j') plaintext[j] = 'i';
        for(p = 0; p < 5; p++)
        {
            for(q = 0; q < 5; q++)
            {
                if(keymatrix[p][q] == x)
                {
                    r1 = p;
                    c1 = q;
                }
                if(keymatrix[p][q] == y)
                {
                    r2 = p;
                    c2 = q;
                }
            }
        }
        if(r1 == r2)
        {
            ciphertext[i] = keymatrix[r1][(c1+1)%5];
            ciphertext[j] = keymatrix[r2][(c2+1)%5];
            printf("%c%c",ciphertext[i],ciphertext[j]);
        }
        else if(c1 == c2)
        {
            ciphertext[i] = keymatrix[(r1+1)%5][c1];
            ciphertext[j] = keymatrix[(r2+1)%5][c2];
            printf("%c%c",ciphertext[i],ciphertext[j]);
        }
        else
        {
            ciphertext[i] = keymatrix[r1][c2];
            ciphertext[j] = keymatrix[r2][c1];
            printf("%c%c",ciphertext[i],ciphertext[j]);
        }
        i += 2;
        j += 2;
    }
    getch();
}

void keydisplay(void)
{
    int i, j, flag, row, col;

    for(i = 0; i < strlen(key); i++)
    {
        flag = 1;
        for(j = 0; j < i; j++)
        {
            if(key[i] == key[j])
                flag = 0;
        }
        if(flag == 1)
        {
            keymatrix[row][col] = key[i];
            printf(" %c",keymatrix[row][col]);
            col++;
            if(col == 5)
            {
                printf("\n");
                col = 0;
                row = row + 1;
            }
        }
    }
    for(i = 0; i < 26; i++)
    {
        flag = 1;
        for(j = 0; j < strlen(key); j++)
        {
            if(key[j] == i+97) flag=0;
        }
        if(flag == 1 && i != 9)
        {
            keymatrix[row][col] = i + 97;
            printf(" %c",keymatrix[row][col]);
            col++;
            if(col == 5)
            {
                row = row+1;
                col = 0;
                printf("\n");
            }
        }
    }
}

/*************************************************************************/
/*************************SAMPLE MAIN APP CODE****************************/
/*************************************************************************/
int display(void)
{
    printf(" [1] Enter The Text\n");
    printf(" [2] Encrypt Text\n");
    printf(" [3] Decrypt Text\n");
    printf(" [4] Exit\n");
    return 0;
}
int select(int c)
{
    int i;
    switch(c)
    {
    case 1:
    {
        int l;
        display();
        printf("Enter the Plain Text:");
        scanf("%s", plaintext);
        l = strlen(plaintext);
        printf("Enter key\n ");
        scanf("%s", key);
        for(i = 0; i < strlen(key); i++)
        {
            if(key[i] == 'j')
                key[i] = 'i';
        }
        break;
    }
    case 2:
    {
        display();
        keydisplay();
        encrypt();
        break;
    }
    case 3:
    {
        display();
        keydisplay();
        decrypt();
        break;
    }
    case 4:
        break;
    }
    return c;

}
/*************************************************************************/




