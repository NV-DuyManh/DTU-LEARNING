<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Test.aspx.cs" Inherits="FirstProject_Sk.Test" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    </head>
<body>
    <form id="form1" runat="server">
        <div>
            <table style="width: 100%;">
                <tr>
                    <td style="width: 30%; class="auto-style1" >
                        <asp:Calendar ID="Calendar1" runat="server"></asp:Calendar>
                        <asp:Image ID="Image1" runat="server" ImageUrl="https://www.pikpng.com/pngl/b/128-1289529_vector-illustration-of-harvested-coffee-beans-in-bowl.png" Width="31%" Height="174px" />
                    </td>
                    <td style="width: 70%; vertical-align: top">Mã sinh viên
                        <br />
                        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                        <br />
                        Họ và tên
                        <br />
                        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                        <br />
                        Ngày sinh
                        <br />
                        <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                        <br />
                        Giới tính
                        <br />
                       
                        <asp:RadioButtonList ID="RadioButtonList1" runat="server" Height="16px" Width="219px">
                            <asp:ListItem>Nam</asp:ListItem>
                            <asp:ListItem>Nữ</asp:ListItem>
                            <asp:ListItem>Khác</asp:ListItem>
                        </asp:RadioButtonList>
                       
                        Quốc tịch<br />
                        &nbsp;<asp:DropDownList ID="DropDownList1" runat="server" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
                            <asp:ListItem>Việt Nam</asp:ListItem>
                            <asp:ListItem>Hàn Quốc</asp:ListItem>
                            <asp:ListItem>Trung Quốc</asp:ListItem>
                            <asp:ListItem>Ấn Độ</asp:ListItem>
                        </asp:DropDownList>
                        <br />
                        Sở thích
                     <asp:CheckBox ID="CheckBox1" runat="server" Text="Đọc sách" />
                        <asp:CheckBox ID="CheckBox2" runat="server" Text="Bóng đá" />
                        <asp:CheckBox ID="CheckBox3" runat="server" Text="Bơi" />
                        <asp:CheckBoxList ID="CheckBoxList1" runat="server">
                            <asp:ListItem>1</asp:ListItem>
                            <asp:ListItem>3</asp:ListItem>
                            <asp:ListItem>2</asp:ListItem>
                            <asp:ListItem>4</asp:ListItem>
                        </asp:CheckBoxList>
                        <br />
                        <asp:Button ID="Button1" runat="server" Text="Button" />

                    </td>
                </tr>

            </table>

        </div>
    </form>

</body>
</html>
