#include "WinTitle.h"

WinTitle::WinTitle(QWidget *parent)
    : QWidget(parent)
{
    initUi();
    initConnect();
}

WinTitle::~WinTitle()
{
}

void WinTitle::initUi()
{
    QSize iconSize(24, 24);
    m_minBtn = new QPushButton();
    m_minBtn->setFixedSize(iconSize);
    m_minBtn->setText("-");

    m_closeBtn = new QPushButton();
    m_closeBtn->setFixedSize(iconSize);
    m_closeBtn->setText("x");

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(m_minBtn);
    layout->addWidget(m_closeBtn);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    this->setLayout(layout);
    this->setContentsMargins(QMargins(0,0,0,0));
}

void WinTitle::initConnect()
{
    connect(m_closeBtn, &QPushButton::clicked, this, [this]() 
    {
        emit signalClose();  
    });

    connect(m_minBtn, &QPushButton::clicked, this, [this]()
    {
        emit signalShowMini();
    });
}
