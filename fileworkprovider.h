#ifndef FILEWORKPROVIDER_H
#define FILEWORKPROVIDER_H

#include <QTextEdit>
#include "cleanfileprovider.h"

class FileWorkProvider
{
    CleanFileProvider FilesWork;
public:
    FileWorkProvider();
    bool openFile(const QString& filename, const QString& openCodec, QTextEdit* window);
    bool saveFile(const QString& filename, const QString& saveCodec, QTextEdit* window);
};

#endif // FILEWORKPROVIDER_H
