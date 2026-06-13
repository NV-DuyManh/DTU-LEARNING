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

namespace Demo14
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
        private void LoadDB()
        {
            dgSP.ItemsSource = db.SANPHAM.ToList();
            cbLoaiSP.ItemsSource = db.LOAISP.ToList();
            cbLoaiSP.DisplayMemberPath = "TenLoai";
            cbLoaiSP.SelectedValuePath = "MaLoai";
        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            LoadDB();
        }

        private void DgSP_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(dgSP.SelectedItem is SANPHAM sp)
            {
                tbMaSP.Text = sp.MaSP;
                tbTenSP.Text = sp.TenSP;
                dpNgay.SelectedDate = sp.NgayNhap;
                cbLoaiSP.SelectedValue = sp.MaLoai;
                if (sp.BaoHanh == 6) bh6.IsChecked = true;
                else if (sp.BaoHanh == 12) bh12.IsChecked = true;
                else bh24.IsChecked = true;
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            SANPHAM sp = new SANPHAM();
            sp.MaSP = tbMaSP.Text;
            sp.TenSP = tbTenSP.Text;
            sp.NgayNhap = dpNgay.SelectedDate;
            sp.MaLoai = cbLoaiSP.SelectedValue.ToString();
            if (bh6.IsChecked == true) sp.BaoHanh = 6;
            else if (bh12.IsChecked == true) sp.BaoHanh = 12;
            else sp.BaoHanh = 24;
            db.SANPHAM.Add(sp);
            db.SaveChanges();
            LoadDB();
            MessageBox.Show("Thêm thành công");

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            string ma = tbMaSP.Text;
            var sp = db.SANPHAM.FirstOrDefault(x => x.MaSP == ma);
            if (sp != null)
            {
                sp.MaSP = tbMaSP.Text;
                sp.TenSP = tbTenSP.Text;
                sp.NgayNhap = dpNgay.SelectedDate;
                sp.MaLoai = cbLoaiSP.SelectedValue.ToString();
                if (bh6.IsChecked == true) sp.BaoHanh = 6;
                else if (bh12.IsChecked == true) sp.BaoHanh = 12;
                else sp.BaoHanh = 24;
                db.SaveChanges();
                LoadDB();
                MessageBox.Show("Sửa thành công");
            }
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            string ma = tbMaSP.Text;
            var sp = db.SANPHAM.FirstOrDefault(x => x.MaSP == ma);
            if (sp != null)
            {
                db.SANPHAM.Remove(sp);
                db.SaveChanges();
                LoadDB();
                MessageBox.Show("Xoá thành công");
            }
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            tbMaSP.Clear();
            tbTenSP.Clear();
            dpNgay.SelectedDate = null;
            cbLoaiSP.SelectedIndex = -1;
            bh6.IsChecked = true;
            tbDem.Clear();
            LoadDB();
        }

        private void CbLoaiSP_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (cbLoaiSP.SelectedValue != null)
            {
                string chon = cbLoaiSP.SelectedValue.ToString();
                var loc = db.SANPHAM.Where(x => x.MaLoai == chon).ToList();
                dgSP.ItemsSource = loc;
                //tbDem.Text = loc.ToList().Count().ToString();
                tbDem.Clear();
            }
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            string tk = tbTim.Text.ToLower().Trim();
            var kq = db.SANPHAM.Where(x => x.TenSP.ToLower().Contains(tk)).ToList();
            dgSP.ItemsSource = kq;
            //tbDem.Text = kq.ToList().Count().ToString();
            tbDem.Clear();
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            tbDem.Text = dgSP.Items.Count.ToString();
        }
    }
}
