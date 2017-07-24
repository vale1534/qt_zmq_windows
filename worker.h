#ifndef WORKER_H
#define WORKER_H

#include <QRunnable>
#include <atomic>

class Worker : public QRunnable
{
public:
    void run();
    void close();

private:
    std::atomic<bool> closed{false};
};

#endif // WORKER_H
