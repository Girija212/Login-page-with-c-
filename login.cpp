#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void regd();
void forget();
void exitProgram();

int main() {
    int c;
    cout << "________________________________________________\n";
    cout << "               Welcome to the page\n";
    cout << "                       Menu\n";
    cout << "\t Press 1 to Login        :\n" << endl;
    cout << "\t Press 2 to Registration :\n" << endl;
    cout << "\t Press 3 to Forget       :\n" << endl;
    cout << "\t Press 4 to Exit         :\n" << endl;
    cin >> c;
    switch (c) {
        case 1:
            login();
            break;
        case 2:
            regd();
            break;
        case 3:
            forget();
            break;
        case 4:
            exitProgram();
            break;
        default:
            system("cls");
            cout << "Invalid option";
            main();
    }
    return 0;
}

void login() {
    int count = 0;
    string userID, password, id, pass;
    system("cls");
    cout << "Enter the username and password:" << endl;
    cout << "Username: ";
    cin >> userID;
    cout << "Password: ";
    cin >> password;
    ifstream input("records.txt");
    while (input >> id >> pass) {
        if (id == userID && pass == password) {
            count = 1;
            system("cls");
            break;
        }
    }
    input.close();
    if (count == 1) {
        cout << userID << "\nYou have logged in successfully\n";
        main();
    } else {
        cout << "\nLogin Error\nPlease check your username and password\n";
        main();
    }
}

void regd() {
    string ruserId, rPassword;
    system("cls");
    cout << "\nEnter the username: ";
    cin >> ruserId;
    cout << "\nEnter the password: ";
    cin >> rPassword;
    ofstream f1("records.txt", ios::app);
    f1 << ruserId << " " << rPassword << endl;
    system("cls");
    cout << "\nRegistration is successful\n";
    main();
}

void forget() {
    int option;
    system("cls");
    cout << "\nForgot your password? No worries\n";
    cout << "Press 1 to search your ID by username:\n";
    cout << "Press 2 to go to the main menu:\n";
    cout << "\t\t\tEnter your choice: ";
    cin >> option;
    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sid, spass;
            cout << "Enter the username: ";
            cin >> suserId;
            ifstream f2("records.txt");
            while (f2 >> sid >> spass) {
                if (sid == suserId) {
                    count = 1;
                    break;
                }
            }
            f2.close();
            if (count == 1) {
                cout << "\n\nYour account is found!";
                cout << "\n\n\nYour password is: " << spass;
                main();
            } else {
                cout << "Sorry! Account not found\n\n";
                main();
            }
            break;
        }
        case 2:
            main();
            break;
        default:
            cout << "\t\t\tWrong choice! Try again" << endl;
            forget();
    }
}

void exitProgram() {
    exit(0);
}

