#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#include "enc.h"
#include "dec.h"


int main(void) {
    const char* __version__ = "0.0.2";

    char input[100];
    char enc_str[1024];

    printf("--- START ENCRYPTION %s ---\n\n", __version__);
    printf("1 - Encryption\n");
    printf("2 - Decryption\n\n");

    fgets(input, sizeof(input), stdin);
    int user_change = atoi(input);

    if (user_change == 1) {
        printf("String for encryption: ");
        scanf("%99s", enc_str);

        // Здесь вызывается функция для шифрования строки
        unsigned char encrypted[1024];
        int output_len = encrypt_string(enc_str, "password", encrypted, sizeof(encrypted));

        printf("Encrypted data: ");
        for (int i = 0; i < output_len; i++) {
            printf("%02x", encrypted[i]);
        }
        printf("\n");
    } 
	if (user_change == 2) {
        printf("String for decryption: ");
        fgets(enc_str, sizeof(enc_str), stdin);

		const char *encrypted_hex_string = enc_str;
		unsigned char decrypted_data[1024];
        decryption(encrypted_hex_string);
        
		printf("Decrypted data: ");
        for (int i = 0; i < sizeof(decrypted_data); i++) {
            printf("%02x", decrypted_data[i]);
        }
		printf("\n");
    }
    
    return 0;
}

