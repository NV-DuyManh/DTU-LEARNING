using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kethua
{
    class NhanVien : Nguoi
    {
        //Đây là cách viết che khuất phương thức 
        public new void Nhap()
        {
            Console.Write("Nhap nhan vien: ");
        }

        public override void Xuat()
        {
            Console.WriteLine("Xuat nhan vien: ");
        }

    }
}
