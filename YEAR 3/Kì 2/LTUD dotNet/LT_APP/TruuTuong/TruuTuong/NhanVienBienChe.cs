using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TruuTuong
{
    class NhanVienBienChe : NhanVien, ILUONG
    {
        double hesoLuong;
        double luongCoBan;

        public double HesoLuong { get => hesoLuong; set => hesoLuong = value; }
        public double LuongCoBan { get => luongCoBan; set => luongCoBan = value; }

        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Nhap he so luong: ");
            this.HesoLuong = double.Parse(Console.ReadLine());
            Console.Write("Nhap luong co ban: ");
            this.LuongCoBan = double.Parse(Console.ReadLine());
        }
        public override void Xuat()
        {
            base.Xuat();
            Console.WriteLine($"He so luong la: {this.HesoLuong}");
            Console.WriteLine($"He luong co ban la: {this.LuongCoBan}");
        }
        public double phuCap()
        {
            return this.LuongCoBan / 10;
        }
        public double thucLinh()
        {
            return this.HesoLuong * this.LuongCoBan + phuCap();
        }
    }
}
