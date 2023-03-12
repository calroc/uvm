#include <stdlib.h>
#include <uvm/syscalls.h>
#include <uvm/utils.h>
#include <uvm/graphics.h>
#include "examples/sine.h"

size_t FRAME_WIDTH = 512;
size_t FRAME_HEIGHT = 512;
u32 frame_buffer[262144];

int wid;  // Window ID.

// Current mouse pointer position
size_t pos_x = 200;
size_t pos_y = 200;


void
keydown(u64 window_id, u16 keycode)
{
	if (KEY_ESCAPE == keycode) {
		exit(0);
	}
	/*if (KEY_BACKSPACE == keycode) {*/
	/*} else if (KEY_TAB == keycode) {*/
	/*} else if (KEY_RETURN == keycode) {*/
	/*} else if (KEY_SPACE == keycode) {*/
	/*} else if (KEY_NUM0 == keycode) {*/
	/*} else if (KEY_NUM1 == keycode) {*/
	/*} else if (KEY_NUM2 == keycode) {*/
	/*} else if (KEY_NUM3 == keycode) {*/
	/*} else if (KEY_NUM4 == keycode) {*/
	/*} else if (KEY_NUM5 == keycode) {*/
	/*} else if (KEY_NUM6 == keycode) {*/
	/*} else if (KEY_NUM7 == keycode) {*/
	/*} else if (KEY_NUM8 == keycode) {*/
	/*} else if (KEY_NUM9 == keycode) {*/
	/*} else if (KEY_A == keycode) {*/
	/*} else if (KEY_B == keycode) {*/
	/*} else if (KEY_C == keycode) {*/
	/*} else if (KEY_D == keycode) {*/
	/*} else if (KEY_S == keycode) {*/
	/*} else if (KEY_W == keycode) {*/
	/*} else if (KEY_LEFT == keycode) {*/
	/*} else if (KEY_RIGHT == keycode) {*/
	/*} else if (KEY_UP == keycode) {*/
	/*} else if (KEY_DOWN == keycode) {*/
	/*} else if (KEY_SHIFT == keycode) {*/
	/*}*/
	/*print_i64(keycode);*/
	/*print_endl();*/
}


void
mousedown(u64 window_id, u8 btn_id)
{
	window_draw_frame(window_id, frame_buffer);
}


void
mousemove(u64 window_id, u64 new_x, u64 new_y)
{
	// Update the mouse position
	pos_x = new_x;
	pos_y = new_y;
}


void
anim_callback()
{
	u32 *d = frame_buffer;
	for (u64 x = 0; x < 0x10001; ++x) {
		u64 j = (FRAME_WIDTH - 1) * sine_table[0x10000 - x] >> 32;
		u64 s = (FRAME_HEIGHT - 1) * sine_table[x] >> 32;
		/*u8 n = (u8)rand();*/
		*(d + j + s * FRAME_WIDTH) = 0xFFFFFF;
	}
	window_draw_frame(0, frame_buffer);
	time_delay_cb(33, anim_callback);
}

void
main()
{
	srand(23);
	wid = window_create(FRAME_WIDTH, FRAME_HEIGHT, "Xerblin", 0);
	// Grey background.
	memset(frame_buffer, 0x7f, sizeof(frame_buffer));
	window_draw_frame(wid, frame_buffer);
	window_on_keydown(wid, keydown);
	window_on_mousedown(wid, mousedown);
	window_on_mousemove(wid, mousemove);

	time_delay_cb(0, anim_callback);
	enable_event_loop();
}
