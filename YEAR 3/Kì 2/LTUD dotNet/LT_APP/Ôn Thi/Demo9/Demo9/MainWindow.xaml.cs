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

namespace Demo9
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        QUANLYTUYENSINHEntities db = new QUANLYTUYENSINHEntities();
        public MainWindow()
        {
            InitializeComponent();
        }
        private void LoadDB()
        {
            dgTS.ItemsSource = db.THISINH.ToList();
            cbNganhHoc.ItemsSource = db.NGANHHOC.ToList();
            cbNganhHoc.DisplayMemberPath = "TenNganh";
            cbNganhHoc.SelectedValuePath = "MaNganh";
            tbDem.Text = db.THISINH.ToList().Count().ToString();

        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            LoadDB();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            THISINH ts = new THISINH();
            ts.MaTS = tbMaTS.Text;
            ts.HoTen = tbTen.Text;
            ts.NgaySinh = dpNgay.SelectedDate;
            ts.DiemThi = double.Parse(tbDiem.Text);
            ts.MaNganh = cbNganhHoc.SelectedValue.ToString();
            db.THISINH.Add(ts);
            db.SaveChanges();
            LoadDB();
            MessageBox.Show("Thêm thành công");
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            string ma = tbMaTS.Text;
            var ts = db.THISINH.FirstOrDefault(x => x.MaTS == ma);
            if(ts != null)
            {
                db.THISINH.Remove(ts);
                db.SaveChanges();
                LoadDB();
                MessageBox.Show("Xoá thành công");
            }
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            string ma = tbMaTS.Text;
            var ts = db.THISINH.FirstOrDefault(x => x.MaTS == ma);
            if (ts != null)
            {
                ts.MaTS = tbMaTS.Text;
                ts.HoTen = tbTen.Text;
                ts.NgaySinh = dpNgay.SelectedDate;
                ts.DiemThi = double.Parse(tbDiem.Text);
                ts.MaNganh = cbNganhHoc.SelectedValue.ToString();
                db.SaveChanges();
                LoadDB();
                MessageBox.Show("Sửa thành công");
            }
        }

        private void DgTS_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(dgTS.SelectedItem is THISINH ts)
            {
                tbMaTS.Text = ts.MaTS;
                tbTen.Text = ts.HoTen;
                dpNgay.SelectedDate = ts.NgaySinh;
                tbDiem.Text = ts.DiemThi.ToString();
                cbNganhHoc.SelectedValue = ts.MaNganh;
            }
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            string tk = tbTim.Text.ToLower().Trim();
            var loc = db.THISINH.Where(x => x.HoTen.ToLower().Contains(tk)).ToList();
            dgTS.ItemsSource = loc;
            tbDem.Text = loc.ToList().Count().ToString();
            if (loc.Count() == 0)
            {
                MessageBox.Show("Khong tim thấy");
            }
        }

        private void CbNganhHoc_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(cbNganhHoc.SelectedValue != null)
            {
                string chon = cbNganhHoc.SelectedValue.ToString();
                var loc = db.THISINH.Where(x => x.MaNganh == chon).ToList();
                dgTS.ItemsSource = loc;
                tbDem.Text = loc.ToList().Count().ToString();
            }
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {

        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
