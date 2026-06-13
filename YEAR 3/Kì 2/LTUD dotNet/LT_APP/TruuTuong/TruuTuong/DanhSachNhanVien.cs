using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TruuTuong
{
    class DanhSachNhanVien : NhanVien
    {
        Dictionary<string, NhanVien> nv = new Dictionary<string, NhanVien>();

        public override void Nhap()
        {
            Console.Write("Nhap so luong nhan vien muon them: ");
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine($"Nhap thong tin nhan vien thu {i + 1}:");
                Console.WriteLine("Chon loai: 1 - Bien Che, 2 - Hop Dong");
                int loai = int.Parse(Console.ReadLine());
                NhanVien nvMoi;

                if (loai == 1)
                {
                    nvMoi = new NhanVienBienChe();
                }
                else
                {
                    nvMoi = new NhanVienHopDong();
                }

                nvMoi.Nhap();

                if (nv.ContainsKey(nvMoi.MaNV))
                {
                    Console.WriteLine("Ma nhan vien da ton tai!");
                }
                else
                {
                    nv.Add(nvMoi.MaNV, nvMoi);
                }
            }
        }

        public void In()
        {
            Console.WriteLine("--- DANH SACH NHAN VIEN ---");
            foreach (var item in nv.Values)
            {
                item.Xuat();
                if (item is ILUONG luongItem)
                {
                    Console.WriteLine($"Thuc linh: {luongItem.thucLinh()}");
                }
                Console.WriteLine("-------------------------");
            }
        }

        public double tongQuyLuong()
        {
            double tong = 0;
            foreach (var item in nv.Values)
            {
                if (item is ILUONG luongItem)
                {
                    tong += luongItem.thucLinh();
                }
            }
            return tong;
        }

        public void Tim()
        {
            Console.Write("Nhap Ma NV can tim: ");
            string maTim = Console.ReadLine();
            if (nv.ContainsKey(maTim))
            {
                Console.WriteLine("Tim thay nhan vien:");
                nv[maTim].Xuat();
            }
            else
            {
                Console.WriteLine("Khong tim thay nhan vien nay.");
            }
        }

        public void Xoa()
        {
            Console.Write("Nhap Ma NV can xoa: ");
            string maXoa = Console.ReadLine();
            if (nv.ContainsKey(maXoa))
            {
                nv.Remove(maXoa);
                Console.WriteLine("Da xoa thanh cong.");
            }
            else
            {
                Console.WriteLine("Khong tim thay ma nhan vien de xoa.");
            }
        }
    }
}
