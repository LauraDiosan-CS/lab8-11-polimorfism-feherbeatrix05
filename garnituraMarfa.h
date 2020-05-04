#pragma once
#include "Garnitura.h"

class GarnituraMarfa : public Garnitura {
private:
	string incarcatura;
public:
	GarnituraMarfa();
	GarnituraMarfa(string numeModel,string producator, double nrVagoane, double nrGarnitDisp , double nrGarnitRez, string incarcatura);
	GarnituraMarfa(const GarnituraMarfa& g);
	~GarnituraMarfa();

	Garnitura* clone();

	string getIncarcatura();
	void setIncarcatura(string incarcatura);
	GarnituraMarfa& operator=(const GarnituraMarfa& g);
	bool operator==(const GarnituraMarfa& g);
	string toString(string delim);
};