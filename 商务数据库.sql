创建数据库
create database 商务数据库系统
on
(
name=business_data,
filename='D:\开发者\busine.mdf',
SIZE=10,
maxsize=500,
filegrowth=10
)
log on
(
name=business_log,
filename='D:\开发者\busine.ldf',
SIZE=10,
maxsize=500,
filegrowth=5
)


创建相应表
use 商务数据库系统
go
--（1）类别表（类别号，类别名称）
create table 类别表
(
类别号 varchar(10) primary key,
类别名 varchar(10)
);

--（2）商品表（商品编号，商品名称，商品价格，详情信息，商品图片，类别号）
create table 商品表
(
商品编号 varchar(10)primary key,
商品名称 varchar(10), 
商品价格 money,
详情信息 varchar(20),
商品图片 image,
类别号 varchar(10)
FOREIGN KEY(类别号) REFERENCES 类别表(类别号)
)
--（3）会员表（会员编号，会员姓名，会员性别，会员邮箱）
create table 会员表
(
 会员编号 varchar(10)  primary key,                 
 会员姓名 varchar(10),  
 会员性别 char(4),
 会员邮箱 varchar(20),
)
--（4）联系方式表（会员编号，电话，邮编，地址）
CREATE TABLE 联系方式表
(会员编号 varchar(10) primary key,
电话 varchar(20),                 
邮编 varchar(10),  
地址 char(20),
FOREIGN KEY(会员编号) REFERENCES 会员表(会员编号))

--（5）状态表（状态号，状态名）
CREATE TABLE 状态表
( 状态号 char(10)primary key,                 
 状态名 varchar(10));
--（6）厂家表（厂家编号，厂家名称）
CREATE TABLE 厂家表
( 厂家编号 char(10) primary key,                 
 厂家名称 char(10));

--（7）生产表（商品编号，厂家编号，上架时间）
CREATE TABLE 生产表
(
商品编号 varchar(10),
厂家编号 char(10),
上架时间 date,
primary key(商品编号,厂家编号),
FOREIGN KEY(商品编号) REFERENCES 商品表(商品编号),
FOREIGN KEY(厂家编号) REFERENCES 厂家表(厂家编号));

--（8）仓库表（商品编号，库存量）
CREATE TABLE 仓库表
( 商品编号 varchar(10) primary key,
	库存量 int,
	FOREIGN KEY(商品编号) REFERENCES 商品表(商品编号)
);

--（9）订购表（订单编号，商品编号，会员编号，数量，提交时间，状态号）
CREATE TABLE 订购表
(订单编号  varchar(10),
会员编号 varchar(10),
商品编号 varchar(10),
数量 int,
提交时间 date,
状态号 char(10),
primary key(订单编号,会员编号,商品编号,状态号),
FOREIGN KEY(商品编号) REFERENCES 商品表(商品编号),
FOREIGN KEY(会员编号) REFERENCES 会员表(会员编号),
FOREIGN KEY(状态号) REFERENCES 状态表(状态号));


