#include <iostream>
#include <cassert>
#include "RingBuffer.hpp"

void test_simple_flow() {
    RingBuffer<int> rb(2);
    rb.put(100);
    assert(rb.get() == 100);
    std::cout << "Test Simple Flow: PASSED" << std::endl;
}

void test_wrap_around() {
    RingBuffer<int> rb(2);
    rb.put(1);
    rb.put(2);
    rb.get(); // removes 1
    rb.put(3); // wraps around
    assert(rb.get() == 2);
    assert(rb.get() == 3);
    std::cout << "Test Wrap Around: PASSED" << std::endl;
}

int main() {
    test_simple_flow();
    test_wrap_around();
    return 0;
}