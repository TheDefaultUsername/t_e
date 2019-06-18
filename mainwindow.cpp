#include "mainwindow.h"
#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(closeTab(int)));
    //connect(this,ui->actions[0]->triggered(),this,onOpenTriggered());
}

void MainWindow::resizeEvent(QResizeEvent *e) {
    ui->tabWidget->resize(QSize(e->size().width(),e->size().height()-37));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::openTab(QString filename) {
    for (int i = 0; i<ui->tabs.size(); i++) {
        if (ui->tabs[i].FileName==filename) {return false;}
    }
    QTextEdit* tmpPtr = new QTextEdit(ui->tabWidget);
    QString FileNameBKP(filename);
    while (filename.lastIndexOf('/')>=0) {
        filename.remove(0,1);
    }
    while (filename.lastIndexOf('\\')>=0) {
        filename.remove(0,1);
    }
    tmpPtr->setObjectName(QString("tabWidget/%1/textEdit").arg(filename));
    ui->tabs.reserve(ui->tabs.size()+1);
    TabInfoProvider newTabInfo;
    ui->tabs.append(newTabInfo);
    ui->tabs.last().TEPointer=tmpPtr;
    ui->tabs.last().FileName=FileNameBKP;
    ui->tabs.last().ShowedName=filename;
    ui->tabWidget->addTab(tmpPtr,filename);
    return true;
}

void Ui_MainWindow::setupUi(QMainWindow *MainWindow)
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
    tabs.reserve(5);
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
    actions[1] = new QAction("Открыть быстро",MainWindow);
    actions[1]->setObjectName(QString::fromUtf8("OpenFast"));
    menus[0]->addAction(actions[0]);
    menus[0]->addAction(actions[1]);
    actions[3] = new QAction("Сохранить",MainWindow);
    actions[3]->setObjectName(QString::fromUtf8("Save"));
    menus[0]->addAction(actions[3]);
    actions[4] = new QAction("Сохранить как",MainWindow);
    actions[4]->setObjectName(QString::fromUtf8("SaveAs"));
    menus[0]->addAction(actions[4]);

    menus[1]= new QMenu("Шрифты",menuBar);
    menus[2]= new QMenu("Цвета", menuBar);
    menuBar->addAction(menus[1]->menuAction());
    menuBar->addAction(menus[2]->menuAction());
    actions[5]= new QAction("Фон",menus[2]);
    actions[5]->setObjectName(QString::fromUtf8("ActBGColor"));
    menus[2]->addAction(actions[5]);
    actions[6]= new QAction("Фон строки",menus[2]);
    actions[6]->setObjectName(QString::fromUtf8("ActTxBGColor"));
    menus[2]->addAction(actions[6]);
    actions[7]= new QAction("Текст",menus[2]);
    actions[7]->setObjectName(QString::fromUtf8("ActTxColor"));
    menus[2]->addAction(actions[7]);
    actions[8]= new QAction("Выделенный текст",menus[2]);
    actions[8]->setObjectName(QString::fromUtf8("ActTxColorLocal"));
    menus[2]->addAction(actions[8]);
    actions[9]= new QAction("Цвет выделения",menus[2]);
    actions[9]->setObjectName(QString::fromUtf8("ActTxABGColor"));
    menus[2]->addAction(actions[9]);

    actions[10]= new QAction("Увеличить",menus[1]);
    actions[10]->setObjectName(QString::fromUtf8("ActIncrease"));
    menus[1]->addAction(actions[10]);
    actions[11]= new QAction("Уменьшить",menus[1]);
    actions[11]->setObjectName(QString::fromUtf8("ActDecrease"));
    menus[1]->addAction(actions[11]);
    actions[13]= new QAction("Жирный",menus[1]);
    actions[13]->setObjectName(QString::fromUtf8("ActBold"));
    actions[13]->setFont(QFont("",10,QFont::Bold,false));
    actions[13]->setCheckable(true);
    menus[1]->addAction(actions[13]);
    actions[14]= new QAction("Курсив",menus[1]);
    actions[14]->setFont(QFont("",10,QFont::Thin,true));
    actions[14]->setObjectName(QString::fromUtf8("ActItalic"));
    actions[14]->setCheckable(true);
    menus[1]->addAction(actions[14]);
    actions[15]= new QAction("Подчеркнутый",menus[1]);
    {
        QFont font("",10,QFont::Thin,false);
        font.setUnderline(true);
        actions[15]->setFont(font);
    }
    actions[15]->setObjectName(QString::fromUtf8("ActUnderline"));
    actions[15]->setCheckable(true);
    menus[1]->addAction(actions[15]);
    actions[16]= new QAction("Зажирить",menus[1]);
    actions[16]->setObjectName(QString::fromUtf8("ActBoldLocal"));
    actions[16]->setFont(QFont("",10,QFont::Bold,false));
    actions[16]->setCheckable(true);
    menus[1]->addAction(actions[16]);
    actions[17]= new QAction("Наклонить",menus[1]);
    actions[17]->setFont(QFont("",10,QFont::Thin,true));
    actions[17]->setObjectName(QString::fromUtf8("ActItalicLocal"));
    actions[17]->setCheckable(true);
    menus[1]->addAction(actions[17]);
    actions[18]= new QAction("Подчеркнуть",menus[1]);
    {
        QFont font("",10,QFont::Thin,false);
        font.setUnderline(true);
        actions[18]->setFont(font);
    }
    actions[18]->setObjectName(QString::fromUtf8("ActUnderlineLocal"));
    actions[18]->setCheckable(true);
    menus[1]->addAction(actions[18]);
    actions[12]= new QAction("Установить",menus[1]);
    actions[12]->setObjectName(QString::fromUtf8("ActSetFont"));
    menus[1]->addAction(actions[12]);

    menus[3]= new QMenu("Кодировка",menuBar);
    menus[4]= new QMenu("Установить",menus[3]);
    menus[5]= new QMenu("Прочитать",menus[3]);
    menus[3]->addAction(menus[4]->menuAction());
    menus[3]->addAction(menus[5]->menuAction());

    actions[19] = new QAction("UTF-8",MainWindow);
    actions[19]->setObjectName(QString::fromUtf8("SetCodec"));
    menus[4]->addAction(actions[19]);
    actions[20] = new QAction("UTF-16",MainWindow);
    actions[20]->setObjectName(QString::fromUtf8("SetCodec"));
    menus[4]->addAction(actions[20]);
    actions[21] = new QAction("UTF-32",MainWindow);
    actions[21]->setObjectName(QString::fromUtf8("SetCodec"));
    menus[4]->addAction(actions[21]);
    actions[22] = new QAction("System",MainWindow);
    actions[22]->setObjectName(QString::fromUtf8("SetCodec"));
    menus[4]->addAction(actions[22]);
    actions[23] = new QAction("windows-1251",MainWindow);
    actions[23]->setObjectName(QString::fromUtf8("SetCodec"));
    menus[4]->addAction(actions[23]);
    actions[24] = new QAction("CP1251",MainWindow);
    actions[24]->setObjectName(QString::fromUtf8("SetCodec"));
    menus[4]->addAction(actions[24]);
    actions[25] = new QAction("KOI8-U",MainWindow);
    actions[25]->setObjectName(QString::fromUtf8("SetCodec"));
    menus[4]->addAction(actions[25]);
    actions[26] = new QAction("KOI8-RU",MainWindow);
    actions[26]->setObjectName(QString::fromUtf8("SetCodec"));
    menus[4]->addAction(actions[26]);

    actions[27] = new QAction("UTF-8",MainWindow);
    actions[27]->setObjectName(QString::fromUtf8("ReadCodec"));
    menus[5]->addAction(actions[27]);
    actions[28] = new QAction("UTF-16",MainWindow);
    actions[28]->setObjectName(QString::fromUtf8("ReadCodec"));
    menus[5]->addAction(actions[28]);
    actions[29] = new QAction("UTF-32",MainWindow);
    actions[29]->setObjectName(QString::fromUtf8("ReadCodec"));
    menus[5]->addAction(actions[29]);
    actions[30] = new QAction("System",MainWindow);
    actions[30]->setObjectName(QString::fromUtf8("ReadCodec"));
    menus[5]->addAction(actions[30]);
    actions[31] = new QAction("windows-1251",MainWindow);
    actions[31]->setObjectName(QString::fromUtf8("ReadCodec"));
    menus[5]->addAction(actions[31]);
    actions[32] = new QAction("CP1251",MainWindow);
    actions[32]->setObjectName(QString::fromUtf8("ReadCodec"));
    menus[5]->addAction(actions[32]);
    actions[33] = new QAction("KOI8-U",MainWindow);
    actions[33]->setObjectName(QString::fromUtf8("ReadCodec"));
    menus[5]->addAction(actions[33]);
    actions[34] = new QAction("KOI8-RU",MainWindow);
    actions[34]->setObjectName(QString::fromUtf8("ReadCodec"));
    menus[5]->addAction(actions[34]);

    menuBar->addAction(menus[3]->menuAction());

    MainWindow->setMenuBar(menuBar);

    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    MainWindow->setStatusBar(statusBar);

    retranslateUi(MainWindow);

    MainWindow::connect(actions[0],SIGNAL(triggered()),MainWindow,SLOT(onOpenTriggered()));
    MainWindow::connect(actions[1],SIGNAL(triggered()),MainWindow,SLOT(onOpenFastTriggered()));
    MainWindow::connect(actions[2],SIGNAL(triggered()),MainWindow,SLOT(onNewTriggered()));
    MainWindow::connect(actions[3],SIGNAL(triggered()),MainWindow,SLOT(onSaveTriggered()));
    MainWindow::connect(actions[4],SIGNAL(triggered()),MainWindow,SLOT(onSaveAsTriggered()));

    MainWindow::connect(actions[5],SIGNAL(triggered()),MainWindow,SLOT(onActBGColorTriggered()));
    MainWindow::connect(actions[7],SIGNAL(triggered()),MainWindow,SLOT(onActTxColorTriggered()));
    MainWindow::connect(actions[6],SIGNAL(triggered()),MainWindow,SLOT(onActTxBGColorTriggered()));
    MainWindow::connect(actions[9],SIGNAL(triggered()),MainWindow,SLOT(onActTxABGColorTriggered()));
    MainWindow::connect(actions[8],SIGNAL(triggered()),MainWindow,SLOT(onActTxColorLocalTriggered()));

    MainWindow::connect(actions[10],SIGNAL(triggered()),MainWindow,SLOT(onActIncreaseTriggered()));
    MainWindow::connect(actions[11],SIGNAL(triggered()),MainWindow,SLOT(onActDecreaseTriggered()));
    MainWindow::connect(actions[12],SIGNAL(triggered()),MainWindow,SLOT(onActSetFontTriggered()));
    MainWindow::connect(actions[13],SIGNAL(triggered(bool)),MainWindow,SLOT(onActBoldTriggered(bool)));
    MainWindow::connect(actions[14],SIGNAL(triggered(bool)),MainWindow,SLOT(onActItalicTriggered(bool)));
    MainWindow::connect(actions[15],SIGNAL(triggered(bool)),MainWindow,SLOT(onActUnderlineTriggered(bool)));
    MainWindow::connect(actions[16],SIGNAL(triggered(bool)),MainWindow,SLOT(onActBoldLocalTriggered(bool)));
    MainWindow::connect(actions[17],SIGNAL(triggered(bool)),MainWindow,SLOT(onActItalicLocalTriggered(bool)));
    MainWindow::connect(actions[18],SIGNAL(triggered(bool)),MainWindow,SLOT(onActUnderlineLocalTriggered(bool)));

    MainWindow::connect(actions[19],SIGNAL(triggered()),MainWindow,SLOT(onSetCodecTriggered()));
    MainWindow::connect(actions[20],SIGNAL(triggered()),MainWindow,SLOT(onSetCodecTriggered()));
    MainWindow::connect(actions[21],SIGNAL(triggered()),MainWindow,SLOT(onSetCodecTriggered()));
    MainWindow::connect(actions[22],SIGNAL(triggered()),MainWindow,SLOT(onSetCodecTriggered()));
    MainWindow::connect(actions[23],SIGNAL(triggered()),MainWindow,SLOT(onSetCodecTriggered()));
    MainWindow::connect(actions[24],SIGNAL(triggered()),MainWindow,SLOT(onSetCodecTriggered()));
    MainWindow::connect(actions[25],SIGNAL(triggered()),MainWindow,SLOT(onSetCodecTriggered()));
    MainWindow::connect(actions[26],SIGNAL(triggered()),MainWindow,SLOT(onSetCodecTriggered()));

    MainWindow::connect(actions[27],SIGNAL(triggered()),MainWindow,SLOT(onReadCodecTriggered()));
    MainWindow::connect(actions[28],SIGNAL(triggered()),MainWindow,SLOT(onReadCodecTriggered()));
    MainWindow::connect(actions[29],SIGNAL(triggered()),MainWindow,SLOT(onReadCodecTriggered()));
    MainWindow::connect(actions[30],SIGNAL(triggered()),MainWindow,SLOT(onReadCodecTriggered()));
    MainWindow::connect(actions[31],SIGNAL(triggered()),MainWindow,SLOT(onReadCodecTriggered()));
    MainWindow::connect(actions[32],SIGNAL(triggered()),MainWindow,SLOT(onReadCodecTriggered()));
    MainWindow::connect(actions[33],SIGNAL(triggered()),MainWindow,SLOT(onReadCodecTriggered()));
    MainWindow::connect(actions[34],SIGNAL(triggered()),MainWindow,SLOT(onReadCodecTriggered()));
} // setupUi

