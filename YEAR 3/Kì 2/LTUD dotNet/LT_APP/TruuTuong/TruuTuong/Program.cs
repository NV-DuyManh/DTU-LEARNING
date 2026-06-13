using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TruuTuong
{
    class Program
    {
        static void Main(string[] args)
        {
            DanhSachNhanVien ql = new DanhSachNhanVien();
            int chon = 0;

            do
            {
                Console.WriteLine("\n=== CHUONG TRINH QUAN LY NHAN VIEN ===");
                Console.WriteLine("1. Nhap nhan vien");
                Console.WriteLine("2. Hien thi danh sach");
                Console.WriteLine("3. Tong quy luong");
                Console.WriteLine("4. Tim kiem nhan vien");
                Console.WriteLine("5. Xoa nhan vien");
                Console.WriteLine("0. Thoat");
                Console.Write("Moi ban chon chuc nang: ");

                try
                {
                    chon = int.Parse(Console.ReadLine());
                }
                catch
                {
                    Console.WriteLine("Loi nhap lieu! Vui long nhap so.");
                    chon = -1;
                }

                switch (chon)
                {
                    case 1:
                        ql.Nhap();
                        break;
                    case 2:
                        ql.In();
                        break;
                    case 3:
                        Console.WriteLine($"Tong quy luong cua cong ty la: {ql.tongQuyLuong()}");
                        break;
                    case 4:
                        ql.Tim();
                        break;
                    case 5:
                        ql.Xoa();
                        break;
                    case 0:
                        Console.WriteLine("Ket thuc chuong trinh.");
                        break;
                    default:
                        Console.WriteLine("Chuc nang khong ton tai. Vui long chon lai!");
                        break;
                }

            } while (chon != 0);
        }
    }
}

