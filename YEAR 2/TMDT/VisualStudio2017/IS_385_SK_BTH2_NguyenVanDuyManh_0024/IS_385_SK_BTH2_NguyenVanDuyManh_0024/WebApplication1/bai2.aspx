<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="bai2.aspx.cs" Inherits="WebApplication1.bai2" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Đăng ký hội thảo</title>
   <style>
    body {
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        background: linear-gradient(to right, #f0f2f5, #e0f7fa);
        margin: 0;
        padding: 0;
    }

    form {
        max-width: 580px;
        margin: 40px auto;
        background-color: #fff;
        border-radius: 15px;
        box-shadow: 0 0 20px rgba(0, 0, 0, 0.1);
        padding: 30px;
    }

    h2 {
        text-align: center;
        color: #00796B;
        margin-bottom: 25px;
    }

    .form-group {
        margin-bottom: 18px;
    }

    label {
        display: block;
        font-weight: bold;
        margin-bottom: 6px;
        color: #333;
        transition: 0.3s;
    }

    label:hover {
        color: #007bff;
        transform: scale(1.05);
    }

    .form-group input[type="text"],
    .form-group select,
    .aspNetTextBox {
        width: 100%;
        padding: 9px 12px;
        border-radius: 6px;
        border: 1px solid #ccc;
        transition: border-color 0.3s, box-shadow 0.3s;
        font-size: 15px;
    }

    .form-group input[type="text"]:focus,
    .form-group select:focus,
    .aspNetTextBox:focus {
        border-color: #007bff;
        box-shadow: 0 0 6px rgba(0, 123, 255, 0.5);
        outline: none;
    }

    .aspNetRadioButtonList {
        display: flex;
        gap: 20px;
        padding-top: 5px;
    }

    .aspNetRadioButtonList input {
        margin-right: 5px;
    }

    .calendar-container {
        margin-top: 10px;
        border: 1px solid #ccc;
        border-radius: 10px;
        padding: 10px;
        overflow-x: auto;
    }

    .aspNetButton {
        background-color: #00796B;
        color: white;
        padding: 10px 15px;
        border: none;
        border-radius: 8px;
        cursor: pointer;
        transition: background-color 0.3s;
        width: 100%;
        font-size: 16px;
    }

    .aspNetButton:hover {
        background-color: #004d40;
    }

    .result-labels {
        margin-top: 20px;
        padding: 15px;
        background-color: #f1f8e9;
        border: 1px solid #c5e1a5;
        border-radius: 10px;
        color: #33691E;
        font-size: 15px;
    }

    .result-labels p {
        margin: 5px 0;
    }

    .styled-gridview {
        margin-top: 25px;
        width: 100%;
        border-collapse: collapse;
    }

    .styled-gridview th,
    .styled-gridview td {
        border: 1px solid #ccc;
        padding: 10px;
        text-align: center;
    }

    .styled-gridview th {
        background-color: #00796B;
        color: white;
    }

    .styled-gridview tr:nth-child(even) {
        background-color: #f2f2f2;
    }

    .styled-gridview tr:hover {
        background-color: #dcedc8;
    }
</style>

  
</head>
<body>
    <form id="form1" runat="server">
        <h2>ĐĂNG KÝ THAM GIA HỘI THẢO</h2>

        <div class="form-group">
            <label for="TextBox1">Nhập họ tên:</label>
            <asp:TextBox ID="TextBox1" runat="server" CssClass="aspNetTextBox"></asp:TextBox>
        </div>

        <div class="form-group">
            <label>Chọn giới tính:</label>
            <asp:RadioButtonList ID="RadioButtonList1" runat="server" RepeatDirection="Horizontal" CssClass="aspNetRadioButtonList">
                <asp:ListItem>Nam</asp:ListItem>
                <asp:ListItem>Nữ</asp:ListItem>
            </asp:RadioButtonList>
        </div>

        <div class="form-group">
            <label for="DropDownList1">Chọn chủ đề:</label>
            <asp:DropDownList ID="DropDownList1" runat="server" CssClass="aspNetTextBox">
                <asp:ListItem>AI</asp:ListItem>
                <asp:ListItem>Blockchain</asp:ListItem>
                <asp:ListItem>IoT</asp:ListItem>
                <asp:ListItem>Big Data</asp:ListItem>
            </asp:DropDownList>
        </div>

        <div class="form-group calendar-container">
            <asp:ScriptManager ID="ScriptManager1" runat="server"></asp:ScriptManager>
            <asp:UpdatePanel ID="UpdatePanel1" runat="server">
                <ContentTemplate>
                    <label>Chọn ngày:</label>
                    <asp:Calendar ID="Calendar1" runat="server"></asp:Calendar>
                </ContentTemplate>
            </asp:UpdatePanel>
        </div>

        <div class="form-group" style="text-align: center;">
            <asp:Button ID="Button1" runat="server" Text="ĐĂNG KÝ" CssClass="aspNetButton" OnClick="Button1_Click1" />
        </div>

        <asp:GridView ID="GridView1" runat="server" CssClass="styled-gridview"></asp:GridView>

        <div class="result-labels">
            <p><asp:Label ID="Label1" runat="server"></asp:Label></p>
            <p><asp:Label ID="Label2" runat="server"></asp:Label></p>
            <p><asp:Label ID="Label3" runat="server"></asp:Label></p>
        </div>
    </form>
</body>
</html>
