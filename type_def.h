#pragma once
#include <string>
using namespace std;

struct personne
{
    string nom;
    string prenom;
    int naissance;
    int sexe;
    personne* conjoint;
};
