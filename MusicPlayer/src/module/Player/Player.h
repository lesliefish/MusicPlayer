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

signals:
    void signalCurrentMediaChanged(const QMediaContent& media);
private:
    void init();
    void initConnect();
private:
    QMediaPlayer* m_mediaPlayer{ nullptr };
    QMediaPlaylist* m_playerList{ nullptr };
    QMediaContent m_currentMediaContent{ nullptr };
};
