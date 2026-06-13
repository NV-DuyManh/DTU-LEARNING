using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace WebApplication1
{
    public class DB_Connect
    {
        public String StrConn = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\KHACHHANG.mdf;Integrated Security=True";

        public DataTable getData(String sql)
        {
            using (SqlConnection conn = new SqlConnection(StrConn))
            {
                SqlCommand cmd = new SqlCommand(sql, conn);
                SqlDataAdapter ad= new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                ad.Fill(dt); 
                return dt;
               }
        }
        public int ExecuteNonQuery(String sql)
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