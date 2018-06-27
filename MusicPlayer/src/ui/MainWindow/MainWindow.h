#pragma once

#include <QWidget>
#include "FramelessWidget.h"
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
    void initQss();
    // 播放/暂停音乐
    void playMusic();
    // 添加音乐
    void addMusic();
    // 更新歌曲信息
    void updateMusicInfo();
private:
	Ui::MainWindow *ui;

    WinTitle* m_winTitle{ nullptr };
    PlayControlPage* m_playControlPage{ nullptr };
    Player* m_player{ nullptr };
};
