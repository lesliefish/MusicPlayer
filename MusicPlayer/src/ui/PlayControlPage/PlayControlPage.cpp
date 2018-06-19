#include "PlayControlPage.h"
#include "ui_PlayControlPage.h"

PlayControlPage::PlayControlPage(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::PlayControlPage();
    ui->setupUi(this);
    initUi();
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
    ui->volumeBtn->setIcon(QIcon(":/new/player/volume.png"));
}
