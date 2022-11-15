#ifndef WEEKCALC_H
#define WEEKCALC_H

int weekCalc();
void initTabs(int tab_prog[], int tab_jour[], int nb_prog);
int numberOfProg();
void prog_implemant(int tab_prog[], int nb_prog);
void numberOfDaysByProg(int nb_prog, int tab_prog[], int tab_jour[]);

#endif
