#include "garnituraMarfa.h"

GarnituraMarfa::GarnituraMarfa() : Garnitura()
{
}

GarnituraMarfa::GarnituraMarfa(string numeModel, string producator, double nrVagoane, double nrGarnitDisp, double nrGarnitRez, string incarcatura) : Garnitura(numeModel, producator,nrVagoane,nrGarnitDisp,nrGarnitRez)
{
	this->incarcatura = incarcatura;
}

GarnituraMarfa::GarnituraMarfa(const GarnituraMarfa& g) : Garnitura(g)
{
	this->incarcatura = g.incarcatura;
}

GarnituraMarfa ::~GarnituraMarfa()
{
}
Garnitura* GarnituraMarfa::clone()
{
	return new GarnituraMarfa(this->numeModel, this->producator, this->nrVagoane, this->nrGarnitDisp, this->nrGarnitRez, this->incarcatura);
}

string GarnituraMarfa::getIncarcatura()
{
	return this->incarcatura;
}

void GarnituraMarfa::setIncarcatura(string incarcatura)
{
	this->incarcatura = incarcatura;
}

GarnituraMarfa& GarnituraMarfa ::operator=(const GarnituraMarfa& g)
{
	Garnitura::operator=(g);
	this->incarcatura= g.incarcatura;
	return *this;
}
bool GarnituraMarfa ::operator==(const GarnituraMarfa& g)
{
	return Garnitura::operator==(g) && this->incarcatura == g.incarcatura;
}

string GarnituraMarfa::toString(string delim)
{
	return "GM" + delim + Garnitura::toString(delim) + delim + this->incarcatura;
}
