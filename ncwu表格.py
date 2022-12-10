import requests
import time
import re
import csv
headers={
    "user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                 "AppleWebKit/537.36 (KHTML, like Gecko) Chrome"
                 "/98.0.4758.139 Safari/537.36",
    "Referer": "https://www2.ncwu.edu.cn/jiaowu/bgxz/1.htm"
}
proxies={
    "https":"https://221.226.75.86:55443"
}

for n in range (0,6,1):
    url=f"https://www2.ncwu.edu.cn/jiaowu/bgxz/{n}.htm"
    # resp=requests.get(url,headers=headers,proxies=proxies)
    resp=requests.get(url,headers=headers)
    resp.encoding='utf-8-sig'
    # print(resp.text)
    page=resp.text
    # print(page)
    obj=re.compile(r'<a href="(?P<heml_>.*?)"><em>(?P<name>.*?)</em>.*?'
                   r'<span>(?P<time>.*?)</span>',re.S)
    result = obj.finditer(page)
    f = open(f"data{n}.csv", mode="w")
    csvwriter = csv.writer(f)
    time.sleep(1)
    for it in result:
        dic = it.groupdict()
        print(dic.values())
        # csvwriter.writerow(dic.values())

