#ifndef FILEWORKPROVIDER_H
#define FILEWORKPROVIDER_H

#include <QFile>
#include <QFileDialog>
#include <QTextEdit>

class MainWindow;

class FileWorkProvider
{
public:
    FileWorkProvider();
    bool openFile(QString filename, QString openCodec, QTextEdit* window);
    bool saveFile(QString filename, QString saveCodec, QTextEdit* window);
};

#endif // FILEWORKPROVIDER_H
