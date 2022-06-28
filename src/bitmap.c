#include "bitmap.h"

#include "cfg.h"


#include <proto/graphics.h>

static struct BitMap* bitmapOne = NULL; 
static struct BitMap* bitmapTwo = NULL; 

/*--------------------------------------------------------------------------*/

int BitmapsAllocate(void)
{
	struct Dimension *dim = CfgGetDimension();

	bitmapOne = BitmapDisplayable(dim);

	if (NULL == bitmapOne)
	{
		return RETURN_FAIL;
	}

	bitmapTwo = BitmapDisplayable(dim);

	if (NULL == bitmapTwo)
	{
		return RETURN_FAIL;
	}

	return RETURN_OK;
}

/*--------------------------------------------------------------------------*/

void BitmapsFree(void)
{
	BitmapFree(bitmapOne);
	BitmapFree(bitmapTwo);
}

/*--------------------------------------------------------------------------*/

struct BitMap* BitmapDisplayable(struct Dimension* dim)
{
	const ULONG flags = BMF_CLEAR | BMF_DISPLAYABLE | BMF_INTERLEAVED;

	return AllocBitMap(dim->width, dim->height, dim->depth, flags, NULL);
}

/*--------------------------------------------------------------------------*/

void BitmapFree(struct BitMap* bm)
{
	FreeBitMap(bm);
}

/*--------------------------------------------------------------------------*/

struct BitMap* BitmapGetOne(void)
{
	return bitmapOne;
}

/*--------------------------------------------------------------------------*/

struct BitMap* BitmapGetTwo(void)
{
	return bitmapTwo;
}

/*--------------------------------------------------------------------------*/
