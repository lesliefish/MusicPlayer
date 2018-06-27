#include "PlayControlPage.h"
#include "ui_PlayControlPage.h"

PlayControlPage::PlayControlPage(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::PlayControlPage();
    ui->setupUi(this);
    initUi();
    initConnect();
}

PlayControlPage::~PlayControlPage()
{
    delete ui;
}

void PlayControlPage::setPlayBtnQss(PlayState state)
{
    if (state == PlayState::Pause)
    {
        ui->playBtn->setStyleSheet(m_qssPlayStyle);
    }
    else
    {
        ui->playBtn->setStyleSheet(m_qssPauseStyle);
    }
}

void PlayControlPage::initUi()
{
    m_qssPlayStyle =
        "QPushButton#playBtn{ border-image:url(:/new/player/play.png);}"
        "QPushButton#playBtn:hover{ border-image:url(:/new/player/play_hor.png);}"
        "QPushButton#playBtn:pressed{ border-image:url(:/new/player/play.png);}";

    m_qssPauseStyle =
        "QPushButton#playBtn{ border-image:url(:/new/player/pause.png);}"
        "QPushButton#playBtn:hover{ border-image:url(:/new/player/pause_hor.png);}"
        "QPushButton#playBtn:pressed{ border-image:url(:/new/player/pause.png);}";
}

void PlayControlPage::initConnect()
{
    connect(ui->playBtn, &QPushButton::clicked, [this]()
    { 
        emit signalPlay(); 
    });

    connect(ui->nextBtn, &QPushButton::clicked, [this]()
    {
        emit signalNext();
    });

    connect(ui->preBtn, &QPushButton::clicked, [this]()
    {
        emit signalPrevious();
    });

    connect(ui->stopBtn, &QPushButton::clicked, [this]()
    {
        emit signalStop();
    });
}
