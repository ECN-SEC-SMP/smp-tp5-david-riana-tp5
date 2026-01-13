#include "type_def.h"
#include "utilitaires.h"
#include <iostream>
using namespace std;

//QUESTION 1

Personne* creerPersonne(string nom,string prenom,int naissance,int sexe,Personne* conjoint){
    Personne* nv   = new Personne;
    nv->nom        = nom;
    nv-> prenom    = prenom;
    nv->naissance  = naissance;
    nv->sexe       = sexe;
    nv->conjoint   = conjoint;
    nv->pere       = nullptr;
    nv->mere       = nullptr;
    return nv;
}

//QUESTION 2
void mariage(Personne* p1,Personne* p2){
    p1-> conjoint = p2;
    p2-> conjoint = p1;
}

//QUESTION 3 

void affichage (Personne* p){
    if (p->sexe == 1){
        cout << "Monsieur ";
    } 
    else{
        cout << "Madame ";
    }
    cout << p-> prenom << " " << p-> nom << endl;
    
    if (p->sexe == 1) 
    {
        cout << "Il";
    } else {
        cout << "Elle";
    }
    
    cout << " est née en "<< p->naissance << endl;

    if (p->conjoint != nullptr)
    {
        if (p->sexe == 1) 
        {
            cout << "Il";
        } else if (p->sexe == 2) {
            cout << "Elle";
        }
        
        cout << " est l'épouse de "<< p->conjoint->prenom << " "<< p->conjoint->nom << endl;
    }
}

//QUESTION 4


