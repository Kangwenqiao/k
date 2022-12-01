#原理 通过第三方的一个机器发送请求
#代理ip和port通过查询获取
import  requests

#60.211.218.78:53281
proxies={
    "https":"https://60.211.218.78:53281"
}
resp=requests.get("http://www.baidu.com",proxies=proxies)
resp.encoding="utf-8"
print(resp.text)
