#pragma once

#include <QWidget>
namespace Ui { class PlayControlPage; };

class PlayControlPage : public QWidget
{
    Q_OBJECT

public:
    PlayControlPage(QWidget *parent = Q_NULLPTR);
    ~PlayControlPage();

private:
    Ui::PlayControlPage *ui;
};
