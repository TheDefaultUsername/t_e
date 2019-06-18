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
    QVector<TabInfoProvider> Tabs;
    QAction* actions[35];
    QMenu* menus[6];


    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1280, 699));
        tabWidget->setTabsClosable(true);
        Tabs.reserve(5);
        MainWindow->setCentralWidget(centralWidget);

        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        menus[0]= new QMenu("Файл",menuBar);
        menuBar->addAction(menus[0]->menuAction());
        actions[2] = new QAction("Новый",MainWindow);
        actions[2]->setObjectName(QString::fromUtf8("New"));
        menus[0]->addAction(actions[2]);
        actions[0] = new QAction("Открыть",MainWindow);
        actions[0]->setObjectName(QString::fromUtf8("Open"));
        actions[33] = new QAction("Открыть быстро",MainWindow);
        actions[33]->setObjectName(QString::fromUtf8("OpenFast"));
        menus[0]->addAction(actions[0]);
        menus[0]->addAction(actions[33]);
        actions[1] = new QAction("Сохранить",MainWindow);
        actions[1]->setObjectName(QString::fromUtf8("Save"));
        menus[0]->addAction(actions[1]);
        actions[3] = new QAction("Сохранить как",MainWindow);
        actions[3]->setObjectName(QString::fromUtf8("SaveAs"));
        menus[0]->addAction(actions[3]);

        menus[1]= new QMenu("Шрифты",menuBar);
        menus[2]= new QMenu("Цвета", menuBar);
        menuBar->addAction(menus[1]->menuAction());
        menuBar->addAction(menus[2]->menuAction());
        actions[20]= new QAction("Фон",menus[2]);
        actions[20]->setObjectName(QString::fromUtf8("ActBGColor"));
        menus[2]->addAction(actions[20]);
        actions[22]= new QAction("Фон строки",menus[2]);
        actions[22]->setObjectName(QString::fromUtf8("ActTxBGColor"));
        menus[2]->addAction(actions[22]);
        actions[21]= new QAction("Текст",menus[2]);
        actions[21]->setObjectName(QString::fromUtf8("ActTxColor"));
        menus[2]->addAction(actions[21]);
        actions[34]= new QAction("Выделенный текст",menus[2]);
        actions[34]->setObjectName(QString::fromUtf8("ActTxColorLocal"));
        menus[2]->addAction(actions[34]);
        actions[32]= new QAction("Цвет выделения",menus[2]);
        actions[32]->setObjectName(QString::fromUtf8("ActTxABGColor"));
		menus[2]->addAction(actions[32]);

        actions[23]= new QAction("Увеличить",menus[1]);
        actions[23]->setObjectName(QString::fromUtf8("ActIncrease"));
        menus[1]->addAction(actions[23]);
        actions[24]= new QAction("Уменьшить",menus[1]);
        actions[24]->setObjectName(QString::fromUtf8("ActDecrease"));
        menus[1]->addAction(actions[24]);
        actions[26]= new QAction("Жирный",menus[1]);
        actions[26]->setObjectName(QString::fromUtf8("ActBold"));
        actions[26]->setFont(QFont("",10,QFont::Bold,false));
        actions[26]->setCheckable(true);
        menus[1]->addAction(actions[26]);
        actions[27]= new QAction("Курсив",menus[1]);
        actions[27]->setFont(QFont("",10,QFont::Thin,true));
        actions[27]->setObjectName(QString::fromUtf8("ActItalic"));
        actions[27]->setCheckable(true);
        menus[1]->addAction(actions[27]);
        actions[28]= new QAction("Подчеркнутый",menus[1]);
        {
            QFont font("",10,QFont::Thin,false);
            font.setUnderline(true);
            actions[28]->setFont(font);
        }
        actions[28]->setObjectName(QString::fromUtf8("ActUnderline"));
        actions[28]->setCheckable(true);
        menus[1]->addAction(actions[28]);
        actions[29]= new QAction("Зажирить",menus[1]);
        actions[29]->setObjectName(QString::fromUtf8("ActBoldLocal"));
        actions[29]->setFont(QFont("",10,QFont::Bold,false));
        actions[29]->setCheckable(true);
        menus[1]->addAction(actions[29]);
        actions[30]= new QAction("Наклонить",menus[1]);
        actions[30]->setFont(QFont("",10,QFont::Thin,true));
        actions[30]->setObjectName(QString::fromUtf8("ActItalicLocal"));
        actions[30]->setCheckable(true);
        menus[1]->addAction(actions[30]);
        actions[31]= new QAction("Подчеркнуть",menus[1]);
        {
            QFont font("",10,QFont::Thin,false);
            font.setUnderline(true);
            actions[31]->setFont(font);
        }
        actions[31]->setObjectName(QString::fromUtf8("ActUnderlineLocal"));
        actions[31]->setCheckable(true);
        menus[1]->addAction(actions[31]);
        actions[25]= new QAction("Установить",menus[1]);
        actions[25]->setObjectName(QString::fromUtf8("ActSetFont"));
        menus[1]->addAction(actions[25]);

        menus[3]= new QMenu("Кодировка",menuBar);
        menus[4]= new QMenu("Установить",menus[3]);
        menus[5]= new QMenu("Прочитать",menus[3]);
        menus[3]->addAction(menus[4]->menuAction());
        menus[3]->addAction(menus[5]->menuAction());

        actions[4] = new QAction("UTF-8",MainWindow);
        actions[4]->setObjectName(QString::fromUtf8("SetCodec"));
        menus[4]->addAction(actions[4]);
        actions[5] = new QAction("UTF-16",MainWindow);
        actions[5]->setObjectName(QString::fromUtf8("SetCodec"));
        menus[4]->addAction(actions[5]);
        actions[6] = new QAction("UTF-32",MainWindow);
        actions[6]->setObjectName(QString::fromUtf8("SetCodec"));
        menus[4]->addAction(actions[6]);
        actions[7] = new QAction("System",MainWindow);
        actions[7]->setObjectName(QString::fromUtf8("SetCodec"));
        menus[4]->addAction(actions[7]);
        actions[8] = new QAction("windows-1251",MainWindow);
        actions[8]->setObjectName(QString::fromUtf8("SetCodec"));
        menus[4]->addAction(actions[8]);
        actions[9] = new QAction("CP1251",MainWindow);
        actions[9]->setObjectName(QString::fromUtf8("SetCodec"));
        menus[4]->addAction(actions[9]);
        actions[10] = new QAction("KOI8-U",MainWindow);
        actions[10]->setObjectName(QString::fromUtf8("SetCodec"));
        menus[4]->addAction(actions[10]);
        actions[11] = new QAction("KOI8-RU",MainWindow);
        actions[11]->setObjectName(QString::fromUtf8("SetCodec"));
        menus[4]->addAction(actions[11]);

        actions[12] = new QAction("UTF-8",MainWindow);
        actions[12]->setObjectName(QString::fromUtf8("ReadCodec"));
        menus[5]->addAction(actions[12]);
        actions[13] = new QAction("UTF-16",MainWindow);
        actions[13]->setObjectName(QString::fromUtf8("ReadCodec"));
        menus[5]->addAction(actions[13]);
        actions[14] = new QAction("UTF-32",MainWindow);
        actions[14]->setObjectName(QString::fromUtf8("ReadCodec"));
        menus[5]->addAction(actions[14]);
        actions[15] = new QAction("System",MainWindow);
        actions[15]->setObjectName(QString::fromUtf8("ReadCodec"));
        menus[5]->addAction(actions[15]);
        actions[16] = new QAction("windows-1251",MainWindow);
        actions[16]->setObjectName(QString::fromUtf8("ReadCodec"));
        menus[5]->addAction(actions[16]);
        actions[17] = new QAction("CP1251",MainWindow);
        actions[17]->setObjectName(QString::fromUtf8("ReadCodec"));
        menus[5]->addAction(actions[17]);
        actions[18] = new QAction("KOI8-U",MainWindow);
        actions[18]->setObjectName(QString::fromUtf8("ReadCodec"));
        menus[5]->addAction(actions[18]);
        actions[19] = new QAction("KOI8-RU",MainWindow);
        actions[19]->setObjectName(QString::fromUtf8("ReadCodec"));
        menus[5]->addAction(actions[19]);

        menuBar->addAction(menus[3]->menuAction());

        MainWindow->setMenuBar(menuBar);

        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

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
    void on_Open_triggered();
    void on_OpenFast_triggered();
    void on_New_triggered();
    void on_Save_triggered();
    void on_SaveAs_triggered();
    void on_SetCodec_triggered();
    void on_ReadCodec_triggered();
    void on_ActBGColor_triggered();
    void on_ActTxColor_triggered();
    void on_ActTxBGColor_triggered();
    void on_ActTxABGColor_triggered();
    void on_ActIncrease_triggered();
    void on_ActDecrease_triggered();
    void on_ActSetFont_triggered();
    void on_ActTxColorLocal_triggered();
    void on_ActBold_triggered(bool);
    void on_ActItalic_triggered(bool);
    void on_ActUnderline_triggered(bool);
    void on_ActBoldLocal_triggered(bool);
    void on_ActItalicLocal_triggered(bool);
    void on_ActUnderlineLocal_triggered(bool);
    void closeTab(int index) {
        ui->Tabs.remove(index);
        ui->tabWidget->removeTab(index);
    }


public:
    Ui::MainWindow *ui;
    CleanFileProvider Files;
    TextWorkProvider Texts;
    TextColorProvider Graph;
};

#endif // MAINWINDOW_H
