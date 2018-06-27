#pragma once

#include <QWidget>
namespace Ui { class PlayControlPage; };

class PlayControlPage : public QWidget
{
    Q_OBJECT

public:
    PlayControlPage(QWidget *parent = Q_NULLPTR);
    ~PlayControlPage();

    enum PlayState
    {
        Stop,
        Playing,
        Pause
    };

public:
    void setPlayBtnQss(PlayState state);

signals:
    void signalPlay();
    void signalNext();
    void signalPrevious();
    void signalStop();
private:
    void initUi();
    void initConnect();

private:
    Ui::PlayControlPage *ui;

    QString m_qssPlayStyle;
    QString m_qssPauseStyle;
};
