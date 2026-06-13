using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.SessionState;

namespace WebApplication1
{
    public class Global : System.Web.HttpApplication
    {

        protected void Application_Start(object sender, EventArgs e)
        {
            Application["SoNguoTruyCap"] = 0;
        }

        protected void Session_Start(object sender, EventArgs e)
        {
            Application.Lock();
            Application["SoNguoTruyCap"] = (int)Application["SoNguoTruyCap"] +1;
            Application.UnLock();
        }

        
        protected void Session_End(object sender, EventArgs e)
        {
            Application.Lock();
            Application["SoNguoTruyCap"] = (int)Application["SoNguoTruyCap"] -1 ;
            Application.UnLock();
        }

        
    }
}