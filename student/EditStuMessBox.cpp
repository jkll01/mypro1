#include "EditStuMessBox.h"

//构建添加学生主界面
EditStuMessBox::EditStuMessBox()
{
    /*
     * QVBoxLayout 局部工具中放置 QFormLayout 和 QHBoxLayout
     * QFormLayout 中放置多个单行输入框
     * QHBoxLayout 中放置两个按钮
    */
    setWindowIcon(QIcon("D:\\Qt_Projects\\student\\logo.ico"));
   // setWindowFlags(Qt::Dialog);设置窗体的图标
    setWindowTitle("添加学生信息");//修改窗口标题
    QVBoxLayout * VBox = new QVBoxLayout;

    QFormLayout *FormLayout = new QFormLayout;
    ID = new QLineEdit;//单行文本编辑控件
    name = new QLineEdit;
    sex = new QLineEdit;
    age = new QLineEdit;
    chinese_score = new QLineEdit;
    math_score = new QLineEdit;
    english_score = new QLineEdit;
    //在QFormLayout中添加新行，这些行以不同的形式出现，可以是标签加输入框，可以是标签加布局、单独的输入框、单独的布局等等。
    FormLayout->addRow("学号：",ID);
    FormLayout->addRow("姓名：",name);
    FormLayout->addRow("年龄：",age);
    FormLayout->addRow("性别：",sex);
    FormLayout->addRow("语文成绩：",chinese_score);
    FormLayout->addRow("数学成绩：",math_score);
    FormLayout->addRow("英语成绩：",english_score);
    //QFormLayout::WrapLongRows：根据输入框的尺寸，标签可能位于输入框的左侧，也可能位于上方
    FormLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);//设置标签的显示格式

    QHBoxLayout * HBox = new QHBoxLayout;
    submit = new QPushButton("提交");
    cancel = new QPushButton("取消");
    HBox->addWidget(submit);//向布局中添加控件
    HBox->addWidget(cancel);

    VBox->addLayout(FormLayout,4);//向布局中添加子布局
    VBox->addLayout(HBox,1);
    this->setLayout(VBox);//将布局管理器添加到 "添加学生信息" 窗口中

    //点击提交按钮时，将新学生信息保存到文件中
    QObject::connect(submit,&QPushButton::clicked,this,&EditStuMessBox::saveStuMess);
    //点击取消按钮时，关闭添加学生信息窗口
    QObject::connect(cancel,&QPushButton::clicked,this,&EditStuMessBox::close);
}

//当用户添加提交按钮时，保存学生信息
void EditStuMessBox::saveStuMess(){
    //确保所有信息填写后，将信息写入到文件中，否则提示用户将信息填写完整
    if(this->ID->text() !="" && this->name->text()!="" &&this->age->text() !="" && this->sex->text()!="" && \
            this->chinese_score->text()!="" && this->math_score->text()!="" && this->english_score->text()!=""){
        Student stu;
        stu.setID(this->ID->text());
        stu.setName(this->name->text());
        stu.setAge(this->age->text());
        stu.setSex(this->sex->text());
        stu.setChinese_score(this->chinese_score->text());
        stu.setMath_score(this->math_score->text());
        stu.setEnglish_score(this->english_score->text());

        QFile file(file_name);
        file.open(QIODevice::WriteOnly|QIODevice::Append);//以只写和追加的方式打开文件
        QDataStream dataStr(&file);
        //将二进制文件写入流
        dataStr << stu.getID() << stu.getName() << stu.getAge() << stu.getSex()
                << stu.getChinese_score() << stu.getMath_score() << stu.getEnglish_score();
        file.close();
        this->close();
        emitCloseBox();
    }else{
        QMessageBox::warning(this,"提示","请将信息填写完整",QMessageBox::Ok);
    }

}

void EditStuMessBox::emitCloseBox(){
    emit closeBox();
}
