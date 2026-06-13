using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            Dictionary<string, Dictionary<string, double>> dsSinhVien = new Dictionary<string, Dictionary<string, double>>();
            int luaChon;
            do
            {
                Console.WriteLine("\n--- MENU QUẢN LÝ ĐIỂM ---");
                Console.WriteLine("1. Thêm sinh viên");
                Console.WriteLine("2. Nhập/Cập nhật điểm môn học");
                Console.WriteLine("3. Xem bảng điểm của 1 sinh viên");
                Console.WriteLine("4. Tính điểm trung bình của 1 sinh viên");
                Console.WriteLine("5. Liệt kê sinh viên có điểm TB >= X");
                Console.WriteLine("6. Xóa 1 môn học của sinh viên");
                Console.WriteLine("0. Thoát");
                Console.Write("Mời bạn chọn: ");
                luaChon = int.Parse(Console.ReadLine());
                switch (luaChon)
                {
                    case 1:
                        Console.Write("Nhập mã sinh viên: ");
                        string maSV = Console.ReadLine();
                        Console.Write("Nhập tên sinh viên: ");
                        string tenSV = Console.ReadLine();
                        if (!dsSinhVien.ContainsKey(maSV))
                        {
                            dsSinhVien.Add(maSV, new Dictionary<string, double>());
                            Console.WriteLine("Đã thêm sinh viên thành công!");
                        }
                        else Console.WriteLine("Lỗi: Mã sinh viên đã tồn tại!");
                        break;

                    case 2:
                        Console.Write("Nhập mã sinh viên: ");
                        string svDiem = Console.ReadLine();
                        if (dsSinhVien.ContainsKey(svDiem))
                        {
                            Console.Write("Nhập mã môn học: ");
                            string maMon = Console.ReadLine();
                            double diem;
                            do
                            {
                                Console.Write("Nhập điểm (0-10): ");
                                diem = double.Parse(Console.ReadLine());
                            } while (diem < 0 || diem > 10);
                            dsSinhVien[svDiem][maMon] = diem;
                            Console.WriteLine("Đã cập nhật điểm thành công!");
                        }
                        else Console.WriteLine("Lỗi: Không tìm thấy sinh viên!");
                        break;

                    case 3:
                        Console.Write("Nhập mã sinh viên: ");
                        string svXem = Console.ReadLine();
                        if (dsSinhVien.ContainsKey(svXem))
                        {
                            Console.WriteLine("Bảng điểm của SV {0}:", svXem);
                            foreach (var item in dsSinhVien[svXem])
                                Console.WriteLine("- Môn {0}: {1} điểm", item.Key, item.Value);
                        }
                        else Console.WriteLine("Không tìm thấy sinh viên!");
                        break;

                    case 4:
                        Console.Write("Nhập mã sinh viên: ");
                        string svTB = Console.ReadLine();
                        if (dsSinhVien.ContainsKey(svTB) && dsSinhVien[svTB].Count > 0)
                        {
                            double tong = 0;
                            foreach (var d in dsSinhVien[svTB].Values) tong += d;
                            double tb = tong / dsSinhVien[svTB].Count;
                            Console.WriteLine("Điểm trung bình của SV {0} là: {1:F2}", svTB, tb);
                        }
                        else Console.WriteLine("Sinh viên chưa có dữ liệu điểm!");
                        break;
                    case 5:
                        Console.Write("Nhập mức điểm trung bình X: ");
                        double X = double.Parse(Console.ReadLine());
                        Console.WriteLine("Danh sách sinh viên đạt yêu cầu:");
                        foreach (var sv in dsSinhVien)
                        {
                            if (sv.Value.Count > 0)
                            {
                                double tb = 0;
                                foreach (var d in sv.Value.Values) tb += d;
                                tb /= sv.Value.Count;

                                if (tb >= X) Console.WriteLine("- Mã SV: {0} (TB: {1:F2})", sv.Key, tb);
                            }
                        }
                        break;
                    case 6:
                        Console.Write("Nhập mã sinh viên: ");
                        string svXoa = Console.ReadLine();
                        if (dsSinhVien.ContainsKey(svXoa))
                        {
                            Console.Write("Nhập mã môn muốn xóa: ");
                            string monXoa = Console.ReadLine();
                            if (dsSinhVien[svXoa].Remove(monXoa)) Console.WriteLine("Đã xóa môn!");
                            else Console.WriteLine("Môn học không tồn tại!");
                        }
                        break;
                }
            } while (luaChon != 0);
        }
    }
}
