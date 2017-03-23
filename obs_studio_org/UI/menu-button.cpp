//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:32��:31��  
// ><�ļ�     ><  menu-button.cpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:32��:31��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <QMenu>
#include <QKeyEvent>
#include <QMouseEvent>
#include "menu-button.hpp"

void MenuButton::keyPressEvent(QKeyEvent *event)
{
	if (menu()) {
		switch (event->key()) {
		case Qt::Key_Enter:
		case Qt::Key_Return:
			emit clicked();
			return;
		case Qt::Key_Down:
			showMenu();
			return;
		}
	}

	QPushButton::keyPressEvent(event);
}

void MenuButton::mousePressEvent(QMouseEvent *event)
{
	if (menu()) {
		if (width() - event->x() <= 15)
			showMenu();
		else
			setDown(true);
	} else {
		QPushButton::mousePressEvent(event);
	}
}
