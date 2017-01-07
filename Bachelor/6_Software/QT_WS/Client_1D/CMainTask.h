#ifndef CMAINTASK_H
#define CMAINTASK_H
#include <QThread>

class CMainTask : public QThread
{
    Q_OBJECT
public:
    void run() override
    {
        this->exec();
    }
};


#endif // CMAINTASK_H
