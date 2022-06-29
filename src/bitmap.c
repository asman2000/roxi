#include "bitmap.h"

#include "cfg.h"

#include <proto/graphics.h>

static struct BitMap* bitmaps[2];
/*--------------------------------------------------------------------------*/

int BitmapsAllocate(void)
{
	UWORD i;
	struct Dimension *dim = CfgGetDimension();

	for (i = 0; i < ARRAY_SIZE(bitmaps); ++i)
	{
		bitmaps[i] = NULL;
	}

	for (i = 0; i < ARRAY_SIZE(bitmaps); ++i)
	{
		bitmaps[i] = BitmapDisplayable(dim);

		if (NULL == bitmaps[i])
		{
			return RETURN_FAIL;
		}
	}

	return RETURN_OK;
}

/*--------------------------------------------------------------------------*/

void BitmapsFree(void)
{
	UWORD i;

	for (i = 0; i < ARRAY_SIZE(bitmaps); ++i)
	{
		BitmapFree(bitmaps[i]);
	}
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

struct BitMap** BitmapsGet(void)
{
	return bitmaps;
}

/*--------------------------------------------------------------------------*/
