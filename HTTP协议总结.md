## 1.HTTP协议概述：

  1.HTTP（HyperText Transfer Protocol，超文本传输协 ）的协议
  2.HTTP是无连接， 无状态， 工作在应用层的协议
        无连接理解为：http协议本身是没有维护连接信息的， http的数据会交给网络协议栈传输层的TCP协议， 而TCP是面向连接的。 大家注意区别。
        无状态：HTTP 协议自身不对请求和响应之间的通信状态进行保存。也就是说在 HTTP 这个级别，协议对于发送过的请求或响应都不做持久化处理。

## 2.HTTP对应的URL解释

![image-20210603141542475](/Users/ann/Library/Application Support/typora-user-images/image-20210603141542475.png)

> A.使用 http: 或 https: 等协议方案名获取访问资源时要指定协议类型。不 区分字母大小写，最后附一个冒号（:）
>
> b.登录信息（认证） 指定用户名和密码作为从服务器端获取资源时必要的登录信息（身份 认证）。此项是可选项。
>
> c.服务器地址 ，必须指定待访问的服务器地址。地址可以是类似 hackr.jp 这种 DNS 可解析的名称，或是 192.168.1.1 这类 IPv4 地址 名，还可以是 [0:0:0:0:0:0:0:1] 这样用方括号括起来的 IPv6 地址名。
>
> d. 服务器端口号 指定服务器连接的网络端口号。此项也是可选项，若用户省略则自动 使用默认端口号。 
>
> e. 带层次的文件路径 指定服务器上的文件路径来定位特指的资源。。 
>
> f. 查询字符串针对已指定的文件路径内的资源，可以使用查询字符串传入任意参 数。此项可选。 
>
> g.片段标识符 使用片段标识符通常可标记出已获取资源中的子资源（文档内的某个 位置）。该项也为可选 项。

## 3.HTTP协议的数据流：

![image-20210603140316120](/Users/ann/Library/Application Support/typora-user-images/image-20210603140316120.png)

## 4.HTTP协议格式：

### 请求：

HTTP 协议规定，请求从客户端发出，最后服务器端响应该请求并返回。换句话说，肯定是先从客户端开始建立通信的，服务器端在没有 

接收到请求之前不会发送响应。

![image-20210603140521345](/Users/ann/Library/Application Support/typora-user-images/image-20210603140521345.png)

#### 综述：

请求首行：方法 URI 协议版本

请求体：key:value的属性行

空行

正文

### 响应：

![image-20210603140606039](/Users/ann/Library/Application Support/typora-user-images/image-20210603140606039.png)

#### 综述：

响应首行：协议版本 状态码 状态码解释

响应体：key:value的属性行

空行

正文

### 图解：

![image-20210603140928929](/Users/ann/Library/Application Support/typora-user-images/image-20210603140928929.png)

## 5.HTTP协议版本：

> HTTP/0.9 HTTP 于 1990 年问世。那时的 HTTP 并没有作为正式的标准被建立。 现在的 HTTP 其实含有 HTTP1.0 之前版本的意思，因此被称为 HTTP/0.9。
>
> HTTP/1.0 HTTP 正式作为标准被公布是在 1996 年的 5 月，版本被命名为 HTTP/1.0，并记载于 RFC1945。虽说是初期标准，但该协议标准至今 仍被广泛使用在服务器端。
>
> HTTP/1.1 1997 年 1 月公布的 HTTP/1.1 是目前主流的 HTTP 协议版本。当初的 标准是 RFC2068，之后发布的修订版 RFC2616 就是当前的最新版 本。
>
> HTTP/2.0 新 一代 HTTP/2.0 正在制订中，但要达到较高的使用覆盖率，仍需假以 时日。

# 6.HTTP请求方法：

### 6.1 **GET** ：获取资源 

GET 方法用来请求访问已被 URI 识别的资源。指定的资源经服务器端解析后返回响应内容。也就是说，如果请求的资源是文本，那就保 持原样返回；

![image-20210603142635932](/Users/ann/Library/Application Support/typora-user-images/image-20210603142635932.png)



### 6.2 **POST**：传输实体主体 

虽然用 GET 方法也可以传输实体的主体，但一般不用 GET 方法进行传输，而是用 POST 方法。虽说 POST 的功能与 GET 很相似，但 POST 的主要目的并不是获取响应的主体内容。

