//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:26分:48秒  
// ><文件     ><  properties-view.moc.hpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:26分:48秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QStackedWidget>
#include <QWidget>

#include <media-io/frame-rate.h>

#include <vector>

#ifdef _MSC_VER
#pragma warning(disable : 4505)
#endif

static bool operator!=(const media_frames_per_second &a,
		const media_frames_per_second &b)
{
	return a.numerator != b.numerator || a.denominator != b.denominator;
}

static bool operator==(const media_frames_per_second &a,
		const media_frames_per_second &b)
{
	return !(a != b);
}

using frame_rate_range_t =
	std::pair<media_frames_per_second, media_frames_per_second>;
using frame_rate_ranges_t = std::vector<frame_rate_range_t>;

class OBSFrameRatePropertyWidget : public QWidget {
	Q_OBJECT

public:
	frame_rate_ranges_t fps_ranges;

	QComboBox      *modeSelect   = nullptr;
	QStackedWidget *modeDisplay  = nullptr;

	QWidget        *labels       = nullptr;
	QLabel         *currentFPS   = nullptr;
	QLabel         *timePerFrame = nullptr;
	QLabel         *minLabel     = nullptr;
	QLabel         *maxLabel     = nullptr;

	QComboBox      *simpleFPS    = nullptr;

	QComboBox      *fpsRange     = nullptr;
	QSpinBox       *numEdit      = nullptr;
	QSpinBox       *denEdit      = nullptr;

	bool           updating      = false;

	const char     *name         = nullptr;
	obs_data_t     *settings     = nullptr;

	QLabel         *warningLabel = nullptr;

	OBSFrameRatePropertyWidget() = default;
};
