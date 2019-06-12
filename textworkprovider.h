#ifndef TEXTWORKPROVIDER_H
#define TEXTWORKPROVIDER_H

#include <QString>
#include <QTextEdit>

class MainWindow;

class TextWorkProvider
{
public:
    TextWorkProvider();
    bool reinterpretCodec(QTextEdit* window, QString codecName, QString previousCodec);
};

#endif // TEXTWORKPROVIDER_H
