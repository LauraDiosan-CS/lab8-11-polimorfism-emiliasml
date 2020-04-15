#pragma once
#include "RepoTemplate.h"

template <class R> class RepoFile :
	public RepoTemplate<class T>
{
private:
	const char* fis;
public:
	RepoFile();
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void saveToFile();
	~RepoFile();
	int addEl(T el);
	int delEl(T el);
	void updateEl(T el, T newT );
	list <T> getAllEl();
	int dim();
};

template<class R>
inline RepoFile<R>::RepoFile()
{
	fis = "";
}

template<class R>
inline RepoFile<R>::RepoFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* name = new char[10];
	char* nr = new char[10];
	char* status = new char[9];
	while (!f.eof()) {
		f >> nume >> nr >> status;
		if (nume != ""/* && nr != "" && status != ""*/) {
			Car c(nume, nr, status);
			repo.push_back(c);
		}
	}
	delete[] status;
	delete[] nr;
	delete[] nume;
	f.close();
}

template<class R>
inline void RepoFile<R>::loadFromFile(const char* fileName)
{
	repo.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[10];
	char* nr = new char[10];
	char* status = new char[9];
	while (!f.eof()) {
		f >> nume >> nr >> status;
		if (nume != "" && nr != "" && status != "") {
			Car c(nume, nr, status);
			repo.push_back(c);
		}
	}
	delete[] status;
	delete[] nr;
	delete[] nume;
	f.close();
}

template<class R>
inline void RepoFile<R>::saveToFile()
{
		ofstream f(fis);
		//list <Car> carsRepo;
		//list <Car>::iterator it;
		//carsRepo = repo;
		//for (it = carsRepo.begin(); it != carsRepo.end(); it++)
		//	f << (*it).getName() << " " << (*it).getNr() << " " << (*it).getStatus() << " ";
		f.close();
}

template<class R>
inline RepoFile<R>::~RepoFile()
{
}

template<class R>
inline int RepoFile<R>::addEl(T el)
{
	add(el);
	saveToFile();
	return 0;
}

template<class R>
inline int RepoFile<R>::delEl(T el)
{
	removee(el);
	saveToFile();
	return 0;
}

template<class R>
inline void RepoFile<R>::updateEl(T el, T newT)
{
	update(el, newT);
	saveToFile();
}

template<class R>
inline list<T> RepoFile<R>::getAllEl()
{
	return getAll();
}

template<class R>
inline int RepoFile<R>::dim()
{
	return size();
}
