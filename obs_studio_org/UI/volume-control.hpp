//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:28分:40秒  
// ><文件     ><  volume-control.hpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:28分:40秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <obs.hpp>
#include <QWidget>
#include <QSharedPointer>
#include <QTimer>
#include <QMutex>
#include <QList>

class QPushButton;
class VolumeMeterTimer;

class VolumeMeter : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QColor bkColor READ getBkColor WRITE setBkColor DESIGNABLE true)
	Q_PROPERTY(QColor magColor READ getMagColor WRITE setMagColor DESIGNABLE true)
	Q_PROPERTY(QColor peakColor READ getPeakColor WRITE setPeakColor DESIGNABLE true)
	Q_PROPERTY(QColor peakHoldColor READ getPeakHoldColor WRITE setPeakHoldColor DESIGNABLE true)

private:
	static QWeakPointer<VolumeMeterTimer> updateTimer;
	QSharedPointer<VolumeMeterTimer> updateTimerRef;
	float curMag = 0.0f, curPeak = 0.0f, curPeakHold = 0.0f;

	inline void calcLevels();

	QMutex dataMutex;
	float mag = 0.0f, peak = 0.0f, peakHold = 0.0f;
	float multiple = 0.0f;
	uint64_t lastUpdateTime = 0;

	QColor bkColor, magColor, peakColor, peakHoldColor;

public:
	explicit VolumeMeter(QWidget *parent = 0);
	~VolumeMeter();

	void setLevels(float nmag, float npeak, float npeakHold);
	QColor getBkColor() const;
	void setBkColor(QColor c);
	QColor getMagColor() const;
	void setMagColor(QColor c);
	QColor getPeakColor() const;
	void setPeakColor(QColor c);
	QColor getPeakHoldColor() const;
	void setPeakHoldColor(QColor c);

protected:
	void paintEvent(QPaintEvent *event);
};

class VolumeMeterTimer : public QTimer {
	Q_OBJECT

public:
	inline VolumeMeterTimer() : QTimer() {}

	void AddVolControl(VolumeMeter *meter);
	void RemoveVolControl(VolumeMeter *meter);

protected:
	virtual void timerEvent(QTimerEvent *event) override;
	QList<VolumeMeter*> volumeMeters;
};

class QLabel;
class QSlider;
class MuteCheckBox;

class VolControl : public QWidget {
	Q_OBJECT

private:
	OBSSource source;
	QLabel          *nameLabel;
	QLabel          *volLabel;
	VolumeMeter     *volMeter;
	QSlider         *slider;
	MuteCheckBox    *mute;
	QPushButton     *config = nullptr;
	float           levelTotal;
	float           levelCount;
	obs_fader_t     *obs_fader;
	obs_volmeter_t  *obs_volmeter;

	static void OBSVolumeChanged(void *param, float db);
	static void OBSVolumeLevel(void *data, float level, float mag,
			float peak, float muted);
	static void OBSVolumeMuted(void *data, calldata_t *calldata);

	void EmitConfigClicked();

private slots:
	void VolumeChanged();
	void VolumeMuted(bool muted);
	void VolumeLevel(float mag, float peak, float peakHold, bool muted);

	void SetMuted(bool checked);
	void SliderChanged(int vol);
	void updateText();

signals:
	void ConfigClicked();

public:
	VolControl(OBSSource source, bool showConfig = false);
	~VolControl();

	inline obs_source_t *GetSource() const {return source;}

	QString GetName() const;
	void SetName(const QString &newName);
};
