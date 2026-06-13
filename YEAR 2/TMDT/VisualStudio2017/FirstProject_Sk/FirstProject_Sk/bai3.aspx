<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="bai3.aspx.cs" Inherits="FirstProject_Sk.bai3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Nhập họ tên:&nbsp;&nbsp; 
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            <br />
            Loại dịch vụ:&nbsp; 
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem>Khám bệnh</asp:ListItem>
                <asp:ListItem>Tư vấn tài chính</asp:ListItem>
                <asp:ListItem>Tư vấn dụ học</asp:ListItem>
            </asp:DropDownList>
            <br />
            <br />
            Ngày hẹn: 
            <asp:Calendar ID="Calendar1" runat="server"></asp:Calendar>
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="Button1" runat="server" Text="Đặt lịch" />
            <br />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
        </div>
    </form>
</body>
</html>
