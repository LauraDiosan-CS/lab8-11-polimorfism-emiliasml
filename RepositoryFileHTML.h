#pragma once
#include "RepositoryFile.h"
#include "IRepository.h"
#include <fstream>
#include <string>
#include <iostream>
#include "Serializer.h"
#include "MyException.h"

template <class T>
class RepositoryFileHTML :public RepositoryFile<T> {
public:	
	RepositoryFileHTML();
	RepositoryFileHTML(const char* fileName, Serializer<T>* serializer);
	~RepositoryFileHTML();
	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepositoryFileHTML<T>::RepositoryFileHTML() : IRepository(){
}

template<class T>
inline RepositoryFileHTML<T>::RepositoryFileHTML(const char* fileName, Serializer<T>* serializer)
	:RepositoryFile<T>(fileName, serializer) {
}

template<class T>
inline RepositoryFileHTML<T>::~RepositoryFileHTML() {
}

template<class T>
inline void RepositoryFileHTML<T>::loadFromFile() {
	std::string linie;
	std::ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, linie)) {
		try {
			RepositoryFile<T>::add(RepositoryFile<T>::serializer->fromString(linie, '/'));
		}
		catch (const MyException& ex) {
			std::cout << ex.what();
		}
	}
}

//template<class T>
//inline void RepositoryFileHTML<T>::saveToFile() {
//	ofstream f(RepositoryFile<T>::fileName);
//	for (T crt : IRepository<T>::elem) {
//		f << crt.toStringDelimiter(',') << endl;
//	}
//}