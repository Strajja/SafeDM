#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "security.h"
#include<conio.h>

using namespace std;


inline bool isLoginSuccessful(const string& nickname, const string& password) {
	ifstream file("users.txt");
	if (!file.is_open()) return false;

	string encNick = encypher(nickname);
	string encPass = encypher(password);

	string storedNickname, storedPassword;
	while (file >> storedNickname >> storedPassword) {
		if (storedNickname == encNick && storedPassword == encPass) {
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}

inline string login() {
	string nickname, password;
	bool loginSuccessful = false;

	while (!loginSuccessful) {
		cout << "If you want to exit, type '-exit' as your nickname or password." << endl;
		cout << "Enter your nickname: " << endl;
		cin >> nickname;

		if (nickname == "-exit") {
			return "";
		}

		cout << "Enter your password: " << endl;
		password = getHiddenPassword();

		if (password == "-exit") {
			return "";
		}

		if (isLoginSuccessful(nickname, password)) {
			cout << "\nLogin successful!\n" << endl;
			loginSuccessful = true;
			return nickname;
		}
		else {
			cout << "\nInvalid nickname or password. Please try again.\n" << endl;
		}
		return "";
	}
	return "";
}