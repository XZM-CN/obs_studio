//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:36��:50��  
// ><�ļ�     ><  window-license-agreement.cpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:36��:50��  
// ><ԭ��     ><    
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
