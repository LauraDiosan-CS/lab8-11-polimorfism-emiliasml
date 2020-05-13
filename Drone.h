#pragma once

//Drona( numarRotoare)
#include <string>
#include <sstream>
#include <iostream>
#include "Series.h"
using namespace std;

class Drone :public Series{
private: 
	int nrRotors;
public:
	Drone() :Series() {
	}
	Drone(const char* p, const char* m, int n, int nR) : Series(p, m, n) {
		this->nrRotors = nR;
	}
	Drone(const Drone& d): Series(d){ 
		this->nrRotors = d.nrRotors;
	}
	Drone(string linie, char delim) : Series(linie, delim) {
		vector<string>tokens = splitLine(linie, delim);
		nrRotors = stoi(tokens[3]);
	}
	~Drone() {
	}
	Series* clone() {
		Drone* newSerie = new Drone();
		newSerie->setProducer(this->producer);
		newSerie->setModel(this->model);
		newSerie->setNr(this->nr);
		newSerie->setNrRotors(this->nrRotors);
		return newSerie;
	}
	Drone& operator=(const Drone& d) {
		this->Series::operator=(d);
		this->nrRotors = d.nrRotors;
		return *this;
	}

	//setter and getter
	int getNrRotors() { return this->nrRotors; }
	void setNrRotors(int nR) { this->nrRotors = nR; }

	string toString() {
		return this->producer + " " + this->model + " " + to_string(this->nr) + " " + to_string(this->nrRotors);
	}
	string toStringDelimiter(string delimiter) {
		return string("Drone") + delimiter + this->producer + delimiter + this->model + delimiter + to_string(this->nr) + delimiter + to_string(this->nrRotors);
	}

	friend ostream& operator<<(ostream& os, Drone d) {
		os << d.producer << " " << d.model << " " << d.nr << " " << d.nrRotors << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Drone& d) {
		int nr, nrR;
		string producer, model;
		is >> producer >> model >> nr >> nrR;
		d.setProducer(producer);
		d.setModel(model);
		d.setNr(nr);
		d.setNrRotors(nrR);
		return is;
	}

};
