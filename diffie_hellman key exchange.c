#include <stdio.h>
#include <math.h>


long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

#include <stdio.h>

long long power(long long base, long long exp, long long mod);

int main() {
    long long p, g;
    long long a, b;
    long long A, B;
    long long keyA, keyB;

    printf("Enter prime number p: ");
    scanf("%lld", &p);

    printf("Enter primitive root g: ");
    scanf("%lld", &g);


    printf("Enter Alice private key a: ");
    scanf("%lld", &a);

    printf("Enter Bob private key b: ");
    scanf("%lld", &b);


    A = power(g, a, p);
    B = power(g, b, p);


    keyA = power(B, a, p);
    keyB = power(A, b, p);

    printf("\nPublic values:\n");
    printf("p = %lld, g = %lld\n\n", p, g);

    printf("Private keys:\n");
    printf("Alice private key (a) = %lld\n", a);
    printf("Bob private key (b)   = %lld\n\n", b);

    printf("Public keys:\n");
    printf("Alice public key (A) = %lld\n", A);
    printf("Bob public key (B)   = %lld\n\n", B);

    printf("Shared secret keys:\n");
    printf("Alice's key = %lld\n", keyA);
    printf("Bob's key   = %lld\n", keyB);

    return 0;
}

