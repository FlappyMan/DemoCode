#include <iostream>
#include <string>
 using namespace std;

template<class T>
 class SmartPtr
 {
public:
    SmartPtr(const T *&ptr = nullptr):m_ptr(ptr)
    {
        if(ptr)
        {
            m_count = new size_t(1);
        }else{
            m_count = new size_t(0);
        }
    }

    SmartPtr(const SmartPtr& other)
    {
        if (this!=other)
        {
            this->m_count = other.m_count;
            this->m_ptr = other.m_ptr;
            (*this->m_count)++;
        }
        
    }

    SmartPtr& operator=(const SmartPtr& other)
    {
        if (this->m_ptr==other->m_ptr)
        {
            return *this;
        }

        if (this->m_ptr)
        {
            (*this->m_count)--;
            if (this->m_count==0)
            {
                delete this->m_count;
                delete this->m_ptr;
            }
        }
        this->m_ptr = other->m_ptr;
        this->m_count = other->m_count;
        (*this->m_count)++;
        return *this;     
    }

    ~SmartPtr()
    {
        
    }
private:
    T *m_ptr;
    size_t *m_count;
 };


 int main()
 {
     return 0;
 }