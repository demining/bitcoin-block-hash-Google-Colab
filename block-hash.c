#include <stdio.h>
#include <stdint.h>

#include <openssl/sha.h>

int main(int argc, char **argv) {
    uint8_t block[80];

    if (fread(block, sizeof(block), 1, stdin) != 1) {
        fputs("Could not read block header\n", stderr);
        return 1;
    }

    SHA256_CTX ctx;
    uint8_t hash[SHA256_DIGEST_LENGTH];

    SHA256_Init(&ctx);
    SHA256_Update(&ctx, block, sizeof(block));
    SHA256_Final(hash, &ctx);

    SHA256_Init(&ctx);
    SHA256_Update(&ctx, hash, sizeof(hash));
    SHA256_Final(hash, &ctx);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%x", hash[SHA256_DIGEST_LENGTH - i - 1]);
    }
    putchar('\n');

    return 0;
}
