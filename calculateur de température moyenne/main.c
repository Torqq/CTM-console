#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// Test t1 = 17, t2 = 19, t3 = 21, h1 = 12.5, h2 = 3, h3 = 8.5;
int main()
{
    printf("-|- Biadan V. 0.3\n"); // Développement des jours de la semaine pour un enregistrement plus précis et plus adaptés par rapports aux personnes tiers.
    printf("CALCULATEUR DE TEMPERATURE MOYENNE\n\n\n");
    printf("Topo : Une plage d'horraire correspond au nombres d'heures concernee a une temperature.\nExemple : 3 heure de chauffe a 17 degree. La plage horraire sera de 3.\n");
    printf("\nATTENTION ! Bien mettre la plage horraire liee a la temperature dans le bon ordre. horraire 1 pour temperature 1.\n");
    printf("ATTENTION ! Bien mettre les plages horraire en valeur numerique.\n            Exemple : 8h30 -> 8.5.\n");

    double moy = 0;

    //TEMP MEM ALLOC-------------------
    int i = 0;
    int tailleT = 0;
    int *valeurT = NULL;

    printf("\nNombres de temperatures et plages d'heure differentes enregistree : ");
    scanf_s("%d", &tailleT);

    if (tailleT > 0) {
        valeurT = malloc(tailleT * sizeof(int));
        if (valeurT == NULL) { 
            exit(0);
        }

        for (i = 0; i < tailleT; i++) {
            printf("\nQuel est la temperature enregistree %d : ", i + 1);
            scanf_s("%d", &valeurT[i]);
        }
    }

    //HOUR MEM ALLOC--------------------
    int j = 0;
    double* valeurH = NULL;

    if (tailleT > 0) {
        valeurH = malloc(tailleT * sizeof(double));
        if (valeurH == NULL) {
            exit(0);
        }

        for (j = 0; j < tailleT; j++) {
            printf("\nQuel est le nombres d'heure de la plage %d liee a la temperature : ", j + 1);
            scanf_s("%lf", &valeurH[j]);
        }
    }

    //CALC------------------------------
    int k = 0;
    double add = 0;

    for (k = 0; k < tailleT; k++) {
        add = (valeurH[k] * valeurT[k]);
        moy = add + moy;
    }

    moy = moy / 24;

    printf("\n\n\nLA MOYENNE DE TEMPERATURE EST DE %.2lf sur 24 heures de la journee.\n\n", moy);

    free(valeurT);
    free(valeurH);

    return 0;
}