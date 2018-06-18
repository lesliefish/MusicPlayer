#pragma once

#include <QWidget>
namespace Ui { class MainWindow; };

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
	Ui::MainWindow *ui;
};
