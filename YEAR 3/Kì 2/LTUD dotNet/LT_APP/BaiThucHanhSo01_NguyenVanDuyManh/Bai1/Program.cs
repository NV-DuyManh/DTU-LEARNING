using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap n: ");
            int n = int.Parse(Console.ReadLine());
            int tong = 0;

            for (int i = 1; i <= n; i++)
            {
                tong += i;
            }

            Console.WriteLine("Tong S = {0}", tong);
            Console.ReadLine();
        }
    }
}
