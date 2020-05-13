#pragma once
#include "RepositoryFile.h"
#include <fstream>
#include <string>
#include "MyException.h"
#include "Serializer.h"
using namespace std;

template  <class T> class RepositoryFileCSV : public RepositoryFile<T>
{public:
	RepositoryFileCSV();
	RepositoryFileCSV(const char* fileName, Serializer<T>* serializer);
	void loadFromFile();
	void saveToFile();
	~RepositoryFileCSV();
};


template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV() {}

template<class T>
inline RepositoryFileCSV<T>::RepositoryFileCSV(const char* fileName, Serializer<T>* serializer)
	:RepositoryFile<T>(fileName, serializer) {
}

template<class T>
void RepositoryFileCSV<T>::loadFromFile()
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line)) {
		try {
			RepositoryFile<T>::add(RepositoryFile<T>::serializer->fromString(line, ','));
		}
		catch (const MyException& ex) {
			std::cout << ex.what();
		}
	}
}

//template<class T>
//void RepositoryFileCSV<T>::saveToFile(){
//	ofstream f(RepositoryFile<T>::fileName);
//	for (T crt : IRepository<T>::elem) {
//		f << crt.toStringDelimiter(',') << endl;
//	}	
//}

template<class T>
RepositoryFileCSV<T>::~RepositoryFileCSV() {}

