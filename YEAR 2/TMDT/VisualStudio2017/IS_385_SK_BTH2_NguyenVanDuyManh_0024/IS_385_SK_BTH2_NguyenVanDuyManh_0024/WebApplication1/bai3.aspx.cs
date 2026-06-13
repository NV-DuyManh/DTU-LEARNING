using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class bai3 : System.Web.UI.Page
    {
        [Serializable]
        public class BANHANG
        {
            public string San_Pham { get; set; }
            public int Don_Gia { get; set; }
            public int So_Luong { get; set; }
            public int Thanh_Tien
            {
                get { return Don_Gia * So_Luong; }
            }
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                List<BANHANG> ds = new List<BANHANG>
                {

                };
                ViewState["List"] = ds;
                GridView1.DataSource = ds;
                GridView1.DataBind();
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string sp = TextBox1.Text;
            int dg = int.Parse(TextBox2.Text);
            int sl = int.Parse(TextBox3.Text);
            BANHANG a = new BANHANG
            {
                San_Pham = sp,
                Don_Gia = dg,
                So_Luong = sl,
            };
            List<BANHANG> ds = ViewState["List"] as List<BANHANG>;
            ds.Add(a);
            ViewState["List"] = ds;
            GridView1.DataSource = ds;
            GridView1.DataBind();
            tinhtien();
        }
        public void tinhtien()
        {
            List<BANHANG> ds = ViewState["List"] as List<BANHANG>;
            int tong = 0;
            foreach (BANHANG value in ds)
            {
                tong += value.Thanh_Tien;
                Label1.Text = "Tổng tiền: " + tong.ToString("N0") + " VND";
            }
        }
    }
}