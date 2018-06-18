#pragma once

#include <QWidget>
namespace Ui { class MusicInfoPage; };

class MusicInfoPage : public QWidget
{
    Q_OBJECT

public:
    MusicInfoPage(QWidget *parent = Q_NULLPTR);
    ~MusicInfoPage();

private:
    Ui::MusicInfoPage *ui;
};
