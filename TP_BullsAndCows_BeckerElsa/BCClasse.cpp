#include "BCClasse.h"
#include <iostream>

using namespace std;


BCClasse::BCClasse()
{
	this->MyCurrentTry = 0;
	this->MyHiddenWord = "pacte";
	this->GameIsWon = false;
	this->Score.nbBulls = 0;
	this->Score.nbCows = 0;
	this->mVerif = gameStatut::invalidStatut;
	this->PlayerWord = "";
}

void BCClasse::reinitGame()
//BUT : r�initialiser les variables importantes � leur valeur par d�faut pour recommencer une partie
//ENTREE : booleen qui d�finit la victoire, entier pour le tour actuel
//SORTIE : Variables r�initialis�es aux valeurs par d�faut
{
	this->GameIsWon = false;
	this->MyCurrentTry = 0;
	this->PlayerWord = "";
	this->Score.nbBulls = 0;
	this->Score.nbCows = 0;
	this->mVerif = gameStatut::invalidStatut;
}

void BCClasse::setBullsandCows() 
//BUT : v�rifier le nombre de lettres existantes et bien plac�es (Bulls) et celles existantes mais mal plac�es (Cows) dans le mot entr� par le joueur
//ENTREE : comparer le mot cach� et le mot entr� par le joueur
//SORTIE : nombre de Bulls et de Cows dans le mot du joueur
{
	unsigned int i = 0;
	unsigned int j = 0;

	Score.nbBulls = 0;
	Score.nbCows = 0;

	for (i = 0; i < MyHiddenWord.length() ; i++)
	{
		for (j = 0; j < MyHiddenWord.length() ; j++)
		{
			if (MyHiddenWord[i] == PlayerWord[j])
			{
				if (i == j)
				{
					Score.nbBulls = Score.nbBulls + 1;
				}
				else
				{
					Score.nbCows = Score.nbCows + 1;
				}
			}
		}
	}
}

int BCClasse::getBulls() const
//BUT : Renvoyer le nombre de lettres correctes et bien plac�es (Bulls)
//ENTREE : entier contenant le nombre de Bulls
//SORTIE : renvoie le nombre de Bulls
{
	return this->Score.nbBulls;
}

bool BCClasse::verifBullsVictoire()
//BUT : V�rifier si le joueur a rempli la condition de victoire -> a tout les Bulls : donc a trouv� le bon mot
//ENTREE : entier contenant le nombre de Bulls du joueur, compar� au nombre de lettres du mot
//SORTIE : Bool�en, victoire si le nombre de bulls = longueur du mot (true), sinon false
{

	if (Score.nbBulls == MyHiddenWord.length())
	{
		GameIsWon = true;
	}

	return GameIsWon ;
}


bool BCClasse::verifIsogram()
//BUT : V�rifier si le mot entr� par le joueur est un isogramme
//ENTREE : mot entr� par le joueur
//SORTIE : bool�en indiquant si le mot est un isogramme (true) ou pas (false)
{
	unsigned int i = 0;
	unsigned int j = 0;
	bool isoTrue = false;
	

	for (i = 0; i < PlayerWord.length(); i++)
	{
		for (j = 0; j < PlayerWord.length(); j++)
		{
			if ((PlayerWord[i] == PlayerWord[j]) && (i != j))
			{
				this->mVerif = gameStatut::notIsogram;
				isoTrue = true;
			}
		}
	}

	return isoTrue;
}

bool BCClasse::verifLength()
//BUT : Comparer la longueur de la string entr�e par le joueur et celle du mot cach�
//ENTREE :  Longueurs de la string entr�e par le joueur et de la string contenant le mot cach�
//SORTIE :  Bool�en indiquant si la longueur est fausse (true) ou correcte (false)
{
	bool wlength = false;

	if (PlayerWord.length() != MyHiddenWord.length())
	{
		this->mVerif = gameStatut::wrongLength;
		wlength = true;
	}

	return wlength;
}

