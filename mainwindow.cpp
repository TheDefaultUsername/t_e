#include "mainwindow.h"
#include "textcolorprovider.h"
#include "textworkprovider.h"
#include "fileworkprovider.h"
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
}

void MainWindow::resizeEvent(QResizeEvent *e) {
    ui->tabWidget->resize(QSize(e->size().width(),e->size().height()-37));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::openTab(QString filename) {
    for (int i = 0; i<ui->Tabs.size(); i++) {
        if (ui->Tabs[i].FileName==filename) {return false;}
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
    ui->Tabs.reserve(ui->Tabs.size()+1);
    TabInfoProvider newTabInfo;
    ui->Tabs.append(newTabInfo);
    ui->Tabs.last().TEPointer=tmpPtr;
    ui->Tabs.last().FileName=FileNameBKP;
    ui->Tabs.last().ShowedName=filename;
    ui->tabWidget->addTab(tmpPtr,filename);
    return true;
}

//SLOTS

void MainWindow::on_Open_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty()) {return;}
    if (!openTab(fileName)) {QMessageBox::warning(this,"ERROR","Файл уже открыт"); return;}
    if(!Files.openFile(fileName,QString("System"),ui->Tabs.last().TEPointer)) {QMessageBox::warning(this,"ERROR","Не удалось открыть файл."); closeTab(ui->Tabs.size()-1); return;}
    ui->Tabs.last().codecName=QString("System");
}
void MainWindow::on_OpenFast_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty()) {return;}
    if (!openTab(fileName)) {QMessageBox::warning(this,"ERROR","Файл уже открыт"); return;}
    if(!Files.openFile(fileName,QString(),ui->Tabs.last().TEPointer)) {QMessageBox::warning(this,"ERROR","Не удалось открыть файл."); closeTab(ui->Tabs.size()-1); return;}
    ui->Tabs.last().codecName=QString("UTF-8");
}
void MainWindow::on_New_triggered() {
    bool flag = true;
    int i=1;
    while (flag) {
        for (int j = 0; j<ui->Tabs.size(); j++) {
            if (ui->Tabs[j].ShowedName==QString("new %1").arg(QString::number(i))) {
                flag = false;
            }
        }
        flag = !flag;
        if (flag) i++;
    }
    openTab(QString("new %1").arg(QString::number(i)));
    ui->Tabs.last().codecName=QString("System");
    ui->Tabs.last().FileName=QString();
}
void MainWindow::on_Save_triggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->Tabs[pos].FileName.isEmpty()) {QMessageBox::warning(this,"ERROR","Вкладка не привязана к файлу."); return;}
    if(!Files.saveFile(ui->Tabs[pos].FileName,ui->Tabs[pos].codecName, ui->Tabs[pos].TEPointer)) {QMessageBox::warning(this,"ERROR","Не удалось сохранить файл.");}
}
void MainWindow::on_SaveAs_triggered() {
    int pos = ui->tabWidget->currentIndex();
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty()) {return;}
    if(!Files.saveFile(fileName,ui->Tabs[pos].codecName, ui->Tabs[pos].TEPointer)) {QMessageBox::warning(this,"ERROR","Не удалось сохранить файл."); return;}
    ui->Tabs[pos].FileName=fileName;
    while (fileName.lastIndexOf('/')>=0) {
        fileName.remove(0,1);
    }
    while (fileName.lastIndexOf('\\')>=0) {
        fileName.remove(0,1);
    }
    ui->Tabs[pos].ShowedName=fileName;
    ui->tabWidget->setTabText(pos,fileName);
}
void MainWindow::on_SetCodec_triggered() {
    int pos = ui->tabWidget->currentIndex();
    ui->Tabs[pos].codecName = reinterpret_cast<QAction*>(sender())->text();
}
void MainWindow::on_ReadCodec_triggered() {
    int pos = ui->tabWidget->currentIndex();
    Texts.reinterpretCodec(ui->Tabs[pos].TEPointer, reinterpret_cast<QAction*>(sender())->text(),ui->Tabs[pos].codecName);
    ui->Tabs[pos].codecName=reinterpret_cast<QAction*>(sender())->text();
}
void MainWindow::on_ActBGColor_triggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QColor newBG = QColorDialog::getColor(QColor(255,255,255,255),this);
    Graph.setBGColor(ui->Tabs[pos].TEPointer, newBG);
}
void MainWindow::on_ActTxColor_triggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QColor newTx = QColorDialog::getColor(QColor(255,255,255,255),this);
    Graph.setFontColor(ui->Tabs[pos].TEPointer, newTx);
}
void MainWindow::on_ActTxBGColor_triggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QColor newTx = QColorDialog::getColor(QColor(255,255,255,255),this);
    Graph.setFontBGColor(ui->Tabs[pos].TEPointer,newTx);
}
void MainWindow::on_ActTxABGColor_triggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QColor newHighLight = QColorDialog::getColor(QColor(255,255,255,255),this);
    Graph.setHihlightColor(ui->Tabs[pos].TEPointer,newHighLight);
}
void MainWindow::on_ActIncrease_triggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QFont font(
                ui->Tabs[pos].TEPointer->font().family(),
                ui->Tabs[pos].TEPointer->font().pointSize()+1,
                ui->Tabs[pos].TEPointer->font().weight(),
                ui->Tabs[pos].TEPointer->font().italic()
                );
    font.setUnderline(ui->Tabs[pos].TEPointer->font().underline());
    ui->Tabs[pos].TEPointer->setFont(font);
}
void MainWindow::on_ActDecrease_triggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    QFont font(
                ui->Tabs[pos].TEPointer->font().family(),
                ui->Tabs[pos].TEPointer->font().pointSize()-1,
                ui->Tabs[pos].TEPointer->font().weight(),
                ui->Tabs[pos].TEPointer->font().italic()
                );
    font.setUnderline(ui->Tabs[pos].TEPointer->font().underline());
    ui->Tabs[pos].TEPointer->setFont(font);
}
void MainWindow::on_ActSetFont_triggered() {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    bool flag;
    QFont newFont = QFontDialog::getFont(&flag,this);
    if (!flag) return;
    Graph.setFontCustom(ui->Tabs[pos].TEPointer, newFont);
}
void MainWindow::on_ActBold_triggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setFontBold(ui->Tabs[pos].TEPointer,flag);
}
void MainWindow::on_ActItalic_triggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setFontItalic(ui->Tabs[pos].TEPointer,flag);
}
void MainWindow::on_ActUnderline_triggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setFontUnderline(ui->Tabs[pos].TEPointer,flag);
}
void MainWindow::on_ActBoldLocal_triggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setCursorBold(ui->Tabs[pos].TEPointer,flag);
}
void MainWindow::on_ActItalicLocal_triggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setCursorItalic(ui->Tabs[pos].TEPointer,flag);
}
void MainWindow::on_ActUnderlineLocal_triggered(bool flag) {
    int pos = ui->tabWidget->currentIndex();
    if (ui->tabWidget->tabText(pos).isEmpty()) return;
    Graph.setCursorUnderline(ui->Tabs[pos].TEPointer,flag);
}
