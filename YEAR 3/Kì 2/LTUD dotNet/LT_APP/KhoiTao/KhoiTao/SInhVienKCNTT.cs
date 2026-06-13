using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KhoiTao
{
    class SinhVienKCNTT
    {
        string MSSV;
        string hoTen;
        string diaChi;
        DateTime ngaySinh;
        double diemCS464;
        double diemIS311;
        double diemCS311;

        public string MSSV1 { get => MSSV; set => MSSV = value; }
        public string HoTen { get => hoTen; set => hoTen = value; }
        public string DiaChi { get => diaChi; set => diaChi = value; }
        public DateTime NgaySinh { get => ngaySinh; set => ngaySinh = value; }
        public double DiemCS464 { get => diemCS464; set => diemCS464 = value; }
        public double DiemIS311 { get => diemIS311; set => diemIS311 = value; }
        public double DiemCS311 { get => diemCS311; set => diemCS311 = value; }

        public double diemTB()
        {
            return (DiemCS464 + DiemCS311 + DiemIS311) / 3;
        }

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

            Console.Write("Nhap diem CS464: ");
            DiemCS464 = double.Parse(Console.ReadLine());
            Console.Write("Nhap diem IS311: ");
            DiemIS311 = double.Parse(Console.ReadLine());
            Console.Write("Nhap diem CS311: ");
            DiemCS311 = double.Parse(Console.ReadLine());
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
            Console.WriteLine("Diem CS464: " + DiemCS464 + " | Diem IS311: " + DiemIS311 + " | Diem CS311: " + DiemCS311);
            Console.WriteLine("Diem trung binh: " + diemTB());
            Console.WriteLine("Xep loai: " + tinhXepLoai());
            Console.WriteLine("-------------------------");
        }
    }

}