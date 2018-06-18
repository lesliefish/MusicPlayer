#include "MusicInfoPage.h"
#include "ui_MusicInfoPage.h"

MusicInfoPage::MusicInfoPage(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::MusicInfoPage();
    ui->setupUi(this);
}

MusicInfoPage::~MusicInfoPage()
{
    delete ui;
}
