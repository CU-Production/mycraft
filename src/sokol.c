#if WIN32
#define SOKOL_D3D11
#else
#define SOKOL_GLCORE
#endif
#define SOKOL_IMPL
#define SOKOL_NO_ENTRY
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_log.h"
#include "sokol_time.h"
#include "sokol_glue.h"