// includes
#include "../colors/colors_1.c"
// global variables
#include "../global/vars_1.h"
#include "../global/screen_size.h"

// the clear terminal function
void clear_terminal() {
	unsigned int i = 0;
	// loop through from 0xb8000 till 0xb8000+(80 * 25 * 2) and set every second byte to ' ', and the middle bytes to the color byte
	while (i < (x_display * y_display * double_)) {
		vidmem[i] = ' ';
		i++;
		vidmem[i] = TEXT_COLOR;
		i++;
	};
};