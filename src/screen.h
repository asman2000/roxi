#ifndef ROXI_SCREEN_H
#define ROXI_SCREEN_H
/*--------------------------------------------------------------------------*/

#include "types.h"


int ScreenOpen(void);
void ScreenClose(void);

struct Screen* ScreenGet(void);

/*--------------------------------------------------------------------------*/
#endif /* ROXI_SCREEN_H */
