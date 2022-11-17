import requests
import re
import csv #大多数以逗号分隔
header={"user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.139 Safari/537.36"}

for n in range(0, 275, 25):
    url=f"https://movie.douban.com/top250?start={n}"
    resp=requests.get(url,headers=header)
    i=n/25
    page_content=resp.text
#解析数据
    obj=re.compile(r'<li>.*?<div class="item">.*?<span class="title">(?P<name>.*?)'
               r'</span>.*?<p class="">.*?<br>(?P<year>.*?)&nbsp.*?'
               r'<span class="rating_num" property="v:average">(?P<score>.*?)</span>'
               r'.*?<span>(?P<communit>.*?)</span>',re.S)

    result=obj.finditer(page_content)
    f=open(f"data{i}.csv",mode="w")
    csvwriter=csv.writer(f)
    for it in result:
     # print(it.group("name"))
     # print(it.group("score"))
     # print(it.group("year").strip())
     # print(it.group("communit"))
     # print()
      dic=it.groupdict()
      dic['year']=dic['year'].strip()
      csvwriter.writerow(dic.values())
f.close()
print("over!")


