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
using System.Windows.Shapes;

namespace WPF
{
    /// <summary>
    /// Interaction logic for MayTinhMini.xaml
    /// </summary>
    public partial class MayTinhMini : Window
    {
        public MayTinhMini()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Button btn = sender as Button;

            if (btn == null) return;

            // Lấy số người dùng nhập
            if (!double.TryParse(txt_nhap1.Text, out double a) ||
               !double.TryParse(txt_nhap2.Text, out double b))
            {
                MessageBox.Show("Vui lòng nhập số hợp lệ!");
                return;
            }

            double kq = 0;

            // Kiểm tra nút được bấm
            if (btn.Name == "btn_cong")
            {
                kq = a + b;
            }
            else if (btn.Name == "btn_tru")
            {
                kq = a - b;
            }
            else if (btn.Name == "btn_nhan")
            {
                kq = a * b;
            }
            else
            {
                if (b == 0)
                {
                    MessageBox.Show("Không thể chia cho 0!");
                    return;
                }
                kq = a / b;
            }

            MessageBox.Show("Kết quả = " + kq);
        }

        private void Txt_nhap2_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
