#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Gen_bgo(int number[25]) {
    int i, j;
    int temp;
    int is_duplicate;
    
    for (i = 0; i < 25; i++) {
        number[i] = 0;
    }
    
    
    for (i = 0; i < 25; i++) {
        do {
            is_duplicate = 0; 
            temp = rand() % 25 + 1; 

            for (j = 0; j < i; j++) {
                if (number[j] == temp) {
                    is_duplicate = 1;
                    break;
                }
            }
        } while (is_duplicate); 
        number[i] = temp; 
    }

}

int main(){
    int my_bgo[5][5], com_bgo[5][5], make_num[25];
    int sel_num, my_open_num[25] = {0}, com_open_num[25] = {0};
    int round = 1, k, y_dup, z_dup;
    int my_bgo_cnt = 0, com_bgo_cnt = 0, dup_cnt = 0;

    srand(time(NULL));
    
    Gen_bgo(make_num);
    k = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            my_bgo[i][j] = make_num[k];
            k++;
        }
    }
    Gen_bgo(make_num);
    k = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            com_bgo[i][j] = make_num[k];
            k++;
        }
    }

    while(my_bgo_cnt < 5 && com_bgo_cnt < 5){
        printf("      나의 게임 판                   컴퓨터의 게임 판\n");
        k = 0;
        for(int i = 0; i < 5; i++){
            dup_cnt = 0;
            for(int j = 0; j < 5; j++){
                for(k = 0; k < 25; k++){
                    if(my_open_num[k] == my_bgo[i][j]) dup_cnt++;    
                }
                if(dup_cnt > 0){
                    printf("(%.2d) ", my_bgo[i][j]);
                    dup_cnt = 0;
                }
                else printf(" %.2d  ", my_bgo[i][j]);
            }
            printf("        ");
            dup_cnt = 0;
            for(int j = 0; j < 5; j++){
                for(k = 0; k < 25; k++){
                    if(com_open_num[k] == com_bgo[i][j]) dup_cnt++;
                }
                if(dup_cnt > 0){
                    printf("(%.2d) ", com_bgo[i][j]);
                    dup_cnt = 0;
                }
                else printf(" --  ", com_bgo[i][j]);
            }
            printf("\n");
        }

        printf("\n\n\n");
        if(round % 2 == 0){
            sel_num = rand() % 25 + 1;
            y_dup = 0;
            for(int x = 0; x < 25; x++){
                if(com_open_num[x] == sel_num) y_dup++;
            }
            while(y_dup > 0){
                sel_num = rand() % 25 + 1;
                y_dup = 0;
                for(int x = 0; x < 25; x++){
                if(com_open_num[x] == sel_num) y_dup++;
            }
            }
            printf("#%d. 컴퓨터의 차례입니다. %d번을 선택했습니다.\n", round, sel_num);
        }
        else{

            printf("#%d. 당신의 차례입니다. 몇 번을 열까요? ", round);
            scanf("%d", &sel_num); 
            y_dup = 0;
            for(int x = 0; x < 25; x++){
                if(com_open_num[x] == sel_num) y_dup++;
            }
            while(y_dup > 0){
                printf("#%d. 이미 나온 번호입니다 다시 입력해주세요. ", round);
                scanf("%d", &sel_num); 
                y_dup = 0;
                for(int x = 0; x < 25; x++){
                if(com_open_num[x] == sel_num) y_dup++;
            }
            }
             
        }
            my_open_num[round - 1] = sel_num;
            com_open_num[round - 1] = sel_num;
            round++;
            

            //내 빙고 체크
            for(int i = 0; i < 5; i++){
                z_dup = 0;
                for(k = 0; k < 25; k++){
                    
                    if(my_open_num[k] == my_bgo[i][0]) z_dup++;
                    if(my_open_num[k] == my_bgo[i][1]) z_dup++; 
                    if(my_open_num[k] == my_bgo[i][2]) z_dup++; 
                    if(my_open_num[k] == my_bgo[i][3]) z_dup++; 
                    if(my_open_num[k] == my_bgo[i][4]) z_dup++;  
                }
                if(z_dup == 5) my_bgo_cnt++;

                z_dup = 0;
                for(k = 0; k < 25; k++){
                    
                    if(my_open_num[k] == my_bgo[0][i]) z_dup++;
                    if(my_open_num[k] == my_bgo[1][i]) z_dup++;
                    if(my_open_num[k] == my_bgo[2][i]) z_dup++;
                    if(my_open_num[k] == my_bgo[3][i]) z_dup++;
                    if(my_open_num[k] == my_bgo[4][i]) z_dup++;
                }
                if(z_dup == 5) my_bgo_cnt++;
            }
            z_dup = 0;
            for(k = 0; k < 25; k++){

                if(my_open_num[k] == my_bgo[0][0]) z_dup++;
                if(my_open_num[k] == my_bgo[1][1]) z_dup++;
                if(my_open_num[k] == my_bgo[2][2]) z_dup++;
                if(my_open_num[k] == my_bgo[3][3]) z_dup++;
                if(my_open_num[k] == my_bgo[4][4]) z_dup++;
            }
            if(z_dup == 5) my_bgo_cnt++;
            z_dup = 0;
            for(k = 0; k < 25; k++){
                
                if(my_open_num[k] == my_bgo[4][0]) z_dup++;
                if(my_open_num[k] == my_bgo[3][1]) z_dup++;
                if(my_open_num[k] == my_bgo[2][2]) z_dup++;
                if(my_open_num[k] == my_bgo[1][3]) z_dup++;
                if(my_open_num[k] == my_bgo[0][4]) z_dup++;
            }
            if(z_dup == 5) my_bgo_cnt++;
            if(my_bgo_cnt < 5) my_bgo_cnt = 0;



            //컴퓨터 빙고 체크
            for(int i = 0; i < 5; i++){
                z_dup = 0;
                for(k = 0; k < 25; k++){
                    
                    if(com_open_num[k] == com_bgo[i][0]) z_dup++;
                    if(com_open_num[k] == com_bgo[i][1]) z_dup++; 
                    if(com_open_num[k] == com_bgo[i][2]) z_dup++; 
                    if(com_open_num[k] == com_bgo[i][3]) z_dup++; 
                    if(com_open_num[k] == com_bgo[i][4]) z_dup++;  
                }
                if(z_dup == 5) com_bgo_cnt++;
                
                z_dup = 0;
                for(k = 0; k < 25; k++){
                    
                    if(com_open_num[k] == com_bgo[0][i]) z_dup++;
                    if(com_open_num[k] == com_bgo[1][i]) z_dup++;
                    if(com_open_num[k] == com_bgo[2][i]) z_dup++;
                    if(com_open_num[k] == com_bgo[3][i]) z_dup++;
                    if(com_open_num[k] == com_bgo[4][i]) z_dup++;
                }
                if(z_dup == 5) com_bgo_cnt++;
            }
            z_dup = 0;
            for(k = 0; k < 25; k++){

                if(com_open_num[k] == com_bgo[0][0]) z_dup++;
                if(com_open_num[k] == com_bgo[1][1]) z_dup++;
                if(com_open_num[k] == com_bgo[2][2]) z_dup++;
                if(com_open_num[k] == com_bgo[3][3]) z_dup++;
                if(com_open_num[k] == com_bgo[4][4]) z_dup++;
            }
            if(z_dup == 5) com_bgo_cnt++;
            z_dup = 0;
            for(k = 0; k < 25; k++){
                
                if(com_open_num[k] == com_bgo[4][0]) z_dup++;
                if(com_open_num[k] == com_bgo[3][1]) z_dup++;
                if(com_open_num[k] == com_bgo[2][2]) z_dup++;
                if(com_open_num[k] == com_bgo[1][3]) z_dup++;
                if(com_open_num[k] == com_bgo[0][4]) z_dup++;
            }
            if(z_dup == 5) com_bgo_cnt++;
            if(com_bgo_cnt < 5) com_bgo_cnt = 0;
    }

    printf("      나의 게임 판                   컴퓨터의 게임 판\n");
        k = 0;
        for(int i = 0; i < 5; i++){
            dup_cnt = 0;
            for(int j = 0; j < 5; j++){
                for(k = 0; k < 25; k++){
                    if(my_open_num[k] == my_bgo[i][j]) dup_cnt++;
                }
                if(dup_cnt > 0){
                    printf("(%.2d) ", my_bgo[i][j]);
                    dup_cnt = 0;
                }
                else printf(" %.2d  ", my_bgo[i][j]);
            }
            printf("        ");
            dup_cnt = 0;
            for(int j = 0; j < 5; j++){
                for(k = 0; k < 25; k++){
                    if(com_open_num[k] == com_bgo[i][j]) dup_cnt++;
                }
                if(dup_cnt > 0){
                    printf("(%.2d) ", com_bgo[i][j]);
                    dup_cnt = 0;
                }
                else printf(" %.2d  ", com_bgo[i][j]);
            }
            printf("\n");
        }
    if(my_bgo_cnt >= 5 && com_bgo_cnt < 5){
        printf("당신이 이겼습니다!.\n");
    }
    else if(my_bgo_cnt < 5 && com_bgo_cnt >= 5){
        printf("컴퓨터가 이겼습니다!.\n");
    }
    else printf("동시에 빙고를 달성하여 무승부 입니다!.\n");

    printf("\n2023320136 유윤서\n");

    return 0;
}