#define dynamic

#include <aquabsd.alps.win/public.h>

static uint64_t (*kos_query_device) (uint64_t, uint64_t name);
static void* (*kos_load_device_function) (uint64_t device, const char* name);
static uint64_t (*kos_callback) (uint64_t callback, int argument_count, ...);

static uint64_t mouse_device = -1;
static uint64_t kbd_device = -1;

#define _NET_WM_STATE_REMOVE AQUABSD_ALPS_WIN__NET_WM_STATE_REMOVE
#define _NET_WM_STATE_ADD    AQUABSD_ALPS_WIN__NET_WM_STATE_ADD
#define _NET_WM_STATE_TOGGLE AQUABSD_ALPS_WIN__NET_WM_STATE_TOGGLE

#define cb_t aquabsd_alps_win_cb_t

#define CB_DRAW AQUABSD_ALPS_WIN_CB_DRAW
#define CB_LEN  AQUABSD_ALPS_WIN_CB_LEN

#define state_t aquabsd_alps_win_state_t

#define STATE_REGULAR    AQUABSD_ALPS_WIN_STATE_REGULAR
#define STATE_TRANSIENT  AQUABSD_ALPS_WIN_STATE_TRANSIENT
#define STATE_FULLSCREEN AQUABSD_ALPS_WIN_STATE_FULLSCREEN
#define STATE_LEN        AQUABSD_ALPS_WIN_STATE_LEN

#define win_t aquabsd_alps_win_t
