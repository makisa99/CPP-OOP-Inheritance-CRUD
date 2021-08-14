#include <iostream>

using namespace std;

class Studenti
{
public:
	Studenti();
	Studenti(int indeks, string ime, string prezime, string grad);
	~Studenti();
	int getIndeks() const;
	void setIndeks(int indeks);
	string getIme() const;
	void setIme(string ime);
	string getPrezime() const;
	void setPrezime(string prezime);
	string getGrad() const;
	void setGrad(string plata);
	virtual int skolarina() = 0;

	friend ostream& operator <<(ostream& os, const Studenti& Studenti);
protected:
	int indeks;
	string ime;
	string prezime;
	string grad;
};

class InternetStudent : public Studenti
{
public:
	InternetStudent();
	InternetStudent(int indeks, string ime, string prezime, string grad, string brTelefona);
	string getBrTelefona() const;
	void setBrTelefona(string brTelefona);
	~InternetStudent();
	int skolarina() override;
	friend ostream& operator <<(ostream& os, const InternetStudent& InternetStudent);
	bool operator > (const InternetStudent& iStudnt) const
	{
		return (grad > iStudnt.grad);
	}
private:
	string brTelefona;
};

class TradicionalniStudent : public Studenti
{
public:
	TradicionalniStudent();
	TradicionalniStudent(int indeks, string ime, string prezime, string grad, string brBusPlus);
	string getBrBusPlus() const;
	void setBrBusPlus(string);
	~TradicionalniStudent();
	int skolarina() override;
	friend ostream& operator <<(ostream& os, const TradicionalniStudent& TradicionalniStudent);
	bool operator > (const TradicionalniStudent& tStudnt) const
	{
		return (indeks > tStudnt.indeks);
	}

private:
	string brBusPlus;
};