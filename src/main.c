#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include "terminal_colors.h"


/*
*   1. Ask for amount to bet.
*
*   2. Ask for how many times to bet.
*
*   3. While looping through the bet times,
*      at the beginning of each bet, do Mafia¹.
*      After the Mafia¹ check, pull three randomly generated numbers,
*
*      if all three of those numbers are the exact same,
*      reward the player with : amount += bet;
*
*      if two of those numbers are the exact same,
*      reward the player with : amount += (bet * 0.5);
*
*      if none of those numbers are the exact same,
*      reward the player with : amount -= bet;
*
*   4. in the case that you die from the Mafia¹, or
*      that you run to or below zero dollars,
*      game over.
*
*   
*   Mafia : 
*        Each time the player bets,
*        the player has a 10% chance to increase the risk meter
*        if the risk counter goes over [15], you have a chance to die.
*   
*/


int main(){
  long long int user_balance = 100;
  short int bet_times = 1;
  short int bet_amount = 0;
  short int risk = 0;
  short int rand_num = 0;
  int slot_symbol[] = {0, 0, 0};
  srand(time(NULL));

  printf("how much would you like to bet?");
  scanf("%d", &bet_amount);
  
  printf("how many times would you like to bet?");
  scanf("%d", &bet_times);
  
  return 0;
}