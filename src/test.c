#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a = 0;
    char *str;
    char *tmp = malloc(sizeof(char));
    fgets(str,128,stdin);
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1 ] = '\0';
    }
    sscanf(str,"%d: %s",&a,tmp);
    printf("a = %d\ntmp:%s\n",a,tmp);
    return 0;
}