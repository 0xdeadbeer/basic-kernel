// includes
// colors
#include "../colors/colors_1.c"
// variables
#include "../global/vars_1.h"
#include "../global/screen_size.h"



// move down function - delete the first row and move the rest of the rows up by one
void move_down() {
	// delete the first row - set every second byte on the first line to 0x0 / ' '
	for (int first_line_char = 0; first_line_char < (x_display*2)+1; first_line_char++) {
		vidmem[first_line_char] = 0x0;
		first_line_char++;
	}

	// loop through all the cells in the rest of the lines 
	// and for each cell that's located one line above the current one, set its value 
	// to the value of the current one ( we're moving a value from a cell to a cell that's 1 line above basically )
	for (int cell = 0; cell < (x_display * y_display * double_)+1; cell++) {
		if (cell >= (x_display * double_)){
			vidmem[cell-(x_display*double_)-2] = vidmem[cell];
		};
	}

	// delete the last row - set every second byte on the last row to 0x0 
	for (int cell = (x_display * y_display * double_)-(x_display*double_); cell < (x_display * y_display * double_); cell++) {
		vidmem[cell] = 0x0;
		cell++;
	}

}

// find available line function
int find_available_line() {
	// if we're on the 25th line - the last line then 
	// call the move_down() function and decrement the 
	// access_line variable and return its value
	// else.. well theres no else, it will just skip 
	// the if and return directly the value
	if (access_line == y_display) { move_down(); access_line-=1;}
	return (access_line);
}

// sysout_line function - its like print in python (output something with an auto break line at the end)
void sysout_line(char *message) {

	// firstly find the location of the highest 
	// possible line that we can use and fill up with information
	int available_line = (find_available_line(x_display, y_display, double_) * x_display * double_)+access_column*double_;

	// while loop, basically loop through the whole message 
	// and set every second byte of information its char and every
	// middle byte the chars property - text color 
	while (*message != 0) {
		vidmem[available_line] = *message;
		*message++;
		available_line++;
		vidmem[available_line] = TEXT_COLOR;
		available_line++;
	};

	// if we're not on the last line you can increment access_line
	if (access_line < y_display) { access_line++; }

	// set access_column to 0 just to be sure the next message will be centered on left
	access_column = 0;
}

// sysout function - its like print in python but without the break at the end thing, 
// while using this function don't expect an autobreak at the end
void sysout(char *message) {
	// firstly find the highest line that we can use !! + the column we must use at the beginning 
	// and fill with useful information
	int available_line = (find_available_line(x_display, y_display, double_) * x_display * double_)+access_column*double_;

	// while loop, basically loop through the whole message 
	// and set every second byte of information its char and every
	// middle byte the chars property - text color 
	while (*message != 0) {
		vidmem[available_line] = *message;
		*message++;
		available_line++;
		vidmem[available_line] = TEXT_COLOR;
		available_line++;
		
		// increment the access column
		access_column += 1; 
	};
}