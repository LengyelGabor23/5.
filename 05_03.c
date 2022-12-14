#include <stdio.h>
#include <stdlib.h>

int main() {

    double tomb[] = {289.5, 292.6, 295.5, 300.4, 300.3, 302.5, 303.3, 303.5, 299.9};
    int db = 0;
    int meret = sizeof(tomb) / sizeof(double);

    for (int i = 0; i < meret; i++) {
        printf("\n A(z) %d. elem: %.1lf", i, tomb[i]);
    }

    for (int i = 0; i < meret; i++) {
        if ( tomb[i] < 300 )
            db++;
    }

    printf("\nDarabszam 300 alatt: %d", db);

    int found = 0;

    for (int i = 1; i < ( meret && !found ); i += 1) {
        if (tomb[i] < tomb[i - 1])
            found = 1;
    }

    printf("\nA sorozat monoton novekvo: %s", found ? "igaz" : "hamis");

    int minindex = 0;
    for ( int i = 1; i < meret; i++) {
        if ( tomb[i] < tomb[minindex] )
            minindex = i;
    }

    printf("\nLegkisebb elem: %lf, sorszam: %d", tomb[minindex], minindex + 1);

    int maxindex = 0;
    for ( int i = 1; i < meret; i++) {
        if ( tomb[i] > tomb[maxindex] )
            maxindex = i;
    }

    printf("\nLegnagyobb elem: %lf, sorszam: %d", tomb[maxindex], maxindex + 1);

    double osszeg = 0;
    double atlag = 0;

    for (int i = 0; i < meret; i++) {
        osszeg += tomb[i];
    }

    atlag = osszeg / meret;

    printf("\nAz atlag: %.2lf", atlag);

    return 0;
}