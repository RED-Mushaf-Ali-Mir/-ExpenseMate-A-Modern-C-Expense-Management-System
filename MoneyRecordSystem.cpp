#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#undef max

// #pragma comment(lib, "User32.lib")

using namespace std;


class Format {

    public :

      void printWithDelay(const string& text, int delay = 1000) {
        for (char c : text) {
            cout << c << flush;
            Sleep(delay);  // delay in milliseconds
        }
    }
      
      void entrance(){
      	system("cls"); 
        
        cout<< endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl;
        cout << "\033[1;31m";  // Bold Red text

        printWithDelay("\t\t\t\t\t  =========================================================\n");
        printWithDelay("\t\t\t\t\t  |Welcome", 1000);
        Sleep(630);  // Slight pause for effect
        printWithDelay(" to the FAST Hostelite Expense Management system", 20);
        printWithDelay("|\n", 50);
        printWithDelay("\t\t\t\t\t  =========================================================\n");
    
        cout << "\033[0m";  // Reset text formatting
        cout << "\n";
         
        Sleep (2000);
	  }

      void section_head (){
        
             cout << "\033[1;31m";  // Bold Red
            cout << "\t\t\t\t\t =========================================================\t\t\t\t\n";
            cout << "\t\t\t\t\t        |FAST Hostelite Expense Management system|\n";
            cout << "\t\t\t\t\t =========================================================\n";
            cout << "\n";
            cout << "\033[0m";
             cout << endl <<endl<<endl <<endl <<endl <<endl <<endl <<endl <<endl;

      }

      void section_head (int bb){
        
             cout << "\033[1;31m";  // Bold Red
            cout << "\t\t\t\t\t =========================================================\t\t\t\t\n";
            cout << "\t\t\t\t\t        |FAST Hostelite Expense Management system|\n";
            cout << "\t\t\t\t\t =========================================================\n";
            cout << "\n";
            cout << "\033[0m";
            cout << endl<< "\t\t\t\t\t\t\t\tRs : "<<bb<<endl;
            
            if (bb<0){
                string orange = "\033[33m";        // Yellow (for !!)
                string cyanBright = "\033[96m";    // Bright Cyan 
                string reset = "\033[0m";          // Reset color

    cout << "\t\t\t\t\t\t   "
         << orange << "!O!"
         << cyanBright << " Negative Balance Kindly Add Money "
         << reset;
            }

            cout<<endl <<endl <<endl <<endl <<endl <<endl <<endl;

      }

};

class Menu {

    Format fmat;
    bool mm_menu;
    bool tool;
    int num_scroll;

    public:

    int mainsc_menu (){

        system ("cls");

        num_scroll =0;

        cout << "\033[?25l"; //Cursor Disable

         mm_menu = true; 
    

         while (mm_menu) {
          
            fmat.section_head();
       

           
            cout << "\t\t\t\t\t\t      Update Expense Record  "<<endl <<endl
           << "\t\t\t\t\t\t      Transaction History  "<<endl <<endl
           << "\t\t\t\t\t\t      Login History  "<<endl <<endl
           << "\t\t\t\t\t\t      Log Out  "<<endl <<endl;

                 tool =true;

            if (num_scroll == 0){
                cout <<"\033[8A";
                cout << "\033[G"; 
                cout <<"\033[2k";
                cout <<">\033[33;44m\t\t\t\t\t\t       Update Expenese Record\033[0m";
                cout <<"\033[8B";
            } if (num_scroll == 1){
                cout <<"\033[6A";
                cout << "\033[G"; 
                cout <<"\033[2k";
                cout <<">\033[33;44m\t\t\t\t\t\t       Transaction History\033[0m";
                cout <<"\033[6B";
            } if (num_scroll == 2){
                cout <<"\033[4A";
                cout << "\033[G"; 
                cout <<"\033[2k";
                cout <<">\033[33;44m\t\t\t\t\t\t       Login History\033[0m";
                cout <<"\033[4B";
            }if (num_scroll == 3){
                cout <<"\033[2A";
                cout << "\033[G"; 
                cout <<"\033[2k";
                cout <<">\033[30;101m\t\t\t\t\t\t       Log Out\033[0m";
                cout <<"\033[2B";
            }
           
            while (tool) {
                if (_kbhit()) {
                    int ch = _getch(); // First getch
            
                    if (ch == 224) { // Special key prefix
                        ch = _getch(); // Actual key code
            
                        switch (ch) {
                            case 72: // UP arrow
                                if (num_scroll == 0) {
                                    num_scroll = 3;
                                } else {
                                    num_scroll--;
                                }
                                tool = false;
                              
                                break;
            
                            case 80: // DOWN arrow
                                if (num_scroll == 3) {
                                    num_scroll = 0;
                                } else {
                                    num_scroll++;
                                }
                                tool = false;
                               
                                break;

                            
                        }
                    }

                    else if (ch == 13){
                        tool = false;
                        mm_menu = false;
                    }

                }
            }
            
             
              system ("cls");
               

        }

        return num_scroll;

    }

