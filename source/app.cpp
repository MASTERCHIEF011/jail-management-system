/**
 * @author: Harsh Pandey
 * @desc: Entry Point of Application
 */

#include<iostream>
#include"./../includes/login/login.h"

using namespace std;

int main(){
	Login loginHandler;
	loginHandler.renderLoginScreen();

	return 0;
}