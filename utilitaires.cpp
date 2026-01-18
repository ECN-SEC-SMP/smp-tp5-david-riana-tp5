#include "type_def.h"
#include "utilitaires.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

//QUESTION 1

Personne* creerPersonne(string nom, string prenom, int naissance, int sexe, Personne* conjoint){
    static int id = 0;

    Personne* nv   = new Personne;
    nv->nom        = nom;
    nv-> prenom    = prenom;
    nv->naissance  = naissance;
    nv->sexe       = sexe;
    nv->conjoint   = conjoint;
    nv->pere       = nullptr;
    nv->mere       = nullptr;
    nv->id         = id;
    nv->pereId     = -1;
    nv->mereId     = -1;
    nv->conjointId = -1;

    id++;
    return nv;
}

//QUESTION 2
void mariage(Personne* p1,Personne* p2){
    p1-> conjoint = p2;
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
    return false;
}

// QUESTION 6
bool estAncetre (Personne* a, Personne* b)
{
    assert(b != nullptr);
    assert(a != nullptr);

    // Si personne b est l'ancetre de personne a
    bool flagEstAncetreMere = false;
    bool flagEstAncetrePere = false;

    if (a == nullptr || b == nullptr)
    {
        return false;
    } else if (a->pere == nullptr && a->mere == nullptr)
    {
        return false;
    }
    
    // TODO: Faire avec les tests avec a->pere == nullptr ou a->mere == nullptr
    else if (a->pere == nullptr && a->mere != nullptr)
    {
        flagEstAncetreMere = estAncetre(a->mere, b);
    }
    else if (a->pere != nullptr && a->mere == nullptr) 
    {
        flagEstAncetreMere = estAncetre(a->mere, b);
    }
    else if(memePersonne(a->pere, b)){
        return true;
    }
    else if (memePersonne(a->mere, b)){
        return true;
    } 
    else{
        flagEstAncetreMere = estAncetre(a->mere, b);
        flagEstAncetrePere = estAncetre(a->pere, b);
        if (flagEstAncetreMere || flagEstAncetrePere){
            return true;
        }
        else{
            return false;
        }
    }
}

//QUESTION 7
int nbGenerations (Personne* pers){
    if (pers == nullptr){
        return 0;
    }
    else{
        return 1+ max(nbGenerations(pers->pere),nbGenerations(pers->mere));
    }
}
    

//QUESTION 8

int nbMembres (Personne* p){
    if(p == nullptr){
        return 0;
    } 
    else{
        return 1 + nbMembres(p->pere) + nbMembres(p->mere);
    }
}

// QUESTION 9
// TODO: à debugger
bool mariagePossible(Personne* a, Personne* b)
{
    if (estAncetre(a, b))
    {
        return false;
    } else if (estAncetre(b, a))
    {
        return false;
    } else if (sontFrereSoeur(b, a)) 
    {
        return false;
    }
    return true;
}

//QUESTION 10
void affichageArbre(Personne* personne){
    if (personne != nullptr){
        if (personne->mere == nullptr && personne->pere == nullptr){
                if (personne->sexe == 1){
                    cout << "Monsieur ";
                } 
                else{
                    cout << "Madame ";
                }
                cout << personne-> prenom << " " << personne-> nom << endl;
        }
        else{
            cout << "               ";
            if (personne->sexe == 1){
                    cout << "Monsieur ";
                } 
                else{
                    cout << "Madame ";
                }
                cout << personne-> prenom << " " << personne-> nom << endl;
            affichageArbre(personne->pere);
            cout << "                            ";
            affichageArbre(personne->mere);
            cout << "  "<< endl;
        }
    }
}

// QUESTION 11
// TODO: finir sauvegarderArbre
int sauvegarderArbre(string nom_fichier, const Personne *p)
{
    ofstream fluxFichier(nom_fichier);

    if (fluxFichier)
    {

    } else {
        cout << "Impossible d'ouvrir le fichier : " << nom_fichier << endl;
    }
}


void vectorisationArbre(vector<Personne>& ps, Personne *p)
{
    if (p != nullptr) {
        affichage(p);
        ps.push_back(*p);
        vectorisationArbre(ps, p->mere);
        vectorisationArbre(ps, p->pere);
        vectorisationArbre(ps, p->conjoint);
    }
}


string serialisePersonne(const Personne *p)
{
    /*
     si x n'existe pas alors x = -1

     <id unique> <prenom> <nom> <naissance> <sexe> <pere> <mere> <conjoint>
    - id       = x
    - pere     = id
    - mere     = id
    - conjoint = id
    - nom      = string
    - prenom   = string
    - naissance= int
    - sexe     = int
    */

    ostringstream oss;

    oss << p->id << " " << p->prenom << " " << p->nom << " " << p->naissance << " " << p->sexe << " ";
    if (p->pere == nullptr) {
        oss << "-1";
    } else {
        oss << p->pere->id;
    }
    oss << " ";
    if (p->mere == nullptr) {
        oss << "-1";
    } else {
        oss << p->mere->id;
    }
    oss << " ";
    if (p->conjoint == nullptr) {
        oss << "-1";
    } else {
        oss << p->conjoint->id;
    }

    return oss.str();
}

Personne* deserialisePersonne(const string& p)
{
    Personne* nouvPersone = new Personne();
    istringstream iss(p);

    iss >> nouvPersone->id;
    iss >> nouvPersone->prenom;
    iss >> nouvPersone->nom;
    iss >> nouvPersone->naissance;
    iss >> nouvPersone->sexe;

    iss >> nouvPersone->pereId;
    iss >> nouvPersone->mereId;
    iss >> nouvPersone->conjointId;

    return nouvPersone;
}