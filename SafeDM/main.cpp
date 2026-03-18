#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "login.h"
#include "register.h"
#include "dm.h"
using namespace std;

string currentUser = "";

void options() {
	if (currentUser == "") {
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
	}
	else {
		cout << "\n\tWelcome, " << currentUser << "!\n\n";
		cout << "1. Send direct messages" << endl;
		cout << "2. Logout" << endl;

	}
	cout << "0. Exit" << endl;
}
void handleOption() {
	int option;
	while (true) {
		cout << "\tWelcome to SafeDM!\nChose options by typing number." << endl;
		options();
		cin >> option;

		switch (option) {
		case 1:
			if (currentUser == "") {
				currentUser = login();
			}
			else {
				directMessages(currentUser);
			}
			break;
		case 2:
			if (currentUser == "") {
				regi();
			}
			else {
				currentUser = "";
				cout << "\nYou have been logged out.\n" << endl;
			}
			break;
		case 0:
			cout << "\nExiting the program. Goodbye!\n" << endl;
			exit(0);
			break;
		default:
			cout << "\nInvalid option. Please choose a valid option.\n" << endl;
		}
	}
}
int main() {

	handleOption();
	return 0;
}