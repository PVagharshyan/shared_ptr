#include <iostream>
#include "shared_ptr.h"

int main() {
    shared_ptr<int> ptr(new int);
    shared_ptr<int> ptr_1 = ptr;
    shared_ptr<int> ptr_2 = ptr_1;
    shared_ptr<int> ptr_3(new int);
    return 0;
}