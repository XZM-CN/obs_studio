//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:25��:59��  
// ><�ļ�     ><  menu-button.hpp  
// ><�ļ�·�� ><  D:\newSvnCode\OBS\trunk\obs_studio\UI  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:25��:59��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <QPushButton>

class MenuButton : public QPushButton {
	Q_OBJECT

protected:
	void mousePressEvent(QMouseEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;

public:
	explicit inline MenuButton(QWidget *parent = nullptr)
		: QPushButton(parent)
	{
	}

	explicit inline MenuButton(const QString &text,
			QWidget *parent = nullptr)
		: QPushButton(text, parent)
	{
	}
};
