#ifndef ROXI_INPUT_H
#define ROXI_INPUT_H
/*--------------------------------------------------------------------------*/

#include <exec/types.h>

void InputInit(void);

void InputSetKeys(UWORD msgCode);
BOOL InputIsExitToOsPressed(void);

/*--------------------------------------------------------------------------*/
#endif /* ROXI_INPUT_H */
