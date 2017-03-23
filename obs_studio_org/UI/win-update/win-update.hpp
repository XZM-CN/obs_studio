//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   14时:11分:06秒  
// ><文件     ><  win-update.hpp  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\UI\win-update  
// ><隶属工程><   obs-studio  
// ><当前用户 ><  Administrator  
// ><作者     ><  Open Broadcaster Software   
// ><出处     >< 《 https://obsproject.com/ 》  
// ><目的     >< 【自动更新升级】  
// ><设计技术 ><   
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
// ><         ><  4.  
//////////////////////////////////迭代修改///////////////////////////////////////////////////////  
// ><作者     ><  xzm  
// ><修改日期 ><  2017年:03月:21日   14时:11分:06秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <QThread>
#include <QString>


class AutoUpdateThread : public QThread {
	Q_OBJECT

	bool manualUpdate;
	bool user_confirmed = false;

	virtual void run() override;

	void info(const QString &title, const QString &text);
	int queryUpdate(bool manualUpdate, const char *text_utf8);

private slots:
	void infoMsg(const QString &title, const QString &text);
	int queryUpdateSlot(bool manualUpdate, const QString &text);

public:
	AutoUpdateThread(bool manualUpdate_) : manualUpdate(manualUpdate_) {}
};
