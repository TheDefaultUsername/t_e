#include "mainwindow.h"
#include "textcolorprovider.h"
#include "textworkprovider.h"
#include "fileworkprovider.h"
#include <QTextCodec>

FileWorkProvider::FileWorkProvider()
{

}
bool FileWorkProvider::openFile(QString filename, QString openCodec, QTextEdit *window) {
    if (filename.isEmpty()) {return false;}
    QFile inputfile(filename);
    if (!inputfile.open(QIODevice::ReadOnly)) {return false;}
    if (openCodec.isEmpty()) {
        window->append(inputfile.readAll());
    } else {
        window->append(QTextCodec::codecForName(openCodec.toLatin1())->toUnicode(inputfile.readAll()));
    }
    inputfile.close();
    return true;
}
bool FileWorkProvider::saveFile(QString filename, QString saveCodec, QTextEdit *window) {
    if (filename.isEmpty()) return false;
    QFile outputfile(filename);
    if (!outputfile.open(QIODevice::WriteOnly)) {return false;}
    outputfile.write(QTextCodec::codecForName(saveCodec.toLatin1())->fromUnicode(window->toPlainText()));
    outputfile.close();
    return true;
}
