#pragma once
#include "Phone.h"
#include "Drone.h"
// Telefon(numeProducator, numeModel, unitatiProduse, listaOperatoriGSMCompatibili) si
//Drona(numeProducator, numeModel, unitatiProduse, numarRotoare)
class Series :
	public Phone, Drone
{
private:
	char* producer;
	char* model;
	int nr;
public:
	Series();
	Series(const char*, const char*, int);
	Series(const Series&);
	~Series();
	char* getProducer();
	char* getModel();
	int getNr();
	//TO DO setters
};
