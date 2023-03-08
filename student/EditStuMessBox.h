#ifndef EDITSTUMESSBOX_H
#define EDITSTUMESSBOX_H

#include <QWidget>
#include <QLineEdit>//单行输入框
#include <QFormLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Student.h"
#include <QFile>
#include <QDataStream>
#include "Tool.h"
#include <QMessageBox>//消息对话框

//自定义添加学生信息窗口
class EditStuMessBox : public QDialog//对话框
{
    Q_OBJECT//只有加入了Q_OBJECT，才能使用QT中的signal和slot机制，而且Q_OBJECT要放在类的最前面
public:
    //构建添加学生信息界面
    EditStuMessBox();
signals:
    //自定义信号，当添加学生信息完成后，更新主界面上的表格
    void closeBox();

public slots:
    //将新学生的信息写入到文件中
    void saveStuMess();
public:
    //发出 closeBox 信号
    void emitCloseBox();
private:
    QLineEdit * ID;
    QLineEdit * name;
    QLineEdit * sex;
    QLineEdit * age;
    QLineEdit * chinese_score;
    QLineEdit * math_score;
    QLineEdit * english_score;
    QPushButton * submit;
    QPushButton * cancel;
};
#endif // EDITSTUMESSBOX_H
