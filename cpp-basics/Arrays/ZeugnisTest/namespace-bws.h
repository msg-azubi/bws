#ifndef NAMESPACEBWS_H
#define NAMESPACEBWS_H
#include<vector>
#include <string>


namespace bws {
    class Fach
    {
    private:
        int note;
        std::string name;
    public:
        Fach(std::string name, int note);
        std::string getName();
        int getNote();
    };


    namespace Zeugnis {

        int berechneNotedurchschnitt(std::vector<bws::Fach> faecher);
    }


    class Schueler
    {
    private:
        std::string vorname;
        std::string nachname;
        std::vector<Fach> bewertungen;
    public:
        Schueler(std::string vorname, std::string nachname, std::vector<Fach> bewertungen);
        std::string getVorname();
        std::string getNachname();
        std::vector<Fach>getBewertungen();
    };
}
#endif // NAMESPACEBWS_H
