#include <iostream>
#include <list>

int main() {
    std::list<int> myList = {10, 20, 30, 40, 50};

    auto it40 = std::next(myList.begin(), 3); // points to 40
    auto it50 = std::next(myList.begin(), 4); // points to 50

    // Move 50 before the beginning
    myList.splice(std::next(myList.begin()), myList, it40);
    myList.splice(std::next(myList.begin()), myList, it50);
    // Move 40 before the beginning

    std::cout << "After moving 40 and 50 to the front:\n";
    for (int x : myList) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
