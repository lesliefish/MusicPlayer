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
    delete m_player;
}

void MainWindow::initUi()
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    m_winTitle = new WinTitle(ui->mainPage);
    m_musicInfoPage = new MusicInfoPage(ui->mainPage);
    m_playControlPage = new PlayControlPage(ui->mainPage);

    QHBoxLayout* topLayout = new QHBoxLayout();
    topLayout->addWidget(m_musicInfoPage);
    topLayout->setContentsMargins(0, 0, 0, 0);
    topLayout->setSpacing(0);

    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->addWidget(m_winTitle);
    vLayout->addLayout(topLayout);
    vLayout->addWidget(m_playControlPage);
    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->setSpacing(0);
    ui->mainPage->setLayout(vLayout);
    ui->mainPage->setContentsMargins(0, 0, 0, 0);

    this->setFixedSize(QSize(300,150));
    this->setWindowTitle(tr("Music Player"));
    this->setWindowIcon(QIcon(":/new/player/title_icon.jpg"));

    // style
    QFile file("./res/MusicPlayer.qss");
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString style = file.readAll();
        this->setStyleSheet(style);
    }

    m_player = new Player();
    m_player->addMusic("C:/Users/Public/Music/Sample Music/Kalimba.mp3");
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

    connect(m_playControlPage, &PlayControlPage::signalPlay, this, [this]()
    {
        m_player->play();
    });

    connect(m_playControlPage, &PlayControlPage::signalNext, this, [this]()
    {
        m_player->next();
    });

    connect(m_playControlPage, &PlayControlPage::signalPrevious, this, [this]()
    {
        m_player->previous();
    });

    connect(m_playControlPage, &PlayControlPage::signalStop, this, [this]()
    {
        m_player->stop();
    });
}
