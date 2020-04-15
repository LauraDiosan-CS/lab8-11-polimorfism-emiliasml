#pragma once
//Drona(numeProducator, numeModel,
//unitatiProduse, numarRotoare)
#include <string>
#include <iostream>
using namespace std;

class Drone {
protected: 
	//char* producer;
	//char* model;
	//int nr;
	int nrRotors;
public:
	Drone();
	Drone(int);
	Drone(const Drone&);
	Drone(string);
	int getNrRotors();
	void setNrRotors(int);
};
