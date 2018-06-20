#pragma once

#include <QWidget>
#include <QMouseEvent>
namespace Ui { class FramelessWidget; };

class FramelessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FramelessWidget(QWidget *parent = Q_NULLPTR);
    ~FramelessWidget();

private:
    Ui::FramelessWidget *ui;

private:
    void initUI();

protected:
    //实现鼠标对无边框窗口拖动
    QPoint m_pointMove;
    bool m_dragWindow{ false };
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
