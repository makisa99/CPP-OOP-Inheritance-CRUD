#include "studenti.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <string>
#include "IzuzetakNasledjuje.h"

using namespace std;
int main() {
	string odgovorTrad, odgovorInt;
	cout << "Da li zelite da sortirate tradicionalne studente po broju indeksa? (da ili ne)" << endl;
	cin >> odgovorTrad;
	cout << "Da li zelite da sortirate internet studente po gradu u kome zive? (da ili ne)" << endl;
	cin >> odgovorInt;
	cout << "Sortiranje studenata u tradicionalne i online studente" << endl;
	ifstream fin;
	try {
		fin.open("Studenti.txt");
		if (!fin) {
			throw IzuzetakFajl(404, "FileNotFoundException");
		}
		else {
			cout << "Uspesno otvorio fajl Studenti.txt" << endl;
		}
	}
	catch (IzuzetakFajl& e)
	{
		e.show_msg();
		cout << e.what() << endl;
		return 1;
	}
	vector<InternetStudent> vIS;
	vector<TradicionalniStudent> vTS;
	int indeks, brIndPretraga = 0;
	string ime, prezime, grad, promenljivo, pretragaDaLi = "";
	InternetStudent is; //zbog dodavanja u vektor
	TradicionalniStudent ts; //zbog dodavanja u vektor
	cout << "Da li mozda zelite da vrsite pretragu po broju indeksa? (da ili ne)";
	cin >> pretragaDaLi;
	if (pretragaDaLi.compare("da") == 0)
	{
		cout << "Unesite broj indeksa koji zelite da ispisete i proverite koji je tip studiranja ";
		cin >> brIndPretraga;
	}
	while (fin >> indeks >> ime >> prezime >> grad >> promenljivo) {
		if (promenljivo.length() == 13) {
			//Onda je tradicionalni
			ts.setIndeks(indeks);
			ts.setIme(ime);
			ts.setPrezime(prezime);
			ts.setGrad(grad);
			ts.setBrBusPlus(promenljivo);
			cout << "Skolarina tradicionalnog studenta " << indeks << " je " << ts.skolarina() << endl;
			if (pretragaDaLi.compare("da") == 0)
			{
				if (indeks == brIndPretraga) {
					cout << "Nadjen tradicionalni student kog ste trazili: " << ts << endl;
				}
			}
			vTS.push_back(ts);
		}
		else {
			//Onda je internet
			is.setIndeks(indeks);
			is.setIme(ime);
			is.setPrezime(prezime);
			is.setGrad(grad);
			is.setBrTelefona(promenljivo);
			cout << "Skolarina internet studenta " << indeks << " je " << is.skolarina() << endl;

			if (pretragaDaLi.compare("da") == 0)
			{
				if (indeks == brIndPretraga) {
					cout << "Nadjen internet student kog ste trazili: " << is << endl;
				}
			}
			vIS.push_back(is);
		}
	}
	//OVDE TREBA SORT AKO JE KORISNIK REKAO DA HOCE SORT
	if (odgovorTrad.compare("da")) {
		sort(vTS.begin(), vTS.end(), greater<TradicionalniStudent>());
	}
	if (odgovorInt.compare("da")) {
		sort(vIS.begin(), vIS.end(), greater<InternetStudent>());
	}
	//Ispisivanje u fajl tradicionalnih
	ofstream foutTS;
	foutTS.open("tradicionalni.txt");

	while (!vTS.empty())
	{
		TradicionalniStudent e = vTS.back();
		foutTS << "Indeks = " << e.getIndeks() << ", Ime = " << e.getIme() << ", Prezime = " << e.getPrezime() << ", Grad = " << e.getGrad() << ", Broj bus plusa = " << e.getBrBusPlus() << '\n';
		vTS.pop_back();
	}
	cout << endl << "Uspesno upisao tradicionalne studente" << endl;

	//Ispisivanje u fajl internet
	ofstream foutIS;
	foutIS.open("online.txt");

	while (!vIS.empty())
	{
		InternetStudent eI = vIS.back();
		foutIS << "Indeks = " << eI.getIndeks() << ", Ime = " << eI.getIme() << ", Prezime = " << eI.getPrezime() << ", Grad = " << eI.getGrad() << ", Broj telefona = " << eI.getBrTelefona() << '\n';
		vIS.pop_back();
	}
	cout << endl << "Uspesno upisao internet studente" << endl;
	return 0;
}