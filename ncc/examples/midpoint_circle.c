#include <stdlib.h>
#include <uvm/syscalls.h>
#include <uvm/utils.h>
#include <uvm/graphics.h>


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
	if (KEY_ESCAPE == keycode) exit(0);
}


void
mousemove(u64 window_id, u64 new_x, u64 new_y)
{
	// Update the mouse position
	pos_x = new_x;
	pos_y = new_y;
}


void
draw_points(u32* fb, u32 fb_width, u32 center_x, u32 center_y, u32 x, u32 y, u32 color)
{
	*(fb + (center_x + x) + (center_y + y) * fb_width) = color;
	*(fb + (center_x - x) + (center_y + y) * fb_width) = color;
	*(fb + (center_x + x) + (center_y - y) * fb_width) = color;
	*(fb + (center_x - x) + (center_y - y) * fb_width) = color;
}

void
draw_circle(u32* fb, u32 fb_width, u32 center_x, u32 center_y, u32 radius, u32 color)
{
	u64 length = 1 + (((u64)radius * 0xb504f334) >> 32);
	// 0xb504f334 == round(0x100000000 * cos(pi/4))
	u32 y = radius;
	u64 y_squared = radius * radius;
	u64 twice_y = (y << 1) - 1;
	u64 y_squared_new = y_squared + 3;
	for (u64 x = 0; x <= length; ++x) {
		y_squared_new = y_squared_new - ((x << 1) - 3);
		if ((y_squared >= y_squared_new) && ((y_squared - y_squared_new) >= twice_y)) {
			--y;
			y_squared = y_squared - twice_y;
			twice_y = twice_y - 2;
		}
		draw_points(fb, fb_width, center_x, center_y, x, y, color);
		draw_points(fb, fb_width, center_x, center_y, y, x, color);
	}

}

void
anim_callback()
{
	// Grey background.
	memset(frame_buffer, 0x7f, sizeof(frame_buffer));

	// Center
	size_t fw = FRAME_WIDTH >> 1;
	size_t fh = FRAME_HEIGHT >> 1;

	for (u32 radius = 10; radius < 201; radius = radius + 5) {
		draw_circle(frame_buffer, FRAME_WIDTH, fw, fh, radius, rgb32(radius, radius, radius));
	}
	draw_circle(frame_buffer, FRAME_WIDTH, fw, fh, 210, COLOR_GREEN);
	draw_circle(frame_buffer, FRAME_WIDTH, fw, fh, 220, COLOR_BLUE);

	window_draw_frame(0, frame_buffer);
	time_delay_cb(33, anim_callback);
}


/*
	u32 increment = 0x10000 / (1 + pos_x);
	for (u32 angle = 0; angle < 0x10001; angle = angle + increment)
	{
		u64 c = cosine(fw - 10, angle);
		u64 s = sine(fh - 10, angle);
		*(d + (fw + c) + (fh + s) * FRAME_WIDTH) = COLOR_MAGENTA;  // lower right
		*(d + (fw - c) + (fh + s) * FRAME_WIDTH) = COLOR_GREEN;    // lower left
		*(d + (fw + c) + (fh - s) * FRAME_WIDTH) = COLOR_TURQUOISE;// upper right
		*(d + (fw - c) + (fh - s) * FRAME_WIDTH) = COLOR_YELLOW;   // upper left
	}
*/


void
main()
{
	srand(23);
	wid = window_create(FRAME_WIDTH, FRAME_HEIGHT, "Xerblin", 0);
	window_draw_frame(wid, frame_buffer);
	window_on_keydown(wid, keydown);
	window_on_mousemove(wid, mousemove);
	time_delay_cb(0, anim_callback);
	enable_event_loop();
}
