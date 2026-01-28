#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char pt[], char key[]) {
    char ek[100];
    int i, klen = strlen(key);


strcpy(ek, key);
strncat(ek, pt, strlen(pt) - klen);

    printf("\nEncrypted Text: ");
    for(i = 0; pt[i] != '\0'; i++) {
        if(isalpha(pt[i])) {
        char c = ((toupper(pt[i]) - 'A') + (toupper(ek[i]) - 'A')) % 26 + 'A';
    printf("%c", c);
        }
    }
}

void decrypt(char ct[], char key[]) {
char ek[100];
int i, klen = strlen(key);

    strcpy(ek, key);

printf("\nDecrypted Text: ");
for(i = 0; ct[i] != '\0'; i++) {
char p = ((toupper(ct[i]) - 'A') - (toupper(ek[i]) - 'A') + 26) % 26 + 'A';
    printf("%c", p);
        ek[i + klen] = p;
    }
}

int main() {
    char pt[100], ct[100], key[100];

    printf("Enter Plain Text: ");
    gets(pt);
    printf("Enter Key: ");
    gets(key);

    encrypt(pt, key);

    printf("\n\nEnter Cipher Text: ");
    gets(ct);
printf("Enter Key: ");
    gets(key);
    decrypt(ct, key);

    return 0;
}
