//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:28��:49��  
// ><�ļ�     ><  window-basic-adv-audio.hpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:28��:49��  
// ><ԭ��     ><    
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
