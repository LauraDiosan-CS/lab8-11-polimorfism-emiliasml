#pragma once
#include "IRepository.h"
#include"RepositoryFile.h"
#include"User.h"
#include"Series.h"
#include"Phone.h"
#include"Drone.h"
#include "ValidatorSeries.h"
#include "ValidatorPhone.h"
#include "RepositoryFile.h"
#include <sstream>

class Service
{
private:
	RepositoryFile<Series*>& repository;
	IRepository<User>* repositoryUser;
	ValidatorSeries vs;
	ValidatorPhone vp;
public:
	Service(RepositoryFile<Series*> r, IRepository<User>* ru);
	bool login(string, string);
	void logout(string, string);
	vector<Series*> findProducer(string);
	vector<Series*> getAllSeries();
	int getSize();
	void addElem(Series*& s);
	void deleteElem(Series*& s);
	~Service();
};