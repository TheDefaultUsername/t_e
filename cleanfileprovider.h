#ifndef CLEANFILEPROVIDER_H
#define CLEANFILEPROVIDER_H

#include <QByteArray>
#include <QString>
#include <QFile>

class CleanFileProvider
{
public:
    CleanFileProvider();
    bool openFile(const QString& filename, QByteArray& input);
    bool saveFile(const QString& filename, const QByteArray& output);
};

#endif // CLEANFILEPROVIDER_H
