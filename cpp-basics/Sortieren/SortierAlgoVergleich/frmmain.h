#ifndef FRMMAIN_H
#define FRMMAIN_H

#include "global.h"
#include "uihelper.h"
#include "sortieralgo.h"

#include <cstdlib>  // to use: rand() // Zufallsgenerator
#include <climits>  // to use: INT_MAX
// Qt Types
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

public slots:

    void on_btnArrayErzeugen_clicked();
    void on_btnBubbleSort_clicked();

    void changedPflichtfeld();
private:
    Ui::MainWindow *ui;

    int anzElemente;
    // tag::declare-var-origArray[]
    datentyp* origArray;
    // end::declare-var-originArray[]


    // tag::declare-init-methods[]
    void init();
    void connectUiSignalsWithSlots();
    void resetTimerLabels();
    void notYetImplemented();
    // end::declare-init-methods[]



};
#endif // FRMMAIN_H
