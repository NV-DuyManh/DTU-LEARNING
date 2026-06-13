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

namespace Demo11
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        QLVATTUEntities db = new QLVATTUEntities();
        public MainWindow()
        {
            InitializeComponent();
        }
        private void LoadDB()
        {
            dgVT.ItemsSource = db.VATTU.ToList();
            cbNSX.ItemsSource = db.NHASANXUAT.ToList();
            cbNSX.DisplayMemberPath = "TenNSX";
            cbNSX.SelectedValuePath = "MaNSX";

        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            LoadDB();
        }

        private void DgVT_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(dgVT.SelectedItem is VATTU vt)
            {
                tbMaVT.Text = vt.MaVatTu.ToString();
                tbTenVT.Text = vt.TenVatTu;
                dpNgay.SelectedDate = vt.NgaySanXuat;
                cbNSX.SelectedValue = vt.MaNSX;
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            VATTU vt = new VATTU();
            vt.MaVatTu =int.Parse(tbMaVT.Text);
            vt.TenVatTu = tbTenVT.Text;
            vt.NgaySanXuat = dpNgay.SelectedDate;
            vt.MaNSX = cbNSX.SelectedValue.ToString();
            db.VATTU.Add(vt);
            db.SaveChanges();
            LoadDB();
            MessageBox.Show("Thêm thành công");

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            int ma = int.Parse(tbMaVT.Text);
            var vt = db.VATTU.FirstOrDefault(x => x.MaVatTu == ma);
            if (vt != null)
            {
                vt.MaVatTu = int.Parse(tbMaVT.Text);
                vt.TenVatTu = tbTenVT.Text;
                vt.NgaySanXuat = dpNgay.SelectedDate;
                vt.MaNSX = cbNSX.SelectedValue.ToString();
                db.SaveChanges();
                LoadDB();
                MessageBox.Show("Sửa thành công");
            }
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            int ma = int.Parse(tbMaVT.Text);
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
            tbMaVT.Clear();
            tbTenVT.Clear();
            dpNgay.SelectedDate = null;
            cbNSX.SelectedIndex = -1;
            tbDem.Text = db.VATTU.ToList().Count().ToString();
            LoadDB();
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            tbDem.Text = db.VATTU.ToList().Count().ToString();
        }

        private void CbNSX_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (cbNSX.SelectedValue != null)
            {
                string chon = cbNSX.SelectedValue.ToString();
                var loc = db.VATTU.Where(x => x.MaNSX == chon).ToList();
                dgVT.ItemsSource = loc;
                tbDem.Text = loc.ToList().Count().ToString();
            }
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            string tk = tbTim.Text.ToLower().Trim();
            var kq = db.VATTU.Where(x => x.TenVatTu.ToLower().Contains(tk)).ToList();
            dgVT.ItemsSource = kq;
            tbDem.Text = kq.ToList().Count().ToString();
            if (kq.Count == 0)
            {
                MessageBox.Show("k co");
            }
        }
    }
}
