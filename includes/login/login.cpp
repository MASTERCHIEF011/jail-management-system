#include<string>
#include<vector>
#include<iostream>
#include"login.h"
#include"./../rainbow/rainbow.h"

// function to show ascii art 
void Login::displayLoginHeader(){
	std::cout << "**********************************************************************" << std::endl;
	std::cout << "                         AUTHENTICATION MODULE                        " << std::endl;
	std::cout << "**********************************************************************" << std::endl;
}

// function to render login screen
void Login::renderLoginScreen(){

	// display login header to user
	Login::displayLoginHeader();

	// ask the user to ender cred
	string username;
	string password;
	string type;

	cout << "\n Enter your username : ";
	cin >> username;
	cout << "\n Enter your password : ";
	cin >> password;
	cout << "\n Enter your accound type: ";
	cin >> type;

	// check if given user is a valid user
	if(Login::authenticateUser(username, password, type)){
		cout << "\n " << rainbow::safe("Successful Login") << endl;
	} else {
		cout << "\n " << rainbow::warn("Invalid User !") << endl;
	}
}

// function to check if user is valid
bool Login::authenticateUser(string username, string password, string type){
	if(username == "admin" && password == "admin" && type == "admin"){
		return true;
	}
	
	if(username == "harsh" && password == "john" && type == "jailer"){
		return true;
	}

	return false;
}

