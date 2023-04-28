#include <iostream>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n) :name(n) {
        cout << "jestem konstruktorem klasy wirtualnej Shape" << endl;
    };
    virtual ~Shape() {
        cout << "jestem destruktorem klasy Shape" << endl;
    };
    void setName(string n) { name = n; }
    string getName() { return name; }
    virtual double area() = 0;
};

class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(string n, double w, double h) :Shape(n), width(w), height(h) {
        cout << "jestem konstruktorem klasy Rectangle" << endl;
    }
    virtual ~Rectangle() {
        cout << "jestem destruktorem klasy Rectangle" << endl;
    };
    double area() {
        return width * height;
    }
};

class Square : public Rectangle {
public:
    Square(string n, double w) : Rectangle(n, w, w) {
        cout << "jestem konstruktorem klasy Square" << endl;
    }
    virtual ~Square() {
        cout << "jestem destruktorem klasy Square" << endl;
    };
    double area() {
        return width * height;
    }

};

class Circle :public Shape {
protected:
    double radius;
public:
    Circle(string n, double r) :Shape(n), radius(r) {};
    virtual ~Circle() {}
    double area() { return 3.14 * radius * radius; }
    virtual double capacity() = 0;
};

class Cylinder : public Circle {
private:
    double height;
public:
    Cylinder(string n, double r, double h) :Circle(n, r), height(h) {};
    virtual ~Cylinder() {}
    double capacity() {
        return Circle::area() * height;
    }
    double area() {
        return 2 * Circle::area() + 2 * 3.14 * radius * height;
    }
};

class Function {
protected:
    Function() {};
    virtual ~Function() {};
public:
    virtual float calculate(float x) = 0;
};

class LinearFunction : public Function {
    float a, b;
public:
    LinearFunction(float a, float b) :a(a), b(b) {};
    virtual ~LinearFunction() {};
    float calculate(float x) {
        return a * x + b;
    }
};

double bisection(LinearFunction* f, double p, double k, double d)
{
    if (f->calculate(p) * f->calculate(k) >= 0) {
        cout << "Podano zly przedzial\n";
        return false;
    }

    double c = p;
    while ((k - p) >= d) {
        c = (p + k) / 2;

        if (f->calculate(c) == 0.0) break;
        else if (f->calculate(c) * f->calculate(p) < 0) k = c;
        else p = c;
    }
    return c;
}

int main()
{
    unsigned short int zadanie = 0;
    do {
        cout << endl;
        cout << "Lista zadan" << endl;
        cout << "1) Zadanie pierwsze" << endl;
        cout << "2) Zadanie drugie" << endl;
        cout << "3) Zadanie trzecie" << endl;
        cout << "4) Zadanie czwarte" << endl;
        cout << "5) Wyjscie" << endl;

        cout << "Prosze podac numer zadania: ";
        cin >> zadanie;
        cout << endl;
        switch (zadanie) {
        case 1:
        {
            Rectangle r("rectangle", 5, 5);
            cout << r.area() << endl;
            cout << endl;
            Square s("square", 3);
            cout << s.area() << endl;
            cout << endl;
            Shape& s_r = r;
            cout << s_r.area() << endl;
            cout << endl;
            Shape& s_s = s;
            cout << s_s.area() << endl;
            cout << endl;
            Shape* wsk_r = &r;
            cout << wsk_r->area() << endl;
            cout << endl;
            Shape* wsk_s = &s;
            cout << wsk_s->area() << endl;
            cout << endl;

            break;
        }
        case 2:
        {
            Cylinder c("cylinder", 3, 3);
            Circle* s;
            s = &c;
            cout << "Objetosc: " << s->capacity() << endl;
            cout << "Pole powierzchni calkowitej: " << s->area() << endl;
            break;
        }
        case 3:
        {
            LinearFunction l(1, 0);
            Function* f;
            f = &l;
            cout << f->calculate(5);
            break;
        }
        case 4:
        {
            LinearFunction l(1, 1);
            double a, b = 0, c;
            cout << "podaj przedzial A: ";
            cin >> a;
            cout << "podaj przedzial B: ";
            cin >> b;
            cout << "Podaj z jaka dokladnoscia: ";
            cin >> c;
            cout << "Funkcja w przedziale od " << a << " do " << b << " posiada miejsce zerowe w x = " << bisection(&l, a, b, c);
            break;
        }
        
        case 5: break;
        default: cout << "Nie ma takiej opcji do wyboru!" << endl;
        }
    } while (zadanie != 5);

    return 0;
}
