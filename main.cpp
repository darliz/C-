#include <iostream>
#include <fstream>
#include "equations.h"

int main() {

    setlocale(LC_ALL, "Russian");

    float a, b, c;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    input >> a >> b >> c;

    SolveEquation(a, b, c, output);

    input.close();
    output.close();

    return 0;
}