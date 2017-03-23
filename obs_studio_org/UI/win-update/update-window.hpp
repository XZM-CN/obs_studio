//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:28��:13��  
// ><�ļ�     ><  update-window.hpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:28��:13��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <QDialog>
#include <memory>

#include "ui_OBSUpdate.h"

class OBSUpdate : public QDialog {
	Q_OBJECT

public:
	enum ReturnVal {
		No,
		Yes,
		Skip
	};

	OBSUpdate(QWidget *parent, bool manualUpdate, const QString &text);

public slots:
	void on_yes_clicked();
	void on_no_clicked();
	void on_skip_clicked();
	virtual void accept() override;
	virtual void reject() override;

private:
	std::unique_ptr<Ui_OBSUpdate> ui;
};
