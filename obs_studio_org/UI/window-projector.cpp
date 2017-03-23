//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:37分:08秒  
// ><文件     ><  window-projector.cpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:37分:08秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <QAction>
#include <QGuiApplication>
#include <QMouseEvent>
#include <QMenu>
#include <QScreen>
#include "window-projector.hpp"
#include "display-helpers.hpp"
#include "qt-wrappers.hpp"
#include "platform.hpp"
#include "obs-app.hpp"

OBSProjector::OBSProjector(QWidget *widget, obs_source_t *source_)
	: OBSQTDisplay                 (widget,
	                                Qt::Window | Qt::FramelessWindowHint |
					Qt::X11BypassWindowManagerHint),
	  source                       (source_),
	  removedSignal                (obs_source_get_signal_handler(source),
	                                "remove", OBSSourceRemoved, this)
{
	setAttribute(Qt::WA_DeleteOnClose, true);

	//disable application quit when last window closed
	setAttribute(Qt::WA_QuitOnClose, false);

	installEventFilter(CreateShortcutFilter());

	auto addDrawCallback = [this] ()
	{
		obs_display_add_draw_callback(GetDisplay(), OBSRender, this);
		obs_display_set_background_color(GetDisplay(), 0x000000);
	};

	connect(this, &OBSQTDisplay::DisplayCreated, addDrawCallback);

	bool hideCursor = config_get_bool(GetGlobalConfig(),
			"BasicWindow", "HideProjectorCursor");
	if (hideCursor) {
		QPixmap empty(16, 16);
		empty.fill(Qt::transparent);
		setCursor(QCursor(empty));
	}

	App()->IncrementSleepInhibition();
}

OBSProjector::~OBSProjector()
{
	if (source)
		obs_source_dec_showing(source);
	App()->DecrementSleepInhibition();
}

void OBSProjector::Init(int monitor)
{
	QScreen *screen = QGuiApplication::screens()[monitor];

	setGeometry(screen->geometry());

	bool alwaysOnTop = config_get_bool(GetGlobalConfig(),
			"BasicWindow", "ProjectorAlwaysOnTop");
	if (alwaysOnTop)
		SetAlwaysOnTop(this, true);

	show();

	if (source)
		obs_source_inc_showing(source);

	QAction *action = new QAction(this);
	action->setShortcut(Qt::Key_Escape);
	addAction(action);

	connect(action, SIGNAL(triggered()), this, SLOT(EscapeTriggered()));

	savedMonitor = monitor;
}

void OBSProjector::OBSRender(void *data, uint32_t cx, uint32_t cy)
{
	OBSProjector *window = reinterpret_cast<OBSProjector*>(data);

	uint32_t targetCX;
	uint32_t targetCY;
	int      x, y;
	int      newCX, newCY;
	float    scale;

	if (window->source) {
		targetCX = std::max(obs_source_get_width(window->source), 1u);
		targetCY = std::max(obs_source_get_height(window->source), 1u);
	} else {
		struct obs_video_info ovi;
		obs_get_video_info(&ovi);
		targetCX = ovi.base_width;
		targetCY = ovi.base_height;
	}

	GetScaleAndCenterPos(targetCX, targetCY, cx, cy, x, y, scale);

	newCX = int(scale * float(targetCX));
	newCY = int(scale * float(targetCY));

	gs_viewport_push();
	gs_projection_push();
	gs_ortho(0.0f, float(targetCX), 0.0f, float(targetCY), -100.0f, 100.0f);
	gs_set_viewport(x, y, newCX, newCY);

	if (window->source)
		obs_source_video_render(window->source);
	else
		obs_render_main_view();

	gs_projection_pop();
	gs_viewport_pop();
}

void OBSProjector::OBSSourceRemoved(void *data, calldata_t *params)
{
	OBSProjector *window = reinterpret_cast<OBSProjector*>(data);

	window->deleteLater();

	UNUSED_PARAMETER(params);
}

void OBSProjector::mousePressEvent(QMouseEvent *event)
{
	OBSQTDisplay::mousePressEvent(event);

	if (event->button() == Qt::RightButton) {
		QMenu popup(this);
		popup.addAction(QTStr("Close"), this, SLOT(EscapeTriggered()));
		popup.exec(QCursor::pos());
	}
}

void OBSProjector::EscapeTriggered()
{
	OBSBasic *main = reinterpret_cast<OBSBasic*>(App()->GetMainWindow());
	main->RemoveSavedProjectors(savedMonitor);

	deleteLater();
}
