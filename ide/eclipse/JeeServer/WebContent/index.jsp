<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
String aStr = request.getParameter("a");
String bStr = request.getParameter("b");

out.write("a="+aStr+",b="+bStr);

%>