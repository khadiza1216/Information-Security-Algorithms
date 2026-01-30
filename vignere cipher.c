#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char text[], char key[]) {
    int i, j = 0;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            text[i] = (toupper(text[i]) - 'A' + (toupper(key[j]) - 'A')) % 26 + 'A';
            j = (j + 1) % strlen(key);
        }
    }
}

void decrypt(char text[], char key[]) {
    int i, j = 0;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {

            text[i] = (toupper(text[i]) - 'A' - (toupper(key[j]) - 'A') + 26) % 26 + 'A';
            j = (j + 1) % strlen(key);
        }
    }
}

int main() {
    char text[100], key[100],cipher[100];
    int choice;


    printf("Enter text: ");
    gets(text);

    printf("Enter key: ");
    gets(key);


        encrypt(text, key);
        printf("Encrypted Text: %s\n", text);

     printf("Enter Ciphertext: ");
    gets(cipher);

    printf("Enter key: ");
    gets(key);
        decrypt(cipher, key);
        printf("Decrypted Text: %s\n", cipher);


    return 0;
}
