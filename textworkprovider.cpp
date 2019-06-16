#include "textworkprovider.h"
#include <QTextCodec>

TextWorkProvider::TextWorkProvider()
{

}

bool TextWorkProvider::reinterpretCodec(QTextEdit *window, QString codecName, QString previousCodec) {
    window->setText(QTextCodec::codecForName(codecName.toLatin1())->toUnicode(QTextCodec::codecForName(previousCodec.toLatin1())->fromUnicode(window->toPlainText())));
}
