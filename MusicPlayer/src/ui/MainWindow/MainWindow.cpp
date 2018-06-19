#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: FramelessWidget(parent)
{
	ui = new Ui::MainWindow();
	ui->setupUi(this);
    initUi();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::initUi()
{
    m_winTitle = new WinTitle(this);
    m_musicInfoPage = new MusicInfoPage(this);
    m_playControlPage = new PlayControlPage(this);

    QHBoxLayout* topLayout = new QHBoxLayout();
    topLayout->addWidget(m_musicInfoPage);
    topLayout->addStretch();
    topLayout->addWidget(m_winTitle);
    topLayout->setContentsMargins(0, 0, 0, 0);
    topLayout->setSpacing(0);

    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->addLayout(topLayout);
    vLayout->addWidget(m_playControlPage);
    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->setSpacing(0);
    this->setLayout(vLayout);
    this->setContentsMargins(0, 0, 0, 0);

    this->setFixedSize(QSize(300,100));
}

void MainWindow::initConnect()
{

}
