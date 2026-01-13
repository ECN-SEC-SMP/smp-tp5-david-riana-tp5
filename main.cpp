#include <iostream>
#include "utilitaires.h"
#include "type_def.h"

int main() {
    Personne* david = creerPersonne("PROSPERIN","David",2004,1,nullptr);
    Personne* riana = creerPersonne("CHAUVET RAHERIMALALA","Riana",2006,2,nullptr);
    Personne* tom = creerPersonne("LOMBE","Tom",2005,1,nullptr);
    affichage(david);
    mariage(riana,tom);
    affichage(riana);
    return 0;
}