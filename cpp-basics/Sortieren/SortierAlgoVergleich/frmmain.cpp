#include "frmmain.h"
#include "ui_frmmain.h"

//
#include <QTime>

// Konstuktor der Klasse
FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

// Dekonstruktor der Klasse
FrmMain::~FrmMain()
{
    delete ui;
}


void FrmMain::init(){
    // bereite eine Verbindung zwischen Signalen und Slots.
    // oder
    // bereite eine Verbindung zwischen den UI-Events und den Eventverarbeitern (_engl. handle)
    connectUiSignalsWithSlots();

    // bereite den Use Case "Array erzeugen" vor
    ui->edtAnzahlDerElemente->setText(QString("10000"));
    ui->edtGroessteZufallszahl->setText(QString("10000"));
    changedPflichtfeld(); // Solange der Konstruktor nicht beendet ist, muss changePflichtfeld()
                          // manuell aufgerufen werden. Später übernimmt das ein Signal
                          // siehe: connectUiSignalsWithSlots();

    // bereite den den Use Case "Array sortieren" vor

    resetTimerLabels();

    // deaktiviere was die UI bereits zeigt, aber noch nicht implementiert ist
    notYetImplemented();
}




void FrmMain::connectUiSignalsWithSlots()
{
/*
 *  Direkt Wert-Übergabe möglich
    connect(ui->edtAnzahlDerElemente, SIGNAL(textChanged(QString)),
            ui->edtInfo,   SLOT(setText(QString)));
 */
    connect( ui->edtAnzahlDerElemente, SIGNAL(textChanged(QString)),
             this, SLOT(changedPflichtfeld()));

    connect( ui->edtGroessteZufallszahl, SIGNAL(textChanged(QString)),
             this, SLOT(changedPflichtfeld()));

}



void FrmMain::changedPflichtfeld()
{
     QString edtAnzElemente  =  ui->edtAnzahlDerElemente->text();
     int    valueAnzElemente = edtAnzElemente.toInt();
     int    valueGroessteZufallszahl = ui->edtGroessteZufallszahl->text().toInt();

     bool ok =     !edtAnzElemente.isEmpty()
                && (valueAnzElemente > 0)
                && (valueAnzElemente <  std::numeric_limits<unsigned short>::max() )
                && (valueGroessteZufallszahl > 0 )
                && (valueGroessteZufallszahl < std::numeric_limits<unsigned short>::max()  )    ;
     ui->btnArrayErzeugen->setEnabled(ok);
     ui->edtInfo->clear();
     if (ok) {
        this->anzElemente = edtAnzElemente.toInt();
      }
      else {
        QString message = "Die Pflichtfelder 'Anzahl der Elemente' und 'Größte Zufallszahl' müssen jeweils einen Wert haben zwischen  0 und "
                // + QString::number( this->maxAnzElemente) ;
                  + QString::number(std::numeric_limits<unsigned short>::max());
                // + QString::number(INT_MAX);
        ui->edtInfo->setText(message);
     }

}



void FrmMain::notYetImplemented()
{

    // Array erzeugen
    ui->chkboxSortiert->setEnabled(false);
    ui->chkboxReihenfolgeInvertiert->setEnabled(false);
    ui->chkbxStartwertAendern->setEnabled(false);
    ui->edtStartwert->setEnabled(false);
    // SortAlgo
    ui->lwKopie->setEnabled(false);
    ui->btnBubbleSort->setEnabled(false);
    ui->btnBubbleSortOptm->setEnabled(false);
    ui->btnSelectionSort->setEnabled(false);
    ui->btnInsertSort->setEnabled(false);
    ui->btnQuickSort->setEnabled(false);
    ui->btnQuickSortGruening->setEnabled(false);

}


void FrmMain::resetTimerLabels()
{
    QString initTimerLabel = QString(" --- ms");
    ui->lblTimeBubbleSort->setText(initTimerLabel);
    ui->lblTimeBubbleSortOptm->setText(initTimerLabel);
    ui->lblTimeSelectionSort->setText(initTimerLabel);
    ui->lblTimeInsertSort->setText(initTimerLabel);
    ui->lblTimeQuickSortGruening->setText(initTimerLabel);
    ui->lblTimeQuickSort->setText(initTimerLabel);

}





//tag::define-qt-slot-for-clicked-on-btnArrayErzeugen[]
void FrmMain::on_btnArrayErzeugen_clicked()
{

    this->setCursor(Qt::WaitCursor);
    this->origArray = new datentyp[this->anzElemente];
    // get from ui
    int groessteZahl = ui->edtGroessteZufallszahl->text().toInt();
    // fill array
    for (int i = 0 ; i < this->anzElemente; i++) {
        origArray[i] = rand() % groessteZahl ;
    }

    uiHelper::arrayAnzeigen(this->origArray,this->anzElemente,ui->lwOrigArray );
    this->setCursor(Qt::ArrowCursor);



}
//end::define-qt-slot-for-clicked-on-btnArrayErzeugen[]O



//tag::define-qt-slot-for-clicked-on-btnBubbelSort[]
void FrmMain::on_btnBubbleSort_clicked()
{
    this->setCursor(Qt::WaitCursor);
    QTime time;
    datentyp* tmpArray = new datentyp[anzElemente];
    tmpArray = origArray;
    time.start();
    SortierAlgo::bubbleSort(tmpArray, anzElemente);
    ui->lblTimeBubbleSort->setText(QString::number(time.elapsed())+ " ms");
    uiHelper::arrayAnzeigen(tmpArray,anzElemente,ui->lwKopie);
    delete[] tmpArray;
    this->setCursor(Qt::ArrowCursor);
}
//end::define-qt-slot-for-clicked-on-btnBubbelSort[]


