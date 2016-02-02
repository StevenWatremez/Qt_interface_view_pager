#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <iostream> 
#include <string>
using namespace std;

class Individu {
  
public : 
    Individu();
	Individu(string prenom, string nom, int age);
   ~Individu();
    string getNom();
	string getPrenom();
	int getAge();
    void afficheInfos();
    void setPrenom(string prenom);
    void setAge(int age);

   // void setNom(string nom); //exercice I
    void setNom(string * nom);  //exercice I
    void setNom(string & nom);

    bool operator < ( const Individu & individu) const;


protected :
    string nom;
	string prenom;
	int age;
};
#endif 
