#include "PlayControlPage.h"
#include "ui_PlayControlPage.h"
#include <QDesktopServices>
#include <QFileDialog>

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

void PlayControlPage::setPlayBtnQss(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::PlayingState)
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

    m_player = new Player();
}

void PlayControlPage::initConnect()
{
    connect(ui->playBtn, &QPushButton::clicked, [this]()
    { 
        playMusic();
    });

    connect(ui->nextBtn, &QPushButton::clicked, [this]()
    {
        m_player->next();
    });

    connect(ui->preBtn, &QPushButton::clicked, [this]()
    {
        m_player->previous();
    });

    connect(ui->stopBtn, &QPushButton::clicked, [this]()
    {
        m_player->stop();
    });

    connect(ui->addMusicBtn, &QPushButton::clicked, [this]()
    {
        addMusic();
    });
}

void PlayControlPage::addMusic()
{
    auto fileList = QFileDialog::getOpenFileNames(nullptr, tr("Choose Music"), ".", "*.mp3");

    for (const auto& iter : fileList)
    {
       m_player->addMusic(iter);
    }
}

void PlayControlPage::playMusic()
{
    m_player->play();
    if (m_player->getPlayState() == QMediaPlayer::PlayingState)
    {
        setPlayBtnQss(QMediaPlayer::PausedState);
    }
    else
    {
        setPlayBtnQss(QMediaPlayer::PlayingState);
    }
}
