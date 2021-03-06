#include "gx2.h"
#include "gx2r_resource.h"

static wfunc_ptr<p32<void>, GX2RResourceFlags, uint32_t, uint32_t>
pGX2RMemAlloc;

static wfunc_ptr<void, GX2RResourceFlags, p32<void>>
pGX2RMemFree;

void
GX2RSetAllocator(GX2RAllocFuncPtr allocFn, GX2RFreeFuncPtr freeFn)
{
   pGX2RMemAlloc = allocFn;
   pGX2RMemFree = freeFn;
}

void
GX2::registerResourceFunctions()
{
   RegisterKernelFunction(GX2RSetAllocator);
}
