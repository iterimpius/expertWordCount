#include "widget.h"
#include "ui_widget.h"
#include <QDebug>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    s = new SettingsForm(this);
    ui->settingsLayout->addWidget(s, Qt::AlignTop);
    s->setVisible(0);

    ui->jobLayout->setAlignment(Qt::AlignTop);
    refresh();

    connect(ui->btnFromTxt, SIGNAL(clicked()), this, SLOT(addJob()));
    connect(ui->btnDeleteAllJobs, SIGNAL(clicked()), this, SLOT(deleteAllJobs()));
    connect(ui->btnQuit, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnSettings, SIGNAL(clicked()), this, SLOT(toggleSettings()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addJob()
{
    JobUI *j = new JobUI(this);
    int last = jobs.length();
    jobs.insert(last, j);
    ui->jobLayout->addWidget(j);
    j->setNumber(last+1);

    connect(j, SIGNAL(deleteThisJob(int)), this, SLOT(deleteJob(int)));
    refresh();
}

void Widget::deleteAllJobs()
{
    if (!jobs.isEmpty()) {
        for (int i = 0; i < jobs.length(); ++i) {
            ui->jobLayout->removeWidget(jobs[i]);
            delete jobs[i];
        }

        jobs.clear();
    }
    refresh();
}

void Widget::deleteJob(int i)
{
    ui->jobLayout->removeWidget(jobs.at(i));
    delete jobs[i];
    jobs.removeAt(i);

    for (int i = 0; i < jobs.length(); ++i) {
        jobs[i]->setNumber(i + 1);
    }
    refresh();
}

void Widget::toggleSettings()
{
    if (s->isVisible()) {
        s->setVisible(0);
        ui->scrollArea->setVisible(1);
        ui->toolBox->setVisible(1);
        ui->btnStartAllJobs->setVisible(1);
        ui->btnDeleteAllJobs->setVisible(1);

        ui->btnFromDOCX->setEnabled(1);
        ui->btnFromHTML->setEnabled(1);
        ui->btnFromOO->setEnabled(1);
        ui->btnFromTxt->setEnabled(1);
        ui->btnFromTxtFile->setEnabled(1);
        ui->btnFromURL->setEnabled(1);
        refresh();
    }
    else {
        s->setVisible(1);
        ui->scrollArea->setVisible(0);
        ui->toolBox->setVisible(0);
        ui->btnStartAllJobs->setVisible(0);
        ui->btnDeleteAllJobs->setVisible(0);

        ui->btnFromDOCX->setEnabled(0);
        ui->btnFromHTML->setEnabled(0);
        ui->btnFromOO->setEnabled(0);
        ui->btnFromTxt->setEnabled(0);
        ui->btnFromTxtFile->setEnabled(0);
        ui->btnFromURL->setEnabled(0);
    }

}

void Widget::refresh()
{
    if (jobs.isEmpty()) {
        ui->btnDeleteAllJobs->setVisible(0);
        ui->btnStartAllJobs->setVisible(0);
        ui->scrollArea->setVisible(0);
        ui->toolBox->setVisible(0);
    }
    else {

        if (jobs.length() > 1) {
            ui->btnDeleteAllJobs->setVisible(1);
            ui->btnStartAllJobs->setVisible(1);
        }
        else {
            ui->btnDeleteAllJobs->setVisible(0);
            ui->btnStartAllJobs->setVisible(0);
        }
        ui->scrollArea->setVisible(1);
        ui->toolBox->setVisible(1);
    }
}
