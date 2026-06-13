using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace FirstProject_Sk
{
    public partial class QLDK_Khoa_Hoc : System.Web.UI.Page
    {
        [Serializable]
        public class SINHVIEN
        {
            public string hoten { get; set; }
            public string monhoc { get; set; }
            public int hocphi { get; set; }
        }

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                DataTable data = new DataTable();
                DB_Connect helper = new DB_Connect();
                data = helper.getData("select * from Khoa_Hoc");
             
                Repeater1.DataSource = data;
                Repeater1.DataBind();
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string ho_ten = TextBox1.Text;
            string mon_hoc = DropDownList1.SelectedItem.Text;
            int hoc_phi = int.Parse(TextBox2.Text);

            //Thêm thông tin phía trên vào danh sách

            SINHVIEN a = new SINHVIEN { hoten = ho_ten, monhoc = mon_hoc, hocphi = hoc_phi };
            List<SINHVIEN> danhsach = ViewState["LIST"] as List<SINHVIEN>;
            danhsach.Add(a);
            //Lưu lại dữ liêu danh sách mới vào Viewstate["LIST"]
            ViewState["LIST"] = danhsach;
            //Đẩy dữ liệu lên view
            Repeater1.DataSource = danhsach;
            Repeater1.DataBind();
            //  tinhhocphi();
        }
        public void tinhhocphi()
        {
            List<SINHVIEN> danhsach = ViewState["LIST"] as List<SINHVIEN>;
            int tong = 0;
            foreach (SINHVIEN value in danhsach)
            {
                tong = tong + value.hocphi;
            }
            Label1.Text = tong.ToString();
        }




    }
}