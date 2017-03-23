//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:34分:07秒  
// ><文件     ><  source-list-widget.cpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:34分:07秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <QMouseEvent>

#include <vector>

#include "qt-wrappers.hpp"
#include "source-list-widget.hpp"

Q_DECLARE_METATYPE(OBSSceneItem);

void SourceListWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
		QListWidget::mouseDoubleClickEvent(event);
}

void SourceListWidget::dropEvent(QDropEvent *event)
{
	QListWidget::dropEvent(event);
	if (!event->isAccepted() || !count())
		return;

	auto GetSceneItem = [&](int i)
	{
		return item(i)->data(Qt::UserRole).value<OBSSceneItem>();
	};

	std::vector<obs_sceneitem_t*> newOrder;
	newOrder.reserve(count());
	for (int i = count() - 1; i >= 0; i--)
		newOrder.push_back(GetSceneItem(i));

	auto UpdateOrderAtomically = [&](obs_scene_t *scene)
	{
		ignoreReorder = true;
		obs_scene_reorder_items(scene, newOrder.data(),
				newOrder.size());
		ignoreReorder = false;
	};
	using UpdateOrderAtomically_t = decltype(UpdateOrderAtomically);

	auto scene = obs_sceneitem_get_scene(GetSceneItem(0));
	obs_scene_atomic_update(scene, [](void *data, obs_scene_t *scene)
	{
		(*static_cast<UpdateOrderAtomically_t*>(data))(scene);
	}, static_cast<void*>(&UpdateOrderAtomically));
}
