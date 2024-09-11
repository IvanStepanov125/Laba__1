#include "Masiv.h"
#include <chrono>
#include <random>


int main(){

    ArrayHandler arrayhandler = ArrayHandler(5);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    // Реализовать заполнения массива на 10000000000
    srand(time(NULL));
    for (long long int i = 0; i < 10000000000; i++) {
        arrayhandler.Append(rand() % 100);
    }
    // Продемонстрировать поиск элемента 
    std::cout << arrayhandler.GetIndexElem(45) << std::endl;
    // Продемонстрировать максимальный элемент 
    std::cout << arrayhandler.GetMax() << std::endl;
    // Продемонстрировать минимальный элемент
    std::cout << arrayhandler.GetMin() << std::endl;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;


    return 0;
}