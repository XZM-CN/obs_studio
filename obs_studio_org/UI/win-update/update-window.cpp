//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:34分:15秒  
// ><文件     ><  update-window.cpp  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\UI\win-update  
// ><隶属工程><   obs-studio  
// ><当前用户 ><  Administrator  
// ><作者     ><  Open Broadcaster Software   
// ><出处     >< 《 https://obsproject.com/ 》  
// ><目的     >< 【】  
// ><设计技术 ><   
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
// ><         ><  4.  
//////////////////////////////////迭代修改///////////////////////////////////////////////////////  
// ><作者     ><  xzm  
// ><修改日期 ><  2017年:03月:21日   16时:34分:15秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include "update-window.hpp"
#include "obs-app.hpp"

OBSUpdate::OBSUpdate(QWidget *parent, bool manualUpdate, const QString &text)
	: QDialog (parent, Qt::WindowSystemMenuHint |
	                   Qt::WindowTitleHint |
	                   Qt::WindowCloseButtonHint),
	  ui      (new Ui_OBSUpdate)
{
	ui->setupUi(this);
	ui->text->setHtml(text);

	if (manualUpdate) {
		delete ui->skip;
		ui->skip = nullptr;

		ui->no->setText(QTStr("Cancel"));
	}
}

void OBSUpdate::on_yes_clicked()
{
	done(OBSUpdate::Yes);
}

void OBSUpdate::on_no_clicked()
{
	done(OBSUpdate::No);
}

void OBSUpdate::on_skip_clicked()
{
	done(OBSUpdate::Skip);
}

void OBSUpdate::accept()
{
	done(OBSUpdate::Yes);
}

void OBSUpdate::reject()
{
	done(OBSUpdate::No);
}
