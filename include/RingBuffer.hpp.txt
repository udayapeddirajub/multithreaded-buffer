#ifndef RING_BUFFER_HPP
#define RING_BUFFER_HPP

#include <vector>
#include <mutex>
#include <condition_variable>

template <typename T>
class RingBuffer {
public:
    explicit RingBuffer(size_t size) 
        : buffer_(size), max_size_(size), head_(0), tail_(0), full_(false) {}

    // Adds item to buffer; blocks if full
    void put(T item) {
        std::unique_lock<std::mutex> lock(mtx_);

        // Wait while buffer is full
        cv_full_.wait(lock, [this]() { return !full_; });

        buffer_[head_] = item;
        head_ = (head_ + 1) % max_size_;
        full_ = (head_ == tail_);

        lock.unlock();
        cv_empty_.notify_one();
    }

    // Removes item from buffer; blocks if empty
    T get() {
        std::unique_lock<std::mutex> lock(mtx_);

        // Wait while buffer is empty
        cv_empty_.wait(lock, [this]() { return full_ || (head_ != tail_); });

        T item = buffer_[tail_];
        full_ = false;
        tail_ = (tail_ + 1) % max_size_;

        lock.unlock();
        cv_full_.notify_one();
        return item;
    }

private:
    std::vector<T> buffer_;
    size_t max_size_;
    size_t head_;
    size_t tail_;
    bool full_;

    std::mutex mtx_;
    std::condition_variable cv_empty_;
    std::condition_variable cv_full_;
};

#endif