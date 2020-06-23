#ifndef LOGIN
#define LOGIN

#include <string>
#include <vector>
#include <conio.h>

using namespace std;
extern string password;
class Login
{
private:
	void displayLoginHeader();
	bool authenticateUser(string, string);

public:
	void renderLoginScreen();
	static void PassKeyEncoder();
};

#endif
