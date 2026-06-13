using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace QuanLiThuVien
{
    public partial class Home : System.Web.UI.Page
    {

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {

                string ma_loai = Request.QueryString["maloai"];
                if (ma_loai != null)
                {
                    DB_connect db = new DB_connect();
                    DataTable data = new DataTable();
                    data = db.getData("select * from SACH where id_loai=" + ma_loai);
                    Repeater1.DataSource = data;
                    Repeater1.DataBind();
                }

            }
        }
    }
}