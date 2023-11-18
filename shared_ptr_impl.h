template <typename T>
shared_ptr<T>::shared_ptr(T* ptr) 
: m_ptr (ptr), m_count (1)
{}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T>& ptr) {
    if (this != &ptr) {
        decreaseCount();

        m_ptr = ptr.m_ptr;
        m_count = ptr.m_count;

        ++m_count;
    }
    return *this;
}

template <typename T>
T& shared_ptr<T>::operator*() const {
    return *m_ptr;
}

template <typename T>
T* shared_ptr<T>::operator->() const {
    return m_ptr;
}

template <typename T>
bool shared_ptr<T>::empty() const {
    return m_ptr;
}

template <typename T>
shared_ptr<T>::~shared_ptr() {
    decreaseCount();
}

template <typename T>
void shared_ptr<T>::decreaseCount() {
    --m_count;
    if (m_count == 0) {
        delete m_ptr;
    }
}

template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr<T>& ptr)
:m_ptr(ptr.m_ptr), m_count(ptr.m_count)
{
    ++m_count;
}