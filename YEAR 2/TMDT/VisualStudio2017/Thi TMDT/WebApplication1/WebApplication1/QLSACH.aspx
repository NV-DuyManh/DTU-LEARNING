<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.Master" AutoEventWireup="true" CodeBehind="QLSACH.aspx.cs" Inherits="WebApplication1.QLSACH" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h3>CSDL SÁCH</h3>
    <div style="display: flex; flex-wrap:wrap;justify-content:center">
        <asp:Repeater ID="Repeater1" runat="server">
            <ItemTemplate>
                <div style="width:45%; border:1px solid; text-align:center;">
                   <a href="Chitiet.aspx?mal=<%# Eval("MASACH") %>">
                     <img style="width:80%; height:auto" src="<%# Eval("HINHANH") %>" />
                    <p><%# Eval("TENSACH") %></p>
                     <p> Tác giả: <%# Eval("TACGIA") %></p>
                     <p> Đơn giá: <%# Eval("DONGIA") %></p>
                   </a>
                </div>
            </ItemTemplate>
        </asp:Repeater>
    </div>
</asp:Content>
