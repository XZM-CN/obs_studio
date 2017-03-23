//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:27分:04秒  
// ><文件     ><  qt-wrappers.hpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:27分:04秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************
    Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#pragma once

#include <QWidget>
#include <obs.hpp>

#include <memory>
#include <vector>

#define QT_UTF8(str) QString::fromUtf8(str)
#define QT_TO_UTF8(str) str.toUtf8().constData()

class QDataStream;
class QWidget;
class QLayout;
struct gs_window;

void OBSErrorBox(QWidget *parent, const char *msg, ...);

void QTToGSWindow(WId windowId, gs_window &gswindow);

uint32_t TranslateQtKeyboardEventModifiers(Qt::KeyboardModifiers mods);

QDataStream &operator<<(QDataStream &out,
		const std::vector<std::shared_ptr<OBSSignal>> &signal_vec);
QDataStream &operator>>(QDataStream &in,
		std::vector<std::shared_ptr<OBSSignal>> &signal_vec);
QDataStream &operator<<(QDataStream &out, const OBSScene &scene);
QDataStream &operator>>(QDataStream &in, OBSScene &scene);
QDataStream &operator<<(QDataStream &out, const OBSSceneItem &si);
QDataStream &operator>>(QDataStream &in, OBSSceneItem &si);

class SignalBlocker {
	QWidget *widget;
	bool blocked;

public:
	inline explicit SignalBlocker(QWidget *widget_) : widget(widget_)
	{
		blocked = widget->blockSignals(true);
	}

	inline ~SignalBlocker()
	{
		widget->blockSignals(blocked);
	}
};

void DeleteLayout(QLayout *layout);
