#ifndef LOGIN
#define LOGIN
#include<string>

using namespace std;

class Login{
	private:
		void displayLoginHeader();
		bool authenticateUser(string, string, string);
    public:
		void renderLoginScreen();
};

#endif
