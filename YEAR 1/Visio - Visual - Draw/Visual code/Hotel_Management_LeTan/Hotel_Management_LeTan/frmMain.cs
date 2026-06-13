using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using DevExpress.XtraBars;

namespace Hotel_Management_LeTan
{
    public partial class frmMain : DevExpress.XtraBars.Ribbon.RibbonForm
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void barButtonItem1_ItemClick(object sender, ItemClickEventArgs e)
        {
            frmLogin frmlogin = new frmLogin();
            frmlogin.Show();
        }

        private void barButtonItem8_ItemClick(object sender, ItemClickEventArgs e)
        {
            frmCheckin frmcheckin = new frmCheckin();   
            frmcheckin.Show();
        }

        private void barButtonItem9_ItemClick(object sender, ItemClickEventArgs e)
        {
            frmCheckout frmcheckout = new frmCheckout();        
              frmcheckout.Show();   
        }

        private void barButtonItem10_ItemClick(object sender, ItemClickEventArgs e)
        {
            frmTraphong frmtraphong = new frmTraphong();    
            frmtraphong.Show(); 
        }

        private void barButtonItem15_ItemClick(object sender, ItemClickEventArgs e)
        {
            Updatedv updatedv = new Updatedv(); 
            updatedv.Show();    
        }

        private void barButtonItem16_ItemClick(object sender, ItemClickEventArgs e)
        {
            Kiemtra kiemtra = new Kiemtra();        
            kiemtra.Show();
        }

        private void barButtonItem11_ItemClick(object sender, ItemClickEventArgs e)
        {
            Theodoi theodoi = new Theodoi();    
            theodoi.Show(); 
        }

        private void barButtonItem12_ItemClick(object sender, ItemClickEventArgs e)
        {
            Voucher voucher = new Voucher();    
            voucher.Show(); 
        }

        private void barButtonItem13_ItemClick(object sender, ItemClickEventArgs e)
        {
            Thongtinkh thongtinkh = new Thongtinkh();
            thongtinkh.Show();  
        }

        private void barButtonItem14_ItemClick(object sender, ItemClickEventArgs e)
        {
            Chuanbi chuanbi = new Chuanbi();
            chuanbi.Show();
        }
    }
}