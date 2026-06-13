using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KhoiTao
{
    class QLSinhVien
    {
        Dictionary<string, SinhVienKCNTT> dsCNTT = new Dictionary<string, SinhVienKCNTT>();
        Dictionary<string, SinhVienDienTu> dsDT = new Dictionary<string, SinhVienDienTu>();

        public void Nhap()
        {
            Console.Write("Nhap so luong sinh vien: ");
            int n = int.Parse(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                Console.Write("\nChon loai SV - Bam (C) cho CNTT, (D) cho Dien tu: ");
                char choice = char.ToUpper(Console.ReadKey().KeyChar);
                Console.WriteLine();

                if (choice == 'C')
                {
                    SinhVienKCNTT sv = new SinhVienKCNTT();
                    sv.Nhap();
                    if (!dsCNTT.ContainsKey(sv.MSSV1))
                        dsCNTT.Add(sv.MSSV1, sv);
                    else
                        Console.WriteLine("Ma so sinh vien da ton tai!");
                }
                else if (choice == 'D')
                {
                    SinhVienDienTu sv = new SinhVienDienTu();
                    sv.Nhap();
                    if (!dsDT.ContainsKey(sv.MSSV))
                        dsDT.Add(sv.MSSV, sv);
                    else
                        Console.WriteLine("Ma so sinh vien da ton tai!");
                }
            }
        }

        public void Xuat()
        {
            Console.WriteLine("\n--- DANH SACH SINH VIEN CNTT ---");
            foreach (var sv in dsCNTT.Values) sv.Xuat();
            Console.WriteLine("\n--- DANH SACH SINH VIEN DIEN TU ---");
            foreach (var sv in dsDT.Values) sv.Xuat();
        }

        public void ThongKe()
        {
            int gioi = 0, kha = 0, tb = 0, yeu = 0;

            foreach (var sv in dsCNTT.Values)
            {
                string loai = sv.tinhXepLoai();
                if (loai == "Gioi") gioi++;
                else if (loai == "Kha") kha++;
                else if (loai == "Trung binh") tb++;
                else yeu++;
            }

            foreach (var sv in dsDT.Values)
            {
                string loai = sv.tinhXepLoai();
                if (loai == "Gioi") gioi++;
                else if (loai == "Kha") kha++;
                else if (loai == "Trung binh") tb++;
                else yeu++;
            }

            Console.WriteLine("\n--- THONG KE CHUNG ---");
            Console.WriteLine("So luong sinh vien Gioi: " + gioi);
            Console.WriteLine("So luong sinh vien Kha: " + kha);
            Console.WriteLine("So luong sinh vien Trung binh: " + tb);
            Console.WriteLine("So luong sinh vien Yeu: " + yeu);
        }
    }
}
