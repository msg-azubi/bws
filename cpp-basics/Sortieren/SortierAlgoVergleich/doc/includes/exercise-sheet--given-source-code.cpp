// tag::declare-origArray[]
typedef int datentyp; // Datentyp des Arrays

datentyp* origArray;
// end::declare-origArray[]

//tag::define-uiHelper-arrayAnzeigen[]
//tag::use-of-typdef-datentyp-as-parameter-type[]
void arrayAnzeigen(datentyp *array,int anz, QListWidget* lwAnzeige)
//end::use-of-typdef-datentyp-as-parameter-type[]
{
    lwAnzeige->clear();
    lwAnzeige->setVisible(false); //sonst kostet die Anzeige zu viel Rechenzeit!
    for (int i=0; i<=anz; i++) {
        lwAnzeige->addItem(QString::number(array[i]));
    }
    lwAnzeige->setVisible(true);
}
//end::define-uiHelper-arrayAnzeigen[]

//tag::define-algorithm-bubbleSort[]
//tag::use-of-typdef-datentyp-as-parameter-type[]
void bubbleSort(datentyp *feld, int anz) //aufsteigendes Sortieren
//end::use-of-typdef-datentyp-as-parameter-type[]
{
    // tag::use-of-typdef-datentyp-as-variable-type-in-function-bubbleSort[]
    datentyp *tmp;
    // end::use-of-typdef-datentyp-as-variable-type-in-function-bubbleSort[]
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

//tag::define-qt-slot-for-clicked-on-btnBubbelSort[]
void FrmMain::on_btnBubbleSort_clicked()
{
    this->setCursor(Qt::WaitCursor);
    QTime time;
    //tag::use-of-typdef-datentyp-as-variable-type-in-function-on_btnBubbleSort_clicked[]
    datentyp* tmpArray = new datentyp[anzElemente];
    //end::use-of-typdef-datentyp-as-variable-type-in-function-on_btnBubbleSort_clicked[]
    //tag::use-of-variable-origArray[]
    tmpArray = origArray;
    //end::use-of-variable-origArray[]
    time.start();
    bubbleSort(tmpArray, anzElemente);
    ui->lblZeitBubbleSort->setText(QString::number(time.elapsed())+ " ms");
    arrayAnzeigen(tmpArray,anzElemente,ui->lwKopie);
    delete tmpArray;
    this->setCursor(Qt::ArrowCursor);
}
//tag::define-qt-slot-for-clicked-on-btnBubbelSort[]

