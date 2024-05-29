#include <iostream>
#include <string>
using namespace std;

struct info {
    int age;
    int opt;
    int CNIC;
    string your_name;
    string father_name;
    string password;
    string enteredPassword;
    string new_password;
	string confirm_password;
    double balance = 0.0;
    double withdrawAmount;
    char choice;
    bool loggedIn = false;
    int attempt;
};

void displayMenu() {
    cout << "\nMAIN MENU :" << endl;
    cout << "\n01. NEW ACCOUNT ." << endl;
    cout << "\n02. LOGIN ACCOUNT ." << endl;
    cout << "\n03. DEPOSIT AMOUNT ." << endl;
    cout << "\n04. WITHDRAW AMOUNT ." << endl;
    cout << "\n05. ACCOUNT ENQUIRY ." << endl;
    cout << "\n06. CLOSE ACCOUNT ." << endl;
    cout << "\n07. EXIT ." << endl;
}

void display(info user) {
    
    do {
        displayMenu();
        cout << "\nPlease select an option from (1-7) : ";
        cin >> user.opt;
        switch (user.opt) {
            case 1:{
                cout << "\nYou want to make a new account : " << endl;
                cout << "\nEnter your age : ";
                cin >> user.age;
                if (user.age >= 18) {
                    cout << "\nYou are eligible for making an account" << endl;
                    cout << "\nEnter your name : ";
                    cin.ignore();
                    getline(cin, user.your_name);
                     cout << "\nEnter your father name : ";
                    cin.ignore();
                    getline(cin, user.father_name);
                     cout << "\nEnter your CNIC : ";
                    cin >> user.CNIC;
                } else {
                    cout << "\nYou are not eligible for making an account" << endl;
                }
                break;
            }
case 2: {
    cout << "\nYou want to log in to your account :" << endl;
    while (user.attempt < 3 && !user.loggedIn) {
        cout << "\nEnter your password : ";
        cin.ignore();
        getline(cin, user.enteredPassword); // Store entered password
        
        if (user.enteredPassword == user.password) { // Compare entered password with stored password
            cout << "\nAccount login successful." << endl;
            user.loggedIn = true;
        } else {
            cout << "\nIncorrect password entered. Please try again." << endl;
            user.attempt++;
        }
    }
    
    if (!user.loggedIn) {
        cout << "\nYou have exceeded the maximum number of attempts." << endl;
        cout << "\nWould you like to reset your password? (y/n): ";
        cin >> user.choice;
        
        if (user.choice == 'y' || user.choice == 'Y') {
            cout << "\nEnter new password : ";
            cin.ignore();
            getline(cin, user.new_password);
            cout << "\nConfirm new password : ";
            getline(cin, user.confirm_password);
            if (user.new_password == user.confirm_password) {
                user.password = user.new_password; // Update password if confirmed
                cout << "\nPassword changed successfully." << endl;
            } else {
                cout << "\nPasswords do not match. Password change failed." << endl;
            }
        }
    }
    break;
}

            case 3:{
                cout << "\nYou want to deposit amount." << endl;
                cout << "\nEnter amount to deposit: ";
                double depositAmount;
                cin >> depositAmount;
                user.balance += depositAmount;
                cout << "\nAmount deposited successfully. New balance: " << user.balance << endl;
                break;
            }
            case 4:{
                cout << "\nYou want to withdraw amount." << endl;
                cout << "\nEnter amount to withdraw: ";
                cin >> user.withdrawAmount;
                if (user.withdrawAmount <= user.balance) {
                    user.balance -= user.withdrawAmount;
                    cout << "\nAmount withdrawn successfully. New balance: " << user.balance << endl;
                } else {
                    cout << "\nInsufficient funds." << endl;
                }
                break;
            }
            case 5:{
                cout << "\nYou want your account enquiry." << endl;
                cout << "\nAccount Holder: " << user.your_name << endl;
                cout << "\nAccount Balance: " << user.balance << endl;
                break;
            }
            case 6: {
                cout << "\nYou want to close account." << endl;
                cout << "\nAccount closed successfully." << endl;
                user.balance = 0.0;
                break;
            }
            case 7:{
                cout << "\nYou want to exit." << endl;
                break;
            }
            default:
                cout << "\nInvalid option. Please select a valid option." << endl;
        }
    } while (user.opt != 7);
}

int main() {
    cout << "\t\t\t\t\t-------------------------------------" << endl;
    cout << "\t\t\t\t\tWelcome To Bank Management System" << endl;
    cout << "\t\t\t\t\t-------------------------------------" << endl;

    cout << "\n\nAccount management : " << endl;

    info user;
    cout << "\nWelcome! How can we help you?" << endl;

    display(user);

    return 0;
}
