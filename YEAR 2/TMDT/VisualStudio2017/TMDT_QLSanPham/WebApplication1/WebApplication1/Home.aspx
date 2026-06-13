<%@ Page Title="" Language="C#" MasterPageFile="~/Master.Master" AutoEventWireup="true" CodeBehind="Home.aspx.cs" Inherits="WebApplication1.Home" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <p>DANH SÁCH SẢN PHẨM</p>
    <div style="display: flex; width: 100%">
        <asp:Repeater ID="Repeater1" runat="server">
            <ItemTemplate>
                <div style="width: 50%; text-align: center; border: 1px solid">
                    <img style="width: 100px" src='<%# Eval("HinhAnh") %>' />
                    <p><%# Eval("TenSanPham") %> </p>
                    <p><%# Eval("GiaSanPham") %> </p>
                    <img  src="img/1.png" />
                </div>
            </ItemTemplate>
        </asp:Repeater>
    </div>
    
</asp:Content>
