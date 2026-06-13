using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            Dictionary<string, string> danhBa = new Dictionary<string, string>();
            int luaChon;
            do
            {
                Console.WriteLine("\n--- MENU QUẢN LÝ DANH BẠ ---");
                Console.WriteLine("1. Thêm liên hệ");
                Console.WriteLine("2. Tìm liên hệ");
                Console.WriteLine("3. Hiển thị toàn bộ danh bạ");
                Console.WriteLine("0. Thoát");
                Console.Write("Mời bạn chọn: ");
                luaChon = int.Parse(Console.ReadLine());

                switch (luaChon)
                {
                    case 0:
                        Console.WriteLine("Đang thoát chương trình...");
                        break;
                    case 1:
                        Console.Write("Nhập số điện thoại: ");
                        string sdt = Console.ReadLine();
                        Console.Write("Nhập tên: ");
                        string ten = Console.ReadLine();
                        if (!danhBa.ContainsKey(sdt))
                        {
                            danhBa.Add(sdt, ten);
                            Console.WriteLine("Đã thêm thành công!");
                        }
                        else
                        {
                            Console.WriteLine("Số điện thoại này đã tồn tại!");
                        }
                        break;
                    case 2:
                        Console.Write("Nhập số điện thoại cần tìm: ");
                        string sdtTim = Console.ReadLine();
                        if (danhBa.ContainsKey(sdtTim))
                        {
                            Console.WriteLine("Kết quả: SĐT {0} là của {1}", sdtTim, danhBa[sdtTim]);
                        }
                        else
                        {
                            Console.WriteLine("Không tìm thấy liên hệ này.");
                        }
                        break;
                    case 3:
                        Console.WriteLine("\n--- DANH SÁCH LIÊN HỆ ---");
                        foreach (var tungLienHe in danhBa)
                        {
                            Console.WriteLine("SĐT: {0} - Tên: {1}", tungLienHe.Key, tungLienHe.Value);
                        }
                        break;
                    default:
                        Console.WriteLine("Lựa chọn không hợp lệ!");
                        break;
                }
            } while (luaChon != 0);
        }
    }
}
