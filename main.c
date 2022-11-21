#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "main.h"
#include "core.h"

/*-----TO DO : Core finality ! V.0.5 !
* Demande de sauvegarde des données en fichier.txt.
* Faire des boucles pour ne pas que l'utilisateur rentre des données superflux.
* 
*/

int main()
{
	printf("                                 -                  -                                               \n");
	printf("--------------------------------  --------*---------  ----------------------------------------------\n");
	printf("---------------          --------     ---------      --------      ----------      -----------------\n");
	printf("-------------       ---     -------               ----------        --------        ----------------\n");
	printf("------------      ----------------------     --------------     *    ------     *    ---------------\n");
	printf("-----------      --------*--------------     -------------     ---    ----     ---    --------------\n");
	printf("------------      ----------------------     ------------     -----    --    ------    -------------\n");
	printf("-------------       ---     ------------     -----------     -------        --------    ------------\n");
	printf("---------------         -----------------   -----------        ------      -------       -----------\n");
	printf("------------------------------------------ ---------------------------------------------------------\n");

	int replay = true;

	do {
		unsigned int blk = 2;
	    printf("-|- Biadan V. 0.4.2\n"); // Développement des jours de la semaine pour un enregistrement plus précis et plus adaptés par rapports aux personnes tiers.
        printf("CALCULATEUR DE TEMPERATURE MOYENNE\n");

		weekCalc();

		do {
			viderBuffer();
			printf("\n\nAvez-vous besoin de relancer le programme ? [o/n] : ");
			blk = choice();
		} while (blk == 2);

		replay = blk;
	} while (replay == true);

    return EXIT_SUCCESS;
}

int choice()
{
	int commut = 0;
	char lettre = 0;
	lettre = entered_caracter();
	switch (lettre) {
	case 'O': commut = true;
		break;
	case 'N': commut = false;
		break;
	default : commut = 2;
		break;
	}
	
	return commut;
}

char entered_caracter()
{
	char caractere = 0;
	
	caractere = getchar();
	caractere = toupper(caractere);
	while (getchar() != '\n');

	return caractere;
}

void viderBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}


