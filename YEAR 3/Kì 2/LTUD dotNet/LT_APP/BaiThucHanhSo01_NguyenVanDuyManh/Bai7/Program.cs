using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap thang: ");
            string input = Console.ReadLine();
            int thang;

            if (!int.TryParse(input, out thang))
            {
                Console.WriteLine("Loi nhap du lieu (phai la so nguyen)");
            }
            else if (thang < 1 || thang > 12)
            {
                Console.WriteLine("Khong ton tai thang nay");
            }
            else
            {
                switch (thang)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        Console.WriteLine("Thang {0} co 31 ngay", thang);
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        Console.WriteLine("Thang {0} co 30 ngay", thang);
                        break;
                    case 2:
                        Console.WriteLine("Thang 2 co 28 hoac 29 ngay");
                        break;
                }
            }
            Console.ReadLine();
        }
    }
}