    int User_Update_Money (int tot_bb){

           mm_menu = true;
           num_scroll =0;
           system ("cls");

        while (mm_menu) {
          
            fmat.section_head(tot_bb);
       
           cout << "\t\t\t\t\t\t      ADD Money To Wallet"<<endl <<endl
           << "\t\t\t\t\t\t      Drop Money From Wallet"<<endl <<endl;

                 bool tool =true;

            if (num_scroll == 0){
                cout <<"\033[4A";
                cout << "\033[G"; 
                cout <<"\033[2k";
                cout <<">\033[33;44m\t\t\t\t\t\t      ADD Money To Wallet\033[0m";
                cout <<"\033[4B";
            } if (num_scroll == 1){
                cout <<"\033[2A";
                cout << "\033[G"; 
                cout <<"\033[2k";
                cout <<">\033[33;44m\t\t\t\t\t\t      Drop Money From Wallet\033[0m";
                cout <<"\033[2B";
            }
           
            while (tool) {
                if (_kbhit()) {
                    int ch = _getch(); // First getch
            
                    if (ch == 224) { // Special key prefix
                        ch = _getch(); // Actual key code
            
                        switch (ch) {
                            case 72: // UP arrow
                                if (num_scroll == 0) {
                                    num_scroll = 1;
                                } else {
                                    num_scroll--;
                                }
                                tool = false;
                              
                                break;
            
                            case 80: // DOWN arrow
                                if (num_scroll == 1) {
                                    num_scroll = 0;
                                } else {
                                    num_scroll++;
                                }
                                tool = false;
                               
                                break;

                            
                        }
                    }

                    else if (ch == 13){
                        tool = false;
                        mm_menu = false;
                    }

                     else if (ch == 27) { // ESC key
                        tool = false;
                        mm_menu = false;
                        num_scroll = 401;  // Optional: indicate that user exited without choosing
                    }

                }
            }
            
             
              system ("cls");
               

        }
        return num_scroll;
    }
     
    
   
};


class Welcome {
public:
        
      static int logs_count;
      static string log_date;
      static string log_time;

    

