#pragma once
#include"Series.h"
#include "MyException.h"
#include <string>
#include<vector>
using namespace std;

class ValidatorSeries {
public:
    ValidatorSeries() {}
    void validate(Series*& s) {
        vector<string> errors;
        if ((*s).getNr() < 100) {
            errors.push_back(string("The number must be at least 100 \n"));
        }
        if (errors.size() > 0) throw MyException(errors);
    }
    ~ValidatorSeries() {}
};
