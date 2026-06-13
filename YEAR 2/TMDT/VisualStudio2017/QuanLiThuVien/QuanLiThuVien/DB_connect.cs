using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;


namespace QuanLiThuVien
{
    public class DB_connect
    {
        public string StrConn = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\ThuVien.mdf;Integrated Security=True";
        //getdata
        public DataTable getData(string sql)
        {
            using (SqlConnection conn = new SqlConnection(StrConn))
            {
                SqlCommand cmd = new SqlCommand(sql, conn);
                SqlDataAdapter ad = new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                ad.Fill(dt);
                return dt;
            }
        }


        //delete, update, insert
        public int ExecuteNonQuery(string sql)
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
   
