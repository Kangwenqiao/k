import requests
import csv
import re
url = "http://www.xinfadi.com.cn/getPriceData.html"
a=int(input("enter the web start page:"))
b=int(input("enter the web end page:"))
for i in range(a,b+1,1):
    data={
     "limit":"",
     "current":f"{i}",
     "pubDateStartTime": "",
     "pubDateEndTime":"",
     "prodPcatid":"",
     "prodCatid":"",
     "prodName":""
    }
    header = {
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit"
                      "/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 S"
                      "afari/537.36"
    }#伪装成chrom浏览器

    resp=requests.post(url=url,headers=header,data=data)
    page=resp.text
    print(page)
    obj=re.compile(r'"id":(?P<id>.*?),"prodName":"(?P<prodName>.*?)","prodCatid":.*?,"prodCat":"(?P<prodCat>.*?)",'
                   r'"prodPcatid":.*?,"lowPrice":"(?P<lowPrice>.*?)","highPrice":"(?P<highPrice>.*?)",'
                   r'"avgPrice":"(?P<avgPrice>.*?)",.*?,"specInfo":"(?P<specInfo>.*?)","unitInfo":"(?P<unitInfo>.*?)",'
                   r'.*?}',re.S)

    result=obj.finditer(page)
    f=open(f"data{i}.csv",mode="w")
    csvwriter=csv.writer(f)
    for it in result:
        dic=it.groupdict()
        csvwriter.writerow(dic.values())


