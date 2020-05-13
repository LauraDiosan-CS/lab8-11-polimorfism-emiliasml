#include <string.h>
#include <sstream>
#include "Series.h"

Series::Series() {
	this->nr = 0;
}

Series::Series(string p, string m, int n)
{
	this->producer = p;
	this->model = m;
	this->nr = n;
}

Series::Series(const Series& s){
	this->producer = s.producer;
	this->model = s.model;
	this->nr = s.nr;
}

Series::Series(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	this->producer= tokens[0];
	this->model = tokens[1];
	this->nr = stoi(tokens[2]);
}

Series::~Series()
{
	this->nr = 0;
}

Series* Series::clone()
{
	Series* newSerie = new Series();
	newSerie->setProducer(this->producer);
	newSerie->setModel(this->model);
	newSerie->setNr(this->nr);
	return newSerie;
}

Series& Series::operator=(const Series& s)
{
	if (this == &s) return *this;
	this->producer = s.producer;
	this->model = s.model;
	this->nr = s.nr;
	return *this;
}

bool Series::operator==(const Series& s)
{
	return (s.producer == this->producer) and 
		(s.model == this->model) and (s.nr == this->nr);
}

string Series::toString()
{
	return this->producer + " " + this->model + " " + to_string(this->nr);
}

string Series::toStringDelimiter(string delim)
{
	return this->producer + delim + this->model + delim + to_string(this->nr);
}

string Series::getProducer(){
	return this->producer;
}

string Series::getModel(){
	return this->model;
}

int Series::getNr(){
	return this->nr;
}

void Series::setProducer(string p){
	this->producer = p;
}

void Series::setModel(string m){
	this->model = m;
}

void Series::setNr(int n){
	this->nr = n;
}

ostream& operator<<(ostream& os, Series& s)
{
	os << s.getProducer() << " " << s.getModel() << " " << s.getNr();
	return os;	
}
