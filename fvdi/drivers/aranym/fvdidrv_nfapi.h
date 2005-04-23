/*
 * STanda 2004
 *
 * GPL
 */

#ifndef _FVDIDRV_NFAPI_H
#define _FVDIDRV_NFAPI_H

/* if you change anything in the enum {} below you have to increase
   this FVDIDRV_NFAPI_VERSION!

   fVDI v0.960 driver API, fVDI Natfeat v1.300
*/
#define FVDIDRV_NFAPI_VERSION    0x13000960L

enum {
	FVDI_GET_VERSION = 0,	/* subID = 0 */
	FVDI_GET_PIXEL,
	FVDI_PUT_PIXEL,
	FVDI_MOUSE,
	FVDI_EXPAND_AREA,
	FVDI_FILL_AREA,
	FVDI_BLIT_AREA,
	FVDI_LINE,
	FVDI_FILL_POLYGON,
	FVDI_GET_HWCOLOR,
	FVDI_SET_COLOR,
	FVDI_GET_FBADDR,
	FVDI_SET_RESOLUTION,
	FVDI_GET_WIDTH,
	FVDI_GET_HEIGHT,
	FVDI_OPENWK,
	FVDI_CLOSEWK
};

extern unsigned long nfFvdiDrvId;

#endif /* _FVDIDRV_NFAPI_H */
