using System;
using System.Collections.Generic;
using System.Windows;

namespace QLBenhNhan
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        // 1. Tạo danh sách để lưu trữ bệnh nhân
        List<BenhNhan> danhSachBenhNhan = new List<BenhNhan>();

        public MainWindow()
        {
            InitializeComponent();

            // 2. Gọi hàm nạp dữ liệu mẫu khi chương trình khởi chạy
            KhoiTaoDuLieu();
        }

        private void KhoiTaoDuLieu()
        {
            // Thêm một vài dữ liệu mẫu để kiểm tra hiển thị trên DataGrid
            danhSachBenhNhan.Add(new BenhNhan
            {
                MaBN = "BN001",
                HoTen = "Nguyễn Văn An",
                GioiTinh = "Nam",
                NgayNhapVien = new DateTime(2026, 01, 20),
                Khoa = "Nội"
            });

            danhSachBenhNhan.Add(new BenhNhan
            {
                MaBN = "BN002",
                HoTen = "Trần Thị Bình",
                GioiTinh = "Nữ",
                NgayNhapVien = new DateTime(2026, 01, 25),
                Khoa = "Nhi"
            });

            // 3. Gán danh sách vào DataGrid (phải khớp với x:Name="dgDanhSach" bên XAML)
            dgDanhSach.ItemsSource = null; // Reset để cập nhật lại
            dgDanhSach.ItemsSource = danhSachBenhNhan;
        }
    }

    // 4. Định nghĩa lớp Bệnh Nhân (Model)
    // Các thuộc tính này phải khớp chính xác với Binding bên file XAML
    public class BenhNhan
    {
        public string MaBN { get; set; }
        public string HoTen { get; set; }
        public string GioiTinh { get; set; }
        public DateTime NgayNhapVien { get; set; }
        public string Khoa { get; set; }
    }
}