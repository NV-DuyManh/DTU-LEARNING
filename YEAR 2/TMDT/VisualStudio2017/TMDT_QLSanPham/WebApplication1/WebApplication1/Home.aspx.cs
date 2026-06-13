using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class Home : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {

                string ma_loai = Request.QueryString["MaLoai"];
                if (ma_loai != null)
                {
                    DB_Connect db = new DB_Connect();
                    DataTable data = new DataTable();
                    data = db.getData("select * from SANPHAM where MaSanPham=" + ma_loai);
                    Repeater1.DataSource = data;
                    Repeater1.DataBind();
                }

            }

        }
    }
}