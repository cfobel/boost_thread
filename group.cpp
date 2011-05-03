#include <boost/thread.hpp>
#include <iostream>
#include <vector>
using namespace std;

void task1() { 
    cout << "task1()\n";
}

void task2() { 
    cout << "task2()\n";
}

int main (int argc, char ** argv) {
    using namespace boost; 
    thread_group threads;
    threads.add_thread(new thread(task1));
    threads.add_thread(new thread(task2));
    threads.add_thread(new thread(task1));
    threads.add_thread(new thread(task1));
    threads.add_thread(new thread(task1));
    threads.add_thread(new thread(task2));

    threads.join_all();
    return 0;
}
