#pragma once
#include<iostream>
#include<ostream>
using namespace std;

class Garnitura {
protected:
	string numeModel, producator;
	double nrGarnitRez, nrGarnitDisp, nrVagoane;
public:
	Garnitura();
	Garnitura(string numeModel, string producator, double nrVagoane, double nrGarnitDisp, double nrGarnitRez);
	Garnitura(const Garnitura& g);
    ~Garnitura();
	void setNumeModel(string numeModel);
	void setProducator(string producator);
	void setNrGarnitRez(double nrGarnitRez);
	void setNrGarnitDisp(double nrGarnitDisp);
	void setNrVagoane(double nrVagoane);
	string getNumeModel();
	string getProducator();
	double getNrGarnitRez();
	double getNrGarnitDisp();
	double getNrVagoane();
	
	virtual Garnitura* clone();

	Garnitura& operator=(const Garnitura& g);
	bool operator==(const Garnitura& g);
	virtual string toString(string delim);

};