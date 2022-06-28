#include "screen.h"

#include "bitmap.h"
#include "cfg.h"

#include <dos/dos.h>
#include <intuition/intuition.h>


#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/utility.h>


static void ScreenSetTag(Tag name, Tag value);

/*--------------------------------------------------------------------------*/

static struct Screen* scr = NULL;

static struct BitMap* bitmap = NULL; 

static struct TagItem tags[] =
{
	{SA_BitMap, 0},
	{SA_Width, 0},
	{SA_Height, 0},
	{SA_Depth, 0},
	{SA_DisplayID, LORES_KEY},
	{SA_Left, 0},
	{SA_Top, 0},
	{SA_Type, CUSTOMSCREEN | CUSTOMBITMAP},
	{SA_Quiet, TRUE},
	{TAG_DONE, TAG_END},
};

/*--------------------------------------------------------------------------*/

int ScreenOpen(void)
{
	struct Dimension *dim = CfgGetDimension();

	bitmap = BitmapDisplayable(dim); 

	if (NULL == bitmap)
	{
		return RETURN_FAIL;
	}

	ScreenSetTag(SA_BitMap, (ULONG)bitmap); 
	ScreenSetTag(SA_Width, dim->width);
	ScreenSetTag(SA_Height, dim->height);
	ScreenSetTag(SA_Depth, dim->depth);

	scr  = OpenScreenTagList(NULL, tags);

	if (NULL == scr)
	{
		return RETURN_FAIL;
	}


	return RETURN_OK;
}

/*--------------------------------------------------------------------------*/

void ScreenClose(void)
{
	if (scr)
	{
		CloseScreen(scr);
	}
	
	FreeBitMap(bitmap);
}

/*--------------------------------------------------------------------------*/

ULONG ScreenGetAddress(void)
{
	return (ULONG)scr;
}

/*--------------------------------------------------------------------------*/

struct RastPort* ScreenGetRastPort(void)
{
	return &scr->RastPort;
}

/*--------------------------------------------------------------------------*/

static void ScreenSetTag(Tag name, Tag value)
{
	struct TagItem* item = FindTagItem(name, tags);

	if (item)
	{
		item->ti_Data = value;
	}
}

/*--------------------------------------------------------------------------*/
