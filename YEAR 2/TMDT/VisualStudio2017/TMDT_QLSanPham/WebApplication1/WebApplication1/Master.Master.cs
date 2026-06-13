using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class Master : System.Web.UI.MasterPage
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                    DB_Connect db = new DB_Connect();
                    DataTable data = new DataTable();
                    data = db.getData("select * from LOAISANPHAM");
                    Repeater1.DataSource = data;
                    Repeater1.DataBind();
            }
        }
    }
}