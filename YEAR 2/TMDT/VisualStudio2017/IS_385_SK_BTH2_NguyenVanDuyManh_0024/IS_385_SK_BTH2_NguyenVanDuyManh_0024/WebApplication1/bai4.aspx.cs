using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class bai4 : System.Web.UI.Page
    {
        [Serializable]
        public class MuonSach
        {
            public string TenDocGia { get; set; }
            public string TenSach { get; set; }
            public string NgayMuon { get; set; }
            public string NgayTra { get; set; }
        }

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                List<MuonSach> ds = new List<MuonSach>();
                ViewState["DanhSach"] = ds;
                GridView1.DataSource = ds;
                GridView1.DataBind();
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string tenDocGia = TextBox1.Text;
            string tenSach = DropDownList1.SelectedItem.Text;
            string ngayMuon = Calendar1.SelectedDate.ToShortDateString();
            string ngayTra = Calendar2.SelectedDate.ToShortDateString();

            MuonSach muon = new MuonSach
            {
                TenDocGia = tenDocGia,
                TenSach = tenSach,
                NgayMuon = ngayMuon,
                NgayTra = ngayTra
            };

            List<MuonSach> ds = ViewState["DanhSach"] as List<MuonSach>;
            ds.Add(muon);
            ViewState["DanhSach"] = ds;

            GridView1.DataSource = ds;
            GridView1.DataBind();

            CapNhatSoLuotMuon();
        }

        private void CapNhatSoLuotMuon()
        {
            List<MuonSach> ds = ViewState["DanhSach"] as List<MuonSach>;
            int tong = ds.Count;
            Label1.Text = "Tổng số lượt mượn: " + tong.ToString();
        }
    }
}