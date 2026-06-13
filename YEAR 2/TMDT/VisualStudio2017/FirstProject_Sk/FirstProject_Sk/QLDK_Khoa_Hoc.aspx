<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="QLDK_Khoa_Hoc.aspx.cs" Inherits="FirstProject_Sk.QLDK_Khoa_Hoc" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Nhập họ tên sinh viên:&nbsp; 
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            <br />
            Chọn tên môn học:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem>Toán</asp:ListItem>
                <asp:ListItem>Lí</asp:ListItem>
                <asp:ListItem>Hoá</asp:ListItem>
                <asp:ListItem>Tin học</asp:ListItem>
            </asp:DropDownList>
            <br />
            <br />
            Nhập học phí:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
            <br />
            <br />
            <br />
            <asp:Button ID="Button1" runat="server" Text="Thêm vào danh sách" OnClick="Button1_Click" />
            <br />
            <br />
            <asp:Repeater ID="Repeater1" runat="server">
                <ItemTemplate>
                    <p>=========</p>
                    <p><%# Eval("HoVaTen") %></p>
                    <p><%# Eval("MonHoc") %></p>
                    <p><%# Eval("HocPhi") %></p>
                </ItemTemplate>
            </asp:Repeater>
            
            <br />
            <asp:Label ID="Label1" runat="server"></asp:Label>
        </div>
    </form>
</body>
</html>
