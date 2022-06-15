/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: exitFunc */
#define  PANEL_GRAPH                      2       /* control type: graph, callback function: (none) */
#define  PANEL_DLL_BUTTON                 3       /* control type: command, callback function: useDll */
#define  PANEL_SOUND_BUTTON               4       /* control type: textButton, callback function: playSound */
#define  PANEL_LED                        5       /* control type: LED, callback function: (none) */
#define  PANEL_TEXTMSG                    6       /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK exitFunc(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK playSound(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK useDll(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif