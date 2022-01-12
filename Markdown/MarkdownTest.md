<!-- Title learing -->
<!-- using '#' to define title class -->
<!-- 第一级标题下好像会自动加一根线 -->
# This is top title
##  This is sub title
### this is third class title  
***
***


<!-- 段落格式 -->
# starting to learing the Paragraph format
<!-- 空行 -->
<!-- 在行末尾添加两个空格后回车 -->
## this is first line
## this is second line

<!-- 分割线 -->
## scale line text
----------------------

## 或者
****************************

<!-- 删除线 -->
## ~~删除线~~

<!-- 下划线 -->
<u>下划线1</u>

<!-- 脚注 -->
[^脚注]:这个是脚注
看看脚注[^脚注]


<!-- 字体 -->
<!-- _斜体_ -->
_这个是斜体_  

<!-- 粗体 -->
__这个是粗体__

<!-- 粗斜体 -->
___这个是粗斜体___
***

# 列表1
* 第一项
* 第二项

# 列表2
* 第一项
   - 第一小项
     - 第一小小项
       - 第一小小小项
* 第二项
   - 第二小项

# 列表3 - 列表中使用区域块
* 第一项
* >第一区域块
* >>第一区域的第一区域块

***


# 区域块
> 第一层
> * 第一层的第一层
>   - 第一层的第一小层
>> 第二层
>>> 第三层
***
# 代码块
```C++
using namespace std;
cout << "this is code area..."  << endl;
```

# Markdownlian链接
<!-- [链接的名称](链接的地址) -->

[百度](www.baidu.com)

或者<www.baidu.com>

## 高级链接
将链接设置成一个变量，变量的赋值在文档末尾进行

这个链接用1作为变量[网址][1]

[1]:www.baidu.com
***

# Markdown图片


