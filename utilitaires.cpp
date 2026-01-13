#include "type_def.h"
#include "utilitaires.h"
#include <iostream>
#include <cassert>
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

//QUESTION 3 ET 4

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

    if (p->pere == nullptr)
    {
        cout << "   De père INCONNU" << endl;
    } else {
        cout << "   De père " << p->pere->prenom << " " << p->pere->nom << endl;
    }

    if (p->mere == nullptr)
    {
        cout << "   De mère INCONNUE" << endl;
    } else {
        cout << "   De mère " << p->mere->prenom << " " << p->mere->nom << endl; 
    }
}

//QUESTION 5
bool memePersonne(Personne* p1,Personne* p2){
    if(p1-> nom == p2->nom && p1->prenom == p2->prenom && p1->naissance == p2->naissance && p1->sexe == p2-> sexe){
        return true;
    }
    return false;
}

bool sontFrereSoeur(Personne* p1, Personne* p2){
    if (!memePersonne(p1,p2)){
        if (p1->pere == p2->pere && p1->mere == p2->mere){
        return true;
        }
        else{
            return false;
        }  
    }
}

// Question 6
bool estAncetre (Personne* a, Personne* b)
{
    assert()
    // Si personne b est l'ancetre de personne a
    //if ()
    return true;
}