#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};

    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2 == 0) {
            // Move even numbers to front
            lst.splice(lst.begin(), lst, it);
        }

        ++it; // ❌ Moves from a spliced position
    }

    std::cout << "Buggy Version (undefined behavior): ";
    for (int x : lst) std::cout << x << " ";
}
