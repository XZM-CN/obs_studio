//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:33��:52��  
// ><�ļ�     ><  slider-absoluteset-style.cpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:33��:52��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include "slider-absoluteset-style.hpp"

SliderAbsoluteSetStyle::SliderAbsoluteSetStyle(const QString& baseStyle)
	:QProxyStyle(baseStyle)
{
}
SliderAbsoluteSetStyle::SliderAbsoluteSetStyle(QStyle* baseStyle)
	:QProxyStyle(baseStyle)
{
}

int SliderAbsoluteSetStyle::styleHint(QStyle::StyleHint hint,
	const QStyleOption* option = 0, const QWidget* widget = 0,
	QStyleHintReturn* returnData = 0) const
{
	if(hint == QStyle::SH_Slider_AbsoluteSetButtons)
		return (Qt::LeftButton | Qt::MidButton);
	return QProxyStyle::styleHint(hint, option, widget, returnData);
}
