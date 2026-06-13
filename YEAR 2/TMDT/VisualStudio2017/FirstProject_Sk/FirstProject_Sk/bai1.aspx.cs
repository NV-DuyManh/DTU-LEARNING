using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace FirstProject_Sk
{
    public partial class bai1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                List<String> listdiemdi = new List<string>
            {
                "Đà Nẵng", "Hà Nội", "Sài Gòn", "Hồ Chí Minh"
            };
                List<String> listdiemden = new List<string>
            {
                "Seoul", "Paris", "Tokyo", "Kyoto"
            };


                DropDownList1.DataSource = listdiemdi;
                DropDownList1.DataBind();
                DropDownList2.DataSource = listdiemden;
                DropDownList2.DataBind();
            }
        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
           

            string hoten = TextBox1.Text;
            Label1.Text = "Ho ten: " + hoten;

            string diemdi = DropDownList1.SelectedItem.Text;
            Label2.Text = "Diem di: "+ diemdi;

            string diemden = DropDownList2.SelectedItem.Text;
            Label3.Text = "Diem den: " + diemden;

            string ngaydat = Calendar1.SelectedDate.ToLongDateString();
            Label4.Text = "Ngay dat: " + ngaydat;

            Label1.Text = "Ho ten: " + hoten + "<br>"+ "Diem di: " + diemdi + "<br>" + "Diem den: " + diemden + "<br>" + "Ngay dat: " + ngaydat;

        }
    }
}