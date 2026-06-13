using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace FirstProject_Sk
{
    public partial class text : System.Web.UI.Page
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
                DB helper = new DB();
                data = helper.getData("select * from Khoa_Hoc");

                Repeater1.DataSource = data;
                Repeater1.DataBind();
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            DB helper = new DB();
            string sql = "insert into Khoa_Hoc (id, hovaten, monhoc,hocphi)" +
                "values('124', N'Duy Mạnh','Tin','100000')";
            int check = helper.ExcuteNonQuery(sql);
        }





    }
}