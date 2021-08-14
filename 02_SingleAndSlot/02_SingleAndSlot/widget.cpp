#include "widget.h"
#include "ui_widget.h"
#include "QPushButton"
#include "QDebug"
//Teacher类   老师类
//Student类   学生类
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);

    //创建一个学生对象
    this->st = new Student(this);

//    //1.老师饿了，学生请客连接
//    connect(zt,&Teacher::hungry,st,&Student::treat);
//    //调用下课
//    classIsOver();


    //2.连接带参数的 信号与槽
    //指针-> 地址
    //函数之战 -> 函数地址
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
    connect(zt,teacherSignal,st,studentSlot);
    classIsOver();



    //3.点击一个下课的按钮，再触发下课
    QPushButton *btn = new QPushButton("下课",this);
    //重置窗口大小
    this->resize(600,400);
    //点击按钮  触发下课
    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);


    //4.无参信号和槽连接
    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *studentSlot2)(void) = &Student::treat;
    connect(zt,teacherSignal2,st,studentSlot2);

    //信号连接信号
    connect(btn,&QPushButton::clicked,zt,teacherSignal2);


    //断开信号
    disconnect(zt,teacherSignal2,st,studentSlot2);



    //lambda表达式
//    int ret = []()->int{return 1000;}();
//    qDebug() << "ret = " << ret;

    //利用lambda表达式 实现点击按钮 关闭窗口
    QPushButton * btn2 = new QPushButton;
    btn2->setText("关闭窗口");
    btn2->move(100,0);
    btn2->setParent(this);
    connect(btn2,&QPushButton::clicked,this,[=](){
        this->close();
        qDebug() << "关闭窗口";
    });

}


Widget::~Widget()
{
    delete ui;
}

void Widget::classIsOver()
{
    //下课函数，调用 触发老师饿了的信号
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

