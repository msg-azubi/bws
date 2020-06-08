#ifndef DEFINE_API_FUER_TST_ZEUGNIS_H
namespace Zeugnis {

    int berechneDurchschnitt(int noten[], int notenAnzahl){
        // C++ Passing Arrays to Functions
        // https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm

        int result = 0;

        for (int i = 0; i < notenAnzahl; i++ ){

            // Summiere die einzeln Noten auf:
            result += noten[i];
        }
        return result / notenAnzahl ;
    }

}
#endif // DEFINE_API_FUER_TST_ZEUGNIS_H

#ifndef TST_ZEUGNIS_H
#define TST_ZEUGNIS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>


using namespace testing;

TEST(ArrayExample, ZeugnisDurchschnitt_ist_glatte_Note)
{
    // Diese Noten von 4 Fächern
    int notenAnzahl =  4;
    int noten[] { 2, 2, 4, 4 };

    // haben einen Durchschnitt
    int erwarteterDurchschnitt = 3;

    // Der Test prüft:
    ASSERT_EQ(Zeugnis::berechneDurchschnitt(noten, notenAnzahl), erwarteterDurchschnitt) ;
}

#endif // TST_ZEUGNIS_H
