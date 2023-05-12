#include "b64.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
static char base46_map[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                     'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/', '='};
static char *jsontob64_block(char *str)
{
    char *b64_block = (char*)calloc(4,1);
    if (b64_block == NULL){
        printf("calloc failed\n");
        return NULL;
    }
    char b64[4];
    if (strlen(str) == 1)
    {
        b64[0] = ((*str) >> 2) & (~((1 << 7) | (1 << 6)));
        b64[1] = ((*str) & (1 << 0 | 1 << 1)) << 4;
        b64[2] = 64;
        b64[3] = 64;
    }
    else if (strlen(str) == 2)
    {
        b64[0] = ((*str) >> 2) & (~((1 << 7) | (1 << 6)));
        b64[1] = (((*str) & ((1 << 0) | (1 << 1))) << 4) | (((*(str + 1)) >> 4) & (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3));
        b64[2] = ((*(str + 1)) & (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3)) << 2;
        b64[3] = 64;
    }
    else
    {
        b64[0] = ((*str) >> 2) & (~((1 << 7) | (1 << 6)));
        b64[1] = (((*str) & ((1 << 0) | (1 << 1))) << 4) | (((*(str + 1)) >> 4) & (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3));
        b64[2] = ((*(str + 1)) & (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3)) << 2 | ((*(str + 2)) & (1 << 7 | 1 << 6)) >> 6;
        b64[3] = (*(str + 2)) & (~((1 << 7) | (1 << 6)));
    }
    for (int i = 0; i < 4; i++)
    {
        b64[i] = base46_map[b64[i]];
    }
    memcpy(b64_block, b64, 4);
    return b64_block;
}
char *jsontob64(char *json_str)
{
    int num_3_bytes;
    int a = strlen(json_str) / 3;
    int b = strlen(json_str) % 3;

    num_3_bytes = (!b) ? a : a + 1;
    char *str[num_3_bytes];
    for (int i = 0; i < num_3_bytes; i++)
    {
        str[i] = calloc(3,1);
        memcpy(str[i], json_str + 3 * i,3);
    }
    
    char s[num_3_bytes * 4];
    for (int i = 0; i < num_3_bytes; i++)
    {
        char *b64_block =  jsontob64_block(str[i]);
        free(str[i]);
        memcpy(&s[i * 4], b64_block, 4);
        free(b64_block);
    }
    char *b64_str = calloc(num_3_bytes * 4 + 1, sizeof(char));
    memcpy(b64_str, s, sizeof(s));
    return b64_str;
}

static char *b64tojson_block(char *b64_str)
{
    char b64[4];
    for(int i = 0; i<4; i++){
        for(int j = 0; j<65; j++){
            if(base46_map[j] == *(b64_str+i)){
                if(j == 64){
                    b64[i] = 0; 
                }
                else b64[i] = j;
                break;
            }
        }
    }
    char *json_block = calloc(3, 1);
    uint8_t json[3];
    b64_str = b64;
    json[0] = ((*b64_str) << 2) | (((*(b64_str + 1)) & (1 << 5 | 1 << 4)) >> 4);
    json[1] = (*(b64_str + 1) & (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3)) << 4 | (*(b64_str + 2) & (1 << 2 | 1 << 3 | 1 << 4 | 1 << 5)) >> 2;
    json[2] = (*(b64_str + 2) & (1 | 1 << 1)) << 6 | (*(b64_str + 3));
    strcpy(json_block, json);
    return json_block;
}
char *b64tojson(char *b64_str){
    int num4bytes;
    num4bytes = strlen(b64_str)/4;
    char *str[num4bytes];
    for(int i = 0; i<num4bytes; i++){
        str[i] = calloc(4,1);
        memcpy(str[i],b64_str + i*4,4);
    }
    char s[num4bytes * 3 + 1];
    for(int i =0; i<num4bytes; i++){
        char *json_block = b64tojson_block(str[i]);
        free(str[i]);
        memcpy(&s[i*3], json_block, 3);
        free(json_block);
    }
    s[num4bytes*3] =0;
    char *json_str = calloc(num4bytes*3+1, sizeof(char));
    strcpy(json_str, s);
    return json_str;
}