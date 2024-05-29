#include<iostream>
using namespace std;

class Customer {
	string name;
	int id;
	string email;
	int phone_no;
	double balance;
	static double total_balance;
	public :
		Customer(string n, int i, string e, int p, double b) : name(n), id(i), email(e), phone_no(p), balance(b) {
			total_balance += b;
		}
		void display() {
			cout << "Name : " << name << endl;
			cout << "Id : " << id << endl;
			cout << "Email : " << email << endl;
			cout << "Phone No : " << phone_no << endl;
			cout << "Balance : " << balance << endl;
		}
		void deposit(double ammount) {
			balance += ammount;
			total_balance += ammount;
			cout << "Deposited Ammount : " << ammount << endl;
			cout << "Total Balance after Depositing : " << total_balance << endl;
		}
		void withdraw(double ammount) {
			if (balance - ammount >= 0) {
				balance -= ammount;
				total_balance -= ammount;
				cout << "Withdrew Ammount : " << ammount << endl;
				cout << "Total Balance after Withdrawing : " << total_balance << endl;
			} else {
				cout << "Insufficient balance" << endl;
			}
		}
		static void total() {
			cout << "Total Balance in bank : " << total_balance << endl;
		}
};

double Customer::total_balance = 0;

int main() {
	cout << "----------- | Welcome to E bank | ----------- " << endl;
	cout << "Select option : " << endl;
	cout << "1. Display Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Total Balance" << endl;
	cout << "5. Exit" << endl;
	int choice;
	Customer c("Rana Ali", 1, "ranaali33128@email.com", 03102222532, 10000);
	do {
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice) {
			case 1:
				c.display();
				break;
			case 2:
				double ammount;
				cout << "Enter the amount to deposit : ";
				cin >> ammount;
				c.deposit(ammount);
				break;
			case 3:
				double withdraw_ammount;
				cout << "Enter the amount to withdraw : ";
				cin >> withdraw_ammount;
				c.withdraw(withdraw_ammount);
				break;
			case 4:
				Customer::total();
				break;
			case 5:
				cout << "Thank you for banking with us!" << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 5);
	return 0;
}