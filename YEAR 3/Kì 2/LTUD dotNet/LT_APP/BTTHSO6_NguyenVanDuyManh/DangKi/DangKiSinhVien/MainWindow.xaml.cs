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

namespace DangKiSinhVien
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void Luu_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(hoTen.Text) || string.IsNullOrWhiteSpace(MSSV.Text))
            {
                MessageBox.Show("Vui lòng nhập đầy đủ Họ tên và MSSV!", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            string gioitinh = (nam.IsChecked == true) ? "Nam" : "Nữ";

            string lop = "";
            if (lopHoc.SelectedItem != null)
            {
                ComboBoxItem item = (ComboBoxItem)lopHoc.SelectedItem;
                lop = item.Content.ToString();
            }

            string ngaysinh = ngaySinh.SelectedDate.HasValue ? ngaySinh.SelectedDate.Value.ToString("dd/MM/yyyy") : "Chưa chọn";

            string thongTin = $"Họ tên: {hoTen.Text}\n" +
                              $"MSSV: {MSSV.Text}\n" +
                              $"Ngày sinh: {ngaysinh}\n" +
                              $"Giới tính: {gioitinh}\n" +
                              $"Lớp: {lop}\n" +
                              $"SĐT: {SDT.Text}\n" +
                              $"Email: {email.Text}\n" +
                              $"Ghi chú: {ghiChu.Text}";

            MessageBox.Show(thongTin, "Thông tin sinh viên", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void Xoa_Click(object sender, RoutedEventArgs e)
        {
            hoTen.Text = "";
            MSSV.Text = "";
            ngaySinh.SelectedDate = null;

            nam.IsChecked = true;

            lopHoc.SelectedIndex = -1;

            SDT.Text = "";
            email.Text = "";
            ghiChu.Text = "";

            hoTen.Focus();
        }

        private void Thoat_Click(object sender, RoutedEventArgs e)
        {
            MessageBoxResult result = MessageBox.Show("Bạn có chắc chắn muốn thoát không?", "Xác nhận", MessageBoxButton.YesNo, MessageBoxImage.Question);

            if (result == MessageBoxResult.Yes)
            {
                this.Close(); 
            }
        }
    }
}
