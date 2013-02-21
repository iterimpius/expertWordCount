#include "jobui.h"
#include "ui_jobui.h"
#include <QDebug>

JobUI::JobUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JobUI)
{
    ui->setupUi(this);
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(setToDelete()));
}

JobUI::~JobUI()
{
    delete ui;
}

void JobUI::setNumber(int n)
{
    ui->btnNumber->setText(QString::number(n));
}


void JobUI::setToDelete()
{
    emit deleteThisJob(ui->btnNumber->text().toInt() - 1);
}
