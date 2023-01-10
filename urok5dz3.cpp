#include <iostream>
#include <windows.h>
#include <string>

class Figura
{
protected:
    std::string name_figura = "Фигура";
    int count_storon = 0;  

public:

    virtual void print_info(Figura* figura) {
        std::cout << figura->get_name() << "\n";
        figura->is_right() ? (std::cout << "Правильная\n") : (std::cout << "Не правильная\n");
        std::cout << "Количество сторон : " << figura->get_count_storon() << "\n" << std::endl;
    };
    Figura():Figura(0){
    }
    Figura(int count_storon){
        this->count_storon = count_storon;
    }

    int get_count_storon() { return count_storon; }
    std::string get_name() { return name_figura; }

    virtual bool is_right() {
        if (get_count_storon() != 0) {
            return false;
        }
        return true;
    }; 

};

//// трехугольник
class Triangle : public Figura
{
protected:
    // углы
    int A = 0;
    int B = 0;
    int C = 0;
    // стороны
    int a = 0;
    int b = 0;
    int c = 0;

public:
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }

    Triangle(int A, int B, int C, int a, int b, int c) {
        name_figura = "Треугольник";
        count_storon = 3;

        this->A = A;
        this->B = B;
        this->C = C;
        this->a = a;
        this->b = b;
        this->c = c;


    };

    bool is_right() override {
        if ((get_A() + get_B() + get_C()) != 180 || get_count_storon() != 3) {
            return false;
        }
        return true;
    };
    void print_info(Figura* figura) override {
        std::cout << figura->get_name() << "\n";
        figura->is_right() ? (std::cout << "Правильная\n") : (std::cout << "Не правильная\n");
        std::cout << "Количество сторон : " << figura->get_count_storon() << "\n";
        std::cout << "Стороны: a=" + std::to_string(get_a()) + " b=" + std::to_string(get_b()) + " c=" + std::to_string(get_c()) << "\n";
        std::cout << "Углы: A=" + std::to_string(get_A()) + " B=" + std::to_string(get_B()) + " C=" + std::to_string(get_C()) << "\n" << std::endl;
    };
};

// прямой треугольник
class Triangle90 : public Triangle
{

public:
    Triangle90(int A, int B, int a, int b, int c) : Triangle(A, B, 90, a, b, c) {
        name_figura = "Прямоугольный треугольник";
    };


    bool is_right() override {
        if (get_C() != 90 || !Triangle::is_right()) {
            return false;
        }
        return true;
    };
};

// равнобедренный
class Triangle2line : public Triangle
{
public:
    Triangle2line(int A, int B, int a, int b) : Triangle(A, B, A, a, b, a) {
        name_figura = "Равнобедренный треугольник";
    };

    bool is_right() override {
        if (get_A() != get_C() || get_a() != get_c() || !Triangle::is_right()) {
            return false;
        }
        return true;
    };
};

// равносторонний
class Triangle3line : public Triangle
{

public:
    Triangle3line(int a) : Triangle(60, 60, 60, a, a, a) {
        name_figura = "Равносторонний треугольник";
    };
    bool is_right() override {
        if (get_a() != get_b() || get_b() != get_c()  || get_A() != 60 || get_B() != 60 || get_B() != 60 || !Triangle::is_right()) {
            return false;
        }
        return true;
    };
};

//// четырехугольник 
class Quatro : public Figura
{
protected:
    // углы
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    // стороны
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

public:    
      int get_a() { return a; }
      int get_b() { return b; }
      int get_c() { return c; }
      int get_d() { return d; }
      int get_A() { return A; }
      int get_B() { return B; }
      int get_C() { return C; }
      int get_D() { return D; }
    Quatro(int A, int B, int C, int D, int a, int b, int c, int d) {
        name_figura = "Четырехугольник";
        count_storon = 4;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    };
    bool is_right() override {
        if ((get_a() + get_b() + get_c() + get_d()) != 360 || get_count_storon() !=4) {
            return false;
        }
        return true;
    };
    void print_info(Figura* figura) override {
        std::cout << figura->get_name() << "\n";
        figura->is_right() ? (std::cout << "Правильная\n") : (std::cout << "Не правильная\n");
        std::cout << "Количество сторон : " << figura->get_count_storon() << "\n";
        std::cout << "Стороны: a=" + std::to_string(get_a()) + " b=" + std::to_string(get_b()) + " c=" + std::to_string(get_c()) + " d=" + std::to_string(get_d()) << "\n";
        std::cout << "Углы: A=" + std::to_string(get_A()) + " B=" + std::to_string(get_B()) + " C=" + std::to_string(get_C()) + " D=" + std::to_string(get_D()) << "\n" << std::endl;
    };
};

// Параллелограмм
class Parrallelogram : public Quatro {
public:
    Parrallelogram(int A, int B, int a, int b) : Quatro(A, B, A, B, a, b, a, b) {
        this->name_figura = "Параллелограмм";
    };
    bool is_right() override {
        if (get_a() != get_c() || get_b() != get_d() || get_A() != get_C() || get_B() != get_D() || !Quatro::is_right()) {
            return false;
        }
        return true;
    };
};

// ромб
class Romb : public Parrallelogram {
public:
    Romb(int a, int A, int B) :Parrallelogram(A, B, a, a) {
        name_figura = "Ромб";
    };
    bool is_right() override {
        if (get_a() != get_b() || !Parrallelogram::is_right()) {
            return false;
        }
        return true;
    };
};

// Прямоугольник
class Pramougolnik : public Parrallelogram {

public:
    Pramougolnik(int a, int b) :Parrallelogram(90, 90, a, b) {
        name_figura = "Прямоугольник";
    };
    bool is_right() override {
        if (get_A() != 90 || get_B() != 90 || !Parrallelogram::is_right()) {
            return false;
        }
        return true;
    };
};

// Квадрат 
class Kvadrat : public Pramougolnik {
public:
    Kvadrat(int a) : Pramougolnik(a, a) {
        name_figura = "Квадрат";
    };
    bool is_right() override {
        if (get_a() != get_b() || !Pramougolnik::is_right()) {
            return false;
        }
        return true;
    };
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    //Figura figura;  
    Figura figura(0);
    Triangle triangle(50, 60, 70, 10, 20, 30);
    Triangle90 triangle90( 50, 60, 10, 20, 30);
    Triangle90 triangle90_(50, 40, 10, 20, 30);
    Triangle2line triangle2line(50, 60, 10, 20);
    Triangle2line triangle2line_(50, 80, 10, 20);
    Triangle3line triangle3line(30);
    Quatro quatro(10, 20, 30, 40, 50, 60, 70, 80);
    Parrallelogram parrallelogram(20, 30, 30, 40);
    Romb romb(30, 30, 40);
    Pramougolnik pramougolnik(10, 20);
    Kvadrat kvadrat(20);

    figura.print_info(&figura);
    triangle.print_info(&triangle);
    triangle90.print_info(&triangle90);
    triangle90_.print_info(&triangle90_);
    triangle2line.print_info(&triangle2line);
    triangle2line_.print_info(&triangle2line_);
    triangle3line.print_info(&triangle3line);
    quatro.print_info(&quatro);
    parrallelogram.print_info(&parrallelogram);
    romb.print_info(&romb);
    pramougolnik.print_info(&pramougolnik);
    kvadrat.print_info(&kvadrat);
}
