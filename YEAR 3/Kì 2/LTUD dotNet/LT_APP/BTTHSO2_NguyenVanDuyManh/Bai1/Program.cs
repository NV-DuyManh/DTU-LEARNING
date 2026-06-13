using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Queue
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            Console.Write("Nhập số khách: ");
            int n = int.Parse(Console.ReadLine());
            Queue<string> hangDoi = new Queue<string>();
            for (int i = 1; i <= n; i++)
            {
                Console.Write("Nhập tên khách {0}: ", i);
                string ten = Console.ReadLine();
                hangDoi.Enqueue(ten);
            }
            while (hangDoi.Count > 0)
            {
                string khachDangPhucVu = hangDoi.Dequeue();
                Console.WriteLine("Đang phục vụ: " + khachDangPhucVu);
            }
            Console.ReadLine();
        }
    }
}
