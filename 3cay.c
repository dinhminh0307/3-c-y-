#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 50
#define STUSIZE 5

typedef struct {
    int card[3];
}point;

typedef struct {
    point player1;
    point player2;
}gamer;

// Get the last digit in thefinal point of player 1
int modulus_1(int sum_1) {
int mod_1;
if(sum_1 >= 10) {
    mod_1 = sum_1 % 10;
    return mod_1;
}
else if( sum_1 < 10) {
    return sum_1;
}
}

//Get the last digit in the final point of player 2
int modulus_2(int sum_2) {
int mod_2;
if(sum_2 >= 10) {
    mod_2 = sum_2 % 10;
    return mod_2;
}
else if( sum_2 < 10) {
    return sum_2;
}
}

int comparision(gamer jack) {
    int sum_1 = 0;
    int sum_2 = 0;

//Calculate the total point of 2 players
    for(int i = 0; i < 3; i ++) {
        sum_1 = sum_1 + jack.player1.card[i];
    }

    for(int i = 0; i < 3; i++) {
        sum_2 = sum_2 + jack.player2.card[i];
    }
    
    int final_sum_1 = modulus_1(sum_1);
    int final_sum_2 = modulus_2(sum_2);
    //Compare points
    if(final_sum_1 > final_sum_2) {
        return 1;
    }
    else return 0;
}
void main() {
    gamer jack;
    srand(time(NULL));

    for(int i = 0; i < 3; i++) {
       jack.player1.card[i] = rand() % 10; 
    }

    for(int i = 0; i < 3; i++) {
       jack.player2.card[i] = rand() % 10 + 1; 
    }
//Show the value of cards:
    printf("Cards value of player 1 is ");
    for(int i = 0; i < 3; i++) {
       printf("%2d", jack.player1.card[i]);
    }
    printf("\nCards value of player 2 is ");
    for(int i = 0; i < 3; i++) {
       printf("%2d", jack.player2.card[i]);
    }

    int check = comparision(jack);

    if(check) {
        printf("\nPlayer 1 win");
    }
    else printf("\nPlayer 2 win");
}