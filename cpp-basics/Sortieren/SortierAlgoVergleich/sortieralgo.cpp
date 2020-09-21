#include "sortieralgo.h"

//tag::define-algorithm-bubbleSort[]
void SortierAlgo::bubbleSort(datentyp* feld, int anz) //aufsteigendes Sortieren
{
    datentyp tmp;
    for (int x=0; x<anz-1; x++) {
        for (int i=0; i<=anz-1; i++) {
            if (feld[i]<feld[i+1]) {
                tmp = feld[i];
                feld[i+1] = feld[i];
                feld[i+1] = tmp;
            } //if
        } //for i
    } // for x
}
//end::define-algorithm-bubbleSort[]
