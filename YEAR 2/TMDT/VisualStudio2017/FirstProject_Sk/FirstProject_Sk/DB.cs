using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace FirstProject_Sk
{
    public class DB
    {
       
        public string StrConn = @"  Data Source = (LocalDB)\MSSQLLocalDB;AttachDbFilename=|Directory|\Test1.mdf;Integrated Security = True";


        // Hàm cho getdata
        public DataTable getData(string sql)
        {
            SqlConnection conn = new SqlConnection(StrConn);
            conn.Open();

            //Tạo ra 1 câu lệnh SQL từ chuỗi SQL được truyền vào
            SqlCommand cmd = new SqlCommand(sql, conn);

            //Giống như 1 cáo cầu nối giữa lệnh sql và database
            SqlDataAdapter ad = new SqlDataAdapter(cmd);

            //Tạo ra biến để lưu trữ dữ liệu
            DataTable data = new DataTable();
            //Thực thi câu lệnh SQL và đưa dữ liệu vào biến data
            ad.Fill(data);

            conn.Close();

            return data;

        }


        //Hàm cho insert, delete ,update
        public int ExcuteNonQuery(string sql)
        {
            SqlConnection conn = new SqlConnection(StrConn);
            conn.Open();
            SqlCommand cmd = new SqlCommand(sql, conn);
            int dem = cmd.ExecuteNonQuery();
            conn.Close();
            return dem;
        }
    }
}