#include "PlayControlPage.h"
#include "ui_PlayControlPage.h"

PlayControlPage::PlayControlPage(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::PlayControlPage();
    ui->setupUi(this);
}

PlayControlPage::~PlayControlPage()
{
    delete ui;
}
