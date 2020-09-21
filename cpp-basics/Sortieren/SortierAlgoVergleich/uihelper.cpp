#include  "uihelper.h"

//tag::define-uiHelper-arrayAnzeigen[]
void uiHelper::arrayAnzeigen(datentyp *array, int anz, QListWidget* lwAnzeige)
{
    lwAnzeige->clear();
    lwAnzeige->setVisible(false); //sonst kostet die Anzeige zu viel Rechenzeit!
    for (int i=0; i<anz; i++) {
        lwAnzeige->addItem(QString::number(array[i]));
    }
    lwAnzeige->setVisible(true);
}
//end::define-uiHelper-arrayAnzeigen[]
