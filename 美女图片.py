import sys
import io
import time
sys.stdout = io.TextIOWrapper(sys.stdout.buffer,encoding='gb18030')
import requests
from bs4 import BeautifulSoup
url="https://www.umei.cc/meinvtupian/xingganmeinv/"
header={
    "user-agent":"Mozilla/5.0 (Windows NT 6.2; WOW64; rv:21.0) Gecko/20100101 Firefox/21.0"
}
resp=requests.get(url=url,headers=header)
resp.encoding='utf-8'
# print(resp.text)
main_page=BeautifulSoup(resp.text,"html.parser")
alist=main_page.find("div",class_="item_list infinite_scroll").find_all("a")
# print(alist)
for a in alist:
    href=a.get('href')
    print(href)
    href="https://www.umei.cc/"+href
    # print(href)
    child_page_resp=requests.get(url=href,headers=header)
    child_page_resp.encoding='utf-8'
    child_page_text=child_page_resp.text
    # print(child_page_text)
    child_page=BeautifulSoup(child_page_text,"html.parser")
    d=child_page.find("div",class_='big-pic')
    # print(d)
    img=d.find("img")
    # print(img)
    src=img.get("src")
    print(src)


    #download
    img_resp=requests.get(src)
    # img_resp.content
    img_name=src.split("/")[-1]
    with open("img/"+img_name,mode="wb")as f:
        f.write(img_resp.content)

    print("over",img_name)
    time.sleep(1)
print("finish")
