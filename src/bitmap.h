#ifndef ROXI_BITMAP_H
#define ROXI_BITMAP_H
/*--------------------------------------------------------------------------*/

#include "types.h"

int BitmapsAllocate(void);
void BitmapsFree(void);

struct BitMap* BitmapDisplayable(struct Dimension* dim);

void BitmapFree(struct BitMap* bm);

struct BitMap** BitmapsGet(void);


/*--------------------------------------------------------------------------*/
#endif /* ROXI_BITMAP_H */
