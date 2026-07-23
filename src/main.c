#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

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
char option6[] = "help";
char option7[] = "exit";

enum Command{
  INVALID,
  BET,
  LOAN,
  PAY,
  DEPOSIT,
  WITHDRAWL,
  HELP,
  EXIT,
};

enum Command CommandParser(const char *user_input){
  if (strcmp(user_input, "bet") == 0){ return BET; }
  if (strcmp(user_input, "loan") == 0){ return LOAN; }
  if (strcmp(user_input, "pay") == 0){ return PAY; }
  if (strcmp(user_input, "withdrawl") == 0){ return WITHDRAWL; }
  if (strcmp(user_input, "deposit") == 0){ return DEPOSIT; }
  if (strcmp(user_input, "help") == 0){ return HELP; }
  if (strcmp(user_input, "exit") == 0){ return EXIT; }
  else{ return INVALID; }
}

int Bet(int amount, int times){
  printf("BET\n");
}

void Loan(int amount){
  printf("LOAN\n");
}

void Pay(int amount){
  printf("PAY\n");
}

void Deposit(){
  printf("DEPOSIT\n");
}

void Withdrawl(){
  printf("WITHDRAWL\n");
}

void ShowCommands(){
  printf("Commands :\n");
  printf("\t%s\n", option1);
  printf("\t%s\n", option2);
  printf("\t%s\n", option3);
  printf("\t%s\n", option4);
  printf("\t%s\n", option5);
  printf("\t%s\n", option6);
  printf("\t%s\n\n", option7);
}

void SaveGame(int user_balance, int loan_amount, short risk, bool death){
  FILE *pFile = fopen("slotto_save.txt", "w");
  fprintf(pFile, "%d\n", user_balance);
  fprintf(pFile, "%d\n", loan_amount);
  fprintf(pFile, "%d\n", risk);
  fprintf(pFile, "%d\n", death);
  fclose(pFile);
}

void ReadSaveFile(){
  char buffer[255];

  FILE *pF = fopen("slotto_save.txt", "r");

  if(pF != NULL){
    while (fgets(buffer, sizeof(buffer), pF)) {
      // Print each buffer to the standard output.
      printf("%s", buffer);
    }
  }
  else{
    printf("File Not Found!");
  }
  fclose(pF);
}

void GenerateSaveFile(){
  FILE *pF = fopen("slotto_save.txt", "w");
  fclose(pF);
}

int main(){

  int user_balance = 100;
  int bet_amount = 0;
  int loan_amount = 0;
  int bet_times = 0;
  int rand_num = 0;
  int slot_symbol[] = {0, 0, 0};
  short int risk = 0;
  bool death = false;
  char user_input[] = "";

  ShowCommands();

  while(1){
    scanf("%s", user_input);

    switch(CommandParser(user_input)){

    case INVALID:
      printf("Invalid\n");
    break;

    case BET:
      printf("Bet\n");
    break;

    case LOAN:
    printf("Loan\n");
    break;
    
    case PAY:
    printf("Pay\n");
    break;
    
    case WITHDRAWL:
    printf("Withdrawl\n");
    break;
    
    case DEPOSIT:
    printf("Deposit\n");
    break;
    
    case HELP:
    printf("Help\n");
    break;
    
    case EXIT:
    return EXIT_SUCCESS;

    default:
    break;
    }
  }
  

  return EXIT_SUCCESS;
}