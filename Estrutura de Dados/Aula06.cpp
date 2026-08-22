#include <iostream>

class FunctionClass{
    public:
        FunctionClass() {}

    double operator()(double x) {
        return 2 * x;
    }

}; 

double sum(FunctionClass g, int N, int m) {
    double total = 0.0;

    for (int i = 0; i <= m; i++) {
        total += g(N);
    }

    return total;
}

int main(){
    int N = 10;
    int m = 10;

    FunctionClass g;
    double result = sum(g, N, m);

    std::cout << "Sum: " << result << std::endl;
    return 0;
}  