bool BCClasse::verifLowercase()
//BUT : V�rifier si la string entr�e par le joueur est en minuscule
//ENTREE : String entr�e par le joueur
//SORTIE : Bool�en indiquant si la string contient au minimum une majuscule (true) ou si elle est en minuscule (false)
{
	unsigned int i = 0;
	bool upperTrue = false;

	for (i = 0; i < PlayerWord.length(); i++)
	{
		if (isupper(PlayerWord[i]))
		{
			this->mVerif = gameStatut::notLowercase;
			upperTrue = true;
		}
	}

	return upperTrue;
}

bool BCClasse::verifInvalid()
//BUT : V�rifier si le joueur a commis une ou plusieurs des erreurs dans la saisie de sa string
//ENTREE : Fonctions de v�rifications des erreurs verifLowercase(), verifLength(), verifIsogram()
//SORTIE : Bool�en indiquant si le jour a commis une/plusieurs erreur(s) (true) ou pas (false)
{
	bool erreur = false;

	if ((verifLowercase() == true) || (verifLength() == true) || (verifIsogram() == true))
	{
		this->mVerif = gameStatut::invalidStatut;
		erreur = true;
	}

	return erreur;
}

void BCClasse::afficheStatut()
//BUT : Affichage � chaque tour du statut du jeu (Erreurs ou Proposition valide) et de feedback sur le mot test� par le joueur (Bulls and Cows) 
//ENTREE : Fonction verifInvalid() qui renvoie si le joueur a commis des erreurs dans sa saisie ou pas
//SORTIE : Donne le nombre de tours restant au joueur (si erreur, pas de tours en moins), En cas d'erreur(s) les �num�rer, Si pas d'erreur affichage du nombre de Bulls and Cows
{
	if (verifInvalid() == true)
	{
		cout << "Proposition invalide. Erreur(s) rencontree(s) :" << endl;

		if (verifIsogram() == true)
		{
			cout << "Les isogrammes sont interdits, vous ne pouvez pas avoir deux lettres similaires" << endl;
		}

		if (verifLowercase() == true)
		{
			cout << "Veuillez n'utiliser que des lettres minuscules" << endl;
		}

		if (verifLength() == true)
		{
			cout << "La longueur de votre mot est incorrecte. Celui-ci doit faire " << MyHiddenWord.length() << " lettres." << endl;
		}

		cout << "Vous avez encore " << getMaxTries() - MyCurrentTry << " essai(s)." << endl;
	}
	else if ((verifInvalid() == false) && (verifBullsVictoire() == true))
	{
		cout << "Felicitations ! Tu as trouve le mot cache : "<< MyHiddenWord << endl;
		cout << endl;
	}
	else
	{
		this->mVerif = gameStatut::ok;
		MyCurrentTry = MyCurrentTry + 1;
		cout << "Proposition valide" << endl;
		cout << "Bulls : " << Score.nbBulls << " / Cows : " << Score.nbCows << endl;

		if ((getMaxTries() - MyCurrentTry) == 0)
		{
			cout << "Vous n'avez plus d'essai disponible ! Merci d'avoir tente :)" << endl;
			cout << endl;
		}
		else
		{
			cout << "Vous avez encore " << getMaxTries() - MyCurrentTry << " essai(s)." << endl;
		}
	}

	
}

void BCClasse::setWordTry()
//BUT : Stocker la string entr�e par le joueur
//ENTREE : String entr�e par l'utilisateur pour tester un mot
//SORTIE : Stockage de son mot dans une string 
{
	cout << "Entrez votre mot :" << endl;
	cin >> PlayerWord;
}

string BCClasse::getWordTry() const
//BUT : Afficher la string entr�e par le joueur � ce tour
//ENTREE : String entr�e par l'utilisateur 
//SORTIE : Retourne la string entr�e par l'utilisateur
{
	return PlayerWord;
}

int BCClasse::getMaxTries() const
{
	std::map<int, int> WordLengthToMaxTries{ { 3,4 },{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int BCClasse::getCurrentTry() const
//BUT : Obtenir le tour actuel du joueur
//ENTREE : entier priv� pour le tour actuel
//SORTIE : entier retournant la valeur du tour actuel
{
	return MyCurrentTry;
}



BCClasse::~BCClasse()
{
}
