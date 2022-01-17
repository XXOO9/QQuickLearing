
#参考: https://blog.51cto.com/u_9291927/2114179
#     https://zhuanlan.zhihu.com/p/39376945
#     https://blog.csdn.net/nicai_xiaoqinxi/article/details/93661170   Qt君
#     https://blog.csdn.net/yizhou2010/article/details/78272505?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164212615316780357277532%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164212615316780357277532&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-78272505.first_rank_v2_pc_rank_v29&utm_term=Qt+Test&spm=1018.2226.3001.4187

#     https://blog.csdn.net/qq_32312307/category_10587029.html(感觉  这篇比较靠谱)

# QObject 元对象   https://zhuanlan.zhihu.com/p/43598693

#/*


# * 创建一个需要测试的类的对象，然后丢进QTest::qExec里面, Qt会将该类的private slots:里面的所有函数认定为需要测试的函数
# * 但是怎么测试异步的接口呢?
# *
# * 如果要将测试结果信息输出到文件中，则在项目->Run->CommandArgumentLine -> 输入-o fileName.format(例如: -o testRet.txt)
#*/

TEMPLATE = subdirs

SUBDIRS += \
#    CustTestPro \
#    QtNoGuiTest
#    QMLTest
