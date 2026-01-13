#include "type_def.h"
#include <iostream>
using namespace std;

Personne* creerPersonne(string nom,string prenom,int naissance,int sexe,Personne* conjoint){
    Personne* nv = new Personne;
    nv->nom = nom;
    nv-> prenom = prenom;
    nv->naissance = naissance;
    nv->sexe = sexe;
    nv->conjoint = conjoint;
}

void mariage(Personne* p1,Personne* p2){
    p1-> conjoint = p2;
    p2 -> conjoint = p1;
}