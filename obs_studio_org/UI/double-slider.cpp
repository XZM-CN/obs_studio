//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:32��:02��  
// ><�ļ�     ><  double-slider.cpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:32��:02��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include "double-slider.hpp"

#include <cmath>

DoubleSlider::DoubleSlider(QWidget *parent) : QSlider(parent)
{
	connect(this, SIGNAL(valueChanged(int)),
			this, SLOT(intValChanged(int)));
}

void DoubleSlider::setDoubleConstraints(double newMin, double newMax,
		double newStep, double val)
{
	minVal = newMin;
	maxVal = newMax;
	minStep = newStep;

	double total = maxVal - minVal;
	int intMax = int(total / minStep);

	setMinimum(0);
	setMaximum(intMax);
	setSingleStep(1);
	setDoubleVal(val);
}

void DoubleSlider::intValChanged(int val)
{
	emit doubleValChanged((minVal/minStep + val) * minStep);
}

void DoubleSlider::setDoubleVal(double val)
{
	setValue(lround((val - minVal) / minStep));
}
