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

namespace WPF
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Btn_DN_Click(object sender, RoutedEventArgs e)
        {
            if (txt_TK.Text == "admin" && txt_MK.Text == "123")
            {
                MayTinhMini mayTinh = new MayTinhMini();
                mayTinh.Show();
            }
            else
            {
                MessageBox.Show("Tai khoan hoac mat khau sai");
            }
        }
    }
}
