#pragma once

#include <QWidget>
namespace Ui { class PlayControlPage; };

class PlayControlPage : public QWidget
{
    Q_OBJECT

public:
    PlayControlPage(QWidget *parent = Q_NULLPTR);
    ~PlayControlPage();

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
};
