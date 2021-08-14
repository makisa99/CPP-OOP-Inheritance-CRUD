#include "studenti.h"
#include <iostream>

using namespace std;
Studenti::Studenti()
{
}

Studenti::Studenti(int indeks, string ime, string prezime, string grad) : indeks(indeks), ime(ime), prezime(prezime), grad(grad)
{
}

Studenti::~Studenti()
{
}

int Studenti::getIndeks() const
{
	return indeks;
}

void Studenti::setIndeks(int indeks)
{
	this->indeks = indeks;
}

string Studenti::getIme() const
{
	return ime;
}

void Studenti::setIme(string ime)
{
	this->ime = ime;
}

string Studenti::getPrezime() const
{
	return prezime;
}

void Studenti::setPrezime(string prezime)
{
	this->prezime = prezime;
}

string Studenti::getGrad() const
{
	return grad;
}

void Studenti::setGrad(string grad)
{
	this->grad = grad;
}

ostream& operator<<(ostream& os, const Studenti& Studenti)
{
	os << "SIndeks = " << Studenti.getIndeks() << " Ime = " << Studenti.getIme() << " Prezime = " << Studenti.getPrezime() << " Grad = " << Studenti.getGrad();
	return os;
}

ostream& operator<<(ostream& os, const InternetStudent& InternetStudent)
{
	os << "Indeks = " << InternetStudent.getIndeks() << " Ime = " << InternetStudent.getIme() << " Prezime = " << InternetStudent.getPrezime() << " Grad = " << InternetStudent.getGrad() << " Broj telefona: " << InternetStudent.getBrTelefona();
	return os;
}

ostream& operator<<(ostream& os, const TradicionalniStudent& TradicionalniStudent)
{
	os << "Indeks = " << TradicionalniStudent.getIndeks() << " Ime = " << TradicionalniStudent.getIme() << " Prezime = " << TradicionalniStudent.getPrezime() << " Grad = " << TradicionalniStudent.getGrad() << " Broj bus plus kartice: " << TradicionalniStudent.getBrBusPlus();
	return os;
}

InternetStudent::InternetStudent()
{
}

InternetStudent::InternetStudent(int indeks, string ime, string prezime, string grad, string brTelefona) : Studenti(indeks, ime, prezime, grad)
{
	this->brTelefona = brTelefona;
}

string InternetStudent::getBrTelefona() const
{
	return brTelefona;
}

void InternetStudent::setBrTelefona(string brTelefona)
{
	this->brTelefona = brTelefona;
}

InternetStudent::~InternetStudent()
{
}

int InternetStudent::skolarina()
{
	return 1999;
}

TradicionalniStudent::TradicionalniStudent()
{
}

TradicionalniStudent::TradicionalniStudent(int indeks, string ime, string prezime, string grad, string brBusPlus) : Studenti(indeks, ime, prezime, grad)
{
	this->brBusPlus = brBusPlus;
}

string TradicionalniStudent::getBrBusPlus() const
{
	return brBusPlus;
}

void TradicionalniStudent::setBrBusPlus(string brBusPlus)
{
	this->brBusPlus = brBusPlus;
}

TradicionalniStudent::~TradicionalniStudent()
{
}

int TradicionalniStudent::skolarina()
{
	return 2500;
}
