using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuanLyXe
{
    internal class Xe
    {
        string bienSo, tenXe;
        int trongTai, tieuChuanBang;
        DateTime ngayDangKiem;
        public string BienSo { get => bienSo; set => bienSo = value; }
        public string TenXe { get => tenXe; set => tenXe = value; }
        public int TrongTai { get => trongTai; set => trongTai = value; }
        public int TieuChuanBang { get => tieuChuanBang; set => tieuChuanBang = value; }
        public DateTime NgayDangKiem { get => ngayDangKiem; set => ngayDangKiem = value; }
        public virtual void Nhap()
        {
            Console.Write("Nhap bien so: ");
            bienSo = Console.ReadLine();
            Console.Write("Nhap ten xe: ");
            tenXe = Console.ReadLine();
            Console.Write("Nhap trong tai: ");
            trongTai = int.Parse(Console.ReadLine());
            Console.Write("Nhap ngay dang kiem (dd/MM/yyyy): ");
            ngayDangKiem = DateTime.ParseExact(Console.ReadLine(), "dd/MM/yyyy", null);
            Console.Write("Nhap tieu chuan bang: ");
            tieuChuanBang = int.Parse(Console.ReadLine());
        }
        public virtual void Xuat()
        {
            Console.WriteLine("Bien so: " + bienSo);
            Console.WriteLine("Ten xe: " + tenXe);
            Console.WriteLine("Trong tai: " + trongTai);
            Console.WriteLine("Ngay dang kiem: " + ngayDangKiem.ToString("dd/MM/yyyy"));
            Console.WriteLine("Tieu chuan bang: " + tieuChuanBang);
        }
    }
}
