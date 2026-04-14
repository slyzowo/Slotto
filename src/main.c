#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "terminal_colors.h"

int main(){
  long long amount = 500;
  int times = 1;
  int bet = 0;
  int slot_symbol[3] = {0, 0, 0};
  srand(time(NULL));

do{
    printf("How much would you like to bet? \n", amount);
    colored_printf(155, 155, 155, "\tYou have $%d\n\n$", amount);
    scanf("%d", &bet);

    printf("How many times would you like to bet? \n");
    colored_printf(155, 155, 155, "\t[ The default is 1 ] \n");
    scanf("%d", &times);
    printf("\n");

    for(int i = 1; i <= times; i++){
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

      if(amount <= 0){
        colored_print(255, 0, 0, "\t You were shot and killed by the mafia.\n");
      }

      else if(slot_symbol[0] == slot_symbol[1] && slot_symbol[1] == slot_symbol[2]){
        colored_print(0, 255, 0, "\t[You win the JACKPOT! times three your money!]\n");
        amount = ((bet * 3) + amount) + 1000;
        colored_printf(0, 155, 0, "\t[Balance $%d]\n\n", amount);
      }

      else if(slot_symbol[0] == slot_symbol[1] || slot_symbol[1] == slot_symbol[2]){
        colored_print(255, 255, 0, "\t[So close; Try again. one point five times your money!]\n");
        amount = (bet * 1.5) + amount;
        colored_printf(155, 155, 0, "\t[Balance $%d]\n\n", amount);
      }

      else{
        colored_printf(255, 0, 0, "\t[You lose. -%d]\n", bet);
        amount -= bet;
        colored_printf(155, 0, 0, "\t[Balance $%d]\n\n", amount);
      }
    }
  }while(amount > 0);

return 0;
}