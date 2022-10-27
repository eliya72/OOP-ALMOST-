using System;

namespace MyApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter x value:");
            int x = Convert.ToInt32(Console.ReadLine());
            if (x == 0) { Environment.Exit(0); }
            string con = (x < -10) ? "Less then -10" : (x < -1) ? "Less then -1" : (x > 10) ? "Bigger then 10" : "Bigger then 1";
            Console.WriteLine("Enter y value:");
            int y = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter z value:");
            int z = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"\nYour x is in this condition:\t{con}\n");
            int v = (z * z);
            double v1 = 3 + z * Math.Sin(y);
            double res = x + (v / v1);
            con = (res >= 0) ? "Positive" : "Negative";
            Console.WriteLine($"Your result is:\t{res}\t{con}");
        }
    }
}