    void welcome(string username) {
        
        auto now = chrono :: system_clock :: now();
        time_t now_time = chrono :: system_clock :: to_time_t(now);

        tm* local_time = localtime(&now_time);

        int day = local_time ->tm_mday;
        int month =local_time -> tm_mon + 1;
        int year = local_time ->tm_year + 1900;
        int hour = local_time ->tm_hour;
        int minute = local_time ->tm_min;
        int second = local_time ->tm_sec;

         log_date = "Day:"+to_string(day)+"/Month:"+ to_string(month)+"/Year:"+ to_string(year);

        string Wpath = "User_Information/User_Login_Record/"+ username +"_Logs.txt" ;

        fstream user_logs ( Wpath, ios :: in | ios :: out);

        if(!user_logs){
      
            ofstream create_new_file (Wpath);
            create_new_file .close ();

            user_logs.open (Wpath ,ios :: in | ios :: out | ios :: app);

            user_logs << "00000" <<endl;

        }

        user_logs >> logs_count;

        logs_count ++;

        user_logs.seekp (0 ,ios :: beg);

        user_logs <<setw(5) <<setfill('0') <<logs_count <<endl;

        user_logs . clear ();

        user_logs .seekp (0 ,ios::end);

        log_time = "Time :" + to_string(hour) +":"+ to_string(minute) +":"+ to_string(second);

        user_logs << "#" + to_string(logs_count) +". " + log_date <<endl
        <<" " + log_time<<endl;
    }
};

class system {
protected:
    // Reserved for future features
};

// Forward declaration
class Files;

class Add_Drop : protected system {
protected:
    int64_t add_money;
    int64_t drop_money;
    string drop_money_use;
    string add_money_wallet;
    Format fmat;
public:
       
    Add_Drop() {
        add_money = 0;
        drop_money = 0;
    }

    void addMoney() {
        drop_money = 0;
        fmat.section_head();

        cout << "\t\t\t\t\t\t Enter The Wallet You Want to Add Money \n";
        cout <<"\t\t\t\t\t\t";
        getline (cin, add_money_wallet);

        cout << "\t\t\t\t\t\t Enter The Amount You Want To Add \n";
        cout <<"\t\t\t\t\t\t";cin>>add_money;
        cin.ignore();
    }

    void dropMoney() {

        add_money = 0;

        fmat.section_head();

        cout << "\t\t\t\t\t\t Enter Your Expenditure Reason \n";
        cout <<"\t\t\t\t\t\t";
        cin.ignore();
        getline (cin, drop_money_use);

        cout << "\t\t\t\t\t\t Enter The Amount You Want To Drop \n";
        cout <<"\t\t\t\t\t\t";cin>>drop_money;
         
        cin.ignore();

    }

    int64_t getAddMoney() const { return add_money; }
    int64_t getDropMoney() const { return drop_money; }

    void saveToFile(Files &f);
};

class Files : protected system , public Format {
protected:
    string fileName;
    fstream Record;

public:
    Files(string name) : fileName(name) {}

    void readlogFile(){
        section_head();
        
        cout << "\033[7A";

        Record.open("User_Information/User_Login_Record/"+ fileName +"_Logs.txt");


        if (Record.is_open()){
            string logs_info;
            getline (Record,logs_info);
             while (getline(Record,logs_info)){
                cout<< logs_info <<endl;
             }

             Record.close();

             while (true) {
                if (_kbhit()){
                    int ch = _getch();

                    if (ch == 27) //ESC Key
                        break;
                    
                }
             }

        }else 
            cout << "Unable to open Login History file.\n";
    }

    void readFile() {

        section_head ();

        cout <<"\033[7A";

        Record.open("User_Information/User_Expense_Record/" + fileName +"Expense Record" + ".txt", ios::in);
        if (Record.is_open()) {
            string expense_rec;
            while (getline(Record, expense_rec)) {
                cout << expense_rec << endl;
            }
            Record.close();

         while (true) {
        if (_kbhit()) {
            int ch = _getch();

            if (ch == 27)  // ESC key
                break;
            
        }
    }

        } else {
            cout << "Unable to open transaction history file.\n";
        }
    }

    void readFile(int &number) {
        string path = "User_Information/User_Total_Expenses/" + fileName +"_Total_Expense"+".txt";
        fstream Tot_expense(path, ios::in);

        if (Tot_expense.is_open()) {
            Tot_expense >> number;
            Tot_expense.close();
        } else {
            cout << "New User Detected. Creating Initial Balance File...\n";
            number = 0;
            fstream createFile(path, ios::out);
            if (createFile.is_open()) {
                createFile << "0\n";
                createFile.close();
            }
        }
    }

