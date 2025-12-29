#include <iostream>
#include <thread>
#include <chrono>
#include "RingBuffer.hpp"

void producer(RingBuffer<int>& rb) {
    for (int i = 1; i <= 10; ++i) {
        std::cout << "[Producer] Sending: " << i << std::endl;
        rb.put(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void consumer(RingBuffer<int>& rb) {
    for (int i = 1; i <= 10; ++i) {
        int val = rb.get();
        std::cout << "[Consumer] Received: " << val << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    RingBuffer<int> rb(5);
    std::thread t1(producer, std::ref(rb));
    std::thread t2(consumer, std::ref(rb));

    t1.join();
    t2.join();

    std::cout << "System task completed." << std::endl;
    return 0;
}