using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kethua
{
    class Program
    {
        static void Main(string[] args)
        {
            NhanVien nv = new NhanVien();
            nv.Nhap();
            nv.Xuat();
            Console.ReadLine();
        }
    }
}
