namespace Zeugnis {

    int berechneDurchschnitt(int noten[]){
        return 6;   // Aktuell geht es darum, dass die API erfüllt wird.
                    // Die Deklaration sagt, das eine Zahl von Typ `int`
                    // als Rückgabewert erwartet wird.
    }

}

#ifndef TST_ZEUGNIS_H
#define TST_ZEUGNIS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>


using namespace testing;

TEST(ArrayExample, ZeugnisDurchschnitt_ist_glatte_Note)
{
    // Diese Noten von 4 Fächern
    int noten[] { 2, 2, 4, 4 };

    // haben einen Durchschnitt
    int erwarteterDurchschnitt = 3;

    // Der Test prüft:
    ASSERT_EQ(Zeugnis::berechneDurchschnitt(noten), erwarteterDurchschnitt) ;
}

#endif // TST_ZEUGNIS_H
