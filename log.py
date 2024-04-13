import requests
from bs4 import BeautifulSoup
# 会话信息
session_info = {
    "name": "SESSION",  # 添加 cookie 的名称
    "path": "/",
    "value": "11065-e5698b97-aaad-43b5-8c6a-1ec2d906bfd4"
}

# 创建一个会话对象
session = requests.Session()

# 将会话信息转换为 Cookie 格式，并添加到会话对象中
cookie = requests.cookies.create_cookie(**session_info)
session.cookies.set_cookie(cookie)

# 示例：使用带有会话信息的会话对象发送 GET 请求
url = 'https://oj.qd.sdu.edu.cn/v2/problemSet/55/problem/0/0'
response = session.get(url)

# 处理响应
if response.status_code == 200:
    print("请求成功！")
    # 处理响应内容
    print(response.text)
    soup=BeautifulSoup(response.content,'html.parser')
    with open("out.html",'w')as f:
        f.write(soup.prettify())
else:
    print("请求失败:", response.status_code)
