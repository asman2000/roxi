#ifndef ROXI_BITMAP_H
#define ROXI_BITMAP_H
/*--------------------------------------------------------------------------*/

#include "types.h"

struct BitMap* BitmapDisplayable(struct Dimension* dim);

void BitmapFree(struct BitMap* bm);

/*--------------------------------------------------------------------------*/
#endif /* ROXI_BITMAP_H */
