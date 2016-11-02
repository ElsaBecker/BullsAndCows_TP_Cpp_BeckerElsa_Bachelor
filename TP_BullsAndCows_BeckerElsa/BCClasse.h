#pragma once

#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

using namespace std;

typedef struct compteurBC 
{
	int nbBulls;
	int nbCows;
}compteurBC;


enum gameStatut // Selon l'erreur set l'enum a la bonne valeur
{
	invalidStatut,
	ok,
	notIsogram,
	wrongLength,
	notLowercase
};



class BCClasse
{

private :

	//Données Membres
	int MyCurrentTry;
	string MyHiddenWord;
	string PlayerWord;
	bool GameIsWon;

	//Type structure
	compteurBC Score;

	//Enum
	gameStatut mVerif;

public:
	BCClasse();

	void reinitGame(); //réinitialiser les variables importantes à 0 pour recommencer une partie

	//Type structure
	void setBullsandCows(); //Verifier et enregistrer le nombre de bulls et nombre de cows
	int getBulls() const; //Renvoyer le nombre de lettres correctes et bien placées (Bulls)
	

	//Enum
	bool verifIsogram(); //Vérifier si le mot entré par le joueur est un isogramme
	bool verifLength(); //Comparer la longueur de la string entrée par le joueur et celle du mot caché
	bool verifLowercase(); //Vérifier si la string entrée par le joueur est en minuscule
	bool verifInvalid(); //Vérifier si le joueur a commis une ou plusieurs des erreurs dans la saisie de sa string

	bool verifBullsVictoire(); //Vérifier si le joueur a rempli la condition de victoire->a tout les Bulls : donc a trouvé le bon mot
	void afficheStatut(); // Affichage à chaque tour du statut du jeu (Erreurs ou Proposition valide) et de feedback sur le mot testé par le joueur (Bulls and Cows)

	void setWordTry(); //Stocker la string entrée par le joueur
	string getWordTry() const; //Afficher la string entrée par le joueur à ce tour

	int getMaxTries() const; //Obtenir nombre d'essais en fonction de la longueur du mot
	int getCurrentTry() const; //Obtenir le tour actuel du joueur

	



	~BCClasse();
};

