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
