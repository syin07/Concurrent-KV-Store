#include "kvstore/version.h"

#include <iostream>

int main() {
    std::cout << "kvserver " << kvstore::version() << "\n";
    return 0;
}
