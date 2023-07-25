#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define AES_BLOCK_SIZE 16

int encrypt_string(const char *input, const char *key, unsigned char *output, int max_output_len) {
    EVP_CIPHER_CTX *ctx;
    int len, total_len;
    unsigned char *padded_input;
    int padded_input_len;

    // Initialize OpenSSL library
    OpenSSL_add_all_algorithms();

    // Allocate memory for padded input
    padded_input_len = ((strlen(input) + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    padded_input = (unsigned char *)malloc(padded_input_len);
    if (padded_input == NULL) {
        return -1;
    }

    // Pad the input
    memset(padded_input, 0, padded_input_len);
    memcpy(padded_input, input, strlen(input));

    // Initialize cipher context
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        free(padded_input);
        return -1;
    }

    // Set cipher type and mode
    EVP_EncryptInit_ex(ctx, EVP_aes_256_ecb(), NULL, (const unsigned char *)key, NULL);

    // Perform encryption
    if (EVP_EncryptUpdate(ctx, output, &len, padded_input, padded_input_len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        free(padded_input);
        return -1;
    }
    total_len = len;

    // Finalize encryption
    if (EVP_EncryptFinal_ex(ctx, output + len, &len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        free(padded_input);
        return -1;
    }
    total_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    free(padded_input);

    return total_len;
}

