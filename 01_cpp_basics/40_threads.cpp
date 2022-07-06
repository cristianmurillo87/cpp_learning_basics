/**
 * Threads: blocks of code executed at the same time but independently
 * (Similar to an asynchronous function in javascript) 
*/
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <ctime>

int get_random(int max)
{
    srand(time(NULL));
    return rand() % max;
}

void run_thread(int id)
{
    // get current time of the system
    auto now_time = std::chrono::system_clock::now();
    time_t sleep_time = std::chrono::system_clock::to_time_t(now_time);
    tm my_local_time = *localtime(&sleep_time);

    std::cout << "Thread " << id << " Sleep Time: " << ctime(&sleep_time) << std::endl;

    std::cout << "Month: " << my_local_time.tm_mon << std::endl;
    std::cout << "Day: " << my_local_time.tm_mday << std::endl;
    std::cout << "Year: " << my_local_time.tm_year + 1900 << std::endl;
    std::cout << "Hours: " << my_local_time.tm_hour << std::endl;
    std::cout << "Minutes: " << my_local_time.tm_min << std::endl;
    std::cout << "Seconds: " << my_local_time.tm_sec << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(get_random(3)));
    now_time = std::chrono::system_clock::now();
    sleep_time = std::chrono::system_clock::to_time_t(now_time);

    std::cout << "Thread: " << id << " Awake time: " << ctime(&sleep_time) << std::endl;
}

int main()
{
    std::thread th1(run_thread, 1);
    // joint to the main thread, so that when finish executing the code in the thread,
    // the main() function will continue its execution
    th1.join();

    std::thread th2(run_thread, 1);
    th2.join();

    return 0;
}