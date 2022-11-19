#ifndef WEEKCALC_H
#define WEEKCALC_H

int weekCalc();
static void initTabs(int tab_prog[], int tab_jour[], double reliq_jour_prog[], int nb_prog);
static int numberOfProg();
static void prog_implemant(int tab_prog[], int nb_prog);
static void numberOfDaysByProg(int nb_prog, int tab_prog[], int tab_jour[]);
static double moyWeek(int nb_prog, int tab_jour[], int tab_prog[], double reliq_jour_prog[]);

#endif
