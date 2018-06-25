#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
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
    QWidget * m_mainWidget{ nullptr };
    QLabel * m_titleBtn{ nullptr };
    QPushButton * m_minBtn{ nullptr };
    QPushButton * m_closeBtn{ nullptr };
};
