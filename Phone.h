#pragma once

// Telefon(listaOperatoriGSMCompatibili)
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Series.h"
#include "Utils.h"
using namespace std;

class Phone: public Series{
private:
	vector <string> operators;
public:
	Phone();
	Phone(string p, string m, int n, vector<string> op);
	Phone(const Phone& p);
	~Phone();
	Phone(string linie, char delim);
	Series* clone();

	//setter and getter
	vector <string> getOperators();
	void setOperators(vector<string>);

	string toString();
	string toStringDelimiter(string delim);
	Phone& operator=(const Phone&);
	bool operator==(const Phone&);
	friend ostream& operator<<(ostream& os, Phone p);
	friend istream& operator>>(istream& is, Phone& p);

};