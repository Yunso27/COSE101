#include <stdio.h>
#include <string.h>
#include <time.h>


int main() {
    char original[30][70] = {
        "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG ON THE HILL",
        "A JOURNEY OF A THOUSAND MILES BEGINS WITH A SINGLE STEP",
        "TO BE YOURSELF IN A WORLD THAT IS CONSTANTLY CHANGING",
        "HAPPINESS IS NOT SOMETHING READY MADE IT COMES FROM ACTIONS",
        "THE ONLY WAY TO DO GREAT WORK IS TO LOVE WHAT YOU DO",
        "DO NOT DWELL IN THE PAST DO NOT DREAM OF THE FUTURE",
        "THE BEST PREPARATION FOR TOMORROW IS DOING YOUR BEST TODAY",
        "LIFE IS TEN PERCENT WHAT HAPPENS AND NINETY PERCENT REACT",
        "IF YOU WANT TO LIVE A HAPPY LIFE TIE IT TO A GOAL",
        "BELIEVE YOU CAN AND YOU ARE HALFWAY THERE",
        "THE PURPOSE OF OUR LIVES IS TO BE HAPPY",
        "LIFE IS WHAT HAPPENS WHEN YOU ARE BUSY MAKING OTHER PLANS",
        "GET BUSY LIVING OR GET BUSY DYING",
        "SUCCESS IS NOT THE KEY TO HAPPINESS HAPPINESS IS THE KEY",
        "THE FUTURE BELONGS TO THOSE WHO BELIEVE IN THEIR DREAMS",
        "YOU MUST BE THE CHANGE YOU WISH TO SEE IN THE WORLD",
        "KEEP YOUR FACE ALWAYS TOWARD THE SUNSHINE AND SHADOWS",
        "YOUR TIME IS LIMITED SO DO NOT WASTE IT LIVING OTHERS LIFE",
        "IN THE END WE WILL REMEMBER NOT THE WORDS OF ENEMIES",
        "DO NOT FOLLOW WHERE THE PATH MAY LEAD GO WHERE NO PATH"
        "IT DOES NOT MATTER HOW SLOWLY YOU GO AS LONG AS YOU DO NOT STOP",
        "EVERYTHING YOU HAVE EVER WANTED IS ON THE OTHER SIDE OF FEAR",
        "BELIEVE YOU CAN AND YOU'RE HALFWAY THERE",
        "THE PUPPY CHASED ITS TAIL IN ENDLESS CIRCLES",
        "THE LIBRARY WAS QUIET WITH ONLY A FEW PEOPLE READING",
        "THE HOT AIR BALLOON ROSE STEADILY INTO THE SKY",
        "SHE PLANTED A VARIETY OF HERBS IN HER BACKYARD",
        "THE LETTER ARRIVED UNEXPECTEDLY ON A RAINY DAY",
        "THE TRAIN STATION WAS BUSTLING WITH TRAVELERS",
        "THE CHEF PREPARED A GOURMET MEAL FOR THE GUESTS"
    };

    srand(time(NULL));
    
    char input[70], k;
    int total_score = 0;
    int round_score;
    clock_t start, end;
    double time_taken;

    printf("game start\n");

    for (int i = 0; i < 5; i++) {
        printf("(%d/%d)\n", i + 1, 5);
        k = rand() % 29;
        printf("= %s\n= ", original[k]);
        
        start = clock();
        fgets(input, sizeof(input), stdin);
        end = clock();
        
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        

        int correct_chars = 0;
        int input_len = strlen(input);
        printf("  ");
        for (int j = 0; j < input_len; j++) {
            if (input[j] == original[k][j]) {
                printf(" ");
                correct_chars++;
            } else {
                printf("^");
            }
        }
        printf("\n");
        
        round_score = (int)((correct_chars / time_taken) * 60);
        total_score += round_score;
        printf("%d strokes/min\n", round_score);
    }

    printf("your score is %d\n", total_score);

    printf("\n2023320136 À¯À±¼­\n");

    return 0;
}
