#include "Phone.h"
#include <sstream>

Phone::Phone() :Series() {
}

Phone::Phone(string p, string m, int n, vector<string> op) : Series(p, m, n)
{
	this->operators = op;
	//for (unsigned int i = 0; i < op.size(); i++) {
	//	this->operators.push_back(op[i]);
	//}
}

Phone::Phone(const Phone& p) : Series(p) {
	this->operators = p.operators;
	//for (unsigned int i = 0; i < p.operators.size(); i++) {
	//	this->operators.push_back(p.operators[i]);
	//}
}

Phone::~Phone()
{
}

Phone::Phone(string linie, char delim):Series(linie, delim)
{
	vector<string> split = splitLine(linie, delim);
	for (unsigned int i = 3; i < split.size(); i++) {
		this->operators.push_back(split[i]);
	}
}

Series* Phone::clone()
{
	Phone* newSerie = new Phone();
	newSerie->setProducer(this->producer);
	newSerie->setModel(this->model);
	newSerie->setNr(this->nr);
	newSerie->setOperators(this->operators);
	return newSerie;
}

vector<string> Phone::getOperators()
{
	return this->operators;
}

void Phone::setOperators(vector<string> op)
{
	this->operators = op;
	//this->operators.clear();
	//for (unsigned int i = 0; i < op.size(); i++) {
	//	this->operators.push_back(op[i]);
	//}
}

string Phone::toString()
{
	string s = this->operators[0];
	for (int i = 1; i < this->operators.size(); i++)
		s = s + "-" + this->operators[i];
	return this->producer + " " + this->model + " " + to_string(this->nr) + " " + s;
}

string Phone::toStringDelimiter(string delim)
{
	string out = this->Series::toStringDelimiter(delim);
	out.insert(0, string("Phone") + delim);
	for (unsigned int i = 0; i < this->operators.size(); i++) {
		out = out + delim + this->operators[i];
	}
	return out;
}

Phone& Phone::operator=(const Phone& p)
{
	this->Series::operator=(p);
	this->operators = p.operators;
	//this->operators.clear();
	//for (unsigned int i = 0; i < p.operators.size(); i++) {
	//	this->operators.push_back(p.operators[i]);
	//}
	return *this;
}

bool Phone::operator==(const Phone& p)
{
	return (this->Series::operator==(p)) and (this->operators == p.operators);
}

ostream& operator<<(ostream& os, Phone p)
{
	os << p.producer << " " << p.model << " " << p.nr << " ";
	for (int i = 0; i < p.operators.size(); i++)
		os << p.operators[i] << ";";
	os << endl;
	return os;
}

istream& operator>>(istream& is, Phone& p)
{
	string producer, model, o;
	int nr, nrOp;
	vector<string> op;
	is >> producer >> model >> nr >> nrOp;
	for (int i = 0; i < nrOp; i++) {
		is >> o;
		op.push_back(o);
	}
	p.setProducer(producer);
	p.setModel(model);
	p.setNr(nr);
	p.setOperators(op);
	return is;
}
