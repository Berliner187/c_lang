#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#include "enc.h"
#include "dec.h"

#define AES_BLOCK_SIZE 16

// Realization of Encryption
void encryption(const char *string_to_enc) {
    const char *key = "password";
    unsigned char output[1024];
    int output_len;

    output_len = encrypt_string(string_to_enc, key, output, sizeof(output));
    if (output_len > 0) {
        printf("Encrypted data: ");
        for (int i = 0; i < output_len; i++) {
            printf("%02x", output[i]);
        }
        printf("\n");
    } else {
        printf("Encryption failed\n");
    }
}

// Realization of Decryption
void decryption() {
	printf("0\n");	
}

int main(void) {
	char input[100];
	char enc_str[1024];
	printf("--- START ENCRYPTION 0.0.1 ---\n\n");
	
	printf("1 - Encryption\n");
	printf("2 - Decryption\n");
	
	printf("\n");	
	
	fgets(input, sizeof(input), stdin); // Считываем строку с клавиатуры
    int user_change = atoi(input); 
	
	if (user_change == 1) {
		printf("String for encryption: ");
		scanf("%99s", enc_str);

		encryption(enc_str);
	} else if (user_change == 2) {
		printf("String for decryption: ");
	}

    return 0;
}

