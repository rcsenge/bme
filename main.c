#include <math.h>
#include <stdio.h>

void feladat1();

double kob(double x);

double abs(double x);

void feladat2();

void feladat3();

void feladat4();

void feladat5();

void feladat6();

int adjHozza(int a);

int valtsElojelet(int a);

int szorozzKettovel(int a);

typedef struct Pont {
    double x, y;
} Pont;

Pont szamoljFelezopontot(Pont p1, Pont p2);

typedef struct Datum {
    int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir(Datum d);

void versenyzo_kiir(Versenyzo v);


int main(void) {
    feladat1();
    feladat2();
    feladat3();
    feladat4();
    feladat5();
    feladat6();
}

void feladat1(void) {
#include <stdio.h>
    double szamok[10] = {2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8};
    int negativIndexek[10];
    int negDb = 0;

    printf("Osszesen %d szam van.\n", 10);

    for (int i = 0; i < 10; ++i) {
        printf("[%d]=%g ", i, szamok[i]);


        if (szamok[i] < 0) {
            negativIndexek[negDb++] = i;
        }
    }
    printf("\n");

    printf("Ebbol %d szam negativ.\n", negDb);

    for (int i = 0; i < negDb; ++i) {
        int index = negativIndexek[i];
        printf("[%d]=%g ", index, szamok[index]);
    }
    printf("\n");
}

double kob(double x) {
    return x * x * x;
}

double abs(double x) {
    if (x < 0) {
        x *= -1;
    }
    return x;
}

void feladat2(void) {
    for (double i = -1; i < 1; i += 0.1) {
        printf("%.4lf, %.4lf, %.4lf, %.4lf \n", i, kob(i), abs(i), sin(i));
    }
}

void feladat3() {
    char c;

    while (scanf("%c", &c) != EOF && c != '\n') {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O') {
            printf("%cv%c", c, c);
        } else {
            printf("%c", c);
        }
        printf("\n");
    }
}

Pont szamoljFelezopontot(Pont p1, Pont p2) {
    Pont p3;
    p3.x = (p1.x + p2.x) / 2;
    p3.y = (p1.y + p2.y) / 2;

    return p3;
}

void feladat4() {
    Pont p1 = {2.2, 1.6};
    Pont p2;

    printf("Add meg az x koordinatajat egy pontnak! \n");
    scanf("%lf", &p2.x);

    printf("Add meg az y koordinatajat egy pontnak! \n");
    scanf("%lf", &p2.y);

    Pont p3 = szamoljFelezopontot(p1, p2);
    printf("(%g; %g)\n", p3.x, p3.y);
}

void feladat5() {
    Versenyzo versenyzok[5] = {
        {"Am Erika", {1984, 5, 6}, 1},
        {"Break Elek", {1982, 9, 30}, 3},
        {"Dil Emma", {1988, 8, 25}, 2},
        {"Kasza Blanka", {1979, 6, 10}, 5},
        {"Reset Elek", {1992, 4, 5}, 4},
    };

    printf("%s\n", versenyzok[0].nev);
    printf("%d\n", versenyzok[2].helyezes);
    datum_kiir(versenyzok[4].szuletes);
    printf("\n");

    char *nev = versenyzok[1].nev;
    printf("%c\n", nev[0]);

    char *szoveg;
    if (versenyzok[1].helyezes <= 3) {
        szoveg = "Dobogos";
    } else {
        szoveg = "Nem dobogos";
    }
    printf("%s\n", szoveg);

    if (versenyzok[3].helyezes < versenyzok[2].helyezes) {
        printf("A 3. versenyzo gyorsabb\n", szoveg);
    } else {
        printf("A 4. versenyzo gyorsabb\n", szoveg);
    }


    if (versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev) {
        printf("Ugyanabban az evben szulettek\n");
    } else {
        printf("Nem ugyanabban az evben szulettek\n");
    }

    versenyzo_kiir(versenyzok[1]);

    for (int i = 0; i < 5; ++i) {
        printf("Sorszam : %d\n", i);
        versenyzo_kiir(versenyzok[i]);
    }
}

void datum_kiir(Datum d) {
    printf("%d. %d. %d.", d.ev, d.ho, d.nap);
}

void versenyzo_kiir(Versenyzo v) {
    printf("Helyezes: %d \n", v.helyezes);
    printf("Nev: %s \n", v.nev);
    printf("Szuletesi datum: ");
    datum_kiir(v.szuletes);
    printf("\n");
}

void feladat6() {
    int a = 1;
    int opcio = 0;

    while (opcio != 9) {
        printf("0. Alapertek visszaallitasa (a = 1)\n"
            "1. Hozzaad 1-et\n"
            "2. Megforditja az elojelet\n"
            "3. Szorozza 2-vel\n"
            "9. Kilepes\n");
        scanf("%d", &opcio);
        switch (opcio) {
            case 0:
                a = 1;
                break;
            case 1:
                a = adjHozza(a);
                printf("%d \n", a);
                break;
            case 2:
                a = valtsElojelet(a);
                printf("%d \n", a);
                break;
            case 3:
                a = szorozzKettovel(a);
                printf("%d \n", a);
                break;
            case 9:
                return;
        }
    }
}

int adjHozza(int a) {
    return a + 1;
}

int valtsElojelet(int a) {
    return a * -1;
}

int szorozzKettovel(int a) {
    return a * 2;
}
