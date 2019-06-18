#include "cleanfileprovider.h"

CleanFileProvider::CleanFileProvider() {

}

bool CleanFileProvider::openFile(const QString &filename, QByteArray& input) {
    bool flag = false;
    QFile file(filename);
    flag = file.open(QIODevice::ReadOnly);
    if (flag) {
        input = file.readAll();
        file.close();
    } else {
        input = QByteArray();
    }
    return flag;
}

bool CleanFileProvider::saveFile(const QString &filename, const QByteArray &output) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {return false;}
    file.write(output);
    file.close();
    return true;
}
