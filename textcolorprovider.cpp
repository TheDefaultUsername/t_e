#include "textcolorprovider.h"

TextColorProvider::TextColorProvider()
{

}

bool TextColorProvider::setFontBold(QTextEdit* window, bool flag) {
    QFont font(
                window->font().family(),
                window->font().pointSize(),
                window->font().weight(),
                window->font().italic()
                );
    font.setUnderline(window->font().underline());
    if (flag)
        font.setWeight(QFont::Bold);
    else
        font.setWeight(QFont::Normal);
    window->setFont(font);
    return true;
}
bool TextColorProvider::setFontItalic(QTextEdit* window, bool flag) {
    QFont font(
                window->font().family(),
                window->font().pointSize(),
                window->font().weight(),
                flag
                );
    font.setUnderline(window->font().underline());
    window->setFont(font);
    return true;
}
bool TextColorProvider::setFontUnderline(QTextEdit* window, bool flag) {
    QFont font(
                window->font().family(),
                window->font().pointSize(),
                window->font().weight(),
                window->font().italic()
                );
    font.setUnderline(flag);
    window->setFont(font);
    return true;
}
bool TextColorProvider::setFontCustom(QTextEdit* window, QFont font) {
    window->setFont(font);
    return true;
}

bool TextColorProvider::setCursorBold(QTextEdit* window, bool flag) {
    window->setFontWeight(QFont::Bold);
    if(!flag) window->setFontWeight(QFont::Normal);
    return true;
}
bool TextColorProvider::setCursorItalic(QTextEdit* window, bool flag) {
    window->setFontItalic(flag);
    return true;
}
bool TextColorProvider::setCursorUnderline(QTextEdit* window, bool flag) {
    window->setFontUnderline(flag);
    return true;
}

bool TextColorProvider::setFontColor(QTextEdit* window, QColor color) {
    QPalette newPalette = window->palette();
    newPalette.setColor(QPalette::Text,color);
    window->setPalette(newPalette);
    return true;
}
bool TextColorProvider::setFontColorLocal(QTextEdit* window, QColor color) {
    window->setTextColor(color);
    return true;
}

bool TextColorProvider::setBGColor(QTextEdit* window, QColor color) {
    window->setStyleSheet(QString("QTextEdit { background-color: rgb(%1, %2, %3) }")
                                     .arg(QString::number(color.red()))
                                     .arg(QString::number(color.green()))
                                     .arg(QString::number(color.blue())));
    return true;
}
bool TextColorProvider::setFontBGColor(QTextEdit* window, QColor color) {
    window->setTextBackgroundColor(color);
    return true;
}
bool TextColorProvider::setHihlightColor(QTextEdit* window, QColor color) {
    QPalette newPalette = window->palette();
    newPalette.setColor(QPalette::Highlight,color);
    newPalette.setColor(QPalette::HighlightedText,
                        QColor(255-color.red(),255-color.green(),255-color.blue(),color.alpha())
                        );
    window->setPalette(newPalette);
    return true;
}
