//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:27��:31��  
// ><�ļ�     ><  source-list-widget.hpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:27��:31��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <QListWidget>

class QMouseEvent;

class SourceListWidget : public QListWidget {
	Q_OBJECT

	bool ignoreReorder = false;
public:
	inline SourceListWidget(QWidget *parent = nullptr)
		: QListWidget(parent)
	{
	}

	bool IgnoreReorder() const { return ignoreReorder; }

protected:
	virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
	virtual void dropEvent(QDropEvent *event) override;
};
