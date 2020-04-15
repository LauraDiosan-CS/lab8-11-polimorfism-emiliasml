#include "Phone.h"

Phone::Phone()
{
	//producer = NULL;
	//model = NULL;
}

Phone::Phone(char* p, char* m, int nr, list<int> op)
{
	//this->producer = new char[strlen(p) + 1];
	//strcpy_s(this->producer, strlen(p) + 1, p);
	//this->model = new char[strlen(m) + 1];
	//strcpy_s(this->model, strlen(m) + 1, m);
	//this->nr = nr;
	this->operators = op;

}

Phone::Phone(const Phone& ph)
{
	//this->producer = new char[strlen(ph.producer) + 1];
	//strcpy_s(this->producer, strlen(ph.producer) + 1, ph.producer);
	//this->model = new char[strlen(ph.model) + 1];
	//strcpy_s(this->model, strlen(ph.model) + 1, ph.model);
	//this->nr = ph.nr;
	this->operators = ph.operators;
}

//char* Phone::getProducer()
//{
//	return producer;
//}
//
//char* Phone::getModel()
//{
//	return model;
//}
//
//int Phone::getNr()
//{
//	return nr;
//}

list<int> Phone::getOperators()
{
	return operators;
}

//void Phone::setProducer(const char* pr)
//{
//	if (producer) delete[] producer;
//	producer = new char[strlen(pr) + 1];
//	strcpy_s(producer, strlen(pr) + 1, pr);
//}
//
//void Phone::setModel(const char* m)
//{
//	if (model) delete[] model;
//	model = new char[strlen(m) + 1];
//	strcpy_s(model, strlen(m) + 1, m);
//}
