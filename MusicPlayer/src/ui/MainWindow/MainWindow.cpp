#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: FramelessWidget(parent)
{
	ui = new Ui::MainWindow();
	ui->setupUi(this);
    initUi();
    initConnect();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::initUi()
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    m_winTitle = new WinTitle(ui->mainPage);

    m_playControlPage = new PlayControlPage(ui->mainPage);
    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->addWidget(m_winTitle);
    vLayout->addWidget(m_playControlPage);
    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->setSpacing(0);
    ui->mainPage->setLayout(vLayout);
    ui->mainPage->setContentsMargins(0, 0, 0, 0);

    this->setFixedWidth(300);
    this->setFixedHeight(m_winTitle->height() + m_playControlPage->height());
    this->setWindowTitle(tr("Music Player"));
    this->setWindowIcon(QIcon(":/new/player/title_icon.jpg"));

    initQss();
}

void MainWindow::initConnect()
{
    connect(m_winTitle, &WinTitle::signalClose, this, [this]() 
    {
        this->close();
    });
    connect(m_winTitle, &WinTitle::signalShowMini, this, [this]()
    {
        this->showMinimized();
    });
}

void MainWindow::initQss()
{
    // style
    QFile file("./res/MusicPlayer.qss");
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString style = file.readAll();
        this->setStyleSheet(style);
    }
}