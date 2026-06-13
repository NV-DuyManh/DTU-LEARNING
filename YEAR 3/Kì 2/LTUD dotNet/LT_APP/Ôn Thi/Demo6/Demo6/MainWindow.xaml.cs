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

namespace Demo6
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        QuanLyVatTuEntities db = new QuanLyVatTuEntities();
        public MainWindow()
        {
            InitializeComponent();
        }
        private void LoadDB()
        {
            dgVatTu.ItemsSource = db.VATTU.ToList();
            cbNSX.ItemsSource = db.NHASANXUAT.ToList();
            cbNSX.DisplayMemberPath = "TenNSX";
            cbNSX.SelectedValuePath = "MaNSX";
           
        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            LoadDB();
        }

        private void DgVatTu_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(dgVatTu.SelectedItem is VATTU vt)
            {
                tbMa.Text = vt.MaVatTu;
                tbTen.Text = vt.TenVatTu;
                dpNgay.SelectedDate = vt.NgaySanXuat;
                cbNSX.SelectedValue = vt.MaNSX;
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            VATTU vt = new VATTU();
            vt.MaVatTu = tbMa.Text;
            vt.TenVatTu = tbTen.Text;
            vt.NgaySanXuat = dpNgay.SelectedDate;
            vt.MaNSX = cbNSX.SelectedValue.ToString();
            db.VATTU.Add(vt);
            db.SaveChanges();
            LoadDB();
            MessageBox.Show("Thêm thành công");

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            string ma = tbMa.Text;
            var vt = db.VATTU.FirstOrDefault(x => x.MaVatTu == ma);
            if (vt != null)
            {
                vt.MaVatTu = tbMa.Text;
                vt.TenVatTu = tbTen.Text;
                vt.NgaySanXuat = dpNgay.SelectedDate;
                vt.MaNSX = cbNSX.SelectedValue.ToString();
                db.SaveChanges();
                LoadDB();
                MessageBox.Show("Sửa thành công");
            }
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            string ma = tbMa.Text;
            var vt = db.VATTU.FirstOrDefault(x => x.MaVatTu == ma);
            if (vt != null)
            {
                db.VATTU.Remove(vt);
                db.SaveChanges();
                LoadDB();
                MessageBox.Show("Xoá thành công");
            }
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            tbMa.Clear();
            tbTen.Clear();
            dpNgay.SelectedDate = null;
            cbNSX.SelectedIndex = -1;
            tbDem.Clear();
            LoadDB();
        }

        private void TbDem_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void BtDem_Click(object sender, RoutedEventArgs e)
        {
            tbDem.Text = db.VATTU.ToList().Count().ToString();
        }

        private void CbNSX_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (cbNSX.SelectedValue != null)
            {
                string machon = cbNSX.SelectedValue.ToString();
                var loc = db.VATTU.Where(x => x.MaNSX == machon).ToList();
                dgVatTu.ItemsSource = loc;
                tbDem.Text = loc.ToList().Count().ToString();
            }


            //if (cbNSX.SelectedValue != null)
            //{
            //    string maDuocChon = cbNSX.SelectedValue.ToString();

            //    // Lọc trong DB: chỉ lấy những Vật tư có MaNSX khớp với mã vừa chọn
            //    var danhSachLoc = db.VATTU.Where(x => x.MaNSX == maDuocChon).ToList();

            //    // Đổ dữ liệu đã lọc vào DataGrid
            //    dgVatTu.ItemsSource = danhSachLoc;

            //    // Cập nhật luôn ô đếm để người dùng biết có bao nhiêu vật tư của NSX này
            //    tbDem.Text = danhSachLoc.ToList().Count.ToString();
            //}
        }
    }
}
