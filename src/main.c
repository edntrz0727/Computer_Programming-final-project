#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

void flush(){
    char c;
    while((c = getchar()) != EOF && c != '\n');
}

typedef struct _player{
    char *name;
    char *item;
    int32_t favor;
}player;

void generate(player *role,char *name,char *item){
    role->name = name;
    role->item = item;
    role->favor = 0;
    return;
};

int main(){
    player *heroine = malloc(sizeof(player));
    player *hero = malloc(sizeof(player));
    generate(heroine,"luo","phone");
    generate(hero,"chi","none");
    // printf("[name]: %s\n[item]: %s\n[favor]: %d\n",heroine->name,heroine->item,heroine->favor);
    int start_game = 0;
    system("tycat example-game/assets/start_scene.bmp");
    printf("1.\t開始遊戲\n2.\t結束遊戲\n");
    scanf("%d",&start_game);
    if(start_game == 2){
        system("clear");
        return 0;
    }
    flush();
    system("clear");
    FILE *pfile = NULL;
    if((pfile = fopen("example-game/script.toml","r")) == NULL){
        printf("Cannot open the script file.\n");
        return 0;
    }
        char *scr_scene = (char*)malloc(sizeof(char));
        char *scr_role = (char*)malloc(sizeof(char));
        char *scr_item = (char*)malloc(sizeof(char));
        char *scene = (char*)malloc(sizeof(char));
        char *role = (char*)malloc(sizeof(char));
        char *item = (char*)malloc(sizeof(char));

        fgets(scr_scene,128,pfile);
        fgets(scr_role,128,pfile);
        fgets(scr_item,128,pfile);
        sscanf(scr_scene,"[scene]: %s\n",scene);
        sscanf(scr_role,"[role]: %s\n",role);
        sscanf(scr_item,"[item]: %s\n",item);

        free(scr_scene);
        free(scr_role);
        free(scr_item);

        if(strncmp(scene,"bedroom",strlen(scene)) == 0){
            system("tycat example-game/assets/bedroom.bmp");
        }else if(strncmp(scene,"bathroom",strlen(scene)) == 0){
            system("tycat example-game/assets/bathroom.bmp");
        }
        
        if(strncmp(role,heroine->name,strlen(role)) == 0){
            system("tycat example-game/assets/heroine.bmp");
        }
        printf("[%s]\n",role);

        char *scr_dialog = (char*)malloc(sizeof(char));
        char *dialogue = (char*)malloc(sizeof(char));
        fgets(scr_dialog,128,pfile);
        sscanf(scr_dialog,"[dialog]: %s\n",dialogue);
        // free(scr_dialog);
        printf("%s\n",dialogue);

        char *scr_choice = (char*)malloc(sizeof(char));
        char *choice = (char*)malloc(sizeof(char));
        fgets(scr_choice,128,pfile);
        sscanf(scr_choice,"[choice]: %s\n",choice);
        // printf("choice = %s\n",choice);
        if(strncmp(scr_choice,"none",strlen(choice)) == 0){
            printf("選擇選項\n");
        }
        char next_page = '0';
        scanf("%c",&next_page);
        if(next_page != ('0'-48)){
            system("clear");
        }
    fclose(pfile);
    return 0;
}