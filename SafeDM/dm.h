#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "security.h"
#include <thread>
#include <chrono>
#include <atomic>

atomic<bool>isChatting(true);

using namespace std;

void refreshScreen(string fileName, string targetUser) {
	int lastLineCount = 0;

	while (isChatting) {
		ifstream chatIn(fileName);
		vector<string> currentLines;
		if (chatIn.is_open()) {
			string line;
			while (getline(chatIn, line)) {
				currentLines.push_back(line);
			}
			chatIn.close();
		}

		if (currentLines.size() > lastLineCount) {
			system("cls");
			cout << "\nChat History with " << targetUser << ":" << endl;

			for (const string& l : currentLines) {
				cout << decypher(l) << endl;
			}

			cout << "\nEnter message (or type '-exit' to go back): " << endl;

			lastLineCount = currentLines.size();
		}

		this_thread::sleep_for(chrono::milliseconds(500));
	}
}

inline void directMessages(const string& currentUser) {
	cout << "\tYou chose to send direct messages.\n" << endl;
	ifstream file("users.txt");
	if (!file.is_open()) {
		cout << "\nError: Cannot open.\n" << endl;
		return;
	}

	vector<string> users;
	string storedNick, storedPass;

	while (file >> storedNick >> storedPass) {
		string normalNick = decypher(storedNick);
		if (normalNick != currentUser) {

			users.push_back(normalNick);
		}


	}
	file.close();

	if (users.empty()) {
		cout << "No other users available to send messages to." << endl;
		return;
	}

	cout << "Chose the user you want to send a message to: " << endl;
	for (size_t i = 0; i < users.size(); ++i) {
		cout << i + 1 << ". " << users[i] << endl;
	}
	cout << "0. Back to options" << endl;

	int choice;
	cout << "\nEnter your choice: ";

	if (!(cin >> choice)) {
		cout << "\nInvalid input! Please enter a number.\n" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		return;
	}

	if (choice == 0) {
		return;
	}

	if (choice < 1 || choice > users.size()) {
		cout << "\nInvalid choice. Returning to options.\n" << endl;
		return;
	}

	string targetUser = users[choice - 1];
	string u1 = currentUser;
	string u2 = targetUser;
	if (u1 > u2) swap(u1, u2);
	string chatFileName = "chat_" + u1 + "_" + u2 + ".txt";

	isChatting = true;
	thread refreshThread(refreshScreen, chatFileName, targetUser);

	while (true) {
		string message;
		cin >> ws;
		getline(cin, message);

		if (message == "-exit") {
			cout << targetUser << " left the chat.\n" << endl;
			isChatting = false;
			refreshThread.join();
			break;
		}

		ofstream chatOut(chatFileName, ios::app);
		if (chatOut.is_open()) {
			string fullLine = currentUser + ": " + message;
			chatOut << encypher(fullLine) << endl;
			chatOut.close();
		}
		else {
			cout << "\nUnable to open chat file for writing.\n" << endl;
			break;
		}
	}
}