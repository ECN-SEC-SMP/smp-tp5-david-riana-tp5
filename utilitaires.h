#pragma once
#include <string>
using namespace std;
#include "type_def.h"

Personne* creerPersonne(string nom,string prenom,int naissance,int sexe,Personne* conjoint);
void mariage(Personne* p1,Personne* p2);
void affichage (Personne* p);
