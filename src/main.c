#include<stdio.h>
#include<stdint.h>
// #include<toml-c.h>
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
    // printf("%p\n",pfile);
    FILE *poptions = NULL;
    if((poptions = fopen("example-game/options.toml","r")) == NULL){
        printf("Cannot open the option script file.\n");
        return 0;
    }
    FILE *optionscript = NULL;
    if((optionscript = fopen("options_script.toml","r")) == NULL){
        printf("Cannot open the option file.\n");
        return 0;
    }
    char *str = malloc(sizeof(char)*1024);
    char *scene = (char*)malloc(sizeof(char));
    char *role = (char*)malloc(sizeof(char));
    char *item = (char*)malloc(sizeof(char));
    char *dialogue = (char*)malloc(sizeof(char));
    char *choice = (char*)malloc(sizeof(char));
    char *option_scene = (char*)malloc(sizeof(char));
    int32_t num_of_options = 0;
    int32_t tmp_choice = 0;
    while(!feof(pfile)){
        fgets(str,128,pfile);
        sscanf(str,"[scene]: %s\n",scene);
        // printf("[scene]: %s\n",scene);
        if(strncmp(scene,"end",strlen(scene)) == 0){
            fgets(str,1024,pfile);
            sscanf(str,"[dialog]: %s\n",dialogue);
            printf("%s\n",dialogue);
            return 0;
        }
        
        // if(strncmp(scene,"bedroom",strlen(scene)) == 0){
        //     system("tycat example-game/assets/bedroom.bmp");
        // }else if(strncmp(scene,"bathroom",strlen(scene)) == 0){
        //     system("tycat example-game/assets/bathroom.bmp");
        // }

        fgets(str,128,pfile);
        sscanf(str,"[role]: %s\n",role);
        // printf("[role]: %s\n",role);
        if(strncmp(role,"LuoYue",strlen(role)) == 0){
            printf("洛玥\n");
        }else if(strncmp(role,"Aside",strlen(role)) == 0){
            printf("旁白\n");
        }else if(strncmp(role,"LuoYue(smartphone)",strlen(role)) == 0){
            printf("洛玥(手機)\n");
        }else if(strncmp(role,"smartphone_message",strlen(role)) == 0){
            printf("洛玥(手機)\n");
        }else if(strncmp(role,"LuoYue(think)",strlen(role)) == 0){
            printf("洛玥(心想)\n");
        }else if(strncmp(role,"LinZhou",strlen(role)) == 0){
            printf("林舟\n");
        }else if(strncmp(role,"System",strlen(role)) == 0){
            printf("系統\n");
        }else if(strncmp(role,"YanYuQi",strlen(role)) == 0){
            printf("言煜祁\n");
        }else if(strncmp(role,"LinZhou(message)",strlen(role)) == 0){
            printf("林舟(簡訊)\n");
        }
        // if(strncmp(role,heroine->name,strlen(role)) == 0){
        //     system("tycat example-game/assets/heroine.bmp");
        // }

        fgets(str,128,pfile);
        sscanf(str,"[item]: %s\n",item);
        // printf("[item]: %s\n",item);

        fgets(str,1024,pfile);
        sscanf(str,"[dialog]: %s\n",dialogue);
        printf("%s\n",dialogue);

        
        fgets(str,128,pfile);
        sscanf(str,"[choice]: %s\n",choice);
        // printf("choice = %s\n",choice);
        if(strncmp(choice,"none",strlen(choice)) != 0){
            sscanf(choice,"%d,%s",&num_of_options,option_scene);
            printf("\n請選擇:\n");
            // printf("幾個選項: %d\n第幾幕的第幾個選擇: %s\n",num_of_options,option_scene);
            fgets(str,128,poptions);
            for(int i = 0;i < num_of_options;i++){
                fgets(str,128,poptions);
                printf("%s",str);
            }
            scanf("%d",&tmp_choice);
            // printf("選擇了%d",tmp_choice);
            if(num_of_options > 1){
                if(str[strlen(str)-1] == '\n'){
                    str[strlen(str)-1] = '\0';
                }
                strncat(option_scene,".",2);
                if(tmp_choice == 1){
                    strncat(option_scene,"1",2);
                }else{
                    strncat(option_scene,"2",2);
                }
                printf("str = %s\n",option_scene);
                fgets(str,128,optionscript);
                if(strstr(str,option_scene) != NULL){
                    system("clear");
                    char *option_end = malloc(sizeof(char) * 100);
                    strncpy(option_end,option_scene,strlen(option_scene));
                    strncat(option_end,":end",5);
                    // printf("option scene = %s\n",option_end);
                    fgets(str,128,optionscript);
                    while(strstr(str,option_end) == NULL){
                        sscanf(str,"[scene]: %s\n",scene);
                        // printf("[scene]:%s\n",scene);

                        fgets(str,128,optionscript);
                        sscanf(str,"[role]: %s\n",role);
                        printf("%s\n",role);

                        fgets(str,128,optionscript);
                        sscanf(str,"[item]: %s\n",item);
                        // printf("[item]:%s\n",item);

                        fgets(str,1024,optionscript);
                        sscanf(str,"[dialog]: %s\n",dialogue);
                        printf("%s\n",dialogue);

                        fgets(str,128,optionscript);
                        sscanf(str,"[choice]: %s\n",choice);
                        // printf("[choice]:%s\n",choice);
                        fgets(str,128,stdin);
                        fgets(str,128,optionscript);
                        // printf("str: %s\n",str);
                        // printf("optionscene: %s\n",option_scene);
                        // printf("optionend: %s\n",option_end);
                        system("clear");
                    }
                }
            }
            flush();
        }
        fgets(str,128,stdin);
        system("clear");
    }
    if(str != NULL){
        free(str);
        str = NULL;
    }
    if(scene != NULL){
        free(scene);
        scene = NULL;
    }
    if(role != NULL){
        free(role);
        role = NULL;
    }
    if(item != NULL){
        free(item);
        item = NULL;
    }
    if(dialogue != NULL){
        free(dialogue);
        dialogue = NULL;
    }
    if(choice != NULL){
        free(choice);
        choice = NULL;
    }
    if(pfile != NULL){
        fclose(pfile);
        pfile = NULL;
    }
    if(poptions != NULL){
        fclose(poptions);
        poptions = NULL;
    }
    return 0;
}