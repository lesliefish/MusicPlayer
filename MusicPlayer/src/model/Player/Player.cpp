#include "Player.h"

Player::Player()
    : QObject()
{
    init();
}

Player::~Player()
{

}

void Player::init()
{
    m_mediaPlayer = new QMediaPlayer(this);
    m_playerList = new QMediaPlaylist(this);
    m_mediaPlayer->setPlaylist(m_playerList);
    m_mediaPlayer->setVolume(50);
    m_playerList->setPlaybackMode(QMediaPlaylist::Loop);
}

void Player::stop()
{
    m_mediaPlayer->stop();
}

void Player::next()
{
    m_playerList->next();
}

void Player::pause()
{
    if (m_mediaPlayer->state() == QMediaPlayer::PlayingState)
    {
        m_mediaPlayer->pause();
    }
}

void Player::play()
{
    if (m_mediaPlayer->state() != QMediaPlayer::PlayingState)
    {
        m_mediaPlayer->play();
    }
}

void Player::previous()
{
    m_playerList->previous();
}

void Player::addMusic(const QString& path)
{
    m_playerList->addMedia(QUrl(path));
}
