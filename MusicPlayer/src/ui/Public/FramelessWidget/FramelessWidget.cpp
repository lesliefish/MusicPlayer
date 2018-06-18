#include "FramelessWidget.h"
#include "ui_FramelessWidget.h"

FramelessWidget::FramelessWidget(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::FramelessWidget();
    ui->setupUi(this);

    initUI();
}

FramelessWidget::~FramelessWidget()
{
    delete ui;
}

void FramelessWidget::initUI()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
}

void FramelessWidget::mousePressEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_pointMove = event->globalPos() - pos();
        event->accept();
    }
}

void FramelessWidget::mouseMoveEvent(QMouseEvent * event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - m_pointMove);
        event->accept();
    }
}
