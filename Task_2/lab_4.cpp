#include <iostream>

using namespace std;

class MyArray
{
private:
    int *array;
    int length;

public:
    MyArray(int length);
    ~MyArray();
    void screen();
    friend void my_friend(MyArray &object_in_func);
};

MyArray::MyArray(int temp)
{
    length = temp;
    array = new int[length];
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            array[i] = i - 4;
        }
        else
        {
            array[i] = i - 6;
        }
    }
}

void MyArray::screen()
{   cout << "\n";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void my_friend(MyArray &object_in_func)
{ 
    int mult = 1;
    for (int i = 0; i < object_in_func.length; i++)
    {
        if (object_in_func.array[i] % 2 != 0)
        {
            cout << object_in_func.array[i] << " ";
            mult *= object_in_func.array[i]; 
        }
    }
    cout << "\nMultiply = " << mult << "\n\n";
}

MyArray::~MyArray()
{
    delete[] array;
}

int main()
{
    MyArray a(8);
    a.screen();
    my_friend(a);

    return (0);
}