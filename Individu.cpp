#include "Individu.h"

Individu::Individu() {
	this->prenom = "prenom";
	this->nom = "nom";
	this->age = 0;
}

Individu::Individu(string prenom, string nom, int age) {
	this->prenom = prenom;
	this->nom = nom;
	this->age = age;
}

Individu::~Individu() {
}

string Individu::getPrenom() {
	return this->prenom;
}

string Individu::getNom() {
	return this->nom;
}

int Individu::getAge() {
	return this->age;
}

void Individu::afficheInfos() {
    cout << "Methode afficheInfos() de la classe Individu" << endl;
	std::cout << "Individu : " << this->getPrenom() << " " << this->getNom() << " a " <<this->getAge() << " ans" << std::endl;
}
/*
void  Individu::setNom(string nom) {
    cout << "Appel de Individu::setNom(string nom)" << endl;
    this->nom = nom;
}
*/
void Individu::setNom(string & nom) {
    cout << "Appel de Individu::setNom(string & nom)" << endl;
    this->nom = nom;
}

void Individu::setNom(string * nom) {
     cout << "Appel de Individu::setNom(string * nom)" << endl;
    this->nom = *nom;
}

void  Individu::setPrenom(string prenom) {
    this->prenom = prenom;
}

void  Individu::setAge(int age) {
    this->age = age;

}

bool Individu::operator < ( const Individu & individu) const {
    if (this->nom <= individu.nom) return true;
    return false;
}
