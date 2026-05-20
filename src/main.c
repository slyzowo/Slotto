#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <conio.h>

// keys
#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80
#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77
#define ESCAPE_KEY 27
#define ENTER_KEY 13

// listing options easier for switches
#define OPTION_1 0
#define OPTION_2 1
#define OPTION_3 2
#define OPTION_4 3

/*
  Q : why are these variables?
  A : if i change my mind on the options later, and
      it'll be easier to replace than just [ctrl] + [shift] + L.
*/
char option1[] = "Bet";
char option2[] = "Loan";
char option3[] = "Deposit";
char option4[] = "Withdrawl";

struct Bet{
  int times;
  int amount;
};

int opt_selector(int opt_counter){

  if (opt_counter > 3){
    opt_counter = 0;
  }

  else if (opt_counter < 0){
    opt_counter = 3;
  }

  printf("Selection Menu ( Esc to exit )");

  switch (opt_counter){
    case OPTION_1:
      printf("\n\033[1;30;47m[ %s ]\033[0m", option1);
      printf("\n[ %s ]", option2);
      printf("\n[ %s ]", option3);
      printf("\n[ %s ]\n", option4);
      break;

    case OPTION_2:
      printf("\n[ %s ]", option1);
      printf("\n\033[1;30;47m[ %s ]\033[0m", option2);
      printf("\n[ %s ]", option3);
      printf("\n[ %s ]\n", option4);
      break;

    case OPTION_3:
      printf("\n[ %s ]", option1);
      printf("\n[ %s ]", option2);
      printf("\n\033[1;30;47m[ %s ]\033[0m", option3);
      printf("\n[ %s ]\n", option4);
      break;

    case OPTION_4:
      printf("\n[ %s ]", option1);
      printf("\n[ %s ]", option2);
      printf("\n[ %s ]", option3);
      printf("\n\033[1;30;47m[ %s ]\033[0m\n", option4);
      break;

    default:
  }

  return opt_counter;
}

struct Bet betting(int bet_amount, int bet_times){
  struct Bet bet;
  bet.amount = bet_amount;
  bet.times = bet_times;

  printf("How much would you like to bet?\n");
  scanf("%d", &bet_amount);

  printf("How many times would you like to bet?\n");
  scanf("%d", &bet_times);

  if(bet_times <= 0 || bet_amount <= 0){
    printf("You can\'t bet nothing.");
  }

  return bet;
}

void loaning(){
  printf("LOAN");
}

void depositing(){
  printf("DEPOSIT");
}

void withdrawling(){
  printf("WITHDRAWL");
}

void death(){
  printf("DEATH");
}

int main(){

  struct Bet Bet;
  Bet.amount = 0;
  Bet.times = 1;

  long long int user_balance = 100;
  int rand_num = 0;
  int slot_symbol[] = {0, 0, 0};
  int key = 0;
  int opt_counter = 0;
  short int risk = 0;
  bool death = false;
  srand(time(NULL));

  printf("Selection Menu ( Esc to exit )");
  printf("\n\033[1;30;47m[ %s ]\033[0m", option1);
  printf("\n[ %s ]", option2);
  printf("\n[ %s ]", option3);
  printf("\n[ %s ]\n", option4);

  while (1){
// Read first byte
    key = _getch();

    if(key == ENTER_KEY){
      switch (opt_counter){
        case OPTION_1:
          Bet = betting(Bet.amount, Bet.times);
        break;

        case OPTION_2:
          loaning();
        break;

        case OPTION_3:
          depositing();
        break;

        case OPTION_4:
          withdrawling();
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
        break;

        case DOWN_ARROW_KEY:
        case RIGHT_ARROW_KEY:
          opt_counter++;
          printf("\033[0J \033[1J \033[H");
          opt_counter = opt_selector(opt_counter);
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