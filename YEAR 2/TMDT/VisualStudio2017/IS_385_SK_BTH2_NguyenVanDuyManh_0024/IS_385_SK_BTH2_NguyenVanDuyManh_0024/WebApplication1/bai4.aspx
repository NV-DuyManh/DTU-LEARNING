<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="bai4.aspx.cs" Inherits="WebApplication1.bai4" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Mượn sách</title>
    <style>
        body {
            font-family: 'Segoe UI', sans-serif;
            background-color: #f4f6f9;
            padding: 40px;
        }

        form {
            max-width: 650px;
            margin: auto;
            background-color: #ffffff;
            padding: 25px 30px;
            border-radius: 12px;
            box-shadow: 0 0 15px rgba(0,0,0,0.08);
        }

        h2 {
            text-align: center;
            color: #007acc;
            margin-bottom: 25px;
        }

        .form-group {
            margin-bottom: 18px;
        }

        label {
            font-weight: bold;
            display: block;
            margin-bottom: 6px;
        }

        input[type="text"],
        select {
            width: 100%;
            padding: 9px 12px;
            border: 1px solid #ccc;
            border-radius: 6px;
            transition: border 0.3s, box-shadow 0.3s;
        }

        input[type="text"]:focus,
        select:focus {
            border-color: #007bff;
            box-shadow: 0 0 6px rgba(0, 123, 255, 0.5);
            outline: none;
        }

        .aspNet-Radio {
            display: flex;
            justify-content: flex-start;
            gap: 20px;
            border: 1px solid #ccc;
            padding: 9px 12px;
            border-radius: 6px;
            width: 100%;
            transition: border 0.3s, box-shadow 0.3s;
        }

        .aspNet-Radio input[type="radio"] {
            margin-right: 5px;
        }

        .aspNet-Radio:focus-within {
            border-color: #007bff;
            box-shadow: 0 0 6px rgba(0, 123, 255, 0.5);
        }

        .calendar-group {
            display: flex;
            justify-content: space-between;
            gap: 20px;
            margin-top: 10px;
        }

        .calendar-item {
            flex: 1;
        }

        .calendar-item label {
            margin-bottom: 6px;
            display: block;
            font-weight: bold;
        }

        .calendar-item .aspNet-Calendar {
            border: 1px solid #ccc;
            border-radius: 8px;
            padding: 5px;
            width: 100%;
        }

        .submit-btn {
            text-align: center;
            margin-top: 25px;
        }

        .aspNet-Button {
            padding: 10px 20px;
            background-color: #007acc;
            color: white;
            border: none;
            border-radius: 8px;
            font-size: 16px;
            cursor: pointer;
            transition: background-color 0.3s;
        }

        .aspNet-Button:hover {
            background-color: #005a99;
        }

        /* GridView */
        .styled-gridview {
            width: 100%;
            border-collapse: collapse;
            margin-top: 25px;
        }

        .styled-gridview th,
        .styled-gridview td {
            border: 1px solid #ccc;
            padding: 10px;
            text-align: center;
        }

        .styled-gridview th {
            background-color: #007acc;
            color: white;
        }

        .styled-gridview tr:nth-child(even) {
            background-color: #f2f2f2;
        }

        .styled-gridview tr:hover {
            background-color: #d0eaff;
        }

        .result-label {
            margin-top: 20px;
            color: #28a745;
            font-weight: bold;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <h2>THƯ VIỆN MƯỢN SÁCH</h2>

        <div class="form-group">
            <label for="TextBox1">Tên độc giả:</label>
            <asp:TextBox ID="TextBox1" runat="server" CssClass="aspNet-Textbox" Width="100%" />
        </div>

        <div class="form-group">
            <label for="DropDownList1">Chọn tên sách:</label>
            <asp:DropDownList ID="DropDownList1" runat="server" CssClass="aspNet-Dropdown" Width="100%">
                <asp:ListItem>Lập trình C#</asp:ListItem>
                <asp:ListItem>ASP.NET</asp:ListItem>
                <asp:ListItem>CSDL</asp:ListItem>
                <asp:ListItem>HTML</asp:ListItem>
            </asp:DropDownList>
        </div>

        <div class="form-group">
            <label for="RadioButtonList1">Giới tính:</label>
            <asp:RadioButtonList ID="RadioButtonList1" runat="server" RepeatDirection="Horizontal" CssClass="aspNet-Radio">
                <asp:ListItem Text="Nam" Value="Nam"></asp:ListItem>
                <asp:ListItem Text="Nữ" Value="Nữ"></asp:ListItem>
            </asp:RadioButtonList>
        </div>

        <div class="calendar-group">
            <div class="calendar-item">
                <label for="Calendar1">Ngày mượn:</label>
                <asp:Calendar ID="Calendar1" runat="server" CssClass="aspNet-Calendar" />
            </div>
            <div class="calendar-item">
                <label for="Calendar2">Ngày trả:</label>
                <asp:Calendar ID="Calendar2" runat="server" CssClass="aspNet-Calendar" />
            </div>
        </div>

        <div class="submit-btn">
            <asp:Button ID="Button1" runat="server" Text="XÁC NHẬN MƯỢN" CssClass="aspNet-Button" OnClick="Button1_Click" />
        </div>

        <asp:GridView ID="GridView1" runat="server" CssClass="styled-gridview" />

        &nbsp;&nbsp;&nbsp;&nbsp;

        <asp:Label ID="Label1" runat="server" CssClass="result-label" />
    </form>
</body>
</html>