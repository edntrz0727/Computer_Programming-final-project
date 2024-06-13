#include<stdio.h>
#include<stdlib.h>

int main(){
    system("tycat example-game/assets/start_scene.bmp");
    FILE *pfile = NULL;
    if((pfile = fopen("example-game/script.toml","r")) == NULL){
        printf("Cannot open the script file.\n");
        return 0;
    }
    return 0;
}