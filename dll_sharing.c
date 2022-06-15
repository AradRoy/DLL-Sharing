#include <cvirte.h>
#include <userint.h>
#include "dll_sharing.h"
#include "persona.h"
#include "bass.h"



static int panelHandle;
static HSTREAM song;
int soundOnOff;
void initialize ()
{
	BASS_Init( -1,44100, 0,0,NULL);
	song= BASS_StreamCreateFile(FALSE,"songs\\I Got Bitches.mp3",0,0,0);
	BASS_ChannelSetAttribute(song, BASS_ATTRIB_VOL, 0.5);
}
void terminate ()
{
	BASS_StreamFree(song);
}



int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "dll_sharing.uir", PANEL)) < 0)
		return -1;
	initialize ();
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	terminate ();
	return 0;
}

int CVICALLBACK exitFunc (int panel, int event, void *callbackData,
						  int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK useDll (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	double xArr[201], yArr[201];
	char name[500];
	switch (event)
	{
		case EVENT_COMMIT:
			for (int i=0; i<201; i++)
			{
				xArr[i]=-10+(i*0.1);
				yArr[i]=calculateValue(xArr[i]);
			}
			PlotXY (panelHandle, PANEL_GRAPH, xArr, yArr, 200, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			getName(name);
			SetCtrlVal (panelHandle, PANEL_TEXTMSG, name);
			SetCtrlAttribute (panelHandle, PANEL_TEXTMSG, ATTR_VISIBLE, 1);
			SetPanelAttribute (panelHandle, ATTR_BACKCOLOR, getColor());
			break;
	}
	return 0;
}

int CVICALLBACK playSound (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_SOUND_BUTTON, &soundOnOff);
			if (soundOnOff)
				BASS_ChannelPlay(song,TRUE);
			else
				BASS_ChannelStop(song);
			SetCtrlVal (panelHandle, PANEL_LED, soundOnOff);
			break;

	}
	return 0;
}
