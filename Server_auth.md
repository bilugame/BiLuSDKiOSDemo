

# 游戏cp内购验证



## Request

```
线上 post  https://bilu.com/game_cp/v1/verify_apple_receipt
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



##### POST Parameters：

| 参数          | 类型   | 描述                                                | 是否必须 |
| ------------- | ------ | --------------------------------------------------- | -------- |
| sandbox       | Int    | 0正式环境1 沙盒环境                                 | 是       |
| apple_receipt | String | apple给客户端的验证参数 ,base64encode,并urlencode下,把+替换为%2B | 是       |



## Response(返回结果)

成功：

```json
{
    "code": 200,
    "status": "ok",
    "payload": {
        "status": 0,  
        "msg": "购买成功",
        "data": [
            {
                "quantity": "1",
                "product_id": "goods1",
                "transaction_id": "1000000589235976",
                "original_transaction_id": "1000000589235976",
                "purchase_date": "2019-11-07 07:27:23 Etc/GMT",
                "purchase_date_ms": "1573111643000",
                "purchase_date_pst": "2019-11-06 23:27:23 America/Los_Angeles",
                "original_purchase_date": "2019-11-07 07:27:23 Etc/GMT",
                "original_purchase_date_ms": "1573111643000",
                "original_purchase_date_pst": "2019-11-06 23:27:23 America/Los_Angeles",
                "is_trial_period": "false"
            }
        ]
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



##### 返回数据说明

`status`:	

-  -1    请求appstore 失败请重试

- 21000 App Store不能读取你提供的JSON对象	

- 21002 receipt-data域的数据有问题

- 21003 receipt无法通过验证
- 21004 提供的shared secret不匹配你账号中的shared secret
- 21005 receipt服务器当前不可用
- 21006 receipt合法，但是订阅已过期。服务器接收到这个状态码时，receipt数据仍然会解码并一起发送
- 21007 receipt是Sandbox receipt，但却发送至生产系统的验证服务
- 21008 receipt是生产receipt，但却发送至Sandbox环境的验证服务