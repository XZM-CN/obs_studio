//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:27分:24秒  
// ><文件     ><  source-label.hpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:27分:24秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************
    Copyright (C) 2015 by Ruwen Hahn <palana@stunned.de>

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

#include <QLabel>
#include <obs.hpp>

class OBSSourceLabel : public QLabel {
	Q_OBJECT;

public:
	OBSSignal renamedSignal;
	OBSSignal removedSignal;
	OBSSignal destroyedSignal;

	OBSSourceLabel(const obs_source_t *source, QWidget *parent=nullptr,
			Qt::WindowFlags f=0)
		: QLabel(obs_source_get_name(source), parent, f),
		  renamedSignal(obs_source_get_signal_handler(source), "rename",
				  &OBSSourceLabel::SourceRenamed, this),
		  removedSignal(obs_source_get_signal_handler(source), "remove",
				  &OBSSourceLabel::SourceRemoved, this),
		  destroyedSignal(obs_source_get_signal_handler(source),
				  "destroy", &OBSSourceLabel::SourceDestroyed,
				  this)
	{}

protected:
	static void SourceRenamed(void *data, calldata_t *params);
	static void SourceRemoved(void *data, calldata_t *params);
	static void SourceDestroyed(void *data, calldata_t *params);

signals:
	void Renamed(const char *name);
	void Removed();
	void Destroyed();
};
