//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:32分:31秒  
// ><文件     ><  menu-button.cpp  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\UI  
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
// ><修改日期 ><  2017年:03月:21日   16时:32分:31秒  
// ><原因     ><    
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
