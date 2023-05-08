#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "b64.h"
#include <unistd.h>
void main()
{   
    char str[]="\"SSID\":\"HELLO\"";
    printf("Original string: %s\n", str);
    char *b64_str = jsontob64(str);
    printf("Base64 string: [%s]\n", b64_str);
    char *js_str =  b64tojson(b64_str);
    printf("Decrypted String: [%s]\n", js_str);
    free(b64_str);
    free(js_str);
    
}