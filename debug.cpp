#include <iostream>

consteval int cube(int x) {
    return x * x * x;
}

int main() {
    constexpr int result = cube(3);
    std::cout << result << '\n'; 
}
