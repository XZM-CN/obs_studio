//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:31��:02��  
// ><�ļ�     ><  window-projector.hpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:31��:02��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <obs.hpp>
#include "qt-display.hpp"
#include "window-basic-main.hpp"

class QMouseEvent;

class OBSProjector : public OBSQTDisplay {
	Q_OBJECT

private:
	OBSSource source;
	OBSSignal removedSignal;

	static void OBSRender(void *data, uint32_t cx, uint32_t cy);
	static void OBSSourceRemoved(void *data, calldata_t *params);

	void mousePressEvent(QMouseEvent *event) override;

	int savedMonitor = 0;

private slots:
	void EscapeTriggered();

public:
	OBSProjector(QWidget *parent, obs_source_t *source);
	~OBSProjector();

	void Init(int monitor);
};