    void writeFile(string text) {
        string path = "User_Information/User_Total_Expenses/" + fileName +"_Total_Expense" + ".txt";
        fstream TotalExpense(path, ios::out); // overwrite mode

        if (TotalExpense.is_open()) {
            TotalExpense << text << endl;
            TotalExpense.close();
        } else {
            cout << "Error writing balance to file.\n";
        }
    }

    void User_Files_chck (){
        fstream filecreat;

        string path = "User_Information/User_Expense_Record/" + fileName +"Expense Record"  + ".txt";
        filecreat.open(path ,ios :: app);

        filecreat <<"@" << Welcome :: logs_count<<". " <<Welcome :: log_date << endl <<endl;

        path =  "User_Information/User_Total_Expenses/" + fileName +"_Total_Expense" + ".txt";
        filecreat.open (path, ios ::app);
    }

    friend void Add_Drop::saveToFile(Files &f);
};

void Add_Drop::saveToFile(Files &f) {
    fstream myFile;
    string path = "User_Information/User_Expense_Record/" + f.fileName +"Expense Record"  + ".txt";

    myFile.open(path, ios::out | ios::app);
    if (myFile.is_open()) {
        if (add_money != 0) {
            myFile << "Added Money: " << add_money << "  ("<<add_money_wallet<<")" << "\n" ;
        }
        if (drop_money != 0) {
            myFile << "Dropped Money: " << drop_money<<"  (" <<drop_money_use<<")" << "\n";
        }
        myFile.close();
    } else {
        cout << "Error Opening critical files\n";
    }
}


class balance : protected Files {
    int64_t total_balance;

public:
    balance(string name) : Files(name) {
        // int number = 0;
        // readFile(number); // previous balance

        // total_balance = number + a1.getAddMoney() - a1.getDropMoney();
        // string text = to_string(total_balance);
        // writeFile(text); // overwrite with new balance
    }

    void  uptd_balance(Add_Drop &a1) {
        int number = 0;
        readFile(number); // previous balance

        total_balance = number + a1.getAddMoney() - a1.getDropMoney();
        string text = to_string(total_balance);
        writeFile(text); // overwrite with new balance
    }

    int display_balance() {
        // cout << "Your total balance is: " << total_balance << endl;
        return total_balance;
    }
};



       int Welcome:: logs_count = 0;
       string Welcome :: log_date ="0";
       string Welcome :: log_time = "0";

void  main_expense_system(string com_user) {

    system("cls");
    

    string username = com_user;

    Welcome w;
    w.welcome(username);

    Format fmat;

    fmat.entrance();

    Files f1(username);
    f1.User_Files_chck();

    

    Menu m1;

    bool mainn_mess=true;

    Add_Drop a1;

    balance b1 (username); 
    
    b1.uptd_balance (a1);

    int menu_choice;

    while (mainn_mess){
    menu_choice =m1.mainsc_menu();
    int case_men_choice;
    bool drop_menu_mess = true;
      

    int total_dis_balance = b1 .display_balance();

     switch (menu_choice) {

        case 0:

        while (drop_menu_mess){
        
        total_dis_balance = b1 .display_balance();   
       
        case_men_choice =  m1.User_Update_Money(total_dis_balance);

        if (case_men_choice == 401) {
            drop_menu_mess = false;
         }

        else if (case_men_choice == 0){
            a1.addMoney();
            a1.saveToFile (f1);
            b1.uptd_balance (a1); 
        }else if ( case_men_choice == 1){
              
            a1.dropMoney();
            a1.saveToFile(f1);
            b1.uptd_balance (a1); 
         }   
    }
          break;
        
        case 1:
        f1.readFile();
        system("cls");
          break;
        
        case 2:
        f1.readlogFile();
        system("cls");
          break;

        case 3:

        mainn_mess = false;
          
        break;
     } 



    }


}
