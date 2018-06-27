#pragma once

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class Player : public QObject
{
    Q_OBJECT

public:
    Player();
    ~Player();

public:
    void stop();
    void next();
    void play();
    void previous();
    void addMusic(const QString& path);
    QMediaPlayer::State getPlayState() const;

private:
    void init();

private:
    QMediaPlayer* m_mediaPlayer{ nullptr };
    QMediaPlaylist* m_playerList{ nullptr };
};
