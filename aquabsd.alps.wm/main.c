#include <aquabsd.alps.wm/private.h>
#include <aquabsd.alps.wm/functions.h>

typedef enum {
	CMD_CREATE       = 0x6377, // 'cw'
	CMD_DELETE       = 0x6477, // 'dw'

	CMD_GET_ROOT_WIN = 0x7277, // 'rw'

	CMD_REGISTER_CB  = 0x7263, // 'rc'
} cmd_t;

int load(
	uint64_t (*_kos_query_device) (uint64_t, uint64_t name),
	void* (*_kos_load_device_function) (uint64_t device, const char* name),
	uint64_t (*_kos_callback) (uint64_t callback, int argument_count, ...)) {

	kos_query_device = _kos_query_device;
	kos_load_device_function = _kos_load_device_function;
	kos_callback = _kos_callback;

	uint64_t win_device = kos_query_device(0, (uint64_t) "aquabsd.alps.win");

	if (win_device == -1) {
		return -1; // we cannot possibly function without the 'aquabsd.alps.win' device
	}

	aquabsd_alps_win_create_setup = kos_load_device_function(win_device, "create_setup");
	aquabsd_alps_win_delete = kos_load_device_function(win_device, "delete");
	aquabsd_alps_win_set_caption = kos_load_device_function(win_device, "set_caption");

	return 0;
}

uint64_t send(uint16_t _cmd, void* data) {
	cmd_t cmd = _cmd;
	uint64_t* args = data;

	if (cmd == CMD_CREATE) {
		return (uint64_t) create();
	}

	else if (cmd == CMD_DELETE) {
		wm_t* wm = (void*) args[0];
		return delete(wm);
	}

	else if (cmd == CMD_GET_ROOT_WIN) {
		wm_t* wm = (void*) args[0];
		return (uint64_t) get_root_win(wm);
	}

	else if (cmd == CMD_REGISTER_CB) {
		wm_t* wm = (void*) args[0];
		cb_t type = args[1];

		uint64_t cb = args[2];
		uint64_t param = args[3];

		return register_cb(wm, type, cb, param);
	}
	
	return -1;
}
