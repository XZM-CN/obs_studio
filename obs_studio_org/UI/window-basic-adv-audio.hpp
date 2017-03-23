//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:28分:49秒  
// ><文件     ><  window-basic-adv-audio.hpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:28分:49秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <obs.hpp>
#include <QDialog>
#include <vector>

class OBSAdvAudioCtrl;
class QGridLayout;

// "Basic advanced audio"?  ...

class OBSBasicAdvAudio : public QDialog {
	Q_OBJECT

private:
	QWidget *controlArea;
	QGridLayout *mainLayout;
	OBSSignal sourceAddedSignal;
	OBSSignal sourceRemovedSignal;

	std::vector<OBSAdvAudioCtrl*> controls;

	inline void AddAudioSource(obs_source_t *source);

	static bool EnumSources(void *param, obs_source_t *source);

	static void OBSSourceAdded(void *param, calldata_t *calldata);
	static void OBSSourceRemoved(void *param, calldata_t *calldata);

public slots:
	void SourceAdded(OBSSource source);
	void SourceRemoved(OBSSource source);

public:
	OBSBasicAdvAudio(QWidget *parent);
	~OBSBasicAdvAudio();
};
