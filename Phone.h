#pragma once

// Telefon(numeProducator, numeModel,
//unitatiProduse, listaOperatoriGSMCompatibili)
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Phone {
protected:
	//char* producer;
	//char* model;
	//int nr;
	list <int> operators;
public:
	Phone();
	Phone(char*, char*, int, list<int>);
	Phone(const Phone&);
	Phone(string);
	//char* getProducer();
	//char* getModel();
	//int getNr();
	list <int> getOperators();
	//void setProducer(const char*);
	//void setModel(const char*);
	//void setNr(int);
	void setOperators(list<int>);
	Phone& operator=(const Phone&);
	bool operator==(const Phone&);
	~Phone();
	friend ostream& operator<<(ostream& os, Phone p);
	friend istream& operator>>(istream& is, Phone& p);

};