#include <stdio.h>
#include <string.h>
int main(){
    char word[128] = "apple", typing[128], duplicated[10][128];
    int score = 0, game = 0, dup;


    while(game < 10){
        printf("word? (%s): ", word);
        scanf("%s", typing);

        if((strlen(typing) >= 3 && strlen(typing) <= 6) && word[strlen(word) - 1] == typing[0]){
            strcpy(duplicated[game], word);
            dup = 0;
            for(int i = 0; i<=game; i++){
                if( ! strcmp(duplicated[i], typing)){
                    dup +=1;
                }
            }
            if(dup > 0){
                score = score - 1;
                if(dup > 0) printf("fail(duplicated). score: %d\n", score);
            }
            else{
            score += 1;
            printf("success(%s-%s). score: %d\n", word, typing, score);
            strcpy(word, typing);
            }
        }
        else{
            if((strlen(typing) < 3 || strlen(typing) > 6)){
                score = score - 1;
                printf("fail(out of range). score: %d\n", score); 
            }
            else{
                score = score - 1;
                printf("fail(dose not match). score: %d\n", score);
            }
              
        }
        game += 1;
    }

    printf("게임 종료 최종 스코어 : %d\n", score);

    printf("\n2023320136 유윤서 \n");
    return 0;
}