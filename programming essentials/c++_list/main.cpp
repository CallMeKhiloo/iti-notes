#include "list.h"

int main()
{
    PyList lst;

    lst.append(10);
    lst.append(3.14);
    lst.append(std::string("hello"));
    lst.append(true);

    // positive indexing
    std::cout << lst.get<int>(0) << "\n";         // 10
    std::cout << lst.get<double>(1) << "\n";      // 3.14
    std::cout << lst.get<std::string>(2) << "\n"; // hello

    // negative indexing (like Python)
    std::cout << lst.get<bool>(-1) << "\n";        // true
    std::cout << lst.get<std::string>(-2) << "\n"; // hello

    return 0;
}