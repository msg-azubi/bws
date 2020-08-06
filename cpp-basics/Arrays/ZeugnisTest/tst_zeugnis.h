#ifndef DEFINE_API_FUER_TST_ZEUGNIS_H
// Definition
// wird später Teil einer *.cpp Datei
#include "namespace-bws.h"

namespace bws {

    Fach::Fach(std::string name, int note){
        this->name = name;
        this->note = note;
    }
    std::string Fach::getName(){
        return this->name;

    }
    int         Fach::getNote(){
        return this->note;
    }

    Schueler::Schueler(std::string vorname, std::string nachname, std::vector<Fach> bewertungen){
        this->vorname = vorname;
        this->nachname = nachname;
        this->bewertungen = bewertungen;
    }

    std::string Schueler::getVorname(){
        return this->vorname;
    }
    std::string Schueler::getNachname(){
        return this->nachname;
    }
    std::vector<Fach>  Schueler::getBewertungen(){
        return this->bewertungen;
    }

    namespace Zeugnis {

        int berechneNotendurchschnitt(std::vector<bws::Fach> faecher){

            int result = 0;

            for (size_t i = 0; i < faecher.size(); i++ ){

                // Summiere die einzeln Noten auf:
                result += faecher.at(i).getNote();
            }
            return result / static_cast<int>( faecher.size() ) ;
        }

    }
} // end-of namespace bws
// end-of Definition
#endif // DEFINE_API_FUER_TST_ZEUGNIS_H

#ifndef TST_ZEUGNIS_H
#define TST_ZEUGNIS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>


using namespace testing;



TEST(bws, FachKonstruktor)
{
    using namespace std;
    using namespace bws;

    std::string testName = "Deutsch";
    int         testNote = 2;

    Fach testFach = Fach(testName, 2 );

    ASSERT_EQ(testFach.getName(), testName );
    ASSERT_EQ(testFach.getNote(), testNote );
}

TEST(bws, SchuelerKonstruktor)
{
    using namespace bws;
    std::string testVorname = "Anna";
    std::string testNachname = "Nachname";
    std::vector<Fach> testBewertungen {
            Fach("Deutsch", 2),
            Fach("Mathematik", 2),
            Fach("Reli", 4),
            Fach("Sport", 4)
        };
    // haben einen Durchschnitt
    int erwarteterDurchschnittDerTestBewertungen = 3;

    Schueler testSchueler = Schueler(testVorname, testNachname, testBewertungen);
    ASSERT_EQ(testSchueler.getVorname(),  testVorname);
    ASSERT_EQ(testSchueler.getNachname(), testNachname);
    // Der Test prüft:
    ASSERT_EQ(Zeugnis::berechneNotendurchschnitt(testSchueler.getBewertungen()),
              erwarteterDurchschnittDerTestBewertungen) ;
}


/*TEST(ArrayExample, ZeugnisDurchschnitt_ist_glatte_Note)
{
    // Die Noten von 4 Fächern als Vektor
    // Allgemein Infos zu Vektoren auf deutsch
    // * http://userpage.fu-berlin.de/~ram/pub/pub_jf47ht81Ht/c++_statische_vektoren_de
    std::vector<int> noten { 2, 2, 4, 4 };

    // haben einen Durchschnitt
    int erwarteterDurchschnitt = 3;

    // Der Test prüft:
    ASSERT_EQ(Zeugnis::berechneNotendurchschnitt(noten), erwarteterDurchschnitt) ;
}*/

#endif // TST_ZEUGNIS_H
