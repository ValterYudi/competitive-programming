#include <iostream>

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;

    double expectedPackets = static_cast<double>(N) / (N - 1);
    std::cout << expectedPackets << std::endl;

    return 0;
}