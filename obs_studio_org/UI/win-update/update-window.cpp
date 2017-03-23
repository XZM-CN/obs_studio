//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:34��:15��  
// ><�ļ�     ><  update-window.cpp  
// ><�ļ�·�� ><  D:\newSvnCode\OBS\trunk\obs_studio\UI\win-update  
// ><��������><   obs-studio  
// ><��ǰ�û� ><  Administrator  
// ><����     ><  Open Broadcaster Software   
// ><����     >< �� https://obsproject.com/ ��  
// ><Ŀ��     >< ����  
// ><��Ƽ��� ><   
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
// ><         ><  4.  
//////////////////////////////////�����޸�///////////////////////////////////////////////////////  
// ><����     ><  xzm  
// ><�޸����� ><  2017��:03��:21��   16ʱ:34��:15��  
// ><ԭ��     ><    
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
