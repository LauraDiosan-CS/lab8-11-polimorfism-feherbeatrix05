#include "garnituraPersoane.h"
#include "Util.h"

GarnituraPersoane::GarnituraPersoane() : Garnitura()
{
	this->nrLoc = 0;
}

GarnituraPersoane::GarnituraPersoane(string numeModel, string producator, double nrVagoane, double nrGarnitDisp, double nrGarnitRez,double nrLoc):Garnitura(numeModel, producator,nrVagoane,nrGarnitDisp,nrGarnitRez)
{
	this->nrLoc = nrLoc;
}

GarnituraPersoane::GarnituraPersoane(const GarnituraPersoane& g) : Garnitura(g)
{
	this->nrLoc = g.nrLoc;
}

GarnituraPersoane ::~GarnituraPersoane()
{
}
Garnitura* GarnituraPersoane::clone()
{
	return new GarnituraPersoane(this->numeModel, this->producator, this->nrVagoane, this->nrGarnitDisp, this->nrGarnitRez, this->nrLoc);
}

double GarnituraPersoane::getNrLoc()
{
	return this->nrLoc = nrLoc;
}

void GarnituraPersoane::setNrLoc(double nrLoc)
{
	this->nrLoc = nrLoc;
}

GarnituraPersoane& GarnituraPersoane ::operator=(const GarnituraPersoane& g)
{
	Garnitura::operator=(g);
	this->nrLoc = g.nrLoc;
	return *this;
}
bool GarnituraPersoane ::operator==(const GarnituraPersoane& g)
{
	return Garnitura::operator==(g) && this->nrLoc == g.nrLoc;
}

string GarnituraPersoane::toString(string delim)
{
	return "GP" + delim + Garnitura::toString(delim) + delim + convertDoubleToString(this->nrLoc);
}