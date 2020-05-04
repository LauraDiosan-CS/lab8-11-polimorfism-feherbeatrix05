#pragma once
#include "Garnitura.h"


class GarnituraPersoane : public Garnitura {
private:
	double nrLoc;
public:
	GarnituraPersoane();
	GarnituraPersoane(string numeModel, string producator, double nrVagoane, double nrGarnitDisp, double nrGarnitRez, double nrLoc);
	GarnituraPersoane(const GarnituraPersoane& g);
	~GarnituraPersoane();

	Garnitura* clone();

	double getNrLoc();
	void setNrLoc(double nrLoc);
	GarnituraPersoane& operator=(const GarnituraPersoane& g);
	bool operator==(const GarnituraPersoane& g);
	string toString(string delim);
};
