```java
public interface Servlet {
    void init(ServletConfig var1) throws ServletException;

    ServletConfig getServletConfig();

    void service(ServletRequest var1, ServletResponse var2) throws ServletException, IOException;

    String getServletInfo();

    void destroy();
}
```

@方法

```java
public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException;//当浏览器请求的时候就会调用get方法
public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException;//通过表单使用 POST 方法： 当 HTML 表单的 method 属性设置为 POST 时，提交表单会触发 POST 请求。服务器会调用相应的 doPost() 方法来处理表单提交。
```

