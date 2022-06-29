#include "window.h"

#include "cfg.h"
#include "input.h"
#include "screen.h"


#include <dos/dos.h>
#include <intuition/intuition.h>

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/utility.h>




static void WindowSetTag(Tag name, Tag value);

/*--------------------------------------------------------------------------*/

static struct Window* win = NULL;

static ULONG windowSignal;
 

static struct TagItem tags[] =
{
	{WA_CustomScreen, 0},
	{WA_Left, 0},
	{WA_Top, 0},
	{WA_InnerWidth, 0},
	{WA_InnerHeight, 0},
	{WA_Activate, TRUE},
	{WA_GimmeZeroZero, TRUE},
	{WA_Borderless, TRUE},
	{WA_Backdrop, TRUE},
	{WA_NoCareRefresh, TRUE},
	{WA_IDCMP, IDCMP_RAWKEY},
	{WA_Flags, WFLG_SUPER_BITMAP},
	{WA_RMBTrap, TRUE},
	{TAG_END, TAG_END},
};

/*--------------------------------------------------------------------------*/

int WindowOpen(void)
{
	struct Dimension* dim = CfgGetDimension(); 

	WindowSetTag(WA_CustomScreen, (ULONG)ScreenGet());
	WindowSetTag(WA_InnerWidth, dim->width);
	WindowSetTag(WA_InnerHeight, dim->height);

	win = OpenWindowTagList(NULL, tags);

	if (NULL == win)
	{
		return RETURN_FAIL;
	}

	return RETURN_OK;
}

/*--------------------------------------------------------------------------*/

void WindowClose(void)
{
	if (win)
	{
		CloseWindow(win);
	}
}

/*--------------------------------------------------------------------------*/

static void WindowSetTag(Tag name, Tag value)
{
	struct TagItem* item = FindTagItem(name, tags);

	if (item)
	{
		item->ti_Data = value;
	}
}

/*--------------------------------------------------------------------------*/

void WindowProcessInputs(void)
{
	struct IntuiMessage *msg;

	while (TRUE)
	{
		msg = (struct IntuiMessage *)GetMsg(win->UserPort);

		if (NULL == msg)
		{
			break;
		}

		ReplyMsg((struct Message *)msg);

		InputSetKeys(msg->Code);
	}
}

/*--------------------------------------------------------------------------*/

ULONG WindowGetSignal(void)
{
	return 1L << win->UserPort->mp_SigBit;
}

/*--------------------------------------------------------------------------*/
