#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class WinTitle : public QWidget
{
    Q_OBJECT

public:
    WinTitle(QWidget *parent);
    ~WinTitle();
private:
    void initUi();
private:
    QPushButton* m_minBtn;
    QPushButton* m_closeBtn;
};
