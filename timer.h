#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>



class Timer1 {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
  public:
    Timer1() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
      start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
      return std::chrono::duration<double>
(std::chrono::high_resolution_clock::now() - start).count();
  }
};

class Timer2 {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
  public:
    Timer2() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
      start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
      return std::chrono::duration<double>
(std::chrono::high_resolution_clock::now() - start).count();
  }
};

class Timer3 {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
  public:
    Timer3() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
      start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
      return std::chrono::duration<double>
(std::chrono::high_resolution_clock::now() - start).count();
  }
};


class Timer4 {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
  public:
    Timer4() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
      start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
      return std::chrono::duration<double>
(std::chrono::high_resolution_clock::now() - start).count();
  }
};

class Timer5 {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
  public:
    Timer5() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
      start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
      return std::chrono::duration<double>
(std::chrono::high_resolution_clock::now() - start).count();
  }
};


#endif // TIMER_H_INCLUDED
