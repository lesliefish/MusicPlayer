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
signals:
    void signalClose();
    void signalShowMini();

private:
    void initUi();
    void initConnect();

private:
    QPushButton* m_minBtn;
    QPushButton* m_closeBtn;
};
