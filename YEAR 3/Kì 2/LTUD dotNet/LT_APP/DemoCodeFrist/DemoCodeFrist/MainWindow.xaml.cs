using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace DemoCodeFrist
{
    public partial class MainWindow : Window
    {
        // Gọi Context mới
        QuanLyKhoaHoc db = new QuanLyKhoaHoc();

        public MainWindow()
        {
            InitializeComponent();
            // Tạo Database nếu chưa có
            db.Database.CreateIfNotExists();
        }

        private void BtnThem_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                // 1. Tạo đối tượng từ dữ liệu nhập
                KhoaHoc kh = new KhoaHoc()
                {
                    MaKhoaHoc = txtMaKH.Text,
                    TenKhoaHoc = txtTenKH.Text,
                    ThoiGianHoc = int.Parse(txtThoiGian.Text) // Chỗ này coi chừng nhập sai định dạng số
                };

                // 2. Thêm vào DB
                db.KhoaHocs.Add(kh);
                db.SaveChanges();

                MessageBox.Show("Thêm khóa học thành công!");

                // Xóa trắng ô nhập để nhập cái tiếp theo
                txtMaKH.Clear();
                txtTenKH.Clear();
                txtThoiGian.Clear();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Lỗi: " + ex.Message);
            }
        }
    }
}