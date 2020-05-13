#pragma once
#include "Phone.h"
#include "MyException.h"
#include <vector>
using namespace std;

class ValidatorPhone {
public:
	ValidatorPhone() {}
	void validate(Phone* p) {
		vector<string> errors;
		if ((*p).getNr() < 100) {
			errors.push_back(string("The number must be at least 100\n"));
		}
		if ((*p).getOperators().size() < 1) {
			errors.push_back(string("The phone must have at least one operator in the list"));
		}
		if (errors.size() > 0) throw MyException(errors);
	}
	~ValidatorPhone() {}
};