//SLOTS

void MainWindow::onOpenTriggered() {
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty()) {
        return;
    }
    if (!openTab(fileName)) {
        QMessageBox::warning(this,"ERROR","Файл уже открыт");
        return;
    }
    QByteArray input;
    bool isOk = Files.openFile(fileName, input);
    if (!isOk) {
        QMessageBox::warning(this,"ERROR","Не удалось открыть файл.");
        closeTab(ui->tabs.size()-1);
        return;
    }
    ui->tabs.last().TEPointer->append(QTextCodec::codecForName(QString("System").toLatin1())->toUnicode(input));
    ui->tabs.last().codecName=QString("System");
}
void MainWindow::onOpenFastTriggered() {
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty()) {
        return;
    }
    if (!openTab(fileName)) {
        QMessageBox::warning(this,"ERROR","Файл уже открыт");
        return;
    }
    QByteArray input;
    bool isOk = Files.openFile(fileName, input);
    if (!isOk) {
        QMessageBox::warning(this,"ERROR","Не удалось открыть файл.");
        closeTab(ui->tabs.size()-1);
        return;
    }
    ui->tabs.last().TEPointer->append(input);
    ui->tabs.last().codecName=QString("UTF-8");
}
void MainWindow::onNewTriggered() {
    bool flag = true;
    int i=1;
    while (flag) {
        for (int j = 0; j<ui->tabs.size(); j++) {
            if (ui->tabs[j].ShowedName==QString("new %1").arg(QString::number(i))) {
                flag = false;
            }
        }
        flag = !flag;
        if (flag) i++;
    }
    openTab(QString("new %1").arg(QString::number(i)));
    ui->tabs.last().codecName=QString("System");
    ui->tabs.last().FileName=QString();
}
void MainWindow::onSaveTriggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabs[pos].FileName.isEmpty()) {
        QMessageBox::warning(this,"ERROR","Вкладка не привязана к файлу.");
        return;
    }
    bool isOk = Files.saveFile(ui->tabs[pos].FileName,QTextCodec::codecForName(ui->tabs[pos].codecName.toLatin1())->fromUnicode(ui->tabs[pos].TEPointer->toPlainText()));
    if (!isOk) {
        QMessageBox::warning(this,"ERROR","Не удалось сохранить файл.");
        return;
    }
}
void MainWindow::onSaveAsTriggered() {
    int pos = ui->tabWidget->currentIndex();
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty()) {
        return;
    }
    bool isOk = Files.saveFile(fileName,QTextCodec::codecForName(ui->tabs[pos].codecName.toLatin1())->fromUnicode(ui->tabs[pos].TEPointer->toPlainText()));
    if (!isOk) {
        QMessageBox::warning(this,"ERROR","Не удалось сохранить файл.");
        return;
    }
    ui->tabs[pos].FileName=fileName;
    while (fileName.lastIndexOf('/')>=0) {
        fileName.remove(0,1);
    }
    while (fileName.lastIndexOf('\\')>=0) {
        fileName.remove(0,1);
    }
    ui->tabs[pos].ShowedName=fileName;
    ui->tabWidget->setTabText(pos,fileName);
}
void MainWindow::onSetCodecTriggered() {
    int pos = ui->tabWidget->currentIndex();
    ui->tabs[pos].codecName = reinterpret_cast<QAction*>(sender())->text();
}
void MainWindow::onReadCodecTriggered() {
    int pos = ui->tabWidget->currentIndex();
    Texts.reinterpretCodec(ui->tabs[pos].TEPointer, reinterpret_cast<QAction*>(sender())->text(),ui->tabs[pos].codecName);
    ui->tabs[pos].codecName=reinterpret_cast<QAction*>(sender())->text();
}
void MainWindow::onActBGColorTriggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QColor newBG = QColorDialog::getColor(QColor(255,255,255,255),this);
    Graph.setBGColor(ui->tabs[pos].TEPointer, newBG);
}
void MainWindow::onActTxColorTriggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QColor newTx = QColorDialog::getColor(QColor(255,255,255,255),this);
    Graph.setFontColor(ui->tabs[pos].TEPointer, newTx);
}
void MainWindow::onActTxColorLocalTriggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QColor newTx = QColorDialog::getColor(QColor(255,255,255,255),this);
    Graph.setFontColorLocal(ui->tabs[pos].TEPointer, newTx);
}
void MainWindow::onActTxBGColorTriggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QColor newTx = QColorDialog::getColor(QColor(255,255,255,255),this);
    Graph.setFontBGColor(ui->tabs[pos].TEPointer,newTx);
}
void MainWindow::onActTxABGColorTriggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QColor newHighLight = QColorDialog::getColor(QColor(255,255,255,255),this);
    Graph.setHihlightColor(ui->tabs[pos].TEPointer,newHighLight);
}
void MainWindow::onActIncreaseTriggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QFont font(
                ui->tabs[pos].TEPointer->font().family(),
                ui->tabs[pos].TEPointer->font().pointSize()+1,
                ui->tabs[pos].TEPointer->font().weight(),
                ui->tabs[pos].TEPointer->font().italic()
                );
    font.setUnderline(ui->tabs[pos].TEPointer->font().underline());
    ui->tabs[pos].TEPointer->setFont(font);
}
void MainWindow::onActDecreaseTriggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QFont font(
                ui->tabs[pos].TEPointer->font().family(),
                ui->tabs[pos].TEPointer->font().pointSize()-1,
                ui->tabs[pos].TEPointer->font().weight(),
                ui->tabs[pos].TEPointer->font().italic()
                );
    font.setUnderline(ui->tabs[pos].TEPointer->font().underline());
    ui->tabs[pos].TEPointer->setFont(font);
}
void MainWindow::onActSetFontTriggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    bool flag;
    QFont newFont = QFontDialog::getFont(&flag,this);
    if (!flag) return;
    Graph.setFontCustom(ui->tabs[pos].TEPointer, newFont);
}
void MainWindow::onActBoldTriggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setFontBold(ui->tabs[pos].TEPointer,flag);
}
void MainWindow::onActItalicTriggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setFontItalic(ui->tabs[pos].TEPointer,flag);
}
void MainWindow::onActUnderlineTriggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setFontUnderline(ui->tabs[pos].TEPointer,flag);
}
void MainWindow::onActBoldLocalTriggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setCursorBold(ui->tabs[pos].TEPointer,flag);
}
void MainWindow::onActItalicLocalTriggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setCursorItalic(ui->tabs[pos].TEPointer,flag);
}
void MainWindow::onActUnderlineLocalTriggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setCursorUnderline(ui->tabs[pos].TEPointer,flag);
}
