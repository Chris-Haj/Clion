#include "functions.h"

void cleanSpaces(char **input){
    size_t i =0,j=0;
    char *cleaned = calloc(LENGTH,sizeof(char));
    char *string = *input;
    while(string[i]==' ')
        i++;
    while(string[i] != '\0')
    {
        if(string[i] == ' ')
        {
            cleaned[j] = ' ';
            j++;
            while(string[i] == ' ')
                i++;
        }
        cleaned[j] = string[i];
        i++;
        j++;
    }
    j= strlen(cleaned)-1;
    while(cleaned[j]==' ')
        j--;
    cleaned[j+1]='\0';
    strcpy(string,cleaned);
    free(cleaned);
}

void test(){
printf("Hello man!\n");
}
