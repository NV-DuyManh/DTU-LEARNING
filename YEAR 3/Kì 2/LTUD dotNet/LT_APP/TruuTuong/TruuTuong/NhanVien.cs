using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TruuTuong
{
    class NhanVien
    {
        string hoTen;
        int namSinh;
        string gioiTinh;
        string cmnd;
        string maNV;

        public string HoTen { get => hoTen; set => hoTen = value; }
        public int NamSinh { get => namSinh; set => namSinh = value; }
        public string GioiTinh { get => gioiTinh; set => gioiTinh = value; }
        public string CMND { get => cmnd; set => cmnd = value; }
        public string MaNV { get => maNV; set => maNV = value; }


        public virtual void Nhap()
        {
            Console.Write("Nhap ho ten: ");
            this.HoTen = Console.ReadLine();
            Console.Write("Nhap nam sinh: ");
            this.NamSinh = int.Parse(Console.ReadLine());
            Console.Write("Nhap gioi tinh: ");
            this.GioiTinh = Console.ReadLine();
            Console.Write("Nhap CMND: ");
            this.CMND = Console.ReadLine();
            Console.Write("Nhap ma nhan vien: ");
            this.MaNV = Console.ReadLine();
        }

        public virtual void Xuat()
        {
            Console.WriteLine($"Ho ten la: {this.HoTen}");
            Console.WriteLine($"Nam sinh la: {this.NamSinh}");
            Console.WriteLine($"Gioi tinh la: {this.GioiTinh}");
            Console.WriteLine($"CMND la: {this.CMND}");
            Console.WriteLine($"Ma nhan vien la: {this.MaNV}");
        }
    }
}
