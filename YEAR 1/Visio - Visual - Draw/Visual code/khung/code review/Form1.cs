using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace code_review
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void labelControl1_Click(object sender, EventArgs e)
        {

        }

        private void labelMessage_Click(object sender, EventArgs e)
        {

        }

        private void buttonLogin_Click(object sender, EventArgs e)
        {
            string username = textBoxUsername.Text;
            string password = textBoxPassword.Text;

            if (Authenticate(username, password))
            {
                labelMessage.Text = "Đăng nhập thành công!";
                labelMessage.ForeColor = System.Drawing.Color.Green;
            }
            else
            {
                labelMessage.Text = "Đăng nhập thất bại!";
                labelMessage.ForeColor = System.Drawing.Color.Red;
            }
        }
        private bool Authenticate(string username, string password)
        {
            // Kiểm tra thông tin đăng nhập
            return username == "admin" && password == "123";
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
