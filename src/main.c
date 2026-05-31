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

char option1[] = "Bet";
char option2[] = "Loan";
char option3[] = "Deposit";
char option4[] = "Withdrawl";
char option5[] = "Exit";

int bet(){
  printf("BET\n");
}

void loan(){
  printf("LOAN\n");
}

void deposit(){
  printf("DEPOSIT\n");
}

void withdrawl(){
  printf("WITHDRAWL\n");
}

void death(){
  printf("DEATH\n");
}

int main(){

  long long int user_balance = 100;
  long long int bet_amount = 0;
  int bet_times = 0;
  int rand_num = 0;
  int slot_symbol[] = {0, 0, 0};
  int key = 0;
  int opt_counter = 0;
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

  while(1){

    scanf("%s", &user_input);
    
    if(strcmp(user_input, "bet") == 0){
      bet();
    }
    
    else if(strcmp(user_input, "loan") == 0){
      loan();
    }
    
    else if(strcmp(user_input, "deposit")== 0){
      deposit();
    }
    
    else if(strcmp(user_input, "withdrawl") == 0){
      withdrawl();
    }

    else if(strcmp(user_input, "exit") == 0){
      break;
    }
    
    else{
      printf("%s was not valid, try again.", user_input);
    };
  }

  return 0;
}