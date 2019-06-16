#include "fileworkprovider.h"
#include <QTextCodec>

FileWorkProvider::FileWorkProvider()
{

}
bool FileWorkProvider::openFile(const QString& filename, const QString& openCodec, QTextEdit *window) {
    if (filename.isEmpty()) {return false;}
    bool isOk;
    QByteArray input = *FilesWork.openFile(filename, &isOk);
    if (!isOk) {return false;}
    if (openCodec.isEmpty()) {
        window->append(input);
    } else {
        window->append(QTextCodec::codecForName(openCodec.toLatin1())->toUnicode(input));
    }
    return true;
}
bool FileWorkProvider::saveFile(const QString& filename, const QString& saveCodec, QTextEdit *window) {
    if (filename.isEmpty()) return false;
    if (!FilesWork.saveFile(filename,QTextCodec::codecForName(saveCodec.toLatin1())->fromUnicode(window->toPlainText()))) {return false;}
    return true;
}
