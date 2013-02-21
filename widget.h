#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>

#include "jobui.h"
#include "jobsettings.h"
#include "settingsform.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;
    QList<JobUI*> jobs;
    QList<JobSettings*> settings;
    SettingsForm *s;

private slots:
    void addJob();
    void deleteAllJobs();
    void deleteJob(int i);
    void toggleSettings();
    void refresh();
};

#endif // WIDGET_H
