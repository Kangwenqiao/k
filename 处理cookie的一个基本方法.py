#处理cookie
#登录-》得到cookie-》带着cookie去请求url

#必须把上面操作连起来
#使用session进行，session可以认为是一连串的请求，在这个cookie不会丢失

#会话
import requests
session=requests.session()
data={
    "loginName":"",#用户名
    "password":""#密码
}

#登录
url="https://passport.17k.com/ck/user/login"
resp=session.post(url,data=data)
# print(resp.text)
# print(resp.cookies) #cookie


#post
urlself="https://user.17k.com/ck/author/shelf?page=1&appKey=2406394919"
resp2=session.get(urlself)
print(resp2.json())




#如果知道cookie可以直接获取
import requests
resp=requests.get("https://user.17k.com/ck/author/shelf?page=1&appKey=2406394919",headers={
"Cookie":""
})
print(resp.text)

