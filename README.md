# Multithreaded Buffer Demo 🚀

![Build Status](https://github.com/ubokka/multithreaded-buffer/actions/workflows/ci.yml/badge.svg)
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
\```

## 🚀 Getting Started
```bash
mkdir build && cd build
cmake ..
make
./buffer_demo
\```

\### Prerequisites



\* A C++17 compatible compiler (GCC, Clang, or MSVC)

\* CMake (3.10 or higher)



\### Local Build and Execution



```bash

\# 1. Clone the repository

git clone \[https://github.com/](https://github.com/)<YOUR\_GITHUB\_USERNAME>/multithreaded-buffer.git

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

\## 🤖 CI/CD Integration



This repository is configured with \*\*GitHub Actions\*\*. Every time you push code:



1\. A fresh Ubuntu environment is provisioned.

2\. The project is compiled using `g++`.

3\. \*\*Unit Tests\*\* are automatically executed to ensure logic remains sound.

4\. \*\*Integration Demo\*\* is run to verify thread coordination.



\## 📝 Expected Output



When running the demo, you will see the asynchronous nature of the threads:



\* The \*\*Producer\*\* will generate data.

\* The \*\*Consumer\*\* will process it at a different speed.

\* The \*\*RingBuffer\*\* manages the "pressure" between them without dropping data.



---



\*Developed as a demonstration of C++ Concurrency and Systems Programming.\*



```

