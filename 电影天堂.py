import requests
import re
#1.定位到2020的必看片
#2.提取子页面的连接地址
#3.请求子页面的链接地址，拿到我们想要的下载地址
url1="https://www.dytt89.com/"
resp=requests.get(url1,verify=False)#去掉安全验证
resp.encoding="gbk"
# print(resp.text)#编码方式是charset=gb2312
obj1=re.compile(r"2022必看热片.*?<ul>(?P<ino1>.*?)</ul>",re.S)
obj2=re.compile(r"<a href='(?P<href>.*?)'",re.S)
obj3=re.compile(r'◎片　　名(?P<name>.*?)<br />.*? <td '
                r'style="WORD-WRAP: break-word" bgcolor="#fdfddf"><a href="(?P<download>.*?)">magnet',re.S)
result1=obj1.finditer(resp.text)

child_href_list = []
for it in result1:

    ul=it.group('ino1')
    # print(ul)

    result2=obj2.finditer(ul)
    for itt in result2:
        #拼接子页面的url地址：域名+子页面地址
        child_href=url1+itt.group('href').strip("/")
        child_href_list.append(child_href)#把子页面连接保存起来

#提取子页面内容
for href in child_href_list:
    child_respon=requests.get(href,verify=False)
    child_respon.encoding='gbk'
    # print(child_respon.text)
    result3=obj3.search(child_respon.text)
    print(result3.group("name"))
    print(result3.group("download"))



