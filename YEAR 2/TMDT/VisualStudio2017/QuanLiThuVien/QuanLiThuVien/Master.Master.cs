using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace QuanLiThuVien
{
    public partial class Master : System.Web.UI.MasterPage
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                DB_connect db = new DB_connect();
                DataTable data = new DataTable();
                data = db.getData("select * from LOAISACH");
                Repeater1.DataSource = data;
                Repeater1.DataBind();
            }
        }
    }
}