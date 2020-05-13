#pragma once
#include "Serializer.h"
#include "Phone.h"
#include "Drone.h"
#include "Series.h"
#include "MyException.h"

class SerializerSeries : public Serializer<Series*> {
public:
	SerializerSeries() :Serializer() {}
	~SerializerSeries() {}
	Series* fromString(string linie, char delim) {
		vector<string> split = splitLine(linie, delim);
		if (split[0] == "Phone") {
			linie.erase(linie.begin(), linie.begin() + 8);
			Series* s = new Phone(linie, delim);
			return s;
		}
		else if (split[0] == "Drone") {
			linie.erase(linie.begin(), linie.begin() + 8);
			Series* s = new Drone(linie, delim);
			return s;
		}
		vector<string> errors;
		errors.push_back(string("The line from this file is wrong! \n"));
		throw MyException(errors);
	}
};