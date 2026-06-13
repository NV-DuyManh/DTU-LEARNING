using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuanLyXe
{
    internal class QuanLyXe
    {
        Dictionary<string, Xe> List;
        public QuanLyXe()
        {
            List = new Dictionary<string, Xe>();
        }
        public void Nhap()
        {
            while (true)
            {
                Console.Write("Nhap H (xe cho hang), D (xe du lich), Enter (thoat): ");
                string choice = Console.ReadLine();
                if (choice == "H" || choice == "h")
                {
                    XeChoHang xeChoHang = new XeChoHang();
                    xeChoHang.Nhap();
                    List.Add(xeChoHang.BienSo, xeChoHang);
                }
                else if (choice == "D" || choice == "d")
                {
                    XeDuLich xeDuLich = new XeDuLich();
                    xeDuLich.Nhap();
                    List.Add(xeDuLich.BienSo, xeDuLich);
                }
                else if (choice == "")
                {
                    break;
                }
                else
                {
                    Console.WriteLine("Lua chon khong hop le!");
                }
            }
        }
        public void Tim(string bienSo)
        {
            if (List.TryGetValue(bienSo, out Xe xe))
            {
                xe.Xuat();
            }
            else
            {
                Console.WriteLine("Khong tim thay xe bien so: " + bienSo);
            }
        }
        public void Xoa(string bienSo)
        {
            if (List.ContainsKey(bienSo))
            {
                List.Remove(bienSo);
                Console.WriteLine("Da xoa xe bien so: " + bienSo);
            }
            else
            {
                Console.WriteLine("Khong tim thay xe bien so: " + bienSo);
            }
        }
    }
}
