#include "screenFrame.h"

#include "bitmap.h"
#include "screen.h"

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <proto/intuition.h> 

struct Frame
{
	struct ScreenBuffer* sbuf;
	struct MsgPort* mport;
	ULONG signal;
	int counter;
};

static struct Frame frames[2];
static ULONG currentFrame;

static struct RastPort rp;
/*--------------------------------------------------------------------------*/

int ScreenFrameOpen(void)
{
	WORD i;
	struct BitMap** bitmaps = BitmapsGet();

	InitRastPort(&rp);
	rp.BitMap = *bitmaps;

	for (i = 0; i < 2; ++i)
	{
		frames[i].mport = NULL;
		frames[i].sbuf = NULL;
	}

	for (i = 0; i < 2; ++i)
	{
		struct Frame* fr = &frames[i];

		fr->mport = CreateMsgPort();

		if (NULL == fr->mport)
		{
			return RETURN_FAIL;
		}

		fr->sbuf = AllocScreenBuffer(ScreenGet(), *bitmaps++, 0);

		if (NULL == fr->sbuf)
		{
			return RETURN_FAIL;
		}

		fr->signal = 1L << fr->mport->mp_SigBit;
		fr->counter = 0;
	}

	for (i = 0; i < 2; ++i)
	{
		frames[i].sbuf->sb_DBufInfo->dbi_SafeMessage.mn_ReplyPort = frames[0].mport;
		frames[i].sbuf->sb_DBufInfo->dbi_DispMessage.mn_ReplyPort = frames[1].mport;
	}

	currentFrame = 0; 

	return RETURN_OK;
}

/*--------------------------------------------------------------------------*/

void ScreenFrameClose(void)
{
	WORD i;

	for (i = 0; i < 2; ++i)
	{
		struct Frame* fr = &frames[i];

		while (0 != fr->counter)
		{
			fr->counter--;
			
			GetMsg(fr->mport);

			if (0 != fr->counter)
			{
				Wait(fr->signal);
			}
		}

		FreeScreenBuffer(ScreenGet(), fr->sbuf);
		DeleteMsgPort(fr->mport);
	} 
}

/*--------------------------------------------------------------------------*/

void ScreenFrameSwap(void)
{
	WaitBlit();
	ChangeScreenBuffer(ScreenGet(), frames[currentFrame].sbuf);
	currentFrame ^= 1;
	frames[0].counter++;
	frames[1].counter++;
}

/*--------------------------------------------------------------------------*/

ULONG ScreenFrameGetDispSignal(void)
{
	return frames[1].signal;
}

/*--------------------------------------------------------------------------*/

ULONG ScreenFrameGetSafeSignal(void)
{
	return frames[0].signal;
}

/*--------------------------------------------------------------------------*/

void ScreenFrameProcessSafe(void)
{
	frames[0].counter--;
	GetMsg(frames[0].mport);
	rp.BitMap = frames[currentFrame].sbuf->sb_BitMap; 
}

/*--------------------------------------------------------------------------*/

void ScreenFrameProcessDisp(void)
{
	frames[1].counter--;

	GetMsg(frames[1].mport);

	ScreenFrameSwap();
}

/*--------------------------------------------------------------------------*/

struct RastPort* ScreenFrameGetRastPort(void)
{
	return &rp;
}

/*--------------------------------------------------------------------------*/
