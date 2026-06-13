using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class QLSACH : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string ma = Request.QueryString["maloai"];
                if (ma != null)
                {
                    DB_Connect db = new DB_Connect();
                    DataTable data = new DataTable();
                    data = db.getData("select * from KHO_SACH where MACHUDE="+ma);
                    Repeater1.DataSource = data;
                    Repeater1.DataBind();
                }
                
            }
        }
    }
}