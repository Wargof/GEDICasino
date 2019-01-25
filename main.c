#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Librairie pour la génération de nombres aléatoires

/*
   ### GEDICasino en C. Dev' by Wargof
*/
/*

Ce fichier abrite le code du GEDICasino, un jeu de roulette adapté.
Voici les règles : vous disposez de 1000 euros, vous misez une somme sur un nombre compris de 0 à 49, vous avez une chance sur 50 de gagner.
Si vous misez sur le bon numéro, vous gagnez 3 fois la mise.
Si vous avez la couleur (Rouge pair ou Noir impair) vous gagnez 50% de la mise.
*/

int main(int argc, char *argv[]) 
{
	srand(time(NULL)); // Initialisation de rand
	const int MIN = 1;
	const int MAX = 49;	
	int replay = 0;
	do {
		int nombreMystere = 0;
		int jouer = -1;
		int solde = 1000;

		printf("Voici les règles : \n");
		printf("- Vous disposez de 1000€, vous misez une somme sur un nombre compris entre 0 et 49, vous avez donc une chance sur 50 de gagner.\n");
		printf("- Si vous misez sur le bon numéro, vous gagnez 3 fois la mise.\n");
		printf("- Si vous avez la couleur ( Noir -> Pair et Blanc -> Impair ) vous gagnez la moitié de la mise.\n\n");
		printf("Voulez-vous jouer une partie ? Oui = 1, Non = 0.\n");
		scanf("%d", &jouer);	

		while(jouer < 0 || jouer > 1) {
				printf("\nErreur !\n\nVous devez taper uniquement 0 ou 1 !\n");
				printf("Voulez-vous jouer une partie ? Oui = 1, Non = 0.\n");
				scanf("%d", &jouer);	
		}

		if(jouer == 1) {
			while(jouer == 1) {
				while(solde >= 1 && jouer == 1) {
					nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
					printf("Sur quel nombre voulez-vous miser ? ( entre 0 et 49 ) \n");
					int miseNbr = 0;
					int miseEur = 0;
					scanf("%d", &miseNbr);
					while(miseNbr < 0 || miseNbr > 49){
						printf("\nErreur !\n\nVous devez choisir un nombre entre 0 et 49 uniquement !\n");
						scanf("%d", &miseNbr);
					}
					printf("\nVous avez miser sur le nombre %d !\n", miseNbr);
					printf("Combien voulez-vous miser ?\n");
					scanf("%d", &miseEur);
					while(solde < miseEur) {
						printf("\nErreur !\n\nVous ne disposez que de %d€ et vous tentez de miser %d€ !\n", solde, miseEur);
						printf("Votre mise maximal possible est de %d€ !\n", solde);
						printf("Combien voulez-vous miser ?\n");
						scanf("%d", &miseEur);
					}
					solde = solde - miseEur;
					printf("\nVous misez %d€, il vous reste donc %d€ sur votre solde.\n\n", miseEur, solde);
					printf("Le nombre mystère est le %d ! Le nombre que vous avez choisi était le %d !\n\n", nombreMystere, miseNbr);
					int pariteMise = miseNbr % 2;
					int pariteMyst = nombreMystere % 2;
					int gain = 0;
					// Si 'parite' = 0 -> pair sinon si = 1 -> impair //
					if(miseNbr == nombreMystere) {		// En cas de jackpot
						printf("Félicitation, vous avez gagner !\n");
						gain = miseEur * 3;
						printf("Vous avez remporter %d€ !\n\n", gain);
						solde = solde + gain;
					}
					else if(pariteMise == pariteMyst) {		// En cas de bonne couleur
						printf("Vous n'avez pas trouvé le bon nombre !\nCependant vous avez trouvé la bonne couleur, prenez ça comme un lot de consolation !\n");
						gain = miseEur / 2;
						solde = solde + gain;
						printf("La bonne couleur vous rapporte %d€ ! Votre solde est désormais de %d€ !\n\n", gain, solde);
					}
					else {
						printf("Dans l'histoire il y a toujours des perdants, vous êtes un perdant !\n\n");
					}
					if(solde <= 0) {
						printf("Vous êtes RUINÉ ! Rappelez-vous que c'est toujours le casino qui gagne !\n");
						printf("Désolé mais s'en est fini de votre partie ! :(\n\n\n");
						jouer = 0;
						printf("Voulez-vous réinitialiser le jeu ? Oui = 1, Quitter = 0\n");
						scanf("%d", &replay);
						if(replay == 1) {
							solde = 1000;
						}
						else {}
					}	
					else {			
						printf("Solde : %d€. Voulez-vous rejouer ? Oui = 1, Non = 0.\n", solde);
						scanf("%d", &jouer);
					}
				}
			}
		}
		else {
			printf("Dommage, vous ne savez pas ce que vous loupez !\n");
		}
	} while(replay == 1);
	return 0;
}
