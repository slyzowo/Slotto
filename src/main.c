#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "terminal_colors.h"

int main(){
  long long int amount = 10'000'000;
  short int times = 1;
  short int bet = 0;
  short int risk = 0;
  short int rand_num = 0;
  int slot_symbol[] = {0, 0, 0};
  srand(time(NULL));

// -------------------------------------------------
//  Ask the player how much they would like to bet,
//  and ask how many times they would like to bet.
// -------------------------------------------------

  do{
    printf("How much would you like to bet? \n", amount);
    cprintf(155, 155, 155, "\tYou have $%lld\n", amount);
    cprintf(0, 200, 0, "$");
    scanf("%d", &bet);

    printf("How many times would you like to bet? \n");
    scanf("%d", &times);

    if(times == 0){
      printf("Congrats, how do you feel about doing that.");
    };

// -----------------------------------------------------------------
//                      Slot Symbols
//  |--------|-----------|--------------|------------|-------------|
//  | Blank  | Cherries  | Bars         | Bells      | Sevens      |
//  | No pay | Lower pay | Variable pay | Higher pay | Highest pay |
//  | x1     | x2        | x2 / x4 / x6 | x20        | x500        |
//  |--------|-----------|--------------|------------|-------------|
//
// ------------------------------------------------------------------

    for(int i = 1; i <= times; i++){
      rand_num = (rand() % 100) + 1;

      for(int j = 0; j <= 2; j++){
        slot_symbol[j] = (rand() % 7) + 1;

        switch(slot_symbol[j]){
          case 1: printf("A"); break;
          case 2: printf("B"); break;
          case 3: printf("C"); break;
          case 4: printf("D"); break;
          case 5: printf("E"); break;
          case 6: printf("F"); break;
          case 7: printf("G"); break;
        }
      }

      if(slot_symbol[0] == slot_symbol[1] && slot_symbol[1] == slot_symbol[2]){
        cprint(0, 255, 0, "\t[You win the JACKPOT! times three your money!]\n");
        amount = ((bet * 3) + amount) + 1000;
        cprintf(0, 155, 0, "\t[Balance $%d]\n\n", amount);
      }

     else if(slot_symbol[0] == slot_symbol[1] || slot_symbol[1] == slot_symbol [2]){
       cprint(255, 255, 0, "\t[So close; Try again. one point five times your  money!]\n");
       amount = (bet * 1.5) + amount;
       cprintf(155, 155, 0, "\t[Balance $%d]\n\n", amount);
     }

      else{
        cprintf(255, 0, 0, "\t[You lose. -%d]\n", bet);
        amount -= bet;
        cprintf(155, 0, 0, "\t[Balance $%d]\n\n", amount);
      }
// ----------------------------------------------
//  Mafia risk checker and incrementer

      if(rand_num < 5){
        (risk)++;
      }

      else if(risk >= 15){
        rand_num = (rand() % 100) + 1;
      }

     else if (rand_num <= 100){
       amount = 0;
       printf("You were murdered by the Mafia; Congrats on dying.");
       break;
     }

      amount -= bet;
      cprintf(155, 155, 155, "amount : %d \nrisk : %d \n", amount, risk);
  }
// ----------------------------------------------

  }while(amount > 0);

  return 0;
}