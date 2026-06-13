using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class SinhVien
    {
        // 1. Các trường dữ liệu (fields) - Private để bảo mật
        private string maSinhVien;
        private string hoTen;
        private double diemTrungBinh;

        // 2. Các thuộc tính (Properties) - Dùng để truy xuất dữ liệu
        public string MaSinhVien { get => maSinhVien; set => maSinhVien = value; }
        public string HoTen { get => hoTen; set => hoTen = value; }
        public double DiemTrungBinh { get => diemTrungBinh; set => diemTrungBinh = value; }

        // 3. Phương thức nhập thông tin từ bàn phím
        public void nhap()
        {
            Console.Write("Nhap ma sinh vien: ");
            MaSinhVien = Console.ReadLine();
            Console.Write("Nhap ho ten: ");
            HoTen = Console.ReadLine();
            Console.Write("Nhap diem trung binh: ");
            DiemTrungBinh = double.Parse(Console.ReadLine());
        }

        // 4. Phương thức hiển thị thông tin
        public void xuat()
        {
            Console.WriteLine("Ma SV: {0} \t Ten: {1} \t DTB: {2}",
                MaSinhVien, HoTen, DiemTrungBinh);
        }
    }
}
