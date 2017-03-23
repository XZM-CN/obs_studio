//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:14分:17秒  
// ><文件     ><  crash-report.cpp  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\UI  
// ><隶属工程><   obs-studio  
// ><当前用户 ><  Administrator  
// ><作者     ><  Open Broadcaster Software   
// ><出处     >< 《 https://obsproject.com/ 》  
// ><目的     >< 【崩溃报告】  
// ><设计技术 ><   
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
// ><         ><  4.  
//////////////////////////////////迭代修改///////////////////////////////////////////////////////  
// ><作者     ><  xzm  
// ><修改日期 ><  2017年:03月:21日   16时:14分:17秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include "crash-report.hpp"
#include <QApplication>
#include <QFontDatabase>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QClipboard>
#include "qt-wrappers.hpp"

OBSCrashReport::OBSCrashReport(QWidget *parent, const char *text)
	: QDialog(parent)
{
	QPushButton *copyButton = new QPushButton;
	copyButton->setText("Copy crash log");

	QPushButton *exitButton = new QPushButton;
	exitButton->setText("Exit");

	textBox = new QPlainTextEdit;
	textBox->setPlainText(QT_UTF8(text));
	textBox->setLineWrapMode(QPlainTextEdit::NoWrap);
	textBox->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));

	QHBoxLayout *buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(copyButton);
	buttonLayout->addWidget(exitButton);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(textBox);
	mainLayout->addItem(buttonLayout);

	setLayout(mainLayout);

	QWidget::connect(copyButton, SIGNAL(clicked()),
			this, SLOT(CopyClicked()));
	QWidget::connect(exitButton, SIGNAL(clicked()),
			this, SLOT(ExitClicked()));

	resize(800, 600);
	setWindowTitle("Oops, OBS has crashed!");
}

void OBSCrashReport::ExitClicked()
{
	exit(-1);
}

void OBSCrashReport::CopyClicked()
{
	QApplication::clipboard()->setText(textBox->toPlainText());
}
