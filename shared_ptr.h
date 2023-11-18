#include <iostream>

template <typename T>
class shared_ptr {
public:
    explicit shared_ptr(T*);
    shared_ptr(const shared_ptr&);
    shared_ptr& operator=(const shared_ptr&);

    T& operator*() const;
    T* operator->() const;
    bool empty() const;

    ~shared_ptr();
private:
    std::size_t m_count{};
    T* m_ptr{};

    void decreaseCount();
};

#include "shared_ptr_impl.h"