using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuanLyXe
{
    internal class Program
    {
        static void Main(string[] args)
        {
            QuanLyXe quanLyXe = new QuanLyXe();
            quanLyXe.Nhap();
            Console.Write("Nhap bien so can tim: ");
            string bienSoTim = Console.ReadLine();
            quanLyXe.Tim(bienSoTim);
            Console.Write("Nhap bien so can xoa: ");
            string bienSoXoa = Console.ReadLine();
            quanLyXe.Xoa(bienSoXoa);
        }
    }
}
