#ifndef JOBUI_H
#define JOBUI_H

#include <QWidget>

namespace Ui {
class JobUI;
}

class JobUI : public QWidget
{
    Q_OBJECT
    
public:
    explicit JobUI(QWidget *parent = 0);
    ~JobUI();

    void setNumber(int n);

signals:
    void deleteThisJob(int i);
    

private slots:
    void setToDelete();

private:
    Ui::JobUI *ui;
};

#endif // JOBUI_H
