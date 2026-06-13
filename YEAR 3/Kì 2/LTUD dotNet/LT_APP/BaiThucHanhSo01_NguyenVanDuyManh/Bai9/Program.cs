using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai9
{
    class Program
    {
        static int Fibonacci(int n)
        {
            if (n == 0) return 0;
            if (n == 1) return 1;
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }

        static void Main(string[] args)
        {
            Console.Write("Nhap X (vi tri phan tu): ");
            int x = int.Parse(Console.ReadLine());

            int giaTri = Fibonacci(x);
            Console.WriteLine("Gia tri phan tu thu {0} la: {1}", x, giaTri);

            int tong = 0;
            Console.Write("Day so: ");
            for (int i = 0; i < x; i++)
            {
                int f = Fibonacci(i);
                Console.Write(f + " ");
                tong += f;
            }
            Console.WriteLine("\nTong cua day co {0} phan tu la: {1}", x, tong);

            Console.ReadLine();
        }
    }
}
