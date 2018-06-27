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

    m_player = new Player();
    m_player->addMusic("C:/Users/Public/Music/Sample Music/Sleep Away.mp3");

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

    connect(m_playControlPage, &PlayControlPage::signalPlay, this, &MainWindow::playMusic);

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
        m_playControlPage->setPlayBtnQss((PlayControlPage::PlayState)(QMediaPlayer::PausedState));
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

/** 
 * @fn     MainWindow::playMusic
 * @brief  ²¥·Å»òÔÝÍ£
 * @return void
 */
void MainWindow::playMusic()
{
    m_player->play();
    m_playControlPage->setPlayBtnQss((PlayControlPage::PlayState)(m_player->getPlayState()));
}
