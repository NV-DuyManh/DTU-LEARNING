using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KhoiTao
{
    class SinhVienDienTu
    {
        string mssv;
        string hoTen;
        string diaChi;
        DateTime ngaySinh;
        double diemEE200;
        double diemEE201;
        double diemEE205;

        public string MSSV { get => mssv; set => mssv = value; }
        public string HoTen { get => hoTen; set => hoTen = value; }
        public string DiaChi { get => diaChi; set => diaChi = value; }
        public DateTime NgaySinh { get => ngaySinh; set => ngaySinh = value; }
        public double DiemEE200 { get => diemEE200; set => diemEE200 = value; }
        public double DiemEE201 { get => diemEE201; set => diemEE201 = value; }
        public double DiemEE205 { get => diemEE205; set => diemEE205 = value; }

        public double diemTB() => (DiemEE200 + DiemEE201 + DiemEE205) / 3;

        public void Nhap()
        {
            Console.Write("Nhap MSSV: ");
            MSSV = Console.ReadLine();
            Console.Write("Nhap ho ten: ");
            HoTen = Console.ReadLine();
            Console.Write("Nhap dia chi: ");
            DiaChi = Console.ReadLine();

            bool checkDate = false;
            while (!checkDate)
            {
                Console.Write("Nhap ngay sinh (dd/mm/yyyy): ");
                checkDate = DateTime.TryParse(Console.ReadLine(), out ngaySinh);
                if (!checkDate) Console.WriteLine("Ngay sinh khong dung dinh dang, vui long nhap lai!");
            }

            Console.Write("Nhap diem EE200: ");
            DiemEE200 = double.Parse(Console.ReadLine());
            Console.Write("Nhap diem EE201: ");
            DiemEE201 = double.Parse(Console.ReadLine());
            Console.Write("Nhap diem EE205: ");
            DiemEE205 = double.Parse(Console.ReadLine());
        }

        public string tinhXepLoai()
        {
            double tb = diemTB();
            if (tb >= 8) return "Gioi";
            if (tb >= 6.5) return "Kha";
            if (tb >= 5) return "Trung binh";
            return "Yeu";
        }

        public void Xuat()
        {
            Console.WriteLine("MSSV: " + MSSV);
            Console.WriteLine("Ho ten: " + HoTen);
            Console.WriteLine("Dia chi: " + DiaChi);
            Console.WriteLine("Ngay sinh: " + NgaySinh.ToShortDateString());
            Console.WriteLine("Diem EE200: " + DiemEE200 + " | Diem EE201: " + DiemEE201 + " | Diem EE205: " + DiemEE205);
            Console.WriteLine("Diem trung binh: " + diemTB());
            Console.WriteLine("Xep loai: " + tinhXepLoai());
            Console.WriteLine("-------------------------");
        }
    }
}
