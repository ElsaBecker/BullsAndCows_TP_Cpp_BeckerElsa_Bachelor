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

	//Donn�es Membres
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

	void reinitGame(); //r�initialiser les variables importantes � 0 pour recommencer une partie

	//Type structure
	void setBullsandCows(); //Verifier et enregistrer le nombre de bulls et nombre de cows
	int getBulls() const; //Renvoyer le nombre de lettres correctes et bien plac�es (Bulls)
	

	//Enum
	bool verifIsogram(); //V�rifier si le mot entr� par le joueur est un isogramme
	bool verifLength(); //Comparer la longueur de la string entr�e par le joueur et celle du mot cach�
	bool verifLowercase(); //V�rifier si la string entr�e par le joueur est en minuscule
	bool verifInvalid(); //V�rifier si le joueur a commis une ou plusieurs des erreurs dans la saisie de sa string

	bool verifBullsVictoire(); //V�rifier si le joueur a rempli la condition de victoire->a tout les Bulls : donc a trouv� le bon mot
	void afficheStatut(); // Affichage � chaque tour du statut du jeu (Erreurs ou Proposition valide) et de feedback sur le mot test� par le joueur (Bulls and Cows)

	void setWordTry(); //Stocker la string entr�e par le joueur
	string getWordTry() const; //Afficher la string entr�e par le joueur � ce tour

	int getMaxTries() const; //Obtenir nombre d'essais en fonction de la longueur du mot
	int getCurrentTry() const; //Obtenir le tour actuel du joueur

	



	~BCClasse();
};

