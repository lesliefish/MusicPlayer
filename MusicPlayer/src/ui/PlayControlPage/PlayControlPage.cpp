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

void PlayControlPage::initUi()
{
    ui->preBtn->setIcon(QIcon(":/new/player/previous.png"));
    ui->nextBtn->setIcon(QIcon(":/new/player/next.png"));
    ui->playBtn->setIcon(QIcon(":/new/player/play.png"));
    ui->stopBtn->setIcon(QIcon(":/new/player/stop.png"));
    ui->playListBtn->setIcon(QIcon(":/new/player/list.png"));
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
