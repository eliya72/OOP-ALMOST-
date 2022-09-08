//Завдання до лабораторної роботи
// 1. Визначити користувальницький клас у відповідності з варіантом 
// завдання. 
// 2. Визначити в класі конструктор без параметрів і конструктор з 
// параметрами.
// 3. Визначити в класі деструктор. 
// 4. Визначити в класі компоненти-функції для перегляду та ініціалізації 
// полів даних. 
// 5. Визначити покажчик на компоненту-функцію. 
// 6. Визначити покажчик на екземпляр класу. 
// 7. Написати демонстраційну програму, в якій створюються і руйнуються 
// об'єкти певного класу і кожен виклик конструктора і деструктора 
// супроводжується видачею відповідного повідомлення. (який об'єкт який 
// конструктор або деструктор викликав). 
// 8. Показати в програмі використання покажчика на об'єкт і покажчика на 
// компоненту функцію.

// Варіант 7. 
// Створити клас «смайлик», такий, що: 🙂
// а) його екземпляр містить розмір радіуса особи R і радіуса r очей.
// b) його конструктор без параметра створює екземпляр зі значенням 0, а 
// конструктор з параметрами створює екземпляр з відповідним значенням 
// R і r.
// c) його методи дозволяють отримувати і присвоювати значення R і r і 
// обчислювати значення площі.
// d) функція print_sqrt () виводить на екран значення її R, r площі (без площі 
// очей).

//#include <conio.h>
#include <iostream>
#define PI 3.14159

using namespace std;


class Smile{
    float R, r;
public:
    Smile();
    Smile(float, float);
    ~Smile();
    void print_sqrt(){
      cout << "R = " << getBodyRadius() << "; r = " << getEyesRadius() << "; area = " << getArea() << endl;
    }
    float getEyesArea(){
      return PI*r*r;
    }
    float getBodyArea(){
      return PI*R*R; 
    }
    float getArea(){
        return getBodyArea()-(2*getEyesArea());
    }
    float getBodyRadius(){
        return R;
    }
    float getEyesRadius(){
        return r;
    }
    void setBodyRadius(float radius){
        R = radius;
    }
    void setEyeRadius(float radius){
        r = radius;
    }
};

Smile::Smile(){
    int a = 0;
    cout << "Конструктор без параметрів" << a << endl;
}

Smile::Smile(float radius, float radiusEye){
    R = radius; 
    r = radiusEye;
    cout << "Конструктор із парамерами" << radius << endl;
}

Smile::~Smile(){
    cout << "Деструктор" << endl;
}

int main(){
    Smile s1(5,1);
    s1.print_sqrt();
    Smile s2(10,2);
    Smile *s2_ptr = &s2;
    // void (Smile::*setter)(float);
    // setter = &Smile::setBodyRadius;
    // (s2_ptr->*setter)(15);
    // s2_ptr->print_sqrt();
    void (Smile::*print)();
    print = &Smile::print_sqrt;
    (s2_ptr->*print)();
}