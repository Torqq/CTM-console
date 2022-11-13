#include <stdio.h>
#include <stdlib.h>
#include "calcul.h"

/* V 0.3.1 */

double calc()
{
    int tailleTab = 0;

    tailleTab = nombreData();
    calculation(tailleTab);

    return 1;
}

int nombreData()
{
    int taille = 0;
    printf("\nNombres de temperatures et plages d'heure differentes enregistree : ");
    scanf_s("%d", &taille);

    return taille;
}

double calculation(int tailleTab)
{
    //TEMP MEM ALLOC-------------------
    int i = 0;
    double moy = 0;
    double* valeurT = NULL;

    if (tailleTab > 0) {
        valeurT = malloc(tailleTab * sizeof(int));
        if (valeurT == NULL) {
            exit(0);
        }

        for (i = 0; i < tailleTab; i++) {
            printf("\nQuel est la temperature enregistree %d : ", i + 1);
            scanf_s("%lf", &valeurT[i]);
        }
    }

    //HOUR MEM ALLOC--------------------
    int j = 0;
    double* valeurH = NULL;

    if (tailleTab > 0) {
        valeurH = malloc(tailleTab * sizeof(double));
        if (valeurH == NULL) {
            exit(0);
        }

        for (j = 0; j < tailleTab; j++) {
            printf("\nQuel est le nombres d'heure de la plage %d liee a la temperature : ", j + 1);
            scanf_s("%lf", &valeurH[j]);
        }
    }

    //CALC------------------------------
    int k = 0;
    double add = 0;

    for (k = 0; k < tailleTab; k++) {
        add = (valeurH[k] * valeurT[k]);
        moy = add + moy;
    }

    free(valeurT);
    free(valeurH);

    moy = moy / 24;

    printf("\n\n\nLA MOYENNE DE TEMPERATURE EST DE %.2lf sur 24 heures de la journee.\n\n", moy);

    return 1;
}










/*

----------------------------------------------------------------------------- VERSION 0.3.0

double calc()
{
    int tailleTab = 0;

    tailleTab = nombreData();
    calculation(tailleTab);

    return 1;
}

int nombreData()
{
    int taille = 0;
    printf("\nNombres de temperatures et plages d'heure differentes enregistree : ");
    scanf_s("%d", &taille);

    return taille;
}

double calculation(int tailleTab)
{
    //TEMP MEM ALLOC-------------------
    int i = 0;
    double moy = 0;
    double* valeurT = NULL;

    if (tailleTab > 0) {
        valeurT = malloc(tailleTab * sizeof(int));
        if (valeurT == NULL) {
            exit(0);
        }

        for (i = 0; i < tailleTab; i++) {
            printf("\nQuel est la temperature enregistree %d : ", i + 1);
            scanf_s("%lf", &valeurT[i]);
        }
    }

    //HOUR MEM ALLOC--------------------
    int j = 0;
    double* valeurH = NULL;

    if (tailleTab > 0) {
        valeurH = malloc(tailleTab * sizeof(double));
        if (valeurH == NULL) {
            exit(0);
        }

        for (j = 0; j < tailleTab; j++) {
            printf("\nQuel est le nombres d'heure de la plage %d liee a la temperature : ", j + 1);
            scanf_s("%lf", &valeurH[j]);
        }
    }

    //CALC------------------------------
    int k = 0;
    double add = 0;

    for (k = 0; k < tailleTab; k++) {
        add = (valeurH[k] * valeurT[k]);
        moy = add + moy;
    }

    free(valeurT);
    free(valeurH);

    moy = moy / 24;

    printf("\n\n\nLA MOYENNE DE TEMPERATURE EST DE %.2lf sur 24 heures de la journee.\n\n", moy);

    return 1;
}
*/