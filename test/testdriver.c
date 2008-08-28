/*
 * PSP Software Development Kit - http://www.pspdev.org
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * main.c - The PspUsbCamTest Application
 *
 * Copyright (c) 2008 Jacky Baltes jacky.baltes@gmail.com
 *
 */
#include <pspkernel.h>
#include <pspdebug.h>

#define printf pspDebugScreenPrintf

/* Define the module info section */
PSP_MODULE_INFO("pspusbcamtest", PSP_MODULE_USER, 1, 0);

/* Define the main thread's attribute value (optional) */
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

int main(int argc, char *argv[])
{
	pspDebugScreenInit();

	pspDebugScreenPrintf("Hello World\n");

	return 0;
}
