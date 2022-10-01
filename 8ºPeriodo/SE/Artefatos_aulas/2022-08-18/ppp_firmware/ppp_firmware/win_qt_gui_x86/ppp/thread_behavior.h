#ifndef THREAD_BEHAVIOR_H
#define THREAD_BEHAVIOR_H

#include <QThread>

class thread_behavior : public QThread
{
public:
    thread_behavior();
    void run();
};

#endif // THREAD_BEHAVIOR_H
