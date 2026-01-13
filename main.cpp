#include <iostream>
#include "utilitaires.h"
#include "type_def.h"

using namespace std;

int main() {
    Personne* david = creerPersonne("PROSPERIN","David",2004,1,nullptr);
    Personne* riana = creerPersonne("CHAUVET RAHERIMALALA","Riana",2006,2,nullptr);
    Personne* tom = creerPersonne("LOMBE","Tom",2005,1,nullptr);
    Personne* angelique = creerPersonne("PAROIS", "Angélique", 2005, 2,nullptr);
    affichage(david);
    mariage(riana,tom);
    affichage(riana);

    // ===== Test question 4 =====
    cout << "Question 4" << endl;
    riana->pere = david;
    angelique->pere = david;

    affichage(riana);

    // ===== Test question 5 =====
    cout << "Question 5" << endl;
    bool b;
    b = memePersonne(riana,riana);
    cout<<"riana et riana sont les mêmes personnes?"<<endl;
    if (b){
        cout<<"true"<<endl;
    }
    else{
        cout << "false" << endl;
    }
    bool c;
    c = memePersonne(riana,david);
    cout<<"riana et david sont les mêmes personnes?"<<endl;
    if (c){
        cout<<"true"<<endl;
    }
    else{
        cout << "false" << endl;
    }
    cout<<"riana et angelique sont soeurs?"<<endl;
    bool d;
    d = sontFrereSoeur(riana,angelique);
    if (d){
        cout<<"true"<<endl;
    }
    else{
        cout << "false" << endl;
    }
    cout<<"riana et david sont frère et soeur?"<<endl;
    bool e;
    e = sontFrereSoeur(riana,david);
    if (e){
        cout<<"true"<<endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}