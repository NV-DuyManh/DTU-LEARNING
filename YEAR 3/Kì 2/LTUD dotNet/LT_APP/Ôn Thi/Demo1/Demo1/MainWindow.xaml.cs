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

    namespace Demo1
    {
        /// <summary>
        /// Interaction logic for MainWindow.xaml
        /// </summary>
        public partial class MainWindow : Window
        {
            QuanLySanPhamEntities db = new QuanLySanPhamEntities();
            public MainWindow()
            {
                InitializeComponent();
            }

            public void LoadData()
            {
                SanPham.ItemsSource = db.SANPHAM.ToList();
                LoaiSP.ItemsSource = db.LOAISP.ToList();
                LoaiSP.DisplayMemberPath= "TenLoai";
                LoaiSP.SelectedValuePath= "MaLoai";
            }

            private void Button_Click(object sender, RoutedEventArgs e)
            {
                SANPHAM moi = new SANPHAM();
            moi.MaSP = MaSP.Text;
            moi.TenSP = TenSP.Text;
            moi.NgayNhap = NgayNhap.SelectedDate;
            if (bh6.IsChecked == true) moi.BaoHanh = 6;
            else if (bh12.IsChecked == true) moi.BaoHanh = 12;
            else moi.BaoHanh = 24;
            moi.MaLoai = LoaiSP.SelectedValue.ToString();
            db.SANPHAM.Add(moi);
            db.SaveChanges();
            LoadData();
            MessageBox.Show("Thêm thành công");
        }

            private void Button_Click_1(object sender, RoutedEventArgs e)
            {
            string ma = MaSP.Text;
            var sp = db.SANPHAM.FirstOrDefault(x => x.MaSP == ma);
            if (sp != null)
            {
                sp.TenSP = TenSP.Text;
                sp.NgayNhap = NgayNhap.SelectedDate;
                if (bh6.IsChecked == true) sp.BaoHanh = 6;
                else if (bh12.IsChecked == true) sp.BaoHanh = 12;
                else sp.BaoHanh = 24;
                sp.MaLoai = LoaiSP.SelectedValue.ToString();

                db.SaveChanges();
                LoadData();
                MessageBox.Show("Cập nhật thành công");
            }
        }

            private void Button_Click_2(object sender, RoutedEventArgs e)
            {
            string ma = MaSP.Text;
            var sp = db.SANPHAM.FirstOrDefault(x => x.MaSP == ma);
            if (sp != null)
            {
                db.SANPHAM.Remove(sp);
                db.SaveChanges();
                LoadData();
                MessageBox.Show("Xóa thành công");
            }
            }

            private void Button_Click_3(object sender, RoutedEventArgs e)
            {
            MaSP.Clear();
            TenSP.Clear();
            NgayNhap.SelectedDate = null;
            LoaiSP.SelectedIndex = -1;
            bh6.IsChecked = true;
         
        }

            private void Window_Loaded(object sender, RoutedEventArgs e)
            {
                LoadData();
            }

        private void LoaiSP_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
           
        }

        private void SanPham_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (SanPham.SelectedItem is SANPHAM sp)
            {
                MaSP.Text = sp.MaSP;
                TenSP.Text = sp.TenSP;
                NgayNhap.SelectedDate = sp.NgayNhap;
                LoaiSP.SelectedValue = sp.MaLoai;
                if (sp.BaoHanh == 6) bh6.IsChecked = true;
                else if (sp.BaoHanh == 12) bh12.IsChecked = true;
                else if (sp.BaoHanh == 24) bh24.IsChecked = true;
            }
        }
    }
    }
