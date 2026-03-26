#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "security.h"
#include<conio.h>

using namespace std;

struct User
{
	string nickname;
	string password;
};

void handleOption();

void putIntoFile(const User& u) {
	ofstream file("users.txt", ios::app);
	if (file.is_open()) {
		file << encypher(u.nickname) << " " << encypher(u.password) << endl;
		file.close();
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
}

inline bool isNicknameTaken(const string& nickname) {
	ifstream file("users.txt");
	if (!file.is_open()) {
		return false;
	}

	string storedNick, storedPass;
	string encryptedNick = encypher(nickname);

	while (file >> storedNick >> storedPass) {
		if (storedNick == encryptedNick) {
			file.close();
			return true;
		}
	}

	file.close();
	return false;
}

inline bool isValidPassword(const string& psw) {
	bool hasUpper = false;
	bool hasDigit = false;
	bool hasSpecial = false;
	bool hasMinLength = false;

	for (char c : psw) {
		if (isupper(c)) hasUpper = true;
		if (isdigit(c)) hasDigit = true;
		if (ispunct(c)) hasSpecial = true;
		if (psw.length() >= 8) hasMinLength = true;
	}

	return hasUpper && hasDigit && hasSpecial && hasMinLength;
}

inline void regi() {
	User u;
	string repeatPassword;
	while (true) {
		cout << "If you want to exit, type '-exit' as your nickname or password." << endl;
		cout << "Enter your nickname: " << endl;
		cin >> u.nickname;

		if (u.nickname == "-exit")return;

		if (isNicknameTaken(u.nickname)) {
			cout << "\nThat nickname is already taken! Please choose another one.\n" << endl;
		}
		else {
			break;
		}
	}

	bool isStrong = false;
	while (isStrong == false) {

		cout << "\nEnter your password (must contain at least 1 uppercase, 1 number, 1 special char and minimal 8 characters): " << endl;
		u.password = getHiddenPassword();

		if (u.password != "-exit") {

			if (isValidPassword(u.password)) {
				isStrong = true;
			}
			else {
				cout << "\nPassword is too weak.\nPlease follow the rules.";
			}
		}
		else return;
	}
	cout << "Repeat your password: " << endl;
	repeatPassword = getHiddenPassword();
	if (u.password == repeatPassword) {
		cout << "Registration successful!" << endl;
		putIntoFile(u);
		handleOption();

	}
	else {
		cout << "Passwords do not match. Registration failed." << endl;
		return;
	}

}