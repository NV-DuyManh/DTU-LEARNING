<%@ Page Title="" Language="C#" MasterPageFile="~/Master.Master" AutoEventWireup="true" CodeBehind="Home.aspx.cs" Inherits="QuanLiThuVien.Home" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

   <p>SÁCH</p>
   <div style ="display: flex; width:100%">
        <asp:Repeater ID="Repeater1" runat="server">
        <ItemTemplate>
           <div style="width: 50%; text-align:center;border:1px solid">
            <img style="width:50%" src="<%# Eval("hinh_anh") %>" />
            <p><%# Eval("ten_sach") %> </p>
             <p><%# Eval("tac_gia") %> </p>
        
           </div>
        </ItemTemplate>
    </asp:Repeater>
   </div>
</asp:Content>
    