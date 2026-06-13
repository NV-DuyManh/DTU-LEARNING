using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap so a: ");
            int nhapso1 = int.Parse(Console.ReadLine());
            Console.Write("Nhap so b: ");
            int nhapso2 = int.Parse(Console.ReadLine());
            Console.Write("Nhap so c: ");
            int nhapso3 = int.Parse(Console.ReadLine());
            if (nhapso1 + nhapso2 > nhapso3 && nhapso2 + nhapso3 > nhapso1 && nhapso1 + nhapso3 > nhapso2)
            {
                Console.Write("3 so tren la 3 canh cua tam giac va la ");
                if (nhapso1 == nhapso2 && nhapso2 == nhapso3)
                {
                    Console.Write("tam giac deu");
                }
                else if (nhapso1 == nhapso2 || nhapso2 == nhapso3 || nhapso1 == nhapso3)
                {
                    Console.Write("tam giac can");
                }
                else if ((nhapso1 * nhapso1 == nhapso2 * nhapso2 + nhapso3 * nhapso3) || (nhapso2 * nhapso2 == nhapso1 * nhapso1 + nhapso3 * nhapso3) ||
                    (nhapso3 * nhapso3 == nhapso1 * nhapso1 + nhapso2 * nhapso2))
                {
                    Console.Write("tam giac vuong");
                }
                else
                {
                    Console.Write("tam giac thuong");
                }
            }
            else
            {
                Console.WriteLine("3 so tren khong phai la 3 canh cua tam giac");
            }
            Console.ReadLine();
        }
    }
}
