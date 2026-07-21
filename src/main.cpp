#include <iostream> // C++ input/output stream
#include <fstream>  // file stream
#include <cstdlib>  // C standard library
#include <string>   // C++ string libary
#include <ctime>    // C time library

using std::cout, std::cin, std::string;
using std::ofstream, std::ifstream;


class Command {
  private:
/* data */

  public:
    string parseCommand(string input){
      return input;
    }

    int bet(int amount){
      return amount;
    }

    int loan(int amount){
      return amount;
    }
    
    int deposit(int amount){
      return amount;
    }

    int withdrawl(int amount){
      return amount;
    }

    void help(){
      cout << "Commands List" << '\n';
      cout << "  bet" << '\n';
      cout << "  loan" << '\n';
      cout << "  pay" << '\n';
      cout << "  deposit" << '\n';
      cout << "  withdrawl" << '\n';
      cout << "  exit" << '\n';
    }
    

    Command(/* args */);
    ~Command();
};

Command::Command(/* args */){}
Command::~Command(){}

class SaveFile {
  private:
/* data */

  public:
    void generate(int balance, int risk, int loan_amount, bool death){
      ofstream file("slotto_save.txt");
      file << balance << '\n';
      file << risk << '\n';
      file << loan_amount << '\n';
      file << death << '\n';
      file.close();
    }

    void read(){
      string data = "";
      ifstream file("slotto_save.txt");
      if (file.is_open()){
        while (getline(file, data)){
          cout << data << '\n';
        }
      }
      else{
        cout << "SOMETHING WENT WRONG AHHHHHHHHH" << '\n';
      }
  
      
      file.close();
    }

    void write(int balance, int risk, int loan_amount, bool death){
      ofstream file("slotto_save.txt");
      file << balance << '\n';
      file << risk << '\n';
      file << loan_amount << '\n';
      file << death << '\n';
      file.close();
    }

    SaveFile(/* args */);
    ~SaveFile();
};

SaveFile::SaveFile(/* args */){}
SaveFile::~SaveFile(){}

void startup(){
  Command command;
  command.help();
}

int main(void){

  Command command;
  SaveFile savefile;

  string input = "";
  int balance = 100;
  int loan_amount = 0;
  int bet_amount = 0;
  int bet_times = 0;
  int risk = 0;
  bool death = false;

  startup();
  savefile.generate(balance, risk, loan_amount, death);
  savefile.read();

return EXIT_SUCCESS;
}