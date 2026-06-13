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

namespace KiemTraCuoiKyLab
{
    public partial class MainWindow : Window
    {
        QLVatTuEntities db = new QLVatTuEntities();

        public MainWindow()
        {
            InitializeComponent();
            LoadComboBox();
            LoadDataGrid();
        }

        private void LoadDataGrid()
        {
            db = new QLVatTuEntities();
            dgVatTu.ItemsSource = db.VATTUs.ToList();
        }

        private void LoadComboBox()
        {
            cbNhaSanXuat.ItemsSource = db.NHASANXUATs.ToList();
            cbNhaSanXuat.DisplayMemberPath = "TenNSX";
            cbNhaSanXuat.SelectedValuePath = "MaNSX";
        }

        private void cbNhaSanXuat_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (cbNhaSanXuat.SelectedValue != null)
            {
                string maNhaSX = cbNhaSanXuat.SelectedValue.ToString();
                dgVatTu.ItemsSource = db.VATTUs.Where(vt => vt.MaNSX == maNhaSX).ToList();
            }
        }

        private void btnLoadLai_Click(object sender, RoutedEventArgs e)
        {
            cbNhaSanXuat.SelectedIndex = -1;
            LoadDataGrid();

            txtMaVatTu.Clear();
            txtTenVatTu.Clear();
            dpNgaySanXuat.SelectedDate = null;
            txtDem.Clear();
        }

        private void dgVatTu_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var selected = dgVatTu.SelectedItem as VATTU;
            if (selected != null)
            {
                txtMaVatTu.Text = selected.MaVatTu;
                txtTenVatTu.Text = selected.TenVatTu;
                dpNgaySanXuat.SelectedDate = selected.NgaySanXuat;

                cbNhaSanXuat.SelectionChanged -= cbNhaSanXuat_SelectionChanged;
                cbNhaSanXuat.SelectedValue = selected.MaNSX;
                cbNhaSanXuat.SelectionChanged += cbNhaSanXuat_SelectionChanged;
            }
        }

        private void btnThem_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                if (string.IsNullOrWhiteSpace(txtMaVatTu.Text) || string.IsNullOrWhiteSpace(txtTenVatTu.Text))
                {
                    MessageBox.Show("Vui lòng nhập đầy đủ Mã và Tên vật tư!");
                    return;
                }

                VATTU newVT = new VATTU()
                {
                    MaVatTu = txtMaVatTu.Text.Trim(),
                    TenVatTu = txtTenVatTu.Text.Trim(),
                    NgaySanXuat = dpNgaySanXuat.SelectedDate,
                    MaNSX = cbNhaSanXuat.SelectedValue?.ToString()
                };

                db.VATTUs.Add(newVT);
                db.SaveChanges();

                MessageBox.Show("Thêm vật tư thành công!", "Thông báo");
                LoadDataGrid();
            }
            catch (Exception)
            {
                MessageBox.Show("Lỗi: Mã vật tư này đã tồn tại trong hệ thống!", "Lỗi thêm mới");
            }
        }

        private void btnSua_Click(object sender, RoutedEventArgs e)
        {
            var maVT = txtMaVatTu.Text.Trim();
            var vtUpdate = db.VATTUs.FirstOrDefault(x => x.MaVatTu == maVT);

            if (vtUpdate != null)
            {
                vtUpdate.TenVatTu = txtTenVatTu.Text.Trim();
                vtUpdate.NgaySanXuat = dpNgaySanXuat.SelectedDate;
                vtUpdate.MaNSX = cbNhaSanXuat.SelectedValue?.ToString();

                db.SaveChanges();
                MessageBox.Show("Cập nhật thông tin thành công!", "Thông báo");
                LoadDataGrid();
            }
            else
            {
                MessageBox.Show("Không tìm thấy Mã vật tư này để sửa!", "Cảnh báo");
            }
        }

        private void btnXoa_Click(object sender, RoutedEventArgs e)
        {
            var maVT = txtMaVatTu.Text.Trim();
            var vtDelete = db.VATTUs.FirstOrDefault(x => x.MaVatTu == maVT);

            if (vtDelete != null)
            {
                MessageBoxResult result = MessageBox.Show($"Bạn có chắc chắn muốn xóa vật tư [{maVT}] không?", "Xác nhận", MessageBoxButton.YesNo, MessageBoxImage.Warning);
                if (result == MessageBoxResult.Yes)
                {
                    db.VATTUs.Remove(vtDelete);
                    db.SaveChanges();

                    MessageBox.Show("Xóa thành công!", "Thông báo");
                    btnLoadLai_Click(null, null);
                }
            }
            else
            {
                MessageBox.Show("Vui lòng chọn vật tư cần xóa từ bảng!", "Cảnh báo");
            }
        }

        private void btnDem_Click(object sender, RoutedEventArgs e)
        {
            txtDem.Text = dgVatTu.Items.Count.ToString();
        }
    }
}