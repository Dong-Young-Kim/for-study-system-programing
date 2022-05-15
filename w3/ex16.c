#include <stdio.h>
#include <string.h>

void main() {
    char buf[256];
    char* token;
    char* tokenized[20];
    printf("enter a sentence\n");
    fgets(buf, 255, stdin);  
    buf[strlen(buf) - 1] = 0;

    token = strtok(buf, " "); // get the first token
    int i = 0;
    for (;;) {
        i++;
        //printf(" % s\n", token);
        tokenized[i - 1] = token;
        token = strtok(NULL, " "); // get the next token
        if (token == NULL) break;
        
    }

    //display tokens
    printf("There were %d words : \n", i);
    for (int j = 0; j < i; j++)
        printf("%s\n", tokenized[j]);
    printf("The original sentence was : ", i);
    for (int j = 0; j < i; j++)
        printf("%s ", tokenized[j]);

    

}

