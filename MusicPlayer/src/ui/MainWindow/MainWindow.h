#pragma once

#include <QWidget>
#include "FramelessWidget.h"
#include "MusicInfoPage.h"
#include "WinTitle.h"
#include "PlayControlPage.h"
#include "Player.h"

namespace Ui { class MainWindow; };

class MainWindow : public FramelessWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
    void initUi();
    void initConnect();
private:
	Ui::MainWindow *ui;

    MusicInfoPage* m_musicInfoPage{ nullptr };
    WinTitle* m_winTitle{ nullptr };
    PlayControlPage* m_playControlPage{ nullptr };
    Player* m_player{ nullptr };
};
