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

void Player::play()
{
    if (m_mediaPlayer->state() != QMediaPlayer::PlayingState)
    {
        m_mediaPlayer->play();
    }
    else
    {
        m_mediaPlayer->pause();
    }
}

void Player::previous()
{
    m_playerList->previous();
}

/** 
 * @fn     Player::addMusic
 * @brief  添加音乐
 * @param  const QString & path music路径
 * @return void
 */
void Player::addMusic(const QString& path)
{
    m_playerList->addMedia(QUrl(path));
}

/** 
 * @fn     Player::getPlayState
 * @brief  获取当前播放状态
 * @return QMediaPlayer::State
 */
QMediaPlayer::State Player::getPlayState() const
{
    return m_mediaPlayer->state();
}
