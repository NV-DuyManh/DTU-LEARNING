<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.Master" AutoEventWireup="true" CodeBehind="Chitiet.aspx.cs" Inherits="WebApplication1.Chitiet" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <style type="text/css">
        .auto-style1 {
            width: 50%;
        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h3>CHI TIẾT SÁCH</h3>
    <div>
        <asp:Repeater ID="Repeater1" runat="server">
            <ItemTemplate>
                <table style="width: 100%;">
                    <tr>
                        <td style="width:70%">
                            <img style ="width:85%" src="<%# Eval("HINHANH") %>" />
                        </td>
                        <td>
                            <p><%# Eval("TENSACH") %></p>
                            <p>Tác giả: <%# Eval("TACGIA") %></p>
                            <p>Đơn giá: <%# Eval("DONGIA") %></p>


                        </td>

                    </tr>

                </table>
            </ItemTemplate>
        </asp:Repeater>
    </div>
</asp:Content>
