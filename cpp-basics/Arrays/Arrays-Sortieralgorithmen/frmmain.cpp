#include "frmmain.h"
#include "ui_frmmain.h"
#include <QObject>
#include <QString>
#include <QTime>
#include <random>
#include <stdlib.h>
#include <QApplication>


// ----------------------------------------------------------------------------------------------
void arrayAnzeigen(datentyp *array,int anz, QListWidget* lwAnzeige) {
    lwAnzeige->clear();
    lwAnzeige->setVisible(false); //sonst kostet die Anzeige zu viel Rechenzeit!
    for (int i=0; i<=anz; i++) {
        lwAnzeige->addItem(QString::number(array[i]));
    }
    lwAnzeige->setVisible(true);
}


// ----------------------------------------------------------------------------------------------

FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmMain)  
{
    ui->setupUi(this);
    deaktiviereButtons();
    pflichtfeldHatSichVeraendert();

    ui->edtAnzahlElemente->setText(QString("1234"));
    connect( ui->edtAnzahlElemente, SIGNAL(textChanged() ), this, SLOT(pflichtfeldHatSichVeraendert()) );

}

FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::deaktiviereButtons()
{
    ui->btnArrayErzeugen->setEnabled(false);
}

void FrmMain::pflichtfeldHatSichVeraendert()
{



    QString anz = "54321";   // =  ui->edtAnzahlElemente->text();
    bool ok = anz > 0;

     ok = 1;

     ui->edtErsterWertGeaendert->setText(anz);
     ui->btnArrayErzeugen->setEnabled(ok);
}

void FrmMain::on_btnArrayErzeugen_clicked()
{
    // Welche Infos brauche ich hier?
    // a) Wieviele Elemente:
    const int  anzahlElemente = ui->edtAnzahlElemente->text().toUInt();
    const int groessteZufallszahl = ui->edtGroussteZufallszahl->text().toUInt();
    if(anzahlElemente && groessteZufallszahl > 1){

    }
    this->originArray = new datentyp[anzahlElemente];

    for (int i = 0; i < anzahlElemente; ++i) {
        originArray[i] = rand() % groessteZufallszahl;
    }

    arrayAnzeigen(this->originArray, anzahlElemente, ui->lwOriginal);
}
// -------------------------------------------------------------------------------------------

void bubbleSort(datentyp* feld, int anz) //aufsteigendes Sortieren
{
    datentyp tmp;
    for (int x=0; x < anz -1; x++) {
        for (int i=0; i < anz -1; i++) {
            if (feld[i] > feld[i+1]) {
                tmp = feld[i];
                feld[i] = feld[i+1];
                feld[i+1] = tmp;
            } //if
        } //for i
    } // for x
}


void FrmMain::on_btnBubbleSort_clicked()
{

    this->setCursor(Qt::WaitCursor);
    QTime time;
    const int  anzahlElemente = ui->edtAnzahlElemente->text().toUInt();

    datentyp* tmpArray = new datentyp[anzahlElemente];
    tmpArray = this->originArray;

    time.start();
    bubbleSort(tmpArray, anzahlElemente);
    ui->edtTimeBubbleSort->setText(QString::number(time.elapsed())+ " ms");
    arrayAnzeigen(tmpArray,anzahlElemente,ui->lwKopie);
    delete tmpArray;
    this->setCursor(Qt::ArrowCursor);

}

void FrmMain::on_btnBubbleSortOptim_clicked()
{

}

void FrmMain::on_btnSelectionSort_clicked()
{

}


