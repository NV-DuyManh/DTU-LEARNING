using System;
using System.Collections.Generic;
using System.Windows;

namespace QLVatTu
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            // --- BẠN THIẾU DÒNG NÀY ---
            LoadDuLieuMau(); // Gọi hàm này thì dữ liệu mới đổ vào bảng
            // ---------------------------
        }

        private void LoadDuLieuMau()
        {
            // Tạo danh sách dữ liệu
            List<VatTu> danhSach = new List<VatTu>
            {
                new VatTu { MaVT = "K01", TenVT = "Kèm",       NgaySX = "11/11/2021 9:44:20", NamHH = "2024", MaNSX = "CT" },
                new VatTu { MaVT = "B02", TenVT = "Búa",       NgaySX = "3/3/2022 9:44:36",   NamHH = "2025", MaNSX = "MV" },
                new VatTu { MaVT = "X03", TenVT = "Xô Loại 3", NgaySX = "3/3/2023 9:44:40",   NamHH = "2026", MaNSX = "VP" },
                new VatTu { MaVT = "K02", TenVT = "Kèm 2",     NgaySX = "8/20/2025 9:44:44",  NamHH = "2028", MaNSX = "MV" },
                new VatTu { MaVT = "B01", TenVT = "Búa L1",    NgaySX = "8/3/2025 9:44:48",   NamHH = "2028", MaNSX = "CT" },
                new VatTu { MaVT = "X01", TenVT = "Xô L1",     NgaySX = "8/18/2024 9:47:40",  NamHH = "2027", MaNSX = "VP" }
            };

            // Đổ dữ liệu vào bảng (Đảm bảo bên XAML bảng đặt tên là x:Name="dgVatTu")
            dgVatTu.ItemsSource = danhSach;
        }
    }

    public class VatTu
    {
        public string MaVT { get; set; }
        public string TenVT { get; set; }
        public string NgaySX { get; set; }
        public string NamHH { get; set; }
        public string MaNSX { get; set; }
    }
}