/* $Id: //WIFI_SOC/release/SDK_4_1_0_0/source/user/miniupnpd-1.1/miniupnpdpath.h#1 $ */
/* MiniUPnP project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 * (c) 2006-2008 Thomas Bernard
 * This software is subject to the conditions detailed
 * in the LICENCE file provided within the distribution */

#ifndef __MINIUPNPDPATH_H__
#define __MINIUPNPDPATH_H__

#include "config.h"

/* Paths and other URLs in the miniupnpd http server */

#define ROOTDESC_PATH 		"/rootDesc.xml"

#ifdef HAS_DUMMY_SERVICE
#define DUMMY_PATH			"/dummy.xml"
#endif

#define WANCFG_PATH			"/WANCfg.xml"
#define WANCFG_CONTROLURL	"/ctl/CmnIfCfg"
#define WANCFG_EVENTURL		"/evt/CmnIfCfg"

#define WANIPC_PATH			"/WANIPCn.xml"
#define WANIPC_CONTROLURL	"/ctl/IPConn"
#define WANIPC_EVENTURL		"/evt/IPConn"

#ifdef ENABLE_L3F_SERVICE
#define L3F_PATH			"/L3F.xml"
#define L3F_CONTROLURL		"/ctl/L3F"
#define L3F_EVENTURL		"/evt/L3F"
#endif

#endif

