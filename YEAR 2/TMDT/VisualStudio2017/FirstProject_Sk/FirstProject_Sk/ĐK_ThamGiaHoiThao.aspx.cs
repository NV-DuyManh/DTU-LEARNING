using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace FirstProject_Sk
{
    public partial class ĐK_ThamGiaHoiThao : System.Web.UI.Page
    {
        [Serializable]
        public class HOITHAO
        {
            public string hoten { get; set; }
            public string gioitinh { get; set; }
            public string chude { get; set; }
            public string ngaythamgia { get; set; }

        }

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                List<HOITHAO> danhsach = new List<HOITHAO>
                {
        
                };
                ViewState["LIST"] = danhsach;
                GridView1.DataSource = danhsach;
                GridView1.DataBind();
            }
        }

        protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }


        protected void Button1_Click1(object sender, EventArgs e)
        {
            string ho_ten = TextBox1.Text;
            string gioi_tinh = RadioButtonList1.SelectedItem.Text;
            string chu_de = DropDownList1.SelectedItem.Text;
            string ngay_tham_gia = Calendar1.SelectedDate.ToLongDateString();



            HOITHAO a = new HOITHAO { hoten = ho_ten, gioitinh = gioi_tinh, chude = chu_de, ngaythamgia = ngay_tham_gia };
            List<HOITHAO> danhsach = ViewState["LIST"] as List<HOITHAO>;
            danhsach.Add(a);

            ViewState["LIST"] = danhsach;

            GridView1.DataSource = danhsach;
            GridView1.DataBind();
            dem();
        }
        public void dem()
        {
            List<HOITHAO> danhsach = ViewState["LIST"] as List<HOITHAO>;
            int tong = 0;
            int dem1 = 0;
            int dem2 = 0;
            foreach (HOITHAO value in danhsach)
            {
                if (value.gioitinh == "Nam")
                {
                    dem1 += 1;
                }else 
                {
                    dem2 += 1;
                }
                tong ++;
            }
            Label1.Text = "Số nam là " + dem1.ToString();
            Label2.Text = "Số nữ là: " + dem2.ToString();
            Label3.Text = "Tổng số người tham gia là: " + tong.ToString();

        }
    }
}