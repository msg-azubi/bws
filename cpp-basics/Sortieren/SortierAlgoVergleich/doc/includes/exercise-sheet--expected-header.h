// tag::declare-origArray[]
typedef int datentyp; // Datentyp des Arrays

datentyp* origArray;
// end::declare-origArray[]

//tag::define-uiHelper-arrayAnzeigen[]
void arrayAnzeigen(datentyp *array,int anz, QListWidget* lwAnzeige);
//end::define-uiHelper-arrayAnzeigen[]

//tag::define-algorithm-bubbleSort[]
void bubbleSort(datentyp *feld, int anz); //aufsteigendes Sortieren
//end::define-algorithm-bubbleSort[]


//tag::define-qt-slot-for-clicked-on-btnBubbelSort[]
void FrmMain::on_btnBubbleSort_clicked()
//tag::define-qt-slot-for-clicked-on-btnBubbelSort[]

