#pragma once
#include <string>
#include "Service.h"
using namespace std;

class UI
{
private:
	Service s;
	User u;
	int login();
	void logout();
	void add();
	void del();
	/*void find();
	void showAll();*/
public:
	UI(Service& ss) :s(ss){ }
	void showMenu();
	~UI() {}
};

