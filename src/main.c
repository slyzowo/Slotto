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
char option3[] = "pay";
char option4[] = "deposit";
char option5[] = "withdrawl";
char option6[] = "exit";

enum Command{
  BET,
  LOAN,
  PAY,
  DEPOSIT,
  WITHDRAWL,
  EXIT,
};

enum Command command_parser(const char *user_input){
  if (strcmp(user_input, "bet") == 0){ return BET; }
  if (strcmp(user_input, "loan") == 0){ return LOAN; }
  if (strcmp(user_input, "pay") == 0){ return PAY; }
  if (strcmp(user_input, "withdrawl") == 0){ return WITHDRAWL; }
  if (strcmp(user_input, "deposit") == 0){ return DEPOSIT; }
  if (strcmp(user_input, "exit") == 0){ return EXIT; }
  
}

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
  printf("\t- %s\n", option6);
  printf("User Balance : $%lld\n", user_balance);
  
  while(1){
    
    scanf("%s", &user_input);
    switch(command_parser(user_input)){
      case BET:
        printf("How much would you like to bet? : $");
        scanf("%d", &bet_amount);
        printf("How many times would you like to bet? : ");
        scanf("%d", &bet_times);
        bet_amount = bet(bet_amount, bet_times);
        printf("User Balance : $%lld\n", user_balance);
      break;

      case LOAN: 
        printf("How much would you like to loan from the mafia? : $");
        scanf("%d", &loan_amount);
        loan_amount = loan(loan_amount);
        user_balance += loan_amount;
        printf("User Balance : $%lld\n", user_balance);
      break;

      case PAY: 
        // TODO: IMPLEMENT PAYING OFF THE MAFIA
      break;

      case DEPOSIT: 
        deposit();
      break;

      case WITHDRAWL: 
        withdrawl();
      break;

      case EXIT:
        return EXIT_SUCCESS; 
      break;
    
    default:
      printf("\"%s\" was not valid, please try again.\n", user_input);
      break;
    }
  }

  return EXIT_SUCCESS;
}