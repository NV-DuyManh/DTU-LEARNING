using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;

namespace QUANLYTUYENSINH
{
    public partial class MainWindow : Window
    {
        QUANLYTUYENSINHEntities db = new QUANLYTUYENSINHEntities();

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
            dgDanhSach.ItemsSource = db.THISINH.ToList();
            cboNganhHoc.ItemsSource = db.NGANHHOC.ToList();
            cboNganhHoc.DisplayMemberPath = "TenNganh";
            cboNganhHoc.SelectedValuePath = "MaNganh";
        }

        private void dgDanhSach_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (dgDanhSach.SelectedItem is THISINH selected)
            {
                txtMaTS.Text = selected.MaTS;
                txtHoTen.Text = selected.HoTen;
                dtpNgaySinh.SelectedDate = selected.NgaySinh;
                txtDiemThi.Text = selected.DiemThi.ToString();
                cboNganhHoc.SelectedValue = selected.MaNganh;

                if (selected.GioiTinh == true)
                {
                    rbNam.IsChecked = true;
                }
                else
                {
                    rbNu.IsChecked = true;
                }
            }
        }

        private void btnThem_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                THISINH ts = new THISINH();
                ts.MaTS = txtMaTS.Text;
                ts.HoTen = txtHoTen.Text;
                ts.NgaySinh = dtpNgaySinh.SelectedDate;
                ts.GioiTinh = rbNam.IsChecked;

                double diem;
                if (double.TryParse(txtDiemThi.Text, out diem))
                {
                    ts.DiemThi = diem;
                }

                if (cboNganhHoc.SelectedValue != null)
                {
                    ts.MaNganh = cboNganhHoc.SelectedValue.ToString();
                }

                db.THISINH.Add(ts);
                db.SaveChanges();
                LoadData();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.InnerException?.Message ?? ex.Message);
            }
        }

        private void btnCapNhat_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string ma = txtMaTS.Text;
                var ts = db.THISINH.FirstOrDefault(x => x.MaTS == ma);
                if (ts != null)
                {
                    ts.HoTen = txtHoTen.Text;
                    ts.NgaySinh = dtpNgaySinh.SelectedDate;
                    ts.GioiTinh = rbNam.IsChecked;

                    double diem;
                    if (double.TryParse(txtDiemThi.Text, out diem))
                    {
                        ts.DiemThi = diem;
                    }

                    if (cboNganhHoc.SelectedValue != null)
                    {
                        ts.MaNganh = cboNganhHoc.SelectedValue.ToString();
                    }

                    db.SaveChanges();
                    LoadData();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.InnerException?.Message ?? ex.Message);
            }
        }

        private void btnXoa_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string ma = txtMaTS.Text;
                var ts = db.THISINH.FirstOrDefault(x => x.MaTS == ma);
                if (ts != null)
                {
                    db.THISINH.Remove(ts);
                    db.SaveChanges();
                    LoadData();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.InnerException?.Message ?? ex.Message);
            }
        }

        private void btnTim_Click(object sender, RoutedEventArgs e)
        {
            string tuKhoa = txtTimKiem.Text.ToLower();
            dgDanhSach.ItemsSource = db.THISINH.Where(x => x.HoTen.ToLower().Contains(tuKhoa)).ToList();
        }
    }
}