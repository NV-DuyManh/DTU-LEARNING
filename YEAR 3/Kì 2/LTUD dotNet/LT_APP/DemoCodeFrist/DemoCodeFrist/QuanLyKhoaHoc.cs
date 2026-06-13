using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;
namespace DemoCodeFrist
{
    public class QuanLyKhoaHoc : DbContext
    {
        // Tạo bảng tên là KhoaHocs trong Database
        public DbSet<KhoaHoc> KhoaHocs { get; set; }

        // Lưu ý: "name=ChuoiKetNoiKhoaHoc" phải khớp với file App.config ở Bước 3
        public QuanLyKhoaHoc() : base("name=ChuoiKetNoiKhoaHoc")
        {
        }
    }
}
