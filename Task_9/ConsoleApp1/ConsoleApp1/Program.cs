// See https://aka.ms/new-console-template for more information
using System;

namespace code
{
    public delegate double Amount(double x);

    public delegate void MyEvent(ConsoleKeyInfo sign);

     class MyEventClass
    {
        public event MyEvent SignPressed;

        public void Action()
        {
            if (SignPressed == null) return;
            var sign = Console.ReadKey(true);
            SignPressed(sign);
        }
    }

     static class Program
    {
        private static void Handler(ConsoleKeyInfo sign)
        {
            var e = sign.KeyChar;
            if (e == 'e' || e == 'E')
                Console.WriteLine($"Eliya, pressed '{e}'");
        }

        private static double FunctionOne(double x)
        {
            return 1 / (Math.Pow(Math.Abs(Math.Cos(x)), 1 / 3));
        }

        private static double FunctionTwo(double x)
        {
            return 1 / (Math.Sqrt(x * x));
        }

        private static double FunctionThree(double x)
        {
            return Math.Pow(Math.Cos(x), 2);
        }

        private static double Trapezoid(Amount temp, double a, double b)
        {
            int counter;
            double x;
            double sum = 0;
            const int n = 90;
            var dx = (b - a) / n;

            for (counter = 0, x = a; counter < n; counter++)
            {
                sum += (temp(x) + temp(x + dx)) / 2 * dx;
                x += dx;
            }

            return sum;
        }

        private static void Main()
        {
            const double a = 20;
            const double b = 30;

            Console.WriteLine(Trapezoid(FunctionOne, a, b));
            Console.WriteLine(Trapezoid(FunctionTwo, a, b));
            Console.WriteLine(Trapezoid(FunctionThree, a, b));

            Console.ReadLine();

            var myEventClass = new MyEventClass();

            myEventClass.SignPressed += Handler;
            myEventClass.Action();

            Console.ReadLine();
        }
    }
}
