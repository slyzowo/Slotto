#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <conio.h>

#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80
#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77
#define ESCAPE_KEY 27
#define ENTER_KEY 13

/*
  Q : why are these variables?
  A : if i change my mind on the options later, and
      it'll be easier to replace than just [ctrl] + [shift] + l.
*/
char option1[] = "Bet";
char option2[] = "Loan";
char option3[] = "Deposit";
char option4[] = "Withdrawl";

int opt_selector(int opt_counter){

  if (opt_counter > 3){
    opt_counter = 0;
  }

  else if (opt_counter < 0){
    opt_counter = 3;
  }

  printf("Selection Menu \nEsc to exit");

  switch (opt_counter){
    case 0:
      printf("\n\033[1;30;47m[ %s ]\033[0m", option1);
      printf("\n[ %s ]", option2);
      printf("\n[ %s ]", option3);
      printf("\n[ %s ]\n", option4);
      break;

    case 1:
      printf("\n[ %s ]", option1);
      printf("\n\033[1;30;47m[ %s ]\033[0m", option2);
      printf("\n[ %s ]", option3);
      printf("\n[ %s ]\n", option4);
      break;

    case 2:
      printf("\n[ %s ]", option1);
      printf("\n[ %s ]", option2);
      printf("\n\033[1;30;47m[ %s ]\033[0m", option3);
      printf("\n[ %s ]\n", option4);
      break;

    case 3:
      printf("\n[ %s ]", option1);
      printf("\n[ %s ]", option2);
      printf("\n[ %s ]", option3);
      printf("\n\033[1;30;47m[ %s ]\033[0m\n", option4);
      break;

    default:
  }

  return opt_counter;
}

void bet(int bet_amount, int bet_times){
  printf("How much would you like to bet?\n");
  scanf("%d", &bet_amount);
  printf("you bet $%d\n", &bet_amount);

  printf("How many times would you like to bet?\n");
  scanf("%d", &bet_times);
  printf("you bet %d many times\n", &bet_times);
}

void loan(){
  printf("LOAN");
}

void deposit(){
  printf("DEPOSIT");
}

void withdrawl(){
  printf("WITHDRAWL");
}

void death(){
  printf("DEATH");
}

int main(){
  long long int user_balance = 100;
  int bet_times = 1;
  int bet_amount = 0;
  int rand_num = 0;
  short int risk = 0;
  int slot_symbol[] = {0, 0, 0};
  bool death = false;
  srand(time(NULL));
  int key = 0;
  int opt_counter = 0;

  printf("\n\033[1;30;47m[ %s ]\033[0m", option1);
  printf("\n[ %s ]", option2);
  printf("\n[ %s ]", option3);
  printf("\n[ %s ]\n", option4);

  while (1){
// Read first byte
    key = _getch();

    if(key == ENTER_KEY){
      switch (opt_counter){
      case 0:
        bet(bet_amount, bet_times);
      break;

      case 1:
        loan();
      break;

      case 2:
        deposit();
      break;

      case 3:
        withdrawl();
      break;
        
        default:
        printf("SOMETHING WENT WRONG HELP MEEEEEEE\n");
        break;
      }
    }

// if it is the ESC key, exit the program.
    else if (key == ESCAPE_KEY){
      break;
    }

    else if (key == 224 || key == 0){ // If it's an extended key
      key = _getch();                 // Read second byte

      switch (key){
        case UP_ARROW_KEY:
        case LEFT_ARROW_KEY:
          opt_counter--;
          printf("\033[0J \033[1J \033[H");
          opt_counter = opt_selector(opt_counter);
          printf("Option Selected : %d\n", opt_counter);
        break;

        case DOWN_ARROW_KEY:
        case RIGHT_ARROW_KEY:
          opt_counter++;
          printf("\033[0J \033[1J \033[H");
          opt_counter = opt_selector(opt_counter);
          printf("Option Selected : %d\n", opt_counter);
        break;

        default:
          printf("\033[0J \033[1J \033[H");
          printf("Key is invalid : %d\n", key);
        break;
      }
    }
  }

  return 0;
}