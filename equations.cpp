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
        out << "����� ���������: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    }
    else if (discriminant == 0) {
        x1 = -b / (2 * a);
        out << "��������� ����� ������������ ������: x = " << x1 << std::endl;
    }
    else {
        out << "��������� �� ����� �������������� ������" << std::endl;
    }
}

void SolveLinearEquation(float b, float c, std::ofstream& out) {
    float x1;

    x1 = -c / b;
    out << "��������� �������� � ����� ������������ ������: x = " << x1 << std::endl;
}

void SolveEquation(float a, float b, float c, std::ofstream& out) {
    if (a != 0) {
        SolveQuadraticEquation(a, b, c, out);
    }
    else if (b != 0) {
        SolveLinearEquation(b, c, out);
    }
    else if (c != 0) {
        out << "��������� �������������" << std::endl;
    }
    else {
        out << "��������� ����� ��� ������ �������� x" << std::endl;
    }
}