#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

/*
  Q : why are these variables?
  A : if i change my mind on the options later, and
      it'll be easier to replace than just [ctrl] + [shift] + L.
*/

char option1[] = "bet";
char option2[] = "loan";
char option3[] = "deposit";
char option4[] = "withdrawl";
char option5[] = "exit";

int bet(int bet_amount, int bet_times){

  for (int i = 0; i < bet_times; i++){
    printf("BET\n");
  }
  
  return bet_amount;
}

int loan(int loan_amount){
  printf("You\'ve now loaned from the mafia.\n");
  printf("You now have to pay $%d back.\n", loan_amount + loan_amount);
return loan_amount;
}

void deposit(){
  printf("DEPOSIT\n");
}

void withdrawl(){
  printf("WITHDRAWL\n");
}

int main(){

  long long int user_balance = 100;
  long long int bet_amount = 0;
  int loan_amount = 0;
  int bet_times = 0;
  int rand_num = 0;
  int slot_symbol[] = {0, 0, 0};
  short int risk = 0;
  bool death = false;
  char user_input[] = "";
  srand(time(NULL));
  
  printf("Commands :\n");
  printf("\t- %s\n", option1);
  printf("\t- %s\n", option2);
  printf("\t- %s\n", option3);
  printf("\t- %s\n", option4);
  printf("\t- %s\n", option5);
  printf("User Balance : $%lld\n", user_balance);
  
  while(1){
    
    scanf("%s", &user_input);
    
    if(strcmp(user_input, option1) == 0){
      printf("How much would you like to bet? : $");
      scanf("%d", &bet_amount);
      printf("How many times would you like to bet? : ");
      scanf("%d", &bet_times);
      bet_amount = bet(bet_amount, bet_times);
      printf("User Balance : $%lld\n", user_balance);
    }
    
    else if(strcmp(user_input, option2) == 0){      
      printf("How much would you like to loan from the mafia? : $");
      scanf("%d", &loan_amount);
      loan_amount = loan(loan_amount);
      user_balance += loan_amount;
      printf("User Balance : $%lld\n", user_balance);
    }
    
    else if(strcmp(user_input, option3)== 0){
      deposit();
    }
    
    else if(strcmp(user_input, option4) == 0){
      withdrawl();
    }

    else if(strcmp(user_input, option5) == 0){
      break;
    }
    
    else{
      printf("\"%s\" was not valid, please try again.\n", user_input);
    };
  }

  return 0;
}