#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>
#include "aes.h"
int main(int argc, char *argv[]){
    char *input_str = "1qwertyuiop[]{}asdfghjkl;'zxcvbnm,./1234567890!@#$^&*()`";
    printf("Plain text: [%s]\n",input_str);
    char *encrypted_str = aes_128_encrypt_full(input_str);
    printf("Encrypted text: [%s]\n", encrypted_str);
    char *decrypted_str = aes_128_decrypt_full(encrypted_str);
    printf("Decrypted text: [%s]\n", decrypted_str);
}
