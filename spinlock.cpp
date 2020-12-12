#include "spinlock.h"
int num = 0;
spin_mutex sm;

void thread_proc()
{

  for(int i = 0; i < 100000; ++i) {
    sm.lock();
    ++num;
    sm.unlock();
  }
}

int main()
{
  std::thread td1(thread_proc), td2(thread_proc);
  td1.join();
  td2.join();
  std::cout << num << std::endl;
  return 0;
}
