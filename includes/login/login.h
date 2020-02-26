#ifndef LOGIN
#define LOGIN

#include<string>
#include<vector>

using namespace std;

class Login{
	private:
		void displayLoginHeader();
		bool authenticateUser(string, string, string);
    public:
		void renderLoginScreen();
};

#endif
