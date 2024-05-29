#include <iostream>

template<typename T>
class unique_ptr {
private:
    T* ptr;

public:
    unique_ptr(T* p) : ptr(p) {}

    ~unique_ptr() {
        delete ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    // “∆∂Ø”Ô“Â
    unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Ω˚÷πøΩ±¥”Ô“Â
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
};

int main() {
    unique_ptr<int> up(new int(10));
    std::cout << *up << std::endl; //  ‰≥ˆ 10
    return 0;
}