#pragma once

#include <QWidget>
#include <QMediaPlayer>
#include "Player.h"
namespace Ui { class PlayControlPage; };


class PlayControlPage : public QWidget
{
    Q_OBJECT

public:
    PlayControlPage(QWidget *parent = Q_NULLPTR);
    ~PlayControlPage();

public:
    void setPlayBtnQss(QMediaPlayer::State state);
signals:
    
private:
    void initUi();
    void initConnect();
    void addMusic();
    void playMusic();
private:
    Ui::PlayControlPage *ui;

    QString m_qssPlayStyle;
    QString m_qssPauseStyle;

    Player* m_player{ nullptr };
};
