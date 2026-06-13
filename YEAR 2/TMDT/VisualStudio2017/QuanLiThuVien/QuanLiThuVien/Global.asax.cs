using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.SessionState;

namespace QuanLiThuVien
{
    public class Global : System.Web.HttpApplication
    {

        protected void Application_Start(object sender, EventArgs e)
        {
            Application["so_nguoi_online"] = 0;
            Application["tong_so_nguoi_da_truy_cap"] = 0;
        }

        protected void Session_Start(object sender, EventArgs e)
        {
            Application.Lock();
            Application["so_nguoi_online"] = (int)Application["so_nguoi_online"] +1 ;
            Application["tong_so_nguoi_da_truy_cap"] = (int)Application["tong_so_nguoi_da_truy_cap"] +1;

            Application.UnLock();
          
        }

        
        protected void Session_End(object sender, EventArgs e)
        {
            Application.Lock();
            Application["so_nguoi_online"] = (int)Application["so_nguoi_online"] - 1;
            Application.UnLock();
        }

        
    }
}