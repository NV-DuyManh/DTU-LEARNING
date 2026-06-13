<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="bai4.aspx.cs" Inherits="FirstProject_Sk.bai4" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Nhập tên khách hàng: 
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            <br />
            Chọn loại phòng:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem>Phòng đơn</asp:ListItem>
                <asp:ListItem>Phòng đôi</asp:ListItem>
                <asp:ListItem>Phòng VIP</asp:ListItem>
            </asp:DropDownList>
            <br />
            <br />
            Ngày nhận phòng: 
            <asp:Calendar ID="Calendar1" runat="server"></asp:Calendar>
            <br />
            Ngày trả phòng: 
            <asp:Calendar ID="Calendar2" runat="server"></asp:Calendar>
            <br />
            <asp:Button ID="Button1" runat="server" Text="Xác nhận đặt phòng" />
            <br />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>

        </div>
    </form>
</body>
</html>
