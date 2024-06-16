#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *name = "LuoYue";
    char *scene = "car";
    char *buffer = malloc(sizeof(char)*50);
    snprintf(buffer,strlen(name)+strlen(scene)+12,"tycat %s_%s.bmp",scene,name);
    printf("buffer = %s\n",buffer);
    
    return 0;
}