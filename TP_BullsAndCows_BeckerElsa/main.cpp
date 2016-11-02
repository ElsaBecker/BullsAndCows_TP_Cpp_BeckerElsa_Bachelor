#include "BCClasse.h"

#include <iostream>
#include <string>
#include <map>


using namespace std;



int main()
{
	//Variables
	BCClasse BCJeu;

	
	char CorQ = '@';
	int i = 0;

	//Une boucle pour rejouer	
		//Une boucle par nombre d'essais (tant que le current try pas egal au max try)
	

	cout << "Bienvenue dans le jeu Bulls and Cows" << endl;
	do 
	{
		cout << "Voulez-vous faire une partie, ou quitter ?" << endl;
		cout << "Entrez ""o"" pour jouer au jeu et ""n"" pour quitter l'application" << endl;
		cin >> CorQ;


		while (CorQ == 'o')
		{
			BCJeu.reinitGame();
			cout << "Le mot cache est un mot de 5 lettres" << endl;
			cout << "Vous avez " << BCJeu.getMaxTries() << " essai(s)." << endl;

			while ((BCJeu.getCurrentTry() < BCJeu.getMaxTries()) && (BCJeu.verifBullsVictoire() == false))
			{
				BCJeu.setWordTry();
				cout << "Vous avez entre : " << BCJeu.getWordTry() << endl;
				BCJeu.setBullsandCows();
				BCJeu.afficheStatut();
			}
			
			
			CorQ = '@';
		}
		
	} while (((CorQ != 'o') && (CorQ != 'n')));

	



	cout << "Merci, et a bientot !" << endl;


	system("pause");

	return 0;
}