![image-20210603142719169](/Users/ann/Library/Application Support/typora-user-images/image-20210603142719169.png)

### 6.3 **PUT**：传输文件 

PUT 方法用来传输文件。就像 FTP 协议的文件上传一样，要求在请求报文的主体中包含文件内容，然后保存到请求 URI 指定的位置。 但是，鉴于 HTTP/1.1 的 PUT 方法自身不带验证机制，任何人都可以上传文件 , 存在安全性问题，因此一般的 Web 网站不使用该方法。

![image-20210603142811377](/Users/ann/Library/Application Support/typora-user-images/image-20210603142811377.png)

### 6.4 **HEAD**：获得报文首部

HEAD 方法和 GET 方法一样，只是不返回报文主体部分。用于确认资源的有效性。 虽说和 **GET** 一样，但不返回报文主体

![image-20210603142903546](/Users/ann/Library/Application Support/typora-user-images/image-20210603142903546.png)

### 6.5 **DELETE**：删除文件

DELETE 方法用来删除文件，是与 PUT 相反的方法。但是，HTTP/1.1 的 DELETE 方法本身和 PUT 方法一样不带验证机制，所以一般的 Web 网站也不使用 DELETE 方法。

![image-20210603143043383](/Users/ann/Library/Application Support/typora-user-images/image-20210603143043383.png)

### 6.6 **OPTIONS**：询问支持的方法

OPTIONS 方法用来查询针对请求 URI 指定的资源支持的方法。 

![image-20210603143114070](/Users/ann/Library/Application Support/typora-user-images/image-20210603143114070.png)

![image-20210603143149958](/Users/ann/Library/Application Support/typora-user-images/image-20210603143149958.png)

## 7.HTTP状态码&状态码解释

### 7.1 状态码类别：

![image-20210603145243088](/Users/ann/Library/Application Support/typora-user-images/image-20210603145243088.png)

### 7.2 **2XX** 成功 

2XX 的响应结果表明请求被正常处理了。 

#### 7.3 **200 OK** 

表示从客户端发来的请求在服务器端被正常处理了。 

![image-20210603145503133](/Users/ann/Library/Application Support/typora-user-images/image-20210603145503133.png)

#### **204 No Content** 

![image-20210603145612932](/Users/ann/Library/Application Support/typora-user-images/image-20210603145612932.png)

**206 Partial Content** 

![image-20210603145655696](/Users/ann/Library/Application Support/typora-user-images/image-20210603145655696.png)

### 7.4 **3XX** 重定向 

#### **301 Moved Permanently** 

永久性重定向。

![image-20210603145733087](/Users/ann/Library/Application Support/typora-user-images/image-20210603145733087.png)

#### **302 Found** 

临时性重定向

![image-20210603145747766](/Users/ann/Library/Application Support/typora-user-images/image-20210603145747766.png)

####  **303 See Other**

![image-20210603145842959](/Users/ann/Library/Application Support/typora-user-images/image-20210603145842959.png)

#### **307 Temporary Redirect** 

临时重定向。

![image-20210603145747766](/Users/ann/Library/Application Support/typora-user-images/image-20210603145747766.png)



### 7.5 **4XX** 客户端错误

#### **400 Bad Request** 

![image-20210603150110901](/Users/ann/Library/Application Support/typora-user-images/image-20210603150110901.png)

####  **401 Unauthorized** 

认证失败

![image-20210603150203580](/Users/ann/Library/Application Support/typora-user-images/image-20210603150203580.png)



#### **403 Forbidden** 

![image-20210603150235487](/Users/ann/Library/Application Support/typora-user-images/image-20210603150235487.png)

#### **404 Not Found** 

![image-20210603150257859](/Users/ann/Library/Application Support/typora-user-images/image-20210603150257859.png)

### 7.6 **5XX** 服务器错误

#### **500 Internal Server Error** 

![image-20210603150344545](/Users/ann/Library/Application Support/typora-user-images/image-20210603150344545.png)

该状态码表明服务器端在执行请求时发生了错误。也有可能是 Web应用存在的 bug 或某些临时的故障。

#### **503 Service Unavailable**

![image-20210603150420634](/Users/ann/Library/Application Support/typora-user-images/image-20210603150420634.png)

















