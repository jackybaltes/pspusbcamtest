 /*
 * PSP Software Development Kit - http://www.pspdev.org
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * main.c - Camera Test example
 *
 * Copyright (c) 2008 Jacky Baltes <jacky@cs.umanitoba.ca>
 *
 * $Id: main.c 705 2005-07-20 18:09:56Z tyranid $
 */

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <pspusb.h>
#include <pspusbcam.h>
#include <pspusbacc.h>
#include <psputility_usbmodules.h>
#include <pspsircs.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "pspusbcamserver.h"

/* Define the module info section */
PSP_MODULE_INFO("CAMERA TEST", PSP_MODULE_KERNEL, 1, 0);

/* Define the main thread's attribute value (optional) */
PSP_MAIN_THREAD_ATTR( THREAD_ATTR_USER );
PSP_HEAP_SIZE_KB(15*1024);
PSP_MAIN_THREAD_STACK_SIZE_KB(512);

/* Prototypes */
int unloadCameraModules( void );
int loadCameraModules( void );
int startCamera( void );

static LogFunction logFunction = 0;

int
module_start (SceSize argc, void* argp)
{
  return SCE_KERNEL_ERROR_OK;
}

int 
module_stop()
{
  return SCE_KERNEL_ERROR_OK;
}


int 
loadCameraModules( void )
{
  int err = SCE_KERNEL_ERROR_OK;

  logFunction("Loading PSP_USB_MODULE_ACC ...");
  if ( ( err = sceUtilityLoadUsbModule(PSP_USB_MODULE_ACC) ) == 0 )
    {
      logFunction("success\n");
    }
  else
    {
      logFunction("ERROR %08x\n", err );
      for(;;)
	{
	  sceDisplayWaitVblankStart(); 
	}
      goto exit;
    }

  logFunction("Loading PSP_USB_MODULE_CAM ...");
  if ( ( err = sceUtilityLoadUsbModule(PSP_USB_MODULE_CAM) ) == 0 )
    {
      logFunction("success\n");
    }
  else
    {
      logFunction("ERROR %08x\n", err );
      for(;;)
	{
	  sceDisplayWaitVblankStart(); 
	}
      goto exit;
    }

 exit:
  return err;
}

int
startCamera( void )
{
  int err = SCE_KERNEL_ERROR_OK;

  logFunction("Starting PSP_USBBUS ...");
  if ( ( err = sceUsbStart(PSP_USBBUS_DRIVERNAME, 0, 0) == 0 ) )
    {
      logFunction("success\n");
    }
  else
    {
      logFunction("Error 0x%08X starting usbbus driver.\n", err);
      goto exit;
    }

  logFunction("Starting PSP_USBACC ...");
  if ( ( err = sceUsbStart(PSP_USBACC_DRIVERNAME, 0, 0) ) == 0 )
    {
      logFunction("success\n");
    }
  else
    {
      logFunction("Error 0x%08X starting usbacc driver.\n", err);
      goto exit;
    }
  
  logFunction("Starting PSP_USBCAM ...");
  if ( ( err = sceUsbStart(PSP_USBCAM_DRIVERNAME, 0, 0) ) == 0 )
    {
      logFunction("success\n");
    }
  else
    {
      logFunction("Error 0x%08X starting usbcam driver.\n", err);
      goto exit;
    }

  logFunction( "Activating PSP_USBCAM ..." );
  if ( ( err = sceUsbActivate(PSP_USBCAM_PID) ) == 0 )
    {
      logFunction("success\n");
    }
  else
    {
      logFunction("Error 0x%08X activating usbcam driver.\n", err);
      goto exit;
    }

 exit:
  return err;
}

int 
unloadCameraModules( void )
{
  int err = SCE_KERNEL_ERROR_OK;

  logFunction("Unloading PSP_USB_MODULE_ACC ...");
  if ( ( err = sceUtilityUnloadUsbModule(PSP_USB_MODULE_ACC) ) == 0 )
    {
      logFunction("success\n");
    }
  else
    {
      logFunction("ERROR %08x\n", err );
      for(;;)
	{
	  sceDisplayWaitVblankStart(); 
	}
      goto exit;
    }

  logFunction("Unloading PSP_USB_MODULE_CAM ...");
  if ( ( err = sceUtilityUnloadUsbModule(PSP_USB_MODULE_CAM) ) == 0 )
    {
      logFunction("success\n");
    }
  else
    {
      logFunction("ERROR %08x\n", err );
      for(;;)
	{
	  sceDisplayWaitVblankStart(); 
	}
      goto exit;
    }

 exit:
  return err;
}

int 
PspUsbCam_Server_Initialize( LogFunction logFunc )
{
  logFunction = logFunc;

  loadCameraModules();
  startCamera();

  logFunction ("Camera Test Application by Jacky\n");
  logFunction ("-------------------------------\n");

  return SCE_KERNEL_ERROR_OK;
}

