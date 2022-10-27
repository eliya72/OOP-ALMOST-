// See https://aka.ms/new-console-template for more information
using System;

namespace MyApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            double kinetic, potential;
            double m, t, v, g=9.8, h;
            Console.WriteLine("Enter m value:");
            m = Convert.ToInt32(Console.ReadLine());
            if (m<0) {
                Console.WriteLine($"\nYour m value is negative");
                Environment.Exit(0);
            }
            Console.WriteLine("Enter v value:");
            v = Convert.ToInt32(Console.ReadLine());
            kinetic = (m*v*v)/2;
            Console.WriteLine("Enter h value:");
            h = Convert.ToInt32(Console.ReadLine());
            if (h<0)
            {
                Console.WriteLine($"\nYour h value is negative");
                Environment.Exit(0);
            }
            potential = m*g*h;
            Console.WriteLine($"\nYour kinetic energy is:\t{kinetic}\n");
            Console.WriteLine($"\nYour potential energy is: {potential}\n");
        }
    }
}