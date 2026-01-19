#include <cassert>
#include <iostream>
#include <sstream>

#include "utilitaires.h"
#include "type_def.h"

using namespace std;

int main() {
    Personne* david = creerPersonne("PROSPERIN","David",2004,1,nullptr);
    Personne* riana = creerPersonne("CHAUVET-RAHERIMALALA","Riana",2006,2,nullptr);
    Personne* tom = creerPersonne("LOMBE","Tom",2005,1,nullptr);
    Personne* angelique = creerPersonne("PAROIS", "Angélique", 2005, 2,nullptr);
    Personne* marceline = creerPersonne("GLIPARD", "Marceline", 1985, 2,nullptr);
    Personne* francis = creerPersonne("GLIPARD", "Francis", 1930, 1,nullptr);
    Personne* francine = creerPersonne("GLIPARD", "Francine", 1930, 2,nullptr);
    Personne* marcel = creerPersonne("IPARD", "Marcel", 1930, 1,nullptr);
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
    cout<<"riana et riana sont les mêmes personnes? "<<endl;
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

    // ===== Test question 6 =====
    cout << "Test question 6" << endl;
    cout << "David ancêtre de Riana ?" << endl;
    cout << std::boolalpha << estAncetre(riana, david) << endl;
    cout << "Riana ancêtre de David ?" << endl;
    cout << std::boolalpha << estAncetre(david, riana) << endl;
    cout << "Riana ancêtre de Marceline ?" << endl;
    cout << std::boolalpha << estAncetre(marceline, riana) << endl;
    // // ===== Test question 7 =====
    cout << "Test question 7" << endl;
    cout << "Il y a " << nbGenerations(riana) << " générations."<< endl;

    // ===== Test question 8 =====
    cout << "Test question 8" << endl;
    cout << "Il y a " << nbMembres(riana) << " personnes."<< endl;

    // ==== Test question 9 =====
    cout << "Test question 9" << endl;
    
    cout << "Mariage possible" << endl;
    assert(mariagePossible(riana, tom) == true && "riana et tom peuvent se marier");

    cout << "Mariage pas possible" << endl;
    assert(mariagePossible(riana, angelique) == false && "riana et angelique ne peuvent pas se marier");
    
    // ==== Test question 10 =====
    cout << "Test question 10" << endl;
    riana->mere = marceline;
    marceline->pere = francis;
    francis->mere = francine;
    francine->pere = marcel;
    affichageArbre(riana);

    // === Test question 11 ===
    // Test serialisePersonne
    assert(serialisePersonne(david) == "0 David PROSPERIN 2004 1 -1 -1 -1");
    assert(serialisePersonne(riana) == "1 Riana CHAUVET-RAHERIMALALA 2006 2 0 4 2");
    assert(serialisePersonne(tom) == "2 Tom LOMBE 2005 1 -1 -1 -1");
    assert(serialisePersonne(angelique) == "3 Angélique PAROIS 2005 2 0 -1 -1");

    // Test deserialisePersonne
    string davidSerialise      = "0 David PROSPERIN 2004 1 -1 -1 -1";
    string rianaSerialise      = "1 Riana CHAUVET-RAHERIMALALA 2006 2 0 -1 2";

    Personne* davidDeserialise   = deserialisePersonne(davidSerialise);
    Personne* rianaDeserialise   = deserialisePersonne(rianaSerialise);

    assert(
        davidDeserialise->id        == 0           &&
        davidDeserialise->prenom    == "David"     &&
        davidDeserialise->nom       == "PROSPERIN" &&
        davidDeserialise->naissance == 2004        &&
        davidDeserialise->sexe      == 1           &&
        davidDeserialise->pereId    == -1          &&
        davidDeserialise->mereId    == -1          &&
        davidDeserialise->conjointId== -1
    );

    assert(
        rianaDeserialise->id        == 1                      &&
        rianaDeserialise->prenom    == "Riana"                &&
        rianaDeserialise->nom       == "CHAUVET-RAHERIMALALA" &&
        rianaDeserialise->naissance == 2006                   &&
        rianaDeserialise->sexe      == 2                      &&
        rianaDeserialise->pereId    == 0                      &&
        rianaDeserialise->mereId    == -1                     &&
        rianaDeserialise->conjointId== 2
    );

     // Test vectorisationArbre
     cout << "vectorisationArbre" << endl;
     vector<Personne> listeRiana;
     vectorisationArbre(listeRiana, riana);

     assert(memePersonne(&listeRiana[0], riana) &&
            memePersonne(&listeRiana[1], david) &&
            memePersonne(&listeRiana[2] , marceline));

     // Test sauvegardeAbre
     cout << "sauvegardeAbre" << endl;
     sauvegarderArbre("./arbreRiana.txt", riana);

     string contenuArbreRiana = lireFichier("./arbreRiana.txt");
     ostringstream chaineAttendu;
     chaineAttendu << "1 Riana CHAUVET-RAHERIMALALA 2006 2 0 4 2\n";
     chaineAttendu << "0 David PROSPERIN 2004 1 -1 -1 -1\n";
     chaineAttendu << "4 Marceline GLIPARD 1985 2 5 -1 -1\n";
     chaineAttendu << "5 Francis GLIPARD 1930 1 -1 6 -1\n";
     chaineAttendu << "6 Francine GLIPARD 1930 2 7 -1 -1\n";
     chaineAttendu << "7 Marcel IPARD 1930 1 -1 -1 -1\n";
     chaineAttendu << "2 Tom LOMBE 2005 1 -1 -1 -1\n";

     assert(contenuArbreRiana == chaineAttendu.str());

    // Test chercherPersonneParId
    cout << "chercherPersonneParId" << endl;

    vector<Personne*> listeRiana2 {david, riana, tom};

    // La personne est dans le vector
    Personne* davidPtr = chercherPersonneParId(listeRiana2, 0);

    assert(davidPtr == listeRiana2[0] && "david est en tête de liste");

    // La personne n'est pas dans le vector
    Personne* marcelinePtr = chercherPersonneParId(listeRiana2, 4);

    assert(marcelinePtr == nullptr && "marceline n'est pas présente dans le vector listeRiana2");

    // Test chargerArbre
    cout << "chargerArbre" << endl;
    Personne* tete = chargerArbre("./arbreRiana.txt");

    assert(
        tete->prenom    == "Riana"                &&
        tete->nom       == "CHAUVET-RAHERIMALALA" &&
        tete->naissance == 2006                   &&
        tete->sexe      == 2                      &&

        tete->pere->prenom    == "David"          &&
        tete->pere->nom       == "PROSPERIN"      &&
        tete->pere->sexe      == 1                &&
        tete->pere->naissance == 2004             &&

        tete->conjoint->prenom    == "Tom"        &&
        tete->conjoint->nom       == "LOMBE"      &&
        tete->conjoint->sexe      == 1            &&
        tete->conjoint->naissance == 2005
        );

     return 0;
}