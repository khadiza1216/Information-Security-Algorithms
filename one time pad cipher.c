#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char message[], char key[], char cipher[]) {
    for(int i = 0; message[i] != '\0'; i++) {
        if(isalpha(message[i])) {
    char base = isupper(message[i]) ? 'A' : 'a';
    char k = isupper(key[i]) ? key[i]-'A' : toupper(key[i])-'A';
    cipher[i] = (message[i]-base + k) % 26 + base;
} else {
    cipher[i] = message[i];
        }
    }
    cipher[strlen(message)] = '\0';
}

void decrypt(char cipher[], char key[], char message[]) {
    for(int i = 0; cipher[i] != '\0'; i++) {
        if(isalpha(cipher[i])) {
    char base = isupper(cipher[i]) ? 'A' : 'a';
        char k = isupper(key[i]) ? key[i]-'A' : toupper(key[i])-'A';
    message[i] = (cipher[i]-base - k + 26) % 26 + base;
        } else {
            message[i] = cipher[i];
        }
    }
    message[strlen(cipher)] = '\0';
}

int main() {
    char message[200], key[200], cipher[200];

    printf("Enter message: ");
gets(message);
    message[strcspn(message, "\n")] = 0;

    printf("Enter key (same or longer length than message): ");
    gets(key);
    key[strcspn(key, "\n")] = 0;

    if(strlen(key) < strlen(message)) {
        printf("Error: Key must be at least as long as the message!\n");
        return 1;
    }

encrypt(message, key, cipher);
    printf("Encrypted Message: %s\n", cipher);

decrypt(cipher, key, message);
    printf("Decrypted Message: %s\n", message);

    return 0;
}
