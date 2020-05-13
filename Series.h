#pragma once
#include <iostream>
#include <string>
#include "Utils.h"
using namespace std;

// Telefon(listaOperatoriGSMCompatibili) si Drona(numarRotoare)
//Serie(numeProducator, numeModel,unitatiProduse)

class Series{
protected:
	string producer;
	string model;
	int nr;
public:
	Series();
	Series(string p, string m, int n);
	Series(const Series&);
	Series(string linie, char delim);
	virtual ~Series();
	virtual Series* clone();
	virtual Series& operator= (const Series&);
	virtual bool operator ==(const Series&);
	//virtual bool operator <(const Series&);
	virtual string toString();
	virtual string toStringDelimiter(string delim);

	//setters and getters
	string getProducer();
	string getModel();
	int getNr();
	void setProducer(string);
	void setModel(string);
	void setNr(int);

	//friend ostream& operator<<(ostream& os, Series s);
	//friend istream& operator >>(istream& is, Series& e);

};
