#include "cfg.h"

#include <graphics/modeid.h>

#include <proto/intuition.h>


struct Cfg
{
	struct Dimension dim;
	ULONG displayId;
};

static struct Cfg cfg;

/*--------------------------------------------------------------------------*/

void CfgInit(void)
{
	cfg.dim.width = 320;
	cfg.dim.height = 256;
	cfg.dim.depth = 3;
	cfg.displayId = LORES_KEY;
}

/*--------------------------------------------------------------------------*/

struct Dimension* CfgGetDimension(void)
{
	return &cfg.dim;
}

/*--------------------------------------------------------------------------*/

ULONG CfgGetDisplayId(void)
{
	return cfg.displayId;
}

/*--------------------------------------------------------------------------*/
