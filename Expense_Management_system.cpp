#include "rang.hpp"
#include "MoneyRecordSystem.cpp"
using namespace std;

class Login {
  public :
   string password;
   string username;

   bool login() {
    string storedPassword;
   cout << rang::fg::cyan << "\t\t\t\tUsername: " << rang::fg::reset;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // clear input buffer
    getline(cin, username);

    cout<<endl;

    cout << rang::fg::magenta << "\t\t\t\tPassword: " << rang::fg::reset;
    getline(cin, password);

    ifstream credFile("Cred/" + username + ".txt");
    if (!credFile) {
        return false;
    }

    getline(credFile, storedPassword);
    credFile.close();

    return (password == storedPassword);
}

};
void heading_display ();

class Signup {
  public :
  string password;
  string username;
  string user_count;

  void signup() {
    bool runner =true;
  while(runner){

     system ("cls");

     heading_display();

    cout<<rang::fg::cyan << "\t\t\t\t\tEnter your new Username (minimum 5 characters): "<<rang::fg::reset;
   // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, username);

    if (username.length() < 5) {
         cout << rang::style::bold << rang::fg::yellow
         << "\n\t\t\t\t\t--Short Username-- Please enter a longer username.\n"
         << rang::style::reset << rang::fg::reset;
        Sleep(2000);
        continue;
    }

    cout<<rang :: fg :: magenta << "\t\t\t\t\tEnter your new password (minimum 5 characters): "<<rang :: fg :: reset;
    getline(cin, password);

    if (password.length() < 5) {
          cout << rang::style::bold << rang::fg::yellow
         << "\n\t\t\t\t\t\t--Short Password-- Please enter a longer password.\n"
         << rang::style::reset << rang::fg::reset;
        Sleep(2000);
        continue;
    }else {
      runner = false;
    }
  }

    ofstream credFile("Cred/" + username + ".txt");
    if (!credFile) {
        cout << "\nError creating user file.\n";
        Sleep(2000);
        return;
    }

    credFile << password;
    credFile.close();

    cout << "\nUser registered successfully!\n";
    Sleep(2000);
}

};

void heading_display (){
        system("cls");
        cout << "\033[1;31m";  // Bold Red
        cout << "\t\t\t\t     =========================================================\n";
        cout << "\t\t\t\t     |Welcome to the FAST Hostelite Expense Management system|\n";
        cout << "\t\t\t\t     =========================================================\n";
        cout << "\n";
        cout << "\033[0m";
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;    
}



int main() {
  
    char select;
    bool running = true;
    Signup Obj;
    Login Obj2;

    // Check if user count file exists
    ifstream userCountFile("Users/Usercount.txt");
    if (!userCountFile) {
        cout << "\nCritical program files missing. Please create 'Users/Usercount.txt' in Users folder.\n";
        return 1;
    }
    std::getline(userCountFile, Obj.user_count);

    userCountFile.close();

    while (running) {
           
        heading_display();
        
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout << "\033[1;31m";  // Bold Red
        cout << "\t\t=========\t\t                      ==========\t\t                 ========\n";
        cout << "\t\t|1.Login|\t\t                      |2.SignUp|\t\t                 |3.Exit|\n";
        cout << "\t\t=========\t\t                      ==========\t\t                 ========\n";
        cout << "\033[0m";

        // Get menu choice without echo
        while (true) {
            if (_kbhit()) {
                select = _getch();
                if (select == '1' || select == '2' || select == '3') {
                    break;
                }
            }
        }

        switch (select) {
            case '1':
                heading_display();
                if (Obj2.login()) {
                    cout << "\nLogin Successful!\n";
                    Sleep (500);
                    main_expense_system(Obj2.username);

                } else {
                    cout << "\nLogin Failed. Incorrect username or password.\n";
                    Sleep(2000);
                }
                break;

            case '2':
            
            heading_display();
                Obj.signup();
                break;

            case '3':
                running = false;
                system ("cls");
                cout << "\n\t\t\t\t\t\t\t\033[1;31mExiting Program";
                for (int i = 0; i < 3; ++i) {
                    Sleep(600);
                    cout << ".";
                }
                cout << "\033[0m";
                cout << "\n";
                break;
        }
    }

    return 0;
}

