#include <assert.h>
#include <stdlib.h>
#include <uvm/graphics.h>
#include <uvm/syscalls.h>
#include <uvm/utils.h>


#define FRAME_WIDTH 400
#define FRAME_HEIGHT 400

u32 frame_buffer[160000];

// Current mouse pointer position
size_t pos_x = 200;
size_t pos_y = 200;

#define NUM_LINES 40
u32 starts[FRAME_WIDTH];
u32 lengths[FRAME_WIDTH];

void init_lines()
{
    for (u32 i = 0; i < NUM_LINES; ++i) {
        u32 j = i + 1;
        starts[i] = 50 - (j >> 1);
        lengths[i] = j + (j >> 1);
    }
}

void copy_lines(
    u32* fb, u32 fb_width,
    u32 y,
    u32 number_of_lines,
    u32* starts,
    u32* lengths,
    u32 color
)
{
	u32* dst = fb + fb_width * y;
    for (u32 i = 0; i < number_of_lines; ++i) {
        memset32(dst + starts[i], color, lengths[i]);
        dst = dst + fb_width;
    }
}


void
mousemove(u64 window_id, u64 new_x, u64 new_y)
{
	// Update the mouse position
	pos_x = new_x;
	pos_y = new_y;
}


void anim_callback()
{
	// Grey background.
	memset(frame_buffer, 0x7f, sizeof(frame_buffer));

	for (u32 y = pos_y; y < FRAME_HEIGHT - 23; ++y) {
        memset32(
            *(frame_buffer + FRAME_WIDTH * y + pos_x),
            (y & 1) ? COLOR_GREEN : COLOR_BLUE,
            FRAME_WIDTH - pos_x
            );
	}
    copy_lines(
        frame_buffer, FRAME_WIDTH,
        23,
        NUM_LINES, starts, lengths,
        COLOR_MAGENTA);

	window_draw_frame(0, frame_buffer);

	time_delay_cb(10, anim_callback);
}

void main()
{
	window_create(FRAME_WIDTH, FRAME_HEIGHT, "Convex Polygon Example", 0);

    init_lines();
	window_on_mousemove(0, mousemove);

	time_delay_cb(0, anim_callback);

	enable_event_loop();
}
