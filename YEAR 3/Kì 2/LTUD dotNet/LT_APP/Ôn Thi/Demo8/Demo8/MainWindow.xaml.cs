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

namespace Demo8
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
            
            dgDS.ItemsSource = db.THISINH.ToList();
            cbNganh.ItemsSource = db.NGANHHOC.ToList();
            cbNganh.DisplayMemberPath = "TenNganh";
            cbNganh.SelectedValuePath = "MaNganh";
            
        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            LoadDB();
        }
        private void DataGrid_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(dgDS.SelectedItem is THISINH ts)
            {
                tbMaTS.Text = ts.MaTS;
                tbHoTen.Text = ts.HoTen;
                dpNgay.SelectedDate = ts.NgaySinh;
                tbDiem.Text = ts.DiemThi.ToString();
                cbNganh.SelectedValue = ts.MaNganh;
            }

        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            THISINH ts = new THISINH();
            ts.MaTS = tbMaTS.Text;
            ts.HoTen = tbHoTen.Text;
            ts.NgaySinh = dpNgay.SelectedDate;
            ts.DiemThi = double.Parse(tbDiem.Text);
            ts.MaNganh = cbNganh.SelectedValue.ToString();
            db.THISINH.Add(ts);
            db.SaveChanges();
            LoadDB();
            MessageBox.Show("Thêm thành công");

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            string ma = tbMaTS.Text;
            var ts = db.THISINH.FirstOrDefault(x => x.MaTS == ma);
            if (ts != null)
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
                ts.HoTen = tbHoTen.Text;
                ts.NgaySinh = dpNgay.SelectedDate;
                ts.DiemThi = double.Parse(tbDiem.Text);
                ts.MaNganh = cbNganh.SelectedValue.ToString();
                db.SaveChanges();
                LoadDB();
                MessageBox.Show("Cập nhật thành công");
            }
        }

     

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            string tk = tbTim.Text.ToLower().Trim();
            var kq = db.THISINH.Where(x => x.HoTen.ToLower().Contains(tk)).ToList();
            dgDS.ItemsSource = kq;
            if (kq.Count() == 0)
            {
                MessageBox.Show("K tìm thấy");
            }

            //string tuKhoa = tbTim.Text.ToLower().Trim();
            //var ketQua = db.THISINH
            //               .Where(x => x.HoTen.ToLower().Contains(tuKhoa))
            //               .ToList();

            //dgDS.ItemsSource = ketQua;

            //if (ketQua.Count == 0)
            //{
            //    MessageBox.Show("Không tìm thấy thí sinh nào khớp với từ khóa!");
            //}
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            int sl = db.THISINH.ToList().Count();
            tbDem.Text =sl.ToString();
            MessageBox.Show("Hiện có tổng cộng " + sl + " sản phẩm.");

        }
    }
}
