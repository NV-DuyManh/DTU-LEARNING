using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TruuTuong
{
    class NhanVienHopDong : NhanVien, ILUONG
    {
        double mucLuong;

        public double MucLuong { get => mucLuong; set => mucLuong = value; }

        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Nhap muc luong: ");
            this.MucLuong = double.Parse(Console.ReadLine());
        }
        public override void Xuat()
        {
            base.Xuat();
            Console.WriteLine($"Muc luong la: {this.MucLuong}");
        }
        public double phuCap()
        {
            return this.MucLuong / 10;
        }
        public double thucLinh()
        {
            return this.MucLuong + phuCap();
        }
    }
}
