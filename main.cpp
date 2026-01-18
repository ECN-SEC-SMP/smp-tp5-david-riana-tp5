#include <assert.h>
#include <iostream>
#include "utilitaires.h"
#include "type_def.h"

using namespace std;

int main() {
    Personne* david = creerPersonne("PROSPERIN","David",2004,1,nullptr);
    Personne* riana = creerPersonne("CHAUVET-RAHERIMALALA","Riana",2006,2,nullptr);
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
    
    //cout << std::boolalpha << estAncetre(riana, david) << endl;
    //cout << std::boolalpha << estAncetre(david, riana) << endl;

    // ===== Test question 7 =====
    cout << "Test question 7" << endl;
    cout << "Il y a " << nbGenerations(riana) << " générations."<< endl;

    // ===== Test question 8 =====
    cout << "Test question 8" << endl;
    cout << "Il y a " << nbMembres(riana) << " personnes."<< endl;

    // ==== Test question 9 =====
    cout << "Test question 9" << endl;
    
    //cout << "Mariage possible" << endl;
    //cout << std::boolalpha << mariagePossible(riana, tom) << endl;

    //cout << "Mariage pas possible" << endl;
    //cout << std::boolalpha << mariagePossible(riana, angelique) << endl;
    
    // ==== Test question 10 =====
    cout << "Test question 10" << endl;
    affichageArbre(riana);

    // === Test question 11 ===
    // Test serialisePersonne
    assert(serialisePersonne(david) == "0 David PROSPERIN 2004 1 -1 -1 -1");
    assert(serialisePersonne(riana) == "1 Riana CHAUVET-RAHERIMALALA 2006 2 0 -1 2");
    assert(serialisePersonne(tom) == "2 Tom LOMBE 2005 1 -1 -1 1");
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

    return 0;
}