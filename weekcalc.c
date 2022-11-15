#include <stdio.h>
#include <stdlib.h>
#include "weekcalc.h"
#include "calcul.h"

int weekCalc()
{
	int i = 0;
	int nb_prog = numberOfProg();
	int* tab_prog = NULL;
	tab_prog = malloc(nb_prog * sizeof(int));
	if (tab_prog == NULL) {
		exit(0);
	}
	int* tab_jour = NULL;
	tab_jour = malloc(nb_prog * sizeof(int));
	if (tab_jour == NULL) {
		exit(0);
	}

	initTabs(tab_prog, tab_jour, nb_prog);
	prog_implemant(tab_prog, nb_prog);
	numberOfDaysByProg(nb_prog, tab_prog, tab_jour);

	return 1;
}

void initTabs(int tab_prog[], int tab_jour[], int nb_prog)
{
	int i = 0;
	for (i = 0; i < nb_prog; i++) {
		tab_prog[i] = 0;
		tab_jour[i] = 0;
	}
}

int numberOfProg()
{
	//Demande à l'utilisateur combien y'a t'il de programmes différents dans la semaines.
	int prog = 0;
	printf("\n\n----------");
	printf("\nLe nombre de programmes differents correspond aux nombre de parametrages similaire qui comprend un ou plusieurs jours.");
	printf("\nExemple : si un parametrage est effectuee du lundi au vendredi et un different est enregistre le week-end, alors il y a 2 programmes.");


		printf("\n\nCombiens de programmes differents y'a t'il dans la semaine : ");
		scanf_s("%d", &prog);
	

	return prog;
}

void prog_implemant(int tab_prog[], int nb_prog)
{
	int i = 0, num = 0;
	for (i = 0; i < nb_prog; i++) {
		num = num + 1;
		tab_prog[i] = tab_prog[i] + num;
	}
}

void numberOfDaysByProg(int nb_prog, int tab_prog[], int tab_jour[])
{
	//Demande a l'utilisateur le nombre de jours qu'il y a par programme.
	int i = 0;
	printf("\n\n----------");
	printf("\nLe nombre de jour par programme est le nombre de jour que le programme englobe.");
	printf("\nExemple : si un meme programme comprend du lundi au vendredi alors le nombre sera 5, un programme comprend le samedi et dimanche alors le nombre sera 2.");
	
	for (i = 0; i < nb_prog; i++) {
		printf("\n\nCombien de jours le programme %d comprend : ", tab_prog[i]);
		scanf_s("%d", &tab_jour[i]);
	}
}
