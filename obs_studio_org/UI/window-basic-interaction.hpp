//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:29��:05��  
// ><�ļ�     ><  window-basic-interaction.hpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:29��:05��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************
    Copyright (C) 2014 by Hugh Bailey <obs.jim@gmail.com>

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

#include <QDialog>
#include <memory>
#include <functional>

#include <obs.hpp>

#include "properties-view.hpp"

class OBSBasic;

#include "ui_OBSBasicInteraction.h"

class OBSEventFilter;

class OBSBasicInteraction : public QDialog {
	Q_OBJECT

private:
	OBSBasic   *main;

	std::unique_ptr<Ui::OBSBasicInteraction> ui;
	OBSSource  source;
	OBSSignal  removedSignal;
	OBSSignal  renamedSignal;
	std::unique_ptr<OBSEventFilter> eventFilter;

	static void SourceRemoved(void *data, calldata_t *params);
	static void SourceRenamed(void *data, calldata_t *params);
	static void DrawPreview(void *data, uint32_t cx, uint32_t cy);

	bool GetSourceRelativeXY(int mouseX, int mouseY, int &x, int &y);

	bool HandleMouseClickEvent(QMouseEvent *event);
	bool HandleMouseMoveEvent(QMouseEvent *event);
	bool HandleMouseWheelEvent(QWheelEvent *event);
	bool HandleFocusEvent(QFocusEvent *event);
	bool HandleKeyEvent(QKeyEvent *event);

	OBSEventFilter *BuildEventFilter();

public:
	OBSBasicInteraction(QWidget *parent, OBSSource source_);
	~OBSBasicInteraction();

	void Init();

protected:
	virtual void closeEvent(QCloseEvent *event) override;
};

typedef std::function<bool(QObject *, QEvent *)> EventFilterFunc;

class OBSEventFilter : public QObject
{
	Q_OBJECT
public:
	OBSEventFilter(EventFilterFunc filter_)
		: filter(filter_)
	{}

protected:
	bool eventFilter(QObject *obj, QEvent *event)
	{
		return filter(obj, event);
	}

private:
	EventFilterFunc filter;
};
