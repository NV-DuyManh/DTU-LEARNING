using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            QuanLySinhVien ql = new QuanLySinhVien();
            int chon;
            do
            {
                Console.WriteLine("\n------- MENU QUAN LY -------");
                Console.WriteLine("1. Them sinh vien");
                Console.WriteLine("2. Xoa sinh vien");
                Console.WriteLine("3. Tim sinh vien");
                Console.WriteLine("4. Xem tat ca");
                Console.WriteLine("5. Tinh DTB chung");
                Console.WriteLine("0. Thoat");
                Console.Write("Chon chuc nang: ");
                chon = int.Parse(Console.ReadLine());

                switch (chon)
                {
                    case 1: ql.ThemSV(); break;
                    case 2: ql.XoaSV(); break;
                    case 3: ql.TimSV(); break;
                    case 4: ql.HienThiTatCa(); break;
                    case 5: ql.TinhDTBChung(); break;
                }
            } while (chon != 0);
        }
    }
}
