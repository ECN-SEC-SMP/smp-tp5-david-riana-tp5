#pragma once
#include <string>
using namespace std;

struct Personne
{
    string nom;
    string prenom;
    int naissance;
    int sexe;
    Personne* conjoint;
    Personne* pere;
    Personne* mere;
    int id;
};
