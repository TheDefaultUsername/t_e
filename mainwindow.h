#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QVector>
#include "cleanfileprovider.h"
#include "textcolorprovider.h"
#include "textworkprovider.h"

namespace Ui {
class MainWindow;
}

class TabInfoProvider {
    public:
    TabInfoProvider(): TEPointer(NULL), FileName(QString()), codecName(QString()), ShowedName(QString()) {}
        QTextEdit* TEPointer;
        QString FileName;
        QString codecName;
        QString ShowedName;
};

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QTabWidget* tabWidget;
    QVector<TabInfoProvider> tabs;
    QAction* actions[35];
    QMenu* menus[6];


    void setupUi(QMainWindow *MainWindow);

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool openTab(QString filename);
    void resizeEvent(QResizeEvent *);

public slots:
    void onOpenTriggered();
    void onOpenFastTriggered();
    void onNewTriggered();
    void onSaveTriggered();
    void onSaveAsTriggered();
    void onSetCodecTriggered();
    void onReadCodecTriggered();
    void onActBGColorTriggered();
    void onActTxColorTriggered();
    void onActTxBGColorTriggered();
    void onActTxABGColorTriggered();
    void onActIncreaseTriggered();
    void onActDecreaseTriggered();
    void onActSetFontTriggered();
    void onActTxColorLocalTriggered();
    void onActBoldTriggered(bool);
    void onActItalicTriggered(bool);
    void onActUnderlineTriggered(bool);
    void onActBoldLocalTriggered(bool);
    void onActItalicLocalTriggered(bool);
    void onActUnderlineLocalTriggered(bool);
    void closeTab(int index) {
        ui->tabs.remove(index);
        ui->tabWidget->removeTab(index);
    }


public:
    Ui::MainWindow *ui;
    CleanFileProvider Files;
    TextWorkProvider Texts;
    TextColorProvider Graph;
};

#endif // MAINWINDOW_H
