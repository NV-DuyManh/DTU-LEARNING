using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;
namespace DemoCodeFrist
{
    public class KhoaHoc
    {
        [Key]
        public int Id { get; set; }

        [StringLength(20)] // Yêu cầu nvarchar(20)
        [Required]
        public string MaKhoaHoc { get; set; }

        [StringLength(100)] // Yêu cầu nvarchar(100)
        [Required]
        public string TenKhoaHoc { get; set; }

        public int ThoiGianHoc { get; set; } // int
    }
}
