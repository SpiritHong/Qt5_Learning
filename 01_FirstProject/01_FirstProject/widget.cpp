#include "widget.h"
#include <QPushButton>  //按钮控件的头文件

//命名规范
//类名 首字母大写，单词和单词之间首字母大写
//函数名 变量名称 首字母小写，单词和单词之间首字母大写

//快捷键
//注释  Ctrl+/
//运行  Ctrl + r
//编译  Ctrl + b
//字体缩放 Ctrl + 鼠标滚轮
//查找  Ctrl + f
//整行移动 Ctrl + Shift + 上箭头/下箭头
//帮助文档 F1
//自动对齐 Ctrl + i
//同名之间的.h和.cpp切换  F4


//帮助文档  第一种方式 F1   第二种方式 左侧按钮  第三种方式 单独打开Assistant

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton * btn = new QPushButton;
    //btn->show();//show以顶层方式弹出窗口控件
    //让btn对象 依赖在myWidget窗口中
    btn->setParent(this);
    //显示文本
    btn->setText("第一个按钮");

    //创建第二个按钮，按照控件的大小创建窗口
    QPushButton * btn2 = new QPushButton("第二个按钮",this);
    //移动btn2按钮
    btn2->move(100,100);

    // 重置窗口
    resize(600,400);

    //设置固定窗口大小
    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("窗口案例");

    QPushButton *quitBtn = new QPushButton("关闭窗口",this);
    connect(quitBtn,&QPushButton::clicked,this,&Widget::close);
}

Widget::~Widget()
{
}

