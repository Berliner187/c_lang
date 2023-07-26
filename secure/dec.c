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

void print_hex(const unsigned char *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

void decryption(const char *encrypted_hex_string) {
    const char *key = "password";
    unsigned char encrypted_data[1024];
    unsigned char decrypted[1024];
    int encrypted_length;

    int i;
    int len = strlen(encrypted_hex_string);
    for (i = 0; i < len / 2; i++) {
        sscanf(encrypted_hex_string + 2 * i, "%2hhx", &encrypted_data[i]);
    }
    encrypted_length = i;

    // Decryption logic
    decrypt_string(encrypted_data, encrypted_length, (const unsigned char *)key, decrypted);

    // Print the decrypted data.
    printf("Decrypted data: ");
    print_hex(decrypted, encrypted_length);
}

