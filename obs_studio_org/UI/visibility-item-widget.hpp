//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:28分:34秒  
// ><文件     ><  visibility-item-widget.hpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:28分:34秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <QWidget>
#include <QStyledItemDelegate>
#include <obs.hpp>

class QLabel;
class QLineEdit;
class QListWidget;
class QListWidgetItem;
class VisibilityCheckBox;

class VisibilityItemWidget : public QWidget {
	Q_OBJECT

private:
	OBSSceneItem item;
	OBSSource source;
	QLabel *label = nullptr;
	VisibilityCheckBox *vis = nullptr;
	QString oldName;

	OBSSignal sceneRemoveSignal;
	OBSSignal enabledSignal;
	OBSSignal renamedSignal;
	bool sceneRemoved = false;

	bool active = false;
	bool selected = false;

	static void OBSSceneRemove(void *param, calldata_t *data);
	static void OBSSceneItemRemove(void *param, calldata_t *data);
	static void OBSSceneItemVisible(void *param, calldata_t *data);
	static void OBSSourceEnabled(void *param, calldata_t *data);
	static void OBSSourceRenamed(void *param, calldata_t *data);

	void DisconnectItemSignals();

private slots:
	void VisibilityClicked(bool visible);
	void SourceEnabled(bool enabled);
	void SourceRenamed(QString name);

public:
	VisibilityItemWidget(obs_source_t *source);
	VisibilityItemWidget(obs_sceneitem_t *item);
	~VisibilityItemWidget();

	void SetColor(const QColor &color, bool active, bool selected);
};

class VisibilityItemDelegate : public QStyledItemDelegate {
	Q_OBJECT

public:
	VisibilityItemDelegate(QObject *parent = nullptr);

	void paint(QPainter *painter, const QStyleOptionViewItem &option,
			const QModelIndex &index) const override;
};

void SetupVisibilityItem(QListWidget *list, QListWidgetItem *item,
		obs_source_t *source);
void SetupVisibilityItem(QListWidget *list, QListWidgetItem *item,
		obs_sceneitem_t *sceneItem);
