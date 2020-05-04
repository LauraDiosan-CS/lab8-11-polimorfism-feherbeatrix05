#include "garnitura.h"
#include "Util.h"
#include<string.h>
#include<ostream>
#include<iostream>
using namespace std;

Garnitura::Garnitura() {
	
	this->nrVagoane = 0;
	this->nrGarnitDisp = 0;
	this->nrGarnitRez = 0;

}

Garnitura::Garnitura(string numeModel, string producator, double nrVagoane, double nrGarnitDisp, double nrGarnitRez){

	this->numeModel = numeModel;
	this->producator = producator;
    this->nrVagoane =nrVagoane;
    this->nrGarnitDisp = nrGarnitDisp;
    this->nrGarnitRez =nrGarnitRez;

}

Garnitura::Garnitura(const Garnitura& g) {
	this->numeModel =g.numeModel;
	this->producator = g.producator;
	this->nrVagoane = g.nrVagoane;
	this->nrGarnitDisp = g.nrGarnitDisp;
	this->nrGarnitRez = g.nrGarnitRez;
}

Garnitura::~Garnitura()
{
}

Garnitura* Garnitura::clone()
{
	return new Garnitura(this->numeModel, this->producator, this->nrVagoane, this->nrGarnitDisp, this->nrGarnitRez);
}

string Garnitura::getNumeModel()
{
	return this->numeModel;
}

string Garnitura::getProducator()
{
	return this->producator;
}
double Garnitura::getNrGarnitRez() {

	return this->nrGarnitRez;
}

double Garnitura::getNrGarnitDisp() {
	return this->nrGarnitDisp;

}
double Garnitura::getNrVagoane() {
	return this->nrVagoane;
}
void Garnitura::setNumeModel(string numeModel)
{
	this->numeModel = numeModel;
}
void Garnitura::setProducator(string producator)
{
	this->producator = producator;
}

void Garnitura::setNrVagoane(double nrVagoane)
{
	this->nrVagoane = nrVagoane;
}

void Garnitura::setNrGarnitDisp(double nrGarnitDisp)
{
	this->nrGarnitDisp= nrGarnitDisp;
}
void Garnitura::setNrGarnitRez(double nrGarnitRez)
{
	this->nrGarnitRez = nrGarnitRez;
}

Garnitura& Garnitura::operator=(const Garnitura& g)
{
	this->numeModel = g.numeModel;
	this->producator = g.producator;
	this->nrVagoane = g.nrVagoane;
	this->nrGarnitDisp = g.nrGarnitDisp;
	this->nrGarnitRez = g.nrGarnitRez;
	return *this;
}

bool Garnitura::operator==(const Garnitura& g)
{
	return this->numeModel == g.numeModel &&
		this->producator == g.producator &&
		this->nrVagoane == g.nrVagoane &&
		this->nrGarnitDisp == g.nrGarnitDisp &&
		this->nrGarnitRez == g.nrGarnitRez;
}

string Garnitura::toString(string delim)
{
	return this->numeModel + delim + this->producator + delim + convertDoubleToString(this->nrVagoane) + delim + convertDoubleToString(this->nrGarnitDisp) + delim + convertDoubleToString(this->nrGarnitRez);
}
