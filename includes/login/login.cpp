#include <string>
#include <vector>
#include <iostream>
#include "login.h"
#include "./../rainbow/rainbow.h"
#include "./../Homescreen/Homescreen.h"
#include <fstream>

// function to show ascii art
void Login::displayLoginHeader()
{
	std::cout << "**********************************************************************" << std::endl;
	std::cout << "                         AUTHENTICATION MODULE                        " << std::endl;
	std::cout << "**********************************************************************" << std::endl;
}
string password = "";

// function to encode the entered password
void Login::PassKeyEncoder()
{

	char s[10] = {0};
	int i;
	for (i = 0; i < 10; i++)
	{
		s[i] = _getch();
		if (s[i] == 13)
			break;
		else
		{
			_putch('*'); //Replacing entered character wit asterisk
			password += s[i];
		}
	};
	getchar();
}

// function to render login screen
void Login::renderLoginScreen()
{

	// display login header to user
	Login::displayLoginHeader();

	// ask the user to ender cred
	string username;
	cout << "\n Enter your username : ";
	cin >> username;
	cout << "\n Enter your password : ";
	Login::PassKeyEncoder();

	// check if given user is a valid user
	if (Login::authenticateUser(username, password))
	{
		cout << "\n " << rainbow::safe("Successful Login") << endl;
		CMD_WIND obj;
		obj.MainMenu();
	}
	else
	{
		cout << "\n " << rainbow::warn("Invalid User !") << endl;
	}
}

// function to check if user is valid
bool Login::authenticateUser(string username, string password)
{
	fstream ob;
	string line;
	ob.open("Password.txt", ios::in | ios::out);
	getline(ob, line);
	if (username == "admin" && password == line)
	{
		ob.close();
		return true;
	}
	else{
		ob.close();
		return false;
	}
}
