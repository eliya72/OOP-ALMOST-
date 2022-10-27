// See https://aka.ms/new-console-template for more information
using System;

namespace MyNamespace
{
    public class RegularPolygon
    {
        private int Apex { get; init; }
        private double Radius { get; init; }

        private double Area =>
            0.5 * (Apex * 2 * Radius * Math.Sin(Math.PI / Apex)) * (Radius * Math.Cos(Math.PI / Apex));

        public RegularPolygon() : this(3, 1.0)
        {
        }

        public RegularPolygon(int apex, double radius)
        {
            if (apex < 3 || radius < 1.0)
            {
                Console.Write("Error (apex < 3 || radius < 1.0)");
                Environment.Exit(0);
            }

            Apex = apex;
            Radius = radius;
        }

        public override string ToString()
        {
            return
                $"Apex: {Apex}, Radius: {Radius}, Area: {Math.Round(Area, 2)}";
        }

        public static bool operator !=(RegularPolygon one, RegularPolygon two)
        {
            return !one.Equals(two);
        }

        public static bool operator ==(RegularPolygon one, RegularPolygon two)
        {
            return one.Equals(two);
        }

        private bool Equals(RegularPolygon other)
        {
            return Apex.Equals(other.Apex) && Radius.Equals(other.Radius);
        }
    }

    public static class Start
    {
        private static void Main()
        {
            var a = new RegularPolygon(6, 2);
            var b = new RegularPolygon(3, 4);

            Console.WriteLine($"{a}");
            Console.WriteLine($"{b}\n");

            Console.Write("a == b\n");
            var c = a == b;
            Console.WriteLine($"{c}\n");

            Console.Write("a != b\n");
            c = a != b;
            Console.WriteLine($"{c}\n");
        }
    }
}
