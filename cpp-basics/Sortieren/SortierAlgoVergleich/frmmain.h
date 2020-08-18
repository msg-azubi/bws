#ifndef FRMMAIN_H
#define FRMMAIN_H

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

    void on_btnBubbleSort_clicked();
    void resetTimerLabels();

private:
    Ui::MainWindow *ui;
};
#endif // FRMMAIN_H
