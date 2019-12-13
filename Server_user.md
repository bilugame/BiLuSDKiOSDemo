

# 游戏cp用户真实性验证



## Request

```
线上 get  https://bilu.com/game_cp/v1/verify_user
```



`特别注意：接口请求时一定要在Header里加 Accept: application/json，否则返回结果不是json`

## 公共参数

API相关的公共参数都是通过header发送的 没有传空即可，**Header必须传大写**

- `TIMESTAMP`        时间戳 必须用13位int时间戳   如1568619193372 （1568619193.372）  （**参与sign**)  
- `BILU-UUID`               哔噜用户唯一字符串     （不参与sign)   
- `APP-ID`             应用id     （不参与sign)  
- `SIGN`             签名         （不参与sign)  

## 签名算法

**接口签名的详细步骤如下：**

秘钥appsecret： 每个应用给的秘钥  


如. 

​       时间戳: 1568619193372

​       秘钥appsecret:275b01943f5ec5f7fa85d45ac4855d39 

​	   **签名字符串**=TIMESTAMP+appsecret        

​                          =    "1568619193372275b01943f5ec5f7fa85d45ac4855d39"	

MD5(**签名字符串**)并转为**大写**，得到签名，

​	    结果是： strtoupper(md5("1568619193372275b01943f5ec5f7fa85d45ac4855d39")) 的值

​						`70A51F11B560B9DD96F9F882EBE4092F`






## Response(返回结果)

成功：

```json
{
    "code": 200,
    "status": "ok",
    "payload": {
        "msg":"ok"
    },
    "version": "500bdb5279c24e6297187202808c1bad"
}

```

失败：

```
{
  'status': 'fail',
  'code': 40000,      code非200就是失败
  'message': 'xxx错误'
}
```

####    
