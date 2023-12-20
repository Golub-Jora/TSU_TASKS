#include <iostream>
#include <cmath>
#include <locale.h>

class RightTriangle {
private:
    double xA, yA;
    double a, b;

public:
    RightTriangle() : xA(0.0), yA(0.0), a(0.0), b(0.0) {}

    void input() {
        std::cout << "������� ���������� ����� A (x y): ";
        std::cin >> xA >> yA;
        std::cout << "������� ����� ������ a: ";
        std::cin >> a;
        std::cout << "������� ����� ������ b: ";
        std::cin >> b;
    }

    void output() {
        std::cout << "���������� ����� A: (" << xA << ", " << yA << ")\n";
        std::cout << "����� ������ a: " << a << "\n";
        std::cout << "����� ������ b: " << b << "\n";
    }

    double calculateHypotenuse() {
        return sqrt(a * a + b * b);
    }

    double calculateArea() {
        return 0.5 * a * b;
    }

    double calculatePerimeter() {
        return a + b + calculateHypotenuse();
    }

    double calculateInscribedCircleRadius() {
        return calculateArea() / (a + b + calculateHypotenuse());
    }

    double calculateCircumscribedCircleRadius() {
        return calculateHypotenuse() / 2;
    }

    double calculateHeight() {
        return (2 * calculateArea()) / calculateHypotenuse();
    }

    double calculateSmallerAngle() {
        return asin(a / calculateHypotenuse());
    }

    bool isIsosceles() {
        return a == b;
    }

    void multiply(double factor) {
        a *= factor;
        b *= factor;
    }

    bool isEqual(const RightTriangle& other) {
        return (xA == other.xA && yA == other.yA && a == other.a && b == other.b);
    }

    bool isSimilar(const RightTriangle& other) {
        double ratioA = a / other.a;
        double ratioB = b / other.b;
        return (ratioA == ratioB);
    }

};

int main() {
    setlocale(0,"");
    RightTriangle triangle;
    triangle.input();
    triangle.output();

    std::cout << "����������: " << triangle.calculateHypotenuse() << "\n";
    std::cout << "�������: " << triangle.calculateArea() << "\n";
    std::cout << "��������: " << triangle.calculatePerimeter() << "\n";
    std::cout << "������ ��������� ����������: " << triangle.calculateInscribedCircleRadius() << "\n";
    std::cout << "������ ��������� ����������: " << triangle.calculateCircumscribedCircleRadius() << "\n";
    std::cout << "������, ��������� �� ����������: " << triangle.calculateHeight() << "\n";
    std::cout << "������� ���� � ������������ (�������): " << triangle.calculateSmallerAngle() << "\n";
    std::cout << "�������������� �����������: " << (triangle.isIsosceles() ? "��" : "���") << "\n";
    //std::cout << "�������������� �����������: " << triangle.isIsosceles() << "\n";

    double factor;
    std::cout << "������� ����� ��� ��������� ������������: ";
    std::cin >> factor;
    triangle.multiply(factor);
    std::cout << "��������� ������������ ����� ���������:\n";
    triangle.output();

    RightTriangle anotherTriangle;
    anotherTriangle.input();

    std::cout << "������������ �����: " << (triangle.isEqual(anotherTriangle) ? "��" : "���") << "\n";
    std::cout << "������������ �������: " << (triangle.isSimilar(anotherTriangle) ? "��" : "���") << "\n";

    return 0;
}
