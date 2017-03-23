//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   17ʱ:51��:24��  
// ><�ļ�     ><  obs-config.h  
// ><�ļ�·�� ><  D:\newSvnCode\OBS\trunk\obs_studio\libobs  
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
// ><�޸����� ><  2017��:03��:21��   17ʱ:51��:24��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************
    Copyright (C) 2014 by Hugh Bailey <obs.jim@gmail.com>

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

#pragma once

/*
 * LIBOBS_API_VER is returned by module_version in each module.
 *
 * Libobs uses semantic versioning.  See http://semver.org/ for more
 * information.
 */

/*
 * Increment if major breaking API changes
 */
#define LIBOBS_API_MAJOR_VER  18

/*
 * Increment if backward-compatible additions
 *
 * Reset to zero each major version
 */
#define LIBOBS_API_MINOR_VER  0

/*
 * Increment if backward-compatible bug fix
 *
 * Reset to zero each major or minor version
 */
#define LIBOBS_API_PATCH_VER  1

#define MAKE_SEMANTIC_VERSION(major, minor, patch) \
                             ((major << 24) | \
                              (minor << 16) | \
                               patch        )

#define LIBOBS_API_VER \
	MAKE_SEMANTIC_VERSION(LIBOBS_API_MAJOR_VER, \
                              LIBOBS_API_MINOR_VER, \
                              LIBOBS_API_PATCH_VER)

#ifdef HAVE_OBSCONFIG_H
# include "obsconfig.h"
#else
# define OBS_VERSION "unknown"
# define OBS_DATA_PATH "../../data"
# define OBS_INSTALL_PREFIX ""
# define OBS_PLUGIN_DESTINATION "obs-plugins"
# define OBS_RELATIVE_PREFIX "../../"
#endif

#define OBS_INSTALL_DATA_PATH OBS_INSTALL_PREFIX OBS_DATA_PATH
