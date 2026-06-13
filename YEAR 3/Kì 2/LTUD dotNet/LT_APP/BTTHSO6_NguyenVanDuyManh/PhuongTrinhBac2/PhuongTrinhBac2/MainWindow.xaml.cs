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

namespace PhuongTrinhBac2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }


        private void giai_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                double a = double.Parse(soA.Text);
                double b = double.Parse(soB.Text);
                double c = double.Parse(soC.Text);

                if (a == 0)
                {
                    if (b == 0)
                    {
                        if (c == 0)
                            ketQua.Text = "Phương trình có vô số nghiệm";
                        else
                            ketQua.Text = "Phương trình vô nghiệm";
                    }
                    else
                    {
                        double x = -c / b;
                        ketQua.Text = "Phương trình có 1 nghiệm: " + x.ToString();
                    }
                }
                else
                {
                    double delta = b * b - 4 * a * c;

                    if (delta < 0)
                    {
                        ketQua.Text = "Phương trình vô nghiệm";
                    }
                    else if (delta == 0)
                    {
                        double x = -b / (2 * a);
                        ketQua.Text = "Nghiệm kép x1 = x2 = " + x.ToString();
                    }
                    else
                    {
                        double x1 = (-b + Math.Sqrt(delta)) / (2 * a);
                        double x2 = (-b - Math.Sqrt(delta)) / (2 * a);
                        ketQua.Text = "x1 = " + x1.ToString() + "\n" + "x2 = " + x2.ToString();
                    }
                }
            }
            catch
            {
                MessageBox.Show("Vui lòng nhập số hợp lệ");
            }
        }

        private void xoa_Click(object sender, RoutedEventArgs e)
        {
            soA.Text = "";
            soB.Text = "";
            soC.Text = "";
            ketQua.Text = "";
            soA.Focus();
        }

        private void thoat_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
