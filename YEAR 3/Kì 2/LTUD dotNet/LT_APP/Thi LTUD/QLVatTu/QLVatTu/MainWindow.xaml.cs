using System;
using System.Linq;
using System.Windows;
using System.Windows.Controls;

namespace QLVatTu
{
    public partial class MainWindow : Window
    {
        QuanLyVatTuEntities db = new QuanLyVatTuEntities();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            LoadData();
        }

        private void LoadData()
        {
            dgVatTu.ItemsSource = db.VATTU.ToList();

            cboNSX.ItemsSource = db.NHASANXUAT.ToList();
            cboNSX.DisplayMemberPath = "TenNSX";
            cboNSX.SelectedValuePath = "MaNSX";
        }

        private void btnDem_Click(object sender, RoutedEventArgs e)
        {
            txtDem.Text = dgVatTu.Items.Count.ToString();
        }

        private void cboNSX_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (cboNSX.SelectedValue != null)
            {
                string maNSX = cboNSX.SelectedValue.ToString();
                dgVatTu.ItemsSource = db.VATTU.Where(x => x.MaNSX == maNSX).ToList();
            }
        }

        private void btnThem_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                VATTU v = new VATTU();
                v.MaVatTu = txtMaVatTu.Text;
                v.TenVatTu = txtTenVatTu.Text;
                v.NgaySanXuat = dtpNgaySX.SelectedDate;

                if (cboNSX.SelectedValue != null)
                {
                    v.MaNSX = cboNSX.SelectedValue.ToString();
                }

                db.VATTU.Add(v);
                db.SaveChanges();
                LoadData();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnSua_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string ma = txtMaVatTu.Text;
                var v = db.VATTU.FirstOrDefault(x => x.MaVatTu == ma);
                if (v != null)
                {
                    v.TenVatTu = txtTenVatTu.Text;
                    v.NgaySanXuat = dtpNgaySX.SelectedDate;

                    if (cboNSX.SelectedValue != null)
                    {
                        v.MaNSX = cboNSX.SelectedValue.ToString();
                    }

                    db.SaveChanges();
                    LoadData();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnXoa_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string ma = txtMaVatTu.Text;
                var v = db.VATTU.FirstOrDefault(x => x.MaVatTu == ma);
                if (v != null)
                {
                    db.VATTU.Remove(v);
                    db.SaveChanges();
                    LoadData();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnLoad_Click(object sender, RoutedEventArgs e)
        {
            cboNSX.SelectedItem = null;
            LoadData();
        }

        private void dgVatTu_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (dgVatTu.SelectedItem is VATTU selected)
            {
                txtMaVatTu.Text = selected.MaVatTu;
                txtTenVatTu.Text = selected.TenVatTu;
                dtpNgaySX.SelectedDate = selected.NgaySanXuat;
                cboNSX.SelectedValue = selected.MaNSX;
            }
        }
    }
}