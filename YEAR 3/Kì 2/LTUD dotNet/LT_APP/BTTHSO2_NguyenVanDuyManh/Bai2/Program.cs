using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            Console.Write("Nhập chuỗi: ");
            string chuoiNhap = Console.ReadLine();
            Stack<char> nganXep = new Stack<char>();
            foreach (char kyTu in chuoiNhap)
            {
                nganXep.Push(kyTu);
            }
            Console.Write("Chuỗi đảo ngược: ");
            while (nganXep.Count > 0)
            {
                char kyTuLayRa = nganXep.Pop();
                Console.Write(kyTuLayRa);
            }
            Console.WriteLine();
            Console.ReadLine();
        }
    }
}
