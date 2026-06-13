using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class QuanLySinhVien
    {
        // Dictionary với Key là MaSinhVien, Value là đối tượng SinhVien
        private Dictionary<string, SinhVien> danhSach = new Dictionary<string, SinhVien>();

        public void ThemSV()
        {
            SinhVien sv = new SinhVien();
            sv.nhap(); // Gọi hàm nhap() của class SinhVien

            if (!danhSach.ContainsKey(sv.MaSinhVien))
            {
                danhSach.Add(sv.MaSinhVien, sv);
                Console.WriteLine("=> Them thanh cong!");
            }
            else
            {
                Console.WriteLine("=> LOI: Ma sinh vien nay da ton tai.");
            }
        }

        public void XoaSV()
        {
            Console.Write("Nhap ma SV can xoa: ");
            string ma = Console.ReadLine();
            if (danhSach.Remove(ma))
                Console.WriteLine("=> Da xoa.");
            else
                Console.WriteLine("=> Khong tim thay ma nay.");
        }

        public void TimSV()
        {
            Console.Write("Nhap ma SV can tim: ");
            string ma = Console.ReadLine();
            if (danhSach.ContainsKey(ma))
                danhSach[ma].xuat(); // Gọi hàm xuat() của class SinhVien
            else
                Console.WriteLine("=> Khong tim thay.");
        }

        public void HienThiTatCa()
        {
            Console.WriteLine("\n--- DANH SACH SINH VIEN ---");
            foreach (var sv in danhSach.Values)
            {
                sv.xuat();
            }
        }

        public void TinhDTBChung()
        {
            if (danhSach.Count == 0) return;
            double tong = danhSach.Values.Sum(s => s.DiemTrungBinh);
            Console.WriteLine("=> Diem TB chung cua lop: {0:F2}", tong / danhSach.Count);
        }
    }
}
