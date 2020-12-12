#if 1
#include <iostream>
#include <memory>

template<typename T>
class SmartPointer {
private:
    T* _ptr;
    size_t* _count;
public:
    SmartPointer(T* ptr = nullptr) :
            _ptr(ptr) {
        if (_ptr) {
            _count = new size_t(1);
        } else {
            _count = new size_t(0);
        }
    }

    SmartPointer(const SmartPointer& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            (*this->_count)++;
        }
    }

    SmartPointer& operator=(const SmartPointer& ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }

        if (this->_ptr) {
            (*this->_count)--;
            if (this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }

        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        return *this;
    }

    T& operator*() {
        assert(this->_ptr == nullptr);
        return *(this->_ptr);

    }

    T* operator->() {
        assert(this->_ptr == nullptr);
        return this->_ptr;
    }

    ~SmartPointer() {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    size_t use_count(){
        return *this->_count;
    }
};

int main() {
    {
        SmartPointer<int> sp(new int(10)); //sp=1
        SmartPointer<int> sp2(sp); //sp=2 sp2=2
        SmartPointer<int> sp3(new int(20)); //sp3=1
        sp2 = sp3;//sp2=2 sp3=2
        std::cout << sp.use_count() << std::endl;
        std::cout << sp2.use_count() << std::endl;
        std::cout << sp3.use_count() << std::endl;
    }
    //delete operator
}
#else
#include <iostream>
#include <memory>
using namespace std;
class Node {
public:
	Node() {
		cout << "construction" << endl;
	}
	~Node() {
		cout << "deconstruction" << endl;
	}
public:
	shared_ptr<Node>next;
};

void test() {
	shared_ptr<Node>sp1(new Node);
    shared_ptr<Node>sp2(sp1);
	shared_ptr<Node>sp3(new Node);
	sp1->next = sp2;
	sp3->next = sp1;
	cout << sp1.use_count()<<endl;
	cout << sp3.use_count()<<endl;
}

int main(){
	test();
	return 0;
}
#endif