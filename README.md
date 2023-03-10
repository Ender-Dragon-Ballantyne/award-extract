# AwardExtract

#### 介绍
一个抽奖的程序

#### 软件架构
采用C++编写


#### 使用教程

1.  可采用如DevCpp等程序打开main.cpp
2.  直接编译运行即可

#### 使用说明

1.  抽奖人数：即参与人数，将影响分数的读取
             应存放在与程序同目录的“score.txt”文本文档中
             内部格式为一个名字，换行输入分数;
2.  奖品数量：此为奖品的总类数，而非奖品所准备的份数
             存放在与程序同目录的“award.txt”文本文档中
             内部格式为一个奖品的名称，换行输入准备的份数
3.  随机种子：随机抽奖的依赖，随便输入一个不超过1000000的数即可

#### 注意事项

1. 奖品种类不要超过55
2. 人数不要超过100
3. 目前未添加排序功能
4. 所有存放在“XX.txt”中的名称/数量，请不要出现空格，否则一定会出错

#### 更新历史

-----------------------------v1.1.0---------2023.1.10--------------------

首次提交程序

-----------------------------v1.1.1---------2023.1.11--------------------

1.修复一些bug

2.添加一键快速抽取时显示每人抽取得到个数的功能

3.添加手动抽取时，可用次数为0时的禁止抽取的功能

-----------------------------v1.2.0---------2023.1.13--------------------

添加仅记录奖品的功能

-----------------------------v1.2.1---------2023.1.14--------------------

1.添加程序内查看更新日志的功能

2.添加程序开始时可选打开源代码网址的功能

3.修复已知bug
