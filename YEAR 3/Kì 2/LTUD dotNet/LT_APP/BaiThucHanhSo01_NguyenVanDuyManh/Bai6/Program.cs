using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai6
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("--- Giai phuong trinh bac 2 ---");
            Console.Write("Nhap a: ");
            double a = double.Parse(Console.ReadLine());
            Console.Write("Nhap b: ");
            double b = double.Parse(Console.ReadLine());
            Console.Write("Nhap c: ");
            double c = double.Parse(Console.ReadLine());

            if (a == 0)
            {
                if (b == 0)
                    Console.WriteLine(c == 0 ? "Phuong trinh vo so nghiem" : "Phuong trinh vo nghiem");
                else
                    Console.WriteLine("Phuong trinh co nghiem x = {0}", -c / b);
            }
            else
            {
                double delta = b * b - 4 * a * c;
                if (delta < 0)
                    Console.WriteLine("Phuong trinh vo nghiem");
                else if (delta == 0)
                    Console.WriteLine("Phuong trinh co nghiem kep x = {0}", -b / (2 * a));
                else
                {
                    double x1 = (-b + Math.Sqrt(delta)) / (2 * a);
                    double x2 = (-b - Math.Sqrt(delta)) / (2 * a);
                    Console.WriteLine("Phuong trinh co 2 nghiem: x1 = {0}, x2 = {1}", x1, x2);
                }
            }
            Console.ReadLine();
        }
    }
}
