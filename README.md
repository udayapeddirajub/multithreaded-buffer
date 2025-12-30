# Multithreaded Buffer Demo 🚀

![Build Status](https://github.com/udayapeddirajub/multithreaded-buffer/actions/workflows/ci.yml/badge.svg)
![C++ Standard](https://img.shields.io/badge/C%2B%2B-17-blue.svg)

A high-performance, **thread-safe circular buffer** implementation in C++. This project demonstrates core Operating Systems (OS) and Embedded Systems concepts, specifically the **Producer-Consumer pattern**.

## 🧠 Key Engineering Concepts
* **Circular Buffer (Ring Buffer):** Efficient fixed-size memory management.
* **Thread Synchronization:** Uses `std::mutex` and `std::unique_lock`.
* **Efficient Waiting:** Utilizes `std::condition_variable` to prevent busy-waiting.
* **RAII Pattern:** Automatic resource management.

## 🛠 Project Structure
```text
multithreaded-buffer/
├── .github/workflows/  # CI/CD Pipeline
├── include/            # RingBuffer Header
├── src/                # Application Source
├── tests/              # Unit Tests
└── CMakeLists.txt      # Build Logic
\# 1. Clone the repository

git clone \[https://github.com/udayapeddirajub/multithreaded-buffer.git

cd multithreaded-buffer



\# 2. Create build directory

mkdir build \&\& cd build



\# 3. Configure and Build

cmake ..

make



\# 4. Run the Demo

./buffer\_demo



\# 5. Run the Tests

./buffer\_tests



```

