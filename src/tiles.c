#include "tiles.h"

#include "cfg.h"
#include "screen.h"
#include "screenFrame.h"

#include <dos/dos.h>
#include <graphics/gfx.h>

#include <proto/graphics.h>

/*--------------------------------------------------------------------------*/

static struct BitMap* bitmap = NULL;

static struct RastPort* rp = NULL;

static void TilesInit(void);

/*--------------------------------------------------------------------------*/

int TilesOpen(void)
{
	const ULONG flags = BMF_CLEAR | BMF_INTERLEAVED;

	const ULONG depth = CfgGetDimension()->depth;

	bitmap = AllocBitMap(16, 16, depth, flags, NULL);

	if (NULL == bitmap)
	{
		return RETURN_FAIL;
	}

	rp = ScreenFrameGetRastPort();

	TilesInit();

	return RETURN_OK;
}

/*--------------------------------------------------------------------------*/

static void TilesInit(void)
{
	UWORD i = 0;
	UWORD* first = (UWORD*)bitmap->Planes[0];

	for (i = 0; i < 16; ++i)
	{
		*first = 0xffff;
		first += bitmap->BytesPerRow >> 1;
	}
}

/*--------------------------------------------------------------------------*/

void TilesClose(void)
{
	FreeBitMap(bitmap);
}

/*--------------------------------------------------------------------------*/

void TilesDraw(void)
{
	BltBitMapRastPort(bitmap, 0, 0, rp, 0, 0, 16, 16, 0xc0);
}

/*--------------------------------------------------------------------------*/
