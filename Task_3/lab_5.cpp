#include <iostream>
#define PI 3.14159

class Smile{
private:
  float in_radius;
  float out_radius;

public:
  Smile(float r, float R)
  {
    r = r > 0 ? r : 0;
    R = R > 0 ? R : 0;
    in_radius = r;
    out_radius = R;
  }

  Smile()
  {
    in_radius = 0;
    out_radius = 0;
  }

  auto getArea() -> float
  {
    return ((PI * out_radius * out_radius)-(2 * (PI * in_radius * in_radius)));
  }

  auto getIn_Radius() -> float
  {
    return in_radius;
  }

  auto getOut_Radius() -> float
  {
    return out_radius;
  }

  void setIn_Radius(float r)
  {
    r = r > 0 ? r : 0;
    in_radius = r;
  }

  void setOut_Radius(float R)
  {
    R = R > 0 ? R : 0;
    out_radius = R;
  }

  void print()
  {
    std::cout << "in radius: " << getIn_Radius() << ";  out radius: " << getOut_Radius() << ";  Volume: " << getArea() << std::endl;
  }

  Smile operator+(Smile &other)
  {
    Smile result(in_radius + other.getIn_Radius(), out_radius + other.getOut_Radius());
    return result;
  }

  Smile operator++()
  {
    in_radius++;
    out_radius++;
    return *this;
  }

  Smile operator++(int a)
  {
    Smile for_pointer = *this;
    in_radius++;
    out_radius++;
    return for_pointer;
  }

  friend std::ostream &operator<<(std::ostream &for_pointer, Smile &obj);
};

std::ostream &operator<<(std::ostream &for_pointer, Smile &obj)
{
  for_pointer << "In radius: " << obj.getIn_Radius() << ";  Out radius: " << obj.getOut_Radius() << ";  Area: " << obj.getArea();
  return for_pointer;
}

int main()
{
  Smile rad_Rad_1(2, 4);
  Smile rad_Rad_2(2, 4);
  Smile rad_Rad_sum = rad_Rad_1 + rad_Rad_2;
  std::cout << "++in radius ++out radius: " << rad_Rad_1 << std::endl;
  std::cout << "default in and out radius" << rad_Rad_2 << std::endl;
  std::cout << "sum of two default in and out radiuses: " << rad_Rad_sum << std::endl;
  return 0;
}