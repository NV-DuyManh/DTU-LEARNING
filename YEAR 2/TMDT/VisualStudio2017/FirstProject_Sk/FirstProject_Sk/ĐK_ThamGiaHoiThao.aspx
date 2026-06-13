<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ĐK_ThamGiaHoiThao.aspx.cs" Inherits="FirstProject_Sk.ĐK_ThamGiaHoiThao" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Nhập họ tên: 
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            Chọn giới tính:<asp:RadioButtonList ID="RadioButtonList1" runat="server" Height="16px" Width="219px">
                 <asp:ListItem>Nam</asp:ListItem>
                 <asp:ListItem>Nữ</asp:ListItem>
            </asp:RadioButtonList>
            <br />
            Chọn chủ đề: 
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem>AI</asp:ListItem>
                <asp:ListItem>Blockchain</asp:ListItem>
                <asp:ListItem>IoT</asp:ListItem>
                <asp:ListItem>Big Data</asp:ListItem>
            </asp:DropDownList>
            <asp:Calendar ID="Calendar1" runat="server"></asp:Calendar>
            <asp:Button ID="Button1" runat="server" Text="Đăng kí" OnClick="Button1_Click1" />
            <asp:GridView ID="GridView1" runat="server"></asp:GridView>
        </div>
        <p>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="Label1" runat="server"></asp:Label>
        </p>
        <p>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="Label2" runat="server"></asp:Label>
        </p>
        <p>
&nbsp;&nbsp;&nbsp;
            <asp:Label ID="Label3" runat="server"></asp:Label>
        </p>
    </form>
</body>
</html>
