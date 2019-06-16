#include "cleanfileprovider.h"

CleanFileProvider::CleanFileProvider() {}

QByteArray* CleanFileProvider::openFile(const QString& filename, bool *flag) {
    *flag = false;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {return NULL;}
    *flag = true;
    QByteArray *result = new QByteArray(file.readAll());
    file.close();
    return result;
}

bool CleanFileProvider::saveFile(const QString &filename, const QByteArray &output) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {return false;}
    file.write(output);
    file.close();
    return true;
}
