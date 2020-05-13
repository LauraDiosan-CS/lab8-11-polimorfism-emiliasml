#pragma once
#include "IRepository.h"
#include <fstream>
#include "Serializer.h"
template <class T> class RepositoryFile : public IRepository<T>{
protected:
	const char* fileName;
	Serializer<T>* serializer;
public:
	RepositoryFile();
	RepositoryFile(const char*, Serializer<T>* serializer);
	//virtual void saveToFile();
	virtual void loadFromFile();
	void clearFile();
	~RepositoryFile();
};


template<class T>
RepositoryFile<T>::RepositoryFile() :IRepository<T>() {}

template<class T>
RepositoryFile<T>::RepositoryFile(const char* fileName, Serializer<T>* serializer){
	this->fileName = fileName;
	this->serializer = serializer;
}

template<class T>
RepositoryFile<T>::~RepositoryFile() {}

//template<class T>
//void RepositoryFile<T>::saveToFile() {}

template<class T>
void RepositoryFile<T>::loadFromFile() {}

template<class T>
inline void RepositoryFile<T>::clearFile(){
	std::ofstream f;
	f.open(fileName, std::ofstream::out | std::ofstream::trunc);
	f.close();
}
