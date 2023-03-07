#include "equations.h"
#include <cmath>

float CalculateDiscriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

void SolveQuadraticEquation(float a, float b, float c, std::ofstream& out) {
    float x1, x2, discriminant;

    discriminant = CalculateDiscriminant(a, b, c);

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        out << "Корни уравнения: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    }
    else if (discriminant == 0) {
        x1 = -b / (2 * a);
        out << "Уравнение имеет единственный корень: x = " << x1 << std::endl;
    }
    else {
        out << "Уравнение не имеет действительных корней" << std::endl;
    }
}

void SolveLinearEquation(float b, float c, std::ofstream& out) {
    float x1;

    x1 = -c / b;
    out << "Уравнение линейное и имеет единственный корень: x = " << x1 << std::endl;
}

void SolveEquation(float a, float b, float c, std::ofstream& out) {
    if (a != 0) {
        SolveQuadraticEquation(a, b, c, out);
    }
    else if (b != 0) {
        SolveLinearEquation(b, c, out);
    }
    else if (c != 0) {
        out << "Уравнение противоречиво" << std::endl;
    }
    else {
        out << "Уравнение верно для любого значения x" << std::endl;
    }
}