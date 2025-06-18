#include <stdio.h>
#include <string.h>

int main(){
    char word[128][128], input_sentence[128], *tmp;
    int line_cnt = 0, word_cnt = 0;
    
    while(1)
    {
        gets(input_sentence);
        if( ! strcmp(input_sentence,  "end")) break;
        line_cnt++;
        tmp = strtok(input_sentence, " ");
        while(tmp != NULL)
        {
            strcpy(word[word_cnt], tmp);
            word_cnt++;
            tmp = strtok(NULL, " ");
        }
    }    

    printf("%d lines %d words\n", line_cnt, word_cnt);

    for(int i=1;i<word_cnt;i++)
    {
        int j;
        char key[128];
        strcpy(key, word[i]);

        for(j=i;j>0;j--)
        {
            if(0 < strcmp(word[j-1], key)){
                strcpy(word[j], word[j-1]);
            }
            else break;

        }
        strcpy(word[j], key);
    }

    for(int i =0; i<word_cnt; i++){
        printf("%s\n", word[i]);
    }

    printf("\n2023320136 À¯À±¼­ \n");
    return 0;   
}