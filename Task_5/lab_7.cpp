#include <iostream>

class Number
{
private:
  unsigned int value;

public:
  Number(unsigned int value)
  {
    this->value = value;
  }

  unsigned int getValue()
  {
    return value;
  }

  void setValue(unsigned int value)
  {
    this->value = value;
  }

  virtual void print()
  {
    std::cout << value << std::endl;
  }
};

class Integer : public Number
{
public:
  Integer(unsigned int value) : Number(value) {}
  void print() override
  {
    std::cout << "Integer: " << getValue() << std::endl;
  }
};

class Binary : public Number
{
public:
  Binary(unsigned int value) : Number(value) {}
  std::string toBinary()
  {
    unsigned int n = getValue();
    std::string r;
    while (n != 0)
    {
      r = (n % 2 == 0 ? "0" : "1") + r;
      n /= 2;
    }
    return r;
  }

  void print() override
  {
    std::cout << "Binary: " << toBinary() << std::endl;
  }
};

class Hexadecimal : public Number
{
public:
  Hexadecimal(unsigned int value) : Number(value) {}
  std::string toHexadecimal()
  {
    const char *digits = "0123456789ABCDEF";
    unsigned int n = getValue();
    std::string r;
    while (n != 0)
    {
      r = digits[n % 16] + r;
      n /= 16;
    }
    return r;
  }
  void print() override
  {
    std::cout << "Hexadecimal: " << toHexadecimal() << std::endl;
  }
};

int main()
{
  Number *numbers[3];
  Integer i(165);
  Binary b(165);
  Hexadecimal h(165);
  numbers[0] = &i;
  numbers[1] = &b;
  numbers[2] = &h;

  for (int i = 0; i < 3; i++)
  {
    numbers[i]->print();
  }
}