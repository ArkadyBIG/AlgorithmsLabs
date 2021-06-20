#include <iostream>
#include "BinominalHeap.h"

int main() {

    BinominalHeap<int> tree;
    for (int i : {0, 5, 6, 4, 3, 7, 9}) {
        std::cout << "Adding " << i << std::endl;
        tree.insert(i);
        std::cout << "NEW TREE\n";
        tree.print();
    }
    return 0;
}
