#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_BLOCK_SIZE 16

void decrypt_string(const unsigned char *input, int length, const unsigned char *key, unsigned char *output) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 256, &aes_key);

    for (int i = 0; i < length; i += AES_BLOCK_SIZE) {
        AES_decrypt(input + i, output + i, &aes_key);
    }
}

