// tag::declare-origArray[]
typedef int datentyp; // Datentyp des Arrays

datentyp* origArray;
// end::declare-origArray[]

//tag::define-uiHelper-arrayAnzeigen[]
void arrayAnzeigen(datentyp *array,int anz, QListWidget* lwAnzeige)
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
void bubbleSort(datentyp *feld, int anz) //aufsteigendes Sortieren
{
    datentyp *tmp;
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
    datentyp* tmpArray = new datentyp[anzElemente];
    tmpArray = origArray;
    time.start();
    bubbleSort(tmpArray, anzElemente);
    ui->lblZeitBubbleSort->setText(QString::number(time.elapsed())+ " ms");
    arrayAnzeigen(tmpArray,anzElemente,ui->lwKopie);
    delete tmpArray;
    this->setCursor(Qt::ArrowCursor);
}
//tag::define-qt-slot-for-clicked-on-btnBubbelSort[]

