#pragma once

#include <condition_variable>
#include <deque>
#include <mutex>
#include <string>
#include <thread>
#include <list>
#include <vector>

template <typename T>
class BlockingQueue {
public:
    BlockingQueue(uint size) : size_(size) {}
    BlockingQueue() {}

    /**
     * @brief �������push_backһ��Ԫ��
     * **/
    void put(const T x) {
        std::unique_lock<std::mutex> lock(mutex_);
        if (size_ != 0 && queue_.size() > size_) {
            queue_.pop_front();
        }
        queue_.push_back(std::move(x));
        not_empty_.notify_all();  //��������push������ͻ�������wait���߳�
    }

    /**
     * @brief ��ȡ�����е�һ��Ԫ�أ���������Ԫ�أ�
     * Ԫ��һ����ȡ���ʹӶ�����ɾ��
     * **/
    T take() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (queue_.empty()) {
            not_empty_.wait(lock);  //�������Ϊ�գ��߳̾��ڴ��������𣬵ȴ�����
        }
        const T front = queue_.front();
        queue_.pop_front();
        return front;
    }

    /**
     * @brief ȡ������������Ԫ��(ȡ����ʹӶ�����ɾ��),��push_back��һ��vector��
     * **/
    int take(std::vector<T>* v, size_t count) {
        std::unique_lock<std::mutex> lock(mutex_);
        while (queue_.empty()) {
            not_empty_.wait(lock);  //�������Ϊ�գ��߳̾��ڴ��������𣬵ȴ�����
        }
        while (!queue_.empty() && count--) {
            v->push_back(queue_.front());
            queue_.pop_front();
        }

        return v->size();
    }

    /**
     * @brief ����������ȡ�����ж�ӦԪ��
     * **/
    T get(size_t index) {
        std::unique_lock<std::mutex> lock(mutex_);
        while (queue_.empty()) {
            not_empty_.wait(lock);
        }
        return queue_.at(index);
    }

    /**
     * @brief ��ȡ����Ԫ�ظ���
     * **/
    size_t size() const {
        std::unique_lock<std::mutex> lock(mutex_);
        return queue_.size();
    }

private:
    mutable std::mutex mutex_;
    std::condition_variable not_empty_;
    std::deque<T> queue_;
    // std::list<T> queue_;//˫������

    uint size_ = 0;
};
