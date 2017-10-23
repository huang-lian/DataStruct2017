# 作业： 链表的维护与文件形式的保存
# 题目描述
• 要求
用链表结构的有序表表示某商场家电的库存模型。当有提货或进货时需要对该链表进行维护。每个工作日结束之后，将该链表中的数据以文件形式保存，每日开始营业之前，需将以文件形式保存的数据恢复成链
表结构的有序表。
链表结点的数据域包括家电名称、品牌、单价和数量，以单价的升序体现链表的有序性。程序功能包括：创建表、营业开始（读入文件恢复链表数据）、进货（插入）、提货（更新或删除）、查询信息、更新信息、营业结束（链表数据存入文件）等。

# 开始时间
2017年10月22日07:53:54

# 需求分析

## 实现限制
- 使用链表结构
	- 链式结构而不是游标管理
	- 单链表
- 文件存储和再出读入数据
	- 二进制存储信息 F
	- 保留相关数据即可 T
		- 文件内容不必具有过多的可读性,便于读写即可
			- 无需提示信息
			- 无需格式内容
	- 信息可以再次被读入
		- 读入应当是写入的逆操作
		- 可以设置文件标识确定读入正常- 信息表按照单价升序排序
	- 载入即插入,建立的是有序表,而不是在此基础上排序

## 功能要求
- 库存表的创建  | 初始化信息录入
	- 从0到n的过程
	- 录入完整表信息
	- 其他操作的前提
- 开始营业 | 文件信息恢复
	- 必须存在原始数据即本程序创建的文件才可以进入营业
- 进货 | 新增信息
	- 新增产品
	- 已有产品数量增加
- 提货 | 变更信息或者删
	- 数量减少但是还有
	- 清空
- 查询 | 查询内容? 显示信息?
	- 按照商品的各特征来查询
- 更新信息
	- 商品的任意特征-->如何标识各类商品
		- 品牌和产品名作为标识
	         	任意一项不同即标识不同

		
- 营业结束 | 链表数据存入文件

# 问题结构分析
## 数据层次结构分析
- 库存表1 ( 唯一?, // #if 假定库存表唯一
	- 商品N
		- 名称 | char * ,string
		- 品牌 | char * , string
		- 单价 | float ,double
		- 数量 | size_t 

## 功能逻辑分析
### 整体分析
库存表的建立必须在营业开始营业前.其他操作都建立在营业的基础下,营业只能操作一张表.结束工作后将不可进行任意操作.整体框架逻辑如下

start#
程序开始:检查是否有表
- 否,提示建立
	- 否,退出
	- 是,录入文件名并开始引导
- 有,提示加载(允许多表单可罗列并给出加载选项,单表直接提示与否)
	- 否,退出
	- 是,加载表并开始营业
		- 提货
		- 进货
		- 更新
		- 结束营业,并保存信息
程序结束#end
### 局部分析
1. 程序开始运行分析,环境检查
// #pass
2. 库存表建立引导
3. 营业引导
// #pass
4. 进货提货分析,需要进行查找然后才能操作,找到并定位
	1. 已经存在的货物
	只是数量上的变更,一个变大,一个减少
	2. 不存在的货物
		1. 提货失败
		2. 进货提示是否添加,添加的话补充价格
5.更新信息 需要查找到货物才能进行操作

# 实现分析
menu实现功能的组合,其他各部分只需要能够实现各自的基本功能就好了.

## 库存结构
### 操作
-insert 数据录入:假定获得了合法数据(全部).升序,则表头最小.同类数据合并,矛盾数据舍弃,插入失败.
- 查找 局部数据匹配或者标识匹配
	- 更新数据,或者提货出货需要标识完全匹配,
	- 但是比如的出库时需要输入一个数据后就直接的动态匹配
### 数据对象
- 一个头指针-> 指向了一堆货物的指针

## 商品结构
### 操作
访问信息(修改/显示)
- 按照标识,修改各类信息并给出修改结果
- 给出各部分内容
### 数据对象
即商品N的结构,为了能够更加简单的标识各个数据添加一个唯一ID
id由数量外的其他项确定.