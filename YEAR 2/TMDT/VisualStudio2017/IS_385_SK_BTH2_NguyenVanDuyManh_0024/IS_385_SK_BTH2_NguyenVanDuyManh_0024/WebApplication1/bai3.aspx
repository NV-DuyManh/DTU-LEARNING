<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="bai3.aspx.cs" Inherits="WebApplication1.bai3" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Giỏ hàng</title>
    <style>
        body {
            font-family: Arial;
            background: #f2f2f2;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }

        .container {
            background: white;
            padding: 30px 40px;
            border-radius: 12px;
            box-shadow: 0 4px 10px rgba(0, 0, 0, 0.2);
            width: 450px;
        }

        h2 {
            text-align: center;
            color: #00796B;
            margin-bottom: 25px;
        }

        label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
            color: #444;
        }

        .form-group {
            margin-bottom: 20px;
        }

        input[type=text], input[type=number], .aspNetTextBox {
            width: 100%;
            padding: 10px;
            border: 1px solid #ccc;
            border-radius: 8px;
            outline: none;
            transition: 0.3s;
        }

            input[type=text]:focus, input[type=number]:focus, .aspNetTextBox:focus {
                border-color: #00796B;
                box-shadow: 0 0 5px #00796B;
            }

        .btn {
            width: 100%;
            padding: 12px;
            background-color: #00796B;
            color: white;
            border: none;
            border-radius: 8px;
            font-size: 16px;
            cursor: pointer;
            transition: background-color 0.3s;
        }

            .btn:hover {
                background-color: #005F56;
            }

        .result {
            margin-top: 15px;
            color: #D84315;
            font-weight: bold;
            text-align: center;
        }

        .gridview-style {
            margin-top: 20px;
        }

        .styled-grid {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }

            .styled-grid th, .styled-grid td {
                border: 1px solid #ccc;
                padding: 12px 10px;
                text-align: center;
            }

            .styled-grid th {
                background-color: #007BFF;
                color: white;
            }

            .styled-grid tr:nth-child(even) {
                background-color: #f9f9f9;
            }

            .styled-grid tr:hover {
                background-color: #e6f2ff;
                cursor: pointer;
            }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div class="container">
            <h2>BÁN HÀNG ĐƠN GIẢN</h2>

            <div class="form-group">
                <label for="TextBox1">Tên sản phẩm</label>
                <asp:TextBox ID="TextBox1" runat="server" CssClass="aspNetTextBox" />
            </div>

            <div class="form-group">
                <label for="TextBox2">Đơn giá</label>
                <asp:TextBox ID="TextBox2" runat="server" CssClass="aspNetTextBox" />
            </div>

            <div class="form-group">
                <label for="TextBox3">Số lượng</label>
                <asp:TextBox ID="TextBox3" runat="server" CssClass="aspNetTextBox" />
            </div>

            <asp:Button ID="Button1" runat="server" Text="THÊM VÀO GIỎ" CssClass="btn" OnClick="Button1_Click" />

            <div class="gridview-style">
                <asp:GridView ID="GridView1" runat="server" CssClass="styled-grid"></asp:GridView>

                <br />

            </div>

            &nbsp;&nbsp;&nbsp;

            <asp:Label ID="Label1" runat="server" CssClass="result" />
        </div>
    </form>
</body>
</html>
