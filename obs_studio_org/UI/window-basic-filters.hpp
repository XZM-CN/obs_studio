//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:28分:56秒  
// ><文件     ><  window-basic-filters.hpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:28分:56秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************
    Copyright (C) 2015 by Hugh Bailey <obs.jim@gmail.com>

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
#include <QDialogButtonBox>
#include <memory>
#include <obs.hpp>

#include "properties-view.hpp"

class OBSBasic;
class QMenu;

#include "ui_OBSBasicFilters.h"

class OBSBasicFilters : public QDialog {
	Q_OBJECT

private:
	OBSBasic *main;

	std::unique_ptr<Ui::OBSBasicFilters> ui;
	OBSSource source;
	OBSPropertiesView *view = nullptr;

	OBSSignal addSignal;
	OBSSignal removeSignal;
	OBSSignal reorderSignal;

	OBSSignal removeSourceSignal;
	OBSSignal renameSourceSignal;

	inline OBSSource GetFilter(int row, bool async);

	void UpdateFilters();
	void UpdatePropertiesView(int row, bool async);

	static void OBSSourceFilterAdded(void *param, calldata_t *data);
	static void OBSSourceFilterRemoved(void *param, calldata_t *data);
	static void OBSSourceReordered(void *param, calldata_t *data);
	static void SourceRemoved(void *param, calldata_t *data);
	static void SourceRenamed(void *param, calldata_t *data);
	static void DrawPreview(void *data, uint32_t cx, uint32_t cy);

	QMenu *CreateAddFilterPopupMenu(bool async);

	void AddNewFilter(const char *id);
	void ReorderFilter(QListWidget *list, obs_source_t *filter, size_t idx);

	void CustomContextMenu(const QPoint &pos, bool async);
	void EditItem(QListWidgetItem *item, bool async);

	void FilterNameEdited(QWidget *editor, QListWidget *list);

private slots:
	void AddFilter(OBSSource filter);
	void RemoveFilter(OBSSource filter);
	void ReorderFilters();
	void RenameAsyncFilter();
	void RenameEffectFilter();

	void AddFilterFromAction();

	void on_addAsyncFilter_clicked();
	void on_removeAsyncFilter_clicked();
	void on_moveAsyncFilterUp_clicked();
	void on_moveAsyncFilterDown_clicked();
	void on_asyncFilters_currentRowChanged(int row);
	void on_asyncFilters_customContextMenuRequested(const QPoint &pos);
	void on_asyncFilters_GotFocus();

	void on_addEffectFilter_clicked();
	void on_removeEffectFilter_clicked();
	void on_moveEffectFilterUp_clicked();
	void on_moveEffectFilterDown_clicked();
	void on_effectFilters_currentRowChanged(int row);
	void on_effectFilters_customContextMenuRequested(const QPoint &pos);
	void on_effectFilters_GotFocus();

	void AsyncFilterNameEdited(QWidget *editor,
			QAbstractItemDelegate::EndEditHint endHint);
	void EffectFilterNameEdited(QWidget *editor,
			QAbstractItemDelegate::EndEditHint endHint);

public:
	OBSBasicFilters(QWidget *parent, OBSSource source_);
	~OBSBasicFilters();

	void Init();

protected:
	virtual void closeEvent(QCloseEvent *event) override;
};
