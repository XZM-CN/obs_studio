//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:36分:50秒  
// ><文件     ><  window-license-agreement.cpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:36分:50秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <util/util.hpp>
#include <util/platform.h>
#include <platform.hpp>
#include "window-license-agreement.hpp"
#include "qt-wrappers.hpp"

using namespace std;

OBSLicenseAgreement::OBSLicenseAgreement(QWidget *parent)
	: QDialog (parent),
	  ui      (new Ui::OBSLicenseAgreement)
{
	ui->setupUi(this);

	string path;
	if (!GetDataFilePath("license/gplv2.txt", path))
		throw "Could not find license file";

	BPtr<char> licenseText = os_quick_read_utf8_file(path.c_str());
	if (!licenseText || !*licenseText || strlen(licenseText) < 1000)
		throw "Invalid license file data";

	ui->license->setPlainText(QT_UTF8(licenseText));
}
