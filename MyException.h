#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <exception>
using std::exception;

class MyException :virtual public exception{
private:
	vector<string> errors;
public:
	MyException(vector<string>e) :errors{ e } {}
	vector<string> getErrors() const { return this->errors; }
};

class OneException {
private:
	string message;
public:
	OneException(string message) { this->message = message; }
	string getError() { return this->message; }
	~OneException(){}
};