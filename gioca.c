#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funzioni.h"
#define MAX 100
bool includes(char arr[], char target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}
bool includesInt(int arr[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}
void gioca(char codice[], char elementi[], char tentativo[], char risposta[], int tentativi, int size_codice, int size_elementi)
{
    // creo il codice segreto e gli elementi
    int decimal_start = 65; // decimale che indica la lettera A;
    char elemento;
    int num_el_corr = 0;
    char string_el[MAX] = "[";
    char string_cod[MAX] = "[";
    for (int i = 0; i < size_elementi; i++)
    {
        elementi[i] = (char)65 + i;
    }

    srand(time(NULL));
    for (int i = 0; i < size_codice; i++)
    {
        int random = rand() % (size_elementi - 0 + 1) + 0; // funzione per numero random tra due estremi (max-min+1)-min
        codice[i] = elementi[random];
    }
    for (int i = 0; i < size_codice; i++)
    {
        char cod[] = {codice[i], '\0'};
        strcat(string_cod, cod);
        if (i != (size_codice - 1))
        {
            strcat(string_cod, "-");
        }
    }
    strcat(string_cod, "] \n");
    // printf("Codice Segreto: %s", string_cod);

    for (int i = 0; i < size_elementi; i++)
    {
        char el[] = {elementi[i], '\0'};
        strcat(string_el, el);
        if (i != (size_elementi - 1))
        {
            strcat(string_el, "-");
        }
    }
    strcat(string_el, "] \n");

    int ntentativo = 0;
    // loop di tentativi
    do
    {

        bool vittoria = false;
        printf("Tentativo numero %d di %d Elementi %s", ntentativo + 1, tentativi, string_el);
        for (int i = 0; i < size_codice; i++)
        {
            do
            {
                tentativo[i] = toupper(getch());
                if (includes(elementi, tentativo[i], size_elementi))
                {
                    printf("%c", tentativo[i]);
                    if (i < size_codice - 1)
                    {
                        printf("-"); // Stampa un trattino tra i caratteri
                    }
                }
            } while (includes(elementi, tentativo[i], size_elementi) == false);
        }
        num_el_corr = 0;
        for (int i = 0; i < size_codice; i++)
        {
            if (codice[i] == tentativo[i])
            {
                risposta[i] = 'N';
                num_el_corr += 1;
            }
            else
            {

                bool incl = includes(codice, tentativo[i], size_codice);
                if (incl)
                {
                    risposta[i] = 'B';
                }
                else
                {
                    risposta[i] = ' ';
                }
            }
            if (num_el_corr == size_codice)
            {
                printf("\nVittoria!");
                printf("\nCodice Segreto: %s", string_cod);
                return;
            }
        }
        printf("\nTentativo: [");
        for (int i = 0; i < size_codice; i++)
        {
            printf("%c", tentativo[i]);
            if (i != (size_codice - 1))
            {
                printf("-");
            }
        }
        printf("]");
        printf(" Risposta: [");

        for (int i = 0; i < size_codice; i++)
        {
            printf("%c", risposta[i]);
            if (i != (size_codice - 1))
            {
                printf("-");
            }
        }
        printf("] \n");

        for (int i = 0; i < size_codice; i++)
        {
            risposta[i] = ' ';
        }

        ntentativo++;
    } while (ntentativo < tentativi);

    printf("\nSconfitta!");
    printf("\nCodice Segreto: %s", string_cod);
}

void giocaNumeri(int codice[], int elementi[], int tentativo[], char risposta[], int tentativi, int size_codice, int size_elementi)
{
    // creo il codice segreto e gli elementi
    int elemento;
    int num_el_corr = 0;
    char string_el[MAX] = "[";
    char string_cod[MAX] = "[";
    for (int i = 0; i < size_elementi; i++)
    {
        elementi[i] = i ;
    }

    srand(time(NULL));
    for (int i = 0; i < size_codice; i++)
    {
        int random = rand() % (size_elementi - 0 + 1) + 0; // funzione per numero random tra due estremi (max-min+1)-min
        codice[i] = elementi[random];
    }
    for (int i = 0; i < size_codice; i++)
    {
        char cod[2];

        char c = codice[i] + '0';
        cod[0] = c;

        strcat(string_cod, cod);
        if (i != (size_codice - 1))
        {
            strcat(string_cod, "-");
        }
    }
    strcat(string_cod, "] \n");
    // printf("Codice Segreto: %s", string_cod);

    for (int i = 0; i < size_elementi; i++)
    {
        char cod[2];

        char c = elementi[i] + '0';
        cod[0] = c;

        strcat(string_el, cod);
        if (i != (size_elementi - 1))
        {
            strcat(string_el, "-");
        }
    }
    strcat(string_el, "] \n");

    int ntentativo = 0;
    // loop di tentativi
    do
    {

        bool vittoria = false;
        printf("Tentativo numero %d di %d Elementi %s", ntentativo + 1, tentativi, string_el);

        for (int i = 0; i < size_codice; i++)
        {
            do
            {
                tentativo[i] = getch() - '0';
                if (includesInt(elementi, tentativo[i], size_elementi))
                {
                    printf("%d", tentativo[i]);
                    if (i < size_codice - 1)
                    {
                        printf("-"); // Stampa un trattino tra i caratteri
                    }
                }

            } while (includesInt(elementi, tentativo[i], size_elementi) == false);
        }
        num_el_corr = 0;
        for (int i = 0; i < size_codice; i++)
        {
            if (codice[i] == tentativo[i])
            {
                risposta[i] = 'N';
                num_el_corr += 1;
            }
            else
            {

                bool incl = includesInt(codice, tentativo[i], size_codice);
                if (incl)
                {
                    risposta[i] = 'B';
                }
                else
                {
                    risposta[i] = ' ';
                }
            }
            if (num_el_corr == size_codice)
            {
                printf("\nVittoria!");
                printf("\nCodice Segreto: %s", string_cod);
                return;
            }
        }
        printf("\nTentativo: [");
        for (int i = 0; i < size_codice; i++)
        {
            printf("%d", tentativo[i]);
            if (i != (size_codice - 1))
            {
                printf("-");
            }
        }
        printf("]");
        printf(" Risposta: [");

        for (int i = 0; i < size_codice; i++)
        {
            printf("%c", risposta[i]);
            if (i != (size_codice - 1))
            {
                printf("-");
            }
        }
        printf("] \n");

        for (int i = 0; i < size_codice; i++)
        {
            risposta[i] = ' ';
        }

        ntentativo++;
    } while (ntentativo < tentativi);

    printf("\nSconfitta!");
    printf("\nCodice Segreto: %s", string_cod);
}
