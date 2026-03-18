#pragma once
#include <string>
#include<cctype>
#include<conio.h>
#include<iostream>

using namespace std;

inline string encypher(string text) {
	for (int i = 0; i < text.length(); i++) {
		if (text[i] > 32 && text[i] <= 126) {
			text[i] = ((text[i] - 33 + 50) % 94) + 33;
		}
	}
	return text;
}

inline string decypher(string text) {
	for (int i = 0; i < text.length(); i++) {
		if (text[i] > 32 && text[i] <= 126) {
			text[i] = ((text[i] - 33 - 50 + 94) % 94) + 33;
		}
	}
	return text;
}

inline string getHiddenPassword() {
	string psw = "";
	char ch;

	while ((ch = _getch()) != 13) {
		if (ch == 8) {
			if (psw.length() > 0) {
				psw.pop_back();
				cout << "\b \b";
			}
		}
		else {
			psw += ch;
			cout << '*';
		}
	}
	cout << endl;
	return psw;
}