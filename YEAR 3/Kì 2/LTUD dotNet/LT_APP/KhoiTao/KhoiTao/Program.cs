using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KhoiTao
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap so luong sinh vien");
            int n = int.Parse(Console.ReadLine());
            SinhVienKCNTT[] dssv = new SinhVienKCNTT[n];
            //sv.Nhap();
            //sv.Xuat();

            int gioi = 0, kha = 0, tb = 0, yeu = 0;
            for (int i = 0; i < n; i++)
            {
                Console.Write("Nhap sinh vien thu " + i + 1);
                dssv[i] = new SinhVienKCNTT();
                dssv[i].Nhap();
                string loai = dssv[i].tinhXepLoai();
                if (loai == "Gioi") gioi++;
                else if (loai == "Kha") kha++;
                else if (loai == "Trung binh") tb++;
                else yeu++;
            }
            Console.Write("Danh sach cac sinh vien gom: ");
            foreach (var sv in dssv)
            {
                sv.Xuat();
            }




            Console.ReadLine();
        }
    }
}