#include <stdio.h>
#include <stdlib.h>

char * concatena(char *str1, char *str2){
    char *str;
    int i;
    str = malloc(sizeof(char) * (1 + (strlen(str1) + strlen(str2) ) ) );
    for (i = 0; str1[i] != '\0'; i++)
    {
        *(str + i) = *(str1 + i);
    }
    for (i = 0; str2[i] != '\0'; i++)
    {
        *(str + (i+strlen(str1)) ) = *(str2 + i);
    }
    *(str + strlen(str1) + strlen(str2) ) = '\0';
    return str;
}

int main(){
    char str1[9] = "abc";
    char str2[9] = "pcd";
    char *str = concatena(str1,str2);
    printf("\n%s",str);
    return 0;
}