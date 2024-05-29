#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <condition_variable>
#include <mutex>

/**
 * @brief Custom semaphore implementation.
 */
class Semaphore
{
public:
    /**
     * @brief Construct a new Semaphore object.
     *
     * @param count Initial count for the semaphore
     */
    Semaphore(int count = 0);

    /**
     * @brief Notify one waiting thread.
     */
    void notify();

    /**
     * @brief Wait until count is greater than zero.
     */
    void wait();

private:
    std::mutex mtx;             ///< Mutex for thread synchronization
    std::condition_variable cv; ///< Condition variable for thread waiting
    int count;                  ///< Semaphore count
};

#endif
