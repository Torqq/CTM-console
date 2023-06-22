#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "core.h"
#include "calc.h"

int weekCalc()
{
	int error = 0;
	int i = 0;
	int nb_prog = numberOfProg();
		
	//malloc of needed tabs
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
	double* reliq_jour_prog = NULL;
	reliq_jour_prog = malloc(nb_prog * sizeof(double));
	if (reliq_jour_prog == NULL) {
		exit(0);
	}

	//prog algo
	if (nb_prog == 1) {
		system("cls");
		double moyenne_jour = 0;
		moyenne_jour = calc();
		if (moyenne_jour != false) {
			printf("\n\n\nLA MOYENNE DE TEMPERATURE EST DE %.2lf sur 24 heures de la journee.\n\n", moyenne_jour);
		}
	}

	else {
		system("cls");
		double moyenne_semaine = 0;
		initTabs(tab_prog, tab_jour, reliq_jour_prog, nb_prog);
		prog_implemant(tab_prog, nb_prog);
		system("cls");
		numberOfDaysByProg(nb_prog, tab_prog, tab_jour);
		for (i = 0; i < nb_prog; i++) {
			if (tab_jour[i] == 0) {
				error = 1;
			}
		}
		if (error == 0) {
			system("cls");
			moyenne_semaine = moyWeek(nb_prog, tab_jour, tab_prog, reliq_jour_prog);
			if (moyenne_semaine != false) {
				printf("\n\n\nLA MOYENNE DE TEMPERATURE : %.2lf pour 24 heures de la journee pour la semaine.\n\n", moyenne_semaine);
			}
		}
	}

	free(tab_prog);
	free(tab_jour);
	free(reliq_jour_prog);

	return 1;
}

static void initTabs(int tab_prog[], int tab_jour[], double reliq_jour_prog[], int nb_prog)
{
	int i = 0;
	for (i = 0; i < nb_prog; i++) {
		tab_prog[i] = 0;
		tab_jour[i] = 1;
		reliq_jour_prog[i] = 0;
	}
}

static int numberOfProg()
{
	//Demande à l'utilisateur combien y'a t'il de programmes différents dans la semaines.
	int prog = 0;
	printf("\n\n----------");
	printf("\nLe nombre de programmes differents correspond aux nombres de parametrages (plages horraires) similaires qui comprend un ou plusieurs jours.");
	printf("\nExemple : si un parametrage est effectuee du lundi au vendredi et un different est enregistre le week-end, alors il y a 2 programmes.");


	do {
		printf("\n\nCombiens de programmes differents y'a t'il dans la semaine : ");
		scanf_s("%d", &prog);

		if (prog > 7) {
			printf("\n\nDesole, il n'est pas possible d'avoir plus de programmes que de jours dans la semaines.\n");
		}
	} while (prog > 7);

	return prog;
}

static void prog_implemant(int tab_prog[], int nb_prog)
{
	int i = 0, num = 0;
	for (i = 0; i < nb_prog; i++) {
		num = num + 1;
		tab_prog[i] = tab_prog[i] + num;
	}
}

static void numberOfDaysByProg(int nb_prog, int tab_prog[], int tab_jour[])
{
	//Demande a l'utilisateur le nombre de jours qu'il y a par programme.
	int i = 0, j = 0;
	printf("\n\n----------");
	printf("\nLe nombre de jour par programme est le nombre de jour que le programme englobe.");
	printf("\nExemple : si un meme programme comprend du lundi au vendredi alors le nombre sera 5, un programme comprend le samedi et dimanche alors le nombre sera 2.");

	for (i = 0; i < nb_prog; i++) {
		do {
			for (j = 0; j < nb_prog; j++) {
				if (tab_jour[j] == 7 || tab_jour[j] == 0) {
					printf("\n\nUne erreur de saisie c'est produite, veuillez recommencer le programme avec les bonnes informations.\n");
					printf("Tip : Il n'est pas possible d'avoir 7 ou 0 jours dans un programme si vous avez declare 2 programmes minimum. Dans ce cas, declarez 1 programme.\n");
					tab_jour[i] = 0;
				}
			}
	
			if (tab_jour[i] > 7) {
				printf("\n\nIl n'est pas possible que le programme soit affectee a plus de 7 jours.\n");
			}

			if (tab_jour[i] > 7) {
				tab_jour[i] = 1;
			}

			if (tab_jour[i] == 1) {
				printf("\n\nCombien de jours le programme %d comprend : ", tab_prog[i]);
				scanf_s("%d", &tab_jour[i]);
			}

		} while (tab_jour[i] > 7);
	}
}


static double moyWeek(int nb_prog, int tab_jour[], int tab_prog[], double reliq_jour_prog[])
{
	int i = 0, j = 0;
	double moyenne = 0;
	double somme_moy_des_jours_par_prog = 0;

	for (i = 0; i < nb_prog; i++) {
		printf("\n\nProgramme No. %d : \n", tab_prog[i]);
		reliq_jour_prog[i] = calc(); //reliq = Souche d'un jour du programme.
	}

	for (j = 0; j < nb_prog; j++) {
		somme_moy_des_jours_par_prog = (reliq_jour_prog[j] * tab_jour[j]) + somme_moy_des_jours_par_prog;
	}

	moyenne = somme_moy_des_jours_par_prog / 7; // sommes de toutes les temprératures moyennes journaliers * nombres de jours du programmes / 7j de la semaines.

	return moyenne;
}
