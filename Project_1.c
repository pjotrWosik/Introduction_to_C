#include <stdio.h>
#include <math.h>
#include <string.h>

float dodaj(float liczba1, float liczba2) {return liczba1 + liczba2;}
float odejmij(float liczba1, float liczba2) {return liczba1 - liczba2;}
float pomnurz(float liczba1, float liczba2) {return liczba1 * liczba2;}
float podziel(float liczba1, float liczba2) {
    if (liczba2 == 0) {printf("Niema Pierwiastka z ujemnej!\n"); return 0;}
    return liczba1 / liczba2;
}
float poteguj(float liczba1, float liczba2) {return pow(liczba1, liczba2);}
float pierwiastkuj(float liczba1, float liczba2) {
    if (liczba1 < 0) {printf("niema pierwiastka z ujemnej!\n"); return 0;}
    return sqrt(liczba1);
}

float (*operacje[])(float, float) = {dodaj, odejmij, pomnurz, podziel, poteguj, pierwiastkuj};

char historia[100][256];
int ile = 0;
void dodaj_do_historii(char* text) {
    if (ile < 100) {
        strcpy(historia[ile], text);
        ile++;
    } else {
        printf("historia jest pelna!\n");
    }
}

void pokarz_historie() {
    if (ile == 0) {
        printf("historia jest pusta!\n");
        return;
    }
    printf("[-----------historia------------]\n");
    for (int i = 0; i < ile; i++) {
        printf("%2d. %s\n", i+1, historia[i]);
    }
    printf("[-------------------------------]\n");

}

int main(void) {

    float liczba1, liczba2;
    int wybur;
    char linijka[256];

    while(1) {
        printf("[------------------------------]\n"
            "menu: \n"
            "    1 - dodawanie\n"
            "    2 - odejmowanie\n"
            "    3 - mnorzenie\n"
            "    4 - dzielenie\n"
            "    5 - potegowanie\n"
            "    6 - pierwiastkowanie (tylko pierwsza liczba sie liczy)\n"
            "    7 - historia\n"
            "    8 - zakoncz program\n"
            "[------------------------------]\n"
            "podaj swuj wybur: \n"
            );

        scanf("%d", &wybur);

        if (wybur == 8) {
            printf("rzycze milego dzionka\n");
            break;
        }

        if (wybur == 7) {
            pokarz_historie();
            continue;
        }

        if (wybur < 1 || wybur > 6) {
            printf("Niema takiej opcji popraw sie!\n");
            continue;
        }

        printf("Podaj pierwsza liczbe: \n");
        scanf("%f", &liczba1);
        printf("Podaj druga liczbe: \n");
        scanf("%f", &liczba2);

        float wynik = operacje[wybur - 1](liczba1, liczba2);
        printf("wynik = %f", wynik);

        if (wybur == 1)      sprintf(linijka, "%.6g + %.6g = %.6g", liczba1, liczba2, wynik);
        else if (wybur == 2) sprintf(linijka, "%.6g - %.6g = %.6g", liczba1, liczba2, wynik);
        else if (wybur == 3) sprintf(linijka, "%.6g * %.6g = %.6g", liczba1, liczba2, wynik);
        else if (wybur == 4) sprintf(linijka, "%.6g / %.6g = %.6g", liczba1, liczba2, wynik);
        else if (wybur == 5) sprintf(linijka, "%.6g ^ %.6g = %.6g", liczba1, liczba2, wynik);
        else if (wybur == 6) sprintf(linijka, "pierwiastkuj(%.6g) = %.6g", liczba1, wynik);

        dodaj_do_historii(linijka);

    }
    return 0;
}
