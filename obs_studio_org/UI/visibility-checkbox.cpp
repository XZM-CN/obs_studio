//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:34��:33��  
// ><�ļ�     ><  visibility-checkbox.cpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:34��:33��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <QPaintEvent>
#include <QPixmap>
#include <QPainter>
#include "visibility-checkbox.hpp"

#include <util/c99defs.h>

VisibilityCheckBox::VisibilityCheckBox() : QCheckBox()
{
	checkedImage =
		QPixmap::fromImage(QImage(":/res/images/visible_mask.png"));
	uncheckedImage =
		QPixmap::fromImage(QImage(":/res/images/invisible_mask.png"));
	setMinimumSize(16, 16);

	setStyleSheet("outline: none;");
}

void VisibilityCheckBox::paintEvent(QPaintEvent *event)
{
	UNUSED_PARAMETER(event);

	QPixmap &pixmap = isChecked() ? checkedImage : uncheckedImage;
	QImage image(pixmap.size(), QImage::Format_ARGB32);

	QPainter draw(&image);
	draw.setCompositionMode(QPainter::CompositionMode_Source);
	draw.drawPixmap(0, 0, pixmap.width(), pixmap.height(), pixmap);
	draw.setCompositionMode(QPainter::CompositionMode_SourceIn);
	draw.fillRect(QRectF(QPointF(0.0f, 0.0f), pixmap.size()),
			palette().color(foregroundRole()));

	QPainter p(this);
	p.drawPixmap(0, 0, image.width(), image.height(),
			QPixmap::fromImage(image));
}
