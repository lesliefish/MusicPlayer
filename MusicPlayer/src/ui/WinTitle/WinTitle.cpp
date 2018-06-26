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
    m_mainWidget = new QWidget(this);
    m_mainWidget->setObjectName("winTitle");
    QSize iconSize(32, 24);
    m_titleBtn = new QLabel();
    m_titleBtn->setFixedHeight(24);
    m_titleBtn->setText(tr("Music Player"));

    m_minBtn = new QPushButton();
    m_minBtn->setFixedSize(iconSize);
    m_minBtn->setObjectName("m_minBtn");
    m_closeBtn = new QPushButton();
    m_closeBtn->setFixedSize(iconSize);
    m_closeBtn->setObjectName("m_closeBtn");

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(m_titleBtn);
    layout->addStretch();
    layout->addWidget(m_minBtn);
    layout->addWidget(m_closeBtn);
    layout->setContentsMargins(6,0,0,0);
    layout->setSpacing(0);
    m_mainWidget->setLayout(layout);
    m_mainWidget->setContentsMargins(QMargins(0,0,0,0));

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->addWidget(m_mainWidget);
    gridLayout->setContentsMargins(QMargins(0, 0, 0, 0));
    this->setLayout(gridLayout);
    this->setContentsMargins(QMargins(0, 0, 0, 0));

    m_closeBtn->setText(QString::fromLocal8Bit("¡Á"));
    m_minBtn->setText("-");

    this->setFixedHeight(24);
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
