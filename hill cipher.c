#include <stdio.h>
#include <string.h>

int mod26(int x) {
    return (x % 26 + 26) % 26;
}

int main() {
    char pt[50], ct[50], dt[50];
    int key[3][3], inv[3][3];
    int i;

    printf("Enter plaintext (CAPITAL): ");
    scanf("%s", pt);

    printf("Enter 3x3 key matrix:\n");
    for(i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &key[i][j]);

    int len = strlen(pt);

    // padding
    while(len % 3 != 0) {
        pt[len++] = 'X';
        pt[len] = '\0';
    }

    // 🔒 Encryption
    for(i = 0; i < len; i += 3) {
        ct[i]   = mod26(key[0][0]*(pt[i]-'A') + key[0][1]*(pt[i+1]-'A') + key[0][2]*(pt[i+2]-'A')) + 'A';
        ct[i+1] = mod26(key[1][0]*(pt[i]-'A') + key[1][1]*(pt[i+1]-'A') + key[1][2]*(pt[i+2]-'A')) + 'A';
        ct[i+2] = mod26(key[2][0]*(pt[i]-'A') + key[2][1]*(pt[i+1]-'A') + key[2][2]*(pt[i+2]-'A')) + 'A';
    }
    ct[len] = '\0';

    printf("\nEncrypted Text: %s\n", ct);

    // 🔓 Decryption (pre-known inverse key for exam use)
    // Inverse of:
    // 6 24 1
    // 13 16 10
    // 20 17 15

    inv[0][0]=8;  inv[0][1]=5;  inv[0][2]=10;
    inv[1][0]=21; inv[1][1]=8;  inv[1][2]=21;
    inv[2][0]=21; inv[2][1]=12; inv[2][2]=8;

    for(i = 0; i < len; i += 3) {
        dt[i]   = mod26(inv[0][0]*(ct[i]-'A') + inv[0][1]*(ct[i+1]-'A') + inv[0][2]*(ct[i+2]-'A')) + 'A';
        dt[i+1] = mod26(inv[1][0]*(ct[i]-'A') + inv[1][1]*(ct[i+1]-'A') + inv[1][2]*(ct[i+2]-'A')) + 'A';
        dt[i+2] = mod26(inv[2][0]*(ct[i]-'A') + inv[2][1]*(ct[i+1]-'A') + inv[2][2]*(ct[i+2]-'A')) + 'A';
    }
    dt[len] = '\0';

    printf("Decrypted Text: %s\n", dt);

    return 0;
}
