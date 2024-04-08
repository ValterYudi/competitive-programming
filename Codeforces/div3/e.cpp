#include <iostream>
#include <cmath>

int min_balls_to_buy(long long n) {
    int k = std::floor(std::sqrt(2 * n + 0.25) - 0.5);
    return k + 1;
}

int main() {
    int t; // Número de casos de teste
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        long long n; // Número de tipos de sorvetes
        std::cin >> n;
        std::cout << min_balls_to_buy(n) << std::endl;
    }

    return 0;
}
