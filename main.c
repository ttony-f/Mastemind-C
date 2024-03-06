#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"
#include <time.h>
#include <conio.h>
#include <ctype.h>

#define CODICE_SIZE_MINI4 4
#define CODICE_SIZE_SUPER5 5
#define CODICE_SIZE_GIGANT6 6

#define ELEMENTI_SIZE_MINI4 6
#define ELEMENTI_SIZE_SUPER5 8
#define ELEMENTI_SIZE_GIGANT6 10

#define TENTATIVI_MINI4 10
#define TENTATIVI_SUPER5 12
#define TENTATIVI_GIGANT6 15

int main()
{
    char modalità;
    char tipo_elementi;
    char continua;
    bool scelta_modalità = false;
    bool scelta_elementi = false;
    do
    {
        printf("Seleziona Modalità di gioco:\n");
        printf("Mini4 (A) Super5(B) Gigant6 (C)\n");
        do
        {
            char arr[] = {'A', 'B', 'C'};
            int size = sizeof(arr);

            modalità = toupper(getch());
            if (modalità == 'A' || modalità == 'B' || modalità == 'C')
            {
                printf("%c \n", modalità);
                scelta_modalità = false;
            }
            else
            {
                scelta_modalità = true;
                // printf("Attenzione valore non valido! \n");
            }
        } while (scelta_modalità);

        printf("Seleziona Tipi di Elementi:\n");
        printf("Numeri(A) Lettere (B) \n");
        do
        {
            char arr[] = {'A', 'B'};
            int size = sizeof(arr);

            tipo_elementi = toupper(getch());
            if (tipo_elementi == 'A' || tipo_elementi == 'B')
            {
                printf("%c \n", tipo_elementi);
                scelta_elementi = false;
            }
            else
            {
                scelta_elementi = true;
                // printf("Attenzione valore non valido! \n");
            }

        } while (scelta_elementi);

        if (tipo_elementi == 'A')
        {

            if (modalità == 'A')
            {
                int codiceSegreto[CODICE_SIZE_MINI4];
                int elementi[ELEMENTI_SIZE_MINI4];
                int tentativo[CODICE_SIZE_MINI4];
                char risposta[CODICE_SIZE_MINI4];
                giocaNumeri(codiceSegreto, elementi, tentativo, risposta, TENTATIVI_MINI4, CODICE_SIZE_MINI4, ELEMENTI_SIZE_MINI4);
            }
            else if (modalità == 'B')
            {
                int codiceSegreto[CODICE_SIZE_SUPER5];
                int elementi[ELEMENTI_SIZE_SUPER5];
                int tentativo[CODICE_SIZE_SUPER5];
                char risposta[CODICE_SIZE_SUPER5];
                giocaNumeri(codiceSegreto, elementi, tentativo, risposta, TENTATIVI_SUPER5, CODICE_SIZE_SUPER5, ELEMENTI_SIZE_SUPER5);
            }
            else
            {
                int codiceSegreto[CODICE_SIZE_GIGANT6];
                int elementi[ELEMENTI_SIZE_GIGANT6];
                int tentativo[CODICE_SIZE_GIGANT6];
                char risposta[CODICE_SIZE_GIGANT6];
                giocaNumeri(codiceSegreto, elementi, tentativo, risposta, TENTATIVI_GIGANT6, CODICE_SIZE_GIGANT6, ELEMENTI_SIZE_GIGANT6);
            }
        }
        else if (tipo_elementi == 'B')
        {
            if (modalità == 'A')
            {
                char codiceSegreto[CODICE_SIZE_MINI4];
                char elementi[ELEMENTI_SIZE_MINI4];
                char tentativo[CODICE_SIZE_MINI4];
                char risposta[CODICE_SIZE_MINI4];
                gioca(codiceSegreto, elementi, tentativo, risposta, TENTATIVI_MINI4, CODICE_SIZE_MINI4, ELEMENTI_SIZE_MINI4);
            }
            else if (modalità == 'B')
            {
                char codiceSegreto[CODICE_SIZE_SUPER5];
                char elementi[ELEMENTI_SIZE_SUPER5];
                char tentativo[CODICE_SIZE_SUPER5];
                char risposta[CODICE_SIZE_SUPER5];
                gioca(codiceSegreto, elementi, tentativo, risposta, TENTATIVI_SUPER5, CODICE_SIZE_SUPER5, ELEMENTI_SIZE_SUPER5);
            }
            else
            {
                char codiceSegreto[CODICE_SIZE_GIGANT6];
                char elementi[ELEMENTI_SIZE_GIGANT6];
                char tentativo[CODICE_SIZE_GIGANT6];
                char risposta[CODICE_SIZE_GIGANT6];
                gioca(codiceSegreto, elementi, tentativo, risposta, TENTATIVI_GIGANT6, CODICE_SIZE_GIGANT6, ELEMENTI_SIZE_GIGANT6);
            }
        }
        bool bool_continua = false;

        printf("\nDerideri effettuare un'altra partita? Y/N \n");
        do
        {
           continua = toupper(getch());

            if ((continua == 'Y' || continua == 'N'))
            {
                printf("\n%c",continua);
            }

        } while (!(continua == 'Y' || continua == 'N'));
    } while (continua == 'Y');
    return 0;
}
