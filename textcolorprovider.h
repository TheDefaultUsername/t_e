#ifndef TEXTCOLORPROVIDER_H
#define TEXTCOLORPROVIDER_H

#include <QTextEdit>
#include <QFont>

class TextColorProvider
{
public:
    TextColorProvider();
    bool setFontBold(QTextEdit* window, bool flag);
    bool setFontItalic(QTextEdit* window, bool flag);
    bool setFontUnderline(QTextEdit* window, bool flag);
    bool setFontCustom(QTextEdit* window, QFont font);

    bool setCursorBold(QTextEdit* window, bool flag);
    bool setCursorItalic(QTextEdit* window, bool flag);
    bool setCursorUnderline(QTextEdit* window, bool flag);

    bool setFontColor(QTextEdit* window, QColor color);
    bool setFontColorLocal(QTextEdit* window, QColor color);
    bool setBGColor(QTextEdit* window, QColor color);
    bool setFontBGColor(QTextEdit* window, QColor color);
    bool setHihlightColor(QTextEdit* window, QColor color);
};

#endif // TEXTCOLORPROVIDER_H
