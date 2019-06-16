#ifndef CLEANFILEPROVIDER_H
#define CLEANFILEPROVIDER_H

#include <QByteArray>
#include <QString>
#include <QFile>

class CleanFileProvider
{
public:
    CleanFileProvider();
    QByteArray* openFile(const QString& filename, bool *flag);
    bool saveFile(const QString& filename, const QByteArray& output);
};

#endif // CLEANFILEPROVIDER_H
