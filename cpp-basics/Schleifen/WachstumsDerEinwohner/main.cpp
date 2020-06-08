#include<iostream>
#include<iomanip>



int main(int argc, char *argv[])
{


    double  indien=700;
    double china=990;

    double wachstumIndien=2.1;
    double wachstumChina=1.4;
    int    jahr=1987;
    int    jahrDesLetztenAusdrucks = 2050;

    do {

        std::cout << std::fixed << std::setprecision(3);
        std::cout << jahr << "\tIndien: \t " << indien  <<  " Mio. Einwohner" << std::endl;
        std::cout <<         "\tChina:  \t " << china   <<  " Mio. Einwohner" << std::endl;

        // Berechne Einwohnerzahlen
        indien = indien * ( 1 +  (wachstumIndien/100) );
        china =  china *  ( 1 +  (wachstumChina/100) );

        jahr = jahr + 1;

    // } while(jahr < jahrDesLetztenAusdrucks + 1 );
    } while (indien < china);



}
