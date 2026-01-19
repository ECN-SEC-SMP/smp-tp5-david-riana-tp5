#pragma once
#include <string>
using namespace std;
#include "type_def.h"

Personne* creerPersonne(string nom,string prenom,int naissance,int sexe,Personne* conjoint);
void mariage(Personne* p1,Personne* p2);
void affichage (Personne* p);
bool memePersonne(Personne* p1,Personne* p2);
bool sontFrereSoeur(Personne* p1, Personne* p2);
bool estAncetre (Personne* a, Personne* b);
int nbGenerations (Personne* pers);
int nbMembres (Personne* p);
bool mariagePossible(Personne* a, Personne* b);
void affichageArbre(Personne* personne);
void sauvegarderArbre(string nom_fichier, Personne *p);
string serialisePersonne(const Personne *p);
Personne* deserialisePersonne(const string& p);
void vectorisationArbre(vector<Personne>& ps, Personne *p);
string lireFichier(const string& nomFichier);
Personne* chercherPersonneParId(const vector<Personne*>& ps, int id);
Personne* chargerArbre(const string& nomFichier);