#pragma once
#include <string>
using namespace std;

class User
{
private:
	string userName;
	string password;
public:
	User() {}
	User(string u, string p) {
		this->userName = u;
		this->password = p;
	}
	bool operator==(const User& u);
	void setUserName(string u) { this->userName = u; }
	void setPassword(string p) { this->password = p; }
	string getUserName() { return this->userName; }
	string getPassword() { return this->password; }
	~User() {}
};

