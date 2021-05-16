#include "mainwindow.h"
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QDebug>
#include<QMessageBox>
#include<QVBoxLayout>
#include<QFont>
#include<QDialog>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel *l=new QLabel(this);
       l->setMinimumSize(70,50);
       l->move(100,50);
       QPixmap p("C:/Users/nandi/OneDrive/Desktop/profilepic.jpg");
       l->setPixmap(p.scaled(20,20));

       QLabel *lb=new QLabel(this);
       lb->move(180,25);
       lb->setAlignment(Qt::AlignHCenter);
       QPixmap pi("C:/Users/nandi/OneDrive/Desktop/open+password+icon-1320183290851596683.png");
       l->setPixmap(pi.scaled(20,20));

       QLabel *l1=new QLabel("UserName",this);
       l1->setMinimumSize(70,50);
       l1->move(130,50);
       QPalette pal;
       pal.setColor(QPalette::WindowText,Qt::red);
       l1->setPalette(pal);

       QLineEdit *le=new QLineEdit(this);
       le->setMinimumSize(200,50);
       le->move(220,50);
       le->setStyleSheet("border:2px solid red");

       QLabel *lp=new QLabel(this);
       lp->move(100,110);
       lp->setMinimumSize(200,50);
       QPixmap pix("C:/Users/nandi/OneDrive/Desktop/name-icon-vector-male-user-person-profile-avatar-symbol-identity-card-flat-color-glyph-pictogram-illustration-137931301.jpg");
       lp->setPixmap(pix.scaled(20,20));

       QLabel *pass=new QLabel("Password",this);
       pass->setMinimumSize(70,50);
       pass->move(130,110);
       QPalette pall;
       pall.setColor(QPalette::WindowText,Qt::green);
       pass->setPalette(pall);

       QLineEdit *lie=new QLineEdit(this);
       lie->setMinimumSize(200,50);
       lie->move(220,110);
       lie->setStyleSheet("border:2px solid green");

       QLabel *acc=new QLabel("Don't have account",this);
       acc->setMinimumSize(100,50);
       acc->move(110,170);

       QFont button1("Times",8,QFont::Bold);
       QPushButton *btn1=new QPushButton("Sign Up",this);
       btn1->setFont(button1);
       btn1->move(220,180);
       connect(btn1,&QPushButton::clicked,[=](){
           Dialog *d=new Dialog(this);
           d->exec();
       });

       QFont button("Times",18,QFont::Bold);
       QPushButton *btn=new QPushButton("Login",this);
       btn->setFont(button);
       btn->move(220,280);
       connect(btn,&QPushButton::clicked,[=](){
           QString uname=le->text();
           QString p=lie->text();
           if(uname=="nandi123"&& p=="123456789")
           {
               QMessageBox::information(this,"Login","Login Successful!!");
           }
           else
           {
               QMessageBox::information(this,"Login","Username or Password incorrect!");
           }
       });
      le->setPlaceholderText("username");
      lie->setPlaceholderText("password");
}

MainWindow::~MainWindow()
{
}

