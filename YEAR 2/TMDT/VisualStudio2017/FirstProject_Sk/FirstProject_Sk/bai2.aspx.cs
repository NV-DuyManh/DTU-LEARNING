using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace FirstProject_Sk
{
    public partial class bai2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string ten = TextBox1.Text;
            Label1.Text = "Ho ten: " + ten;
            string sanpham = DropDownList1.SelectedItem.Text;
            Label2.Text = "San pham: " + sanpham;
            string soluong = TextBox2.Text;
            Label3.Text = "So luong: " + soluong;
           



        }
    }
}