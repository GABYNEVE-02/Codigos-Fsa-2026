#include <iostream>

double g(double x) {
    return x * 2;
}

double soma(double (*g)(double), int N, int Passos) {
    double total = 0.0;

    for (int i = 0; i <= Passos - 1; i++) {
        total += g(N);
    }

    return total;
}

int main() {
    int N = 10;
    int Passos = 2;

    double result = soma(g, N, Passos);

    std::cout << "Soma: " << result << std::endl;
    return 0;
}
 