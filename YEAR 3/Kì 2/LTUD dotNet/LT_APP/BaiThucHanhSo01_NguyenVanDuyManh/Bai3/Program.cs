using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap n: ");
            int n = int.Parse(Console.ReadLine());
            long giaiThua = 1;

            for (int i = 1; i <= n; i++)
            {
                giaiThua *= i;
            }

            Console.WriteLine("{0}! = {1}", n, giaiThua);
            Console.ReadLine();
        }
    }
}
