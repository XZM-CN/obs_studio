//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:00分:05秒  
// ><文件     ><  adv-audio-control.hpp  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\UI  
// ><隶属工程><   obs-studio  
// ><当前用户 ><  Administrator  
// ><作者     ><  Open Broadcaster Software   
// ><出处     >< 《 https://obsproject.com/ 》  
// ><目的     >< 【高级音频控制】  
// ><设计技术 ><   
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
// ><         ><  4.  
//////////////////////////////////迭代修改///////////////////////////////////////////////////////  
// ><作者     ><  xzm  
// ><修改日期 ><  2017年:03月:21日   16时:00分:05秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <obs.hpp>
#include <QWidget>
#include <QPointer>

class QGridLayout;
class QLabel;
class QSpinBox;
class QCheckBox;
class QSlider;
class QComboBox;

class OBSAdvAudioCtrl : public QObject {
	Q_OBJECT

private:
	OBSSource              source;

	QPointer<QWidget>      forceMonoContainer;
	QPointer<QWidget>      mixerContainer;
	QPointer<QWidget>      panningContainer;

	QPointer<QLabel>       nameLabel;
	QPointer<QSpinBox>     volume;
	QPointer<QCheckBox>    forceMono;
	QPointer<QSlider>      panning;
	QPointer<QLabel>       labelL;
	QPointer<QLabel>       labelR;
	QPointer<QSpinBox>     syncOffset;
	QPointer<QComboBox>    monitoringType;
	QPointer<QCheckBox>    mixer1;
	QPointer<QCheckBox>    mixer2;
	QPointer<QCheckBox>    mixer3;
	QPointer<QCheckBox>    mixer4;
	QPointer<QCheckBox>    mixer5;
	QPointer<QCheckBox>    mixer6;

	OBSSignal              volChangedSignal;
	OBSSignal              syncOffsetSignal;
	OBSSignal              flagsSignal;
	OBSSignal              mixersSignal;

	static void OBSSourceFlagsChanged(void *param, calldata_t *calldata);
	static void OBSSourceVolumeChanged(void *param, calldata_t *calldata);
	static void OBSSourceSyncChanged(void *param, calldata_t *calldata);
	static void OBSSourceMixersChanged(void *param, calldata_t *calldata);

public:
	OBSAdvAudioCtrl(QGridLayout *layout, obs_source_t *source_);
	virtual ~OBSAdvAudioCtrl();

	inline obs_source_t *GetSource() const {return source;}

public slots:
	void SourceFlagsChanged(uint32_t flags);
	void SourceVolumeChanged(float volume);
	void SourceSyncChanged(int64_t offset);
	void SourceMixersChanged(uint32_t mixers);

	void volumeChanged(int percentage);
	void downmixMonoChanged(bool checked);
	void panningChanged(int val);
	void syncOffsetChanged(int milliseconds);
	void monitoringTypeChanged(int index);
	void mixer1Changed(bool checked);
	void mixer2Changed(bool checked);
	void mixer3Changed(bool checked);
	void mixer4Changed(bool checked);
	void mixer5Changed(bool checked);
	void mixer6Changed(bool checked);
};
