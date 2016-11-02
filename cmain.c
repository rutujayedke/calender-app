/**
* Calender program.
*
* Copyright(C) 2016 RBY_8079 . rutujayedke1997@gmail.com
*
* This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by     Free Software Foundation; either version 2 of the Lincense, or any later version. 
* 
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of 
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
*
* You should have received a copy of GNU Lesser General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 51 Franklin street, Fifth Floor, Boston MA 02110-1301, USA.
**/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses.h>
#include<time.h>
#include<errno.h>
#include"calender.h"
#define TRUE 1
#define MAX 128
int monthday[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *monthname[]={"January","February","March","April","May","June","July",
		"August","September","October","November","Decembeer"};

int usage(){
	printf ("usage: ./project\n");
}
int main(int argc, char *argv[]){
	//if(strcmp(argv[1], "-h") == 0){
	//	return usage();
	//}
	initscr();
	cbreak();
	int row, col;
	getmaxyx(stdscr, row, col);
	char text[] = "!!!  CALENDER  !!!";
	int monthday[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	char *monthname[]={"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
                           "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER",
                           "DECEMBER"};
	int month, year,i,j,k,z,keycode;
	int ch;

top: {
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        attron(A_BOLD);
        mvprintw(0, col / 2, "%s", text);
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
      }
	keypad(stdscr, TRUE);
	curs_set(TRUE);
	while(TRUE){
		fflush(stdin);
		mvprintw(1, 0, "Enter MM YYYY (e.g 10 2016)\n", row, col);
		scanw("%d %d", &month, &year);
		refresh();
		mvprintw(2, 0, "%d %d", month, year);
		refresh();
		if(year < 0){
			printw("Enter Valid Year\n");
		continue;
		}
		if(month < 1 || month > 12){
			printw("Enter Valid Month\n");
			row++;
			col++;
			continue;
		}
	break;
	}
	while(1){
		clear();
	
		z = firstday_month( 1,  month, year);
		if(z == 0) {
			 z = 7;
		}
	 init_pair(1, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        attron(A_BOLD);
        mvprintw(0, col / 2, "%s", text);
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));

    	time_t current_time;
    	char* c_time_string;

    	/* Obtain current time. */
    	current_time = time(NULL);

    	if (current_time == ((time_t)-1)){
        	(void) fprintf(stderr, "Failure to obtain the current time.\n");
        	exit(EXIT_FAILURE);
    	}

    	/* Convert to local time format. */
    	c_time_string = ctime(&current_time);

   	if (c_time_string == NULL){
        	(void) fprintf(stderr, "Failure to convert the current time.\n");
        	exit(EXIT_FAILURE);
   	}

    	/* Print to stdout. ctime() has already added a terminating newline character. */
	attron(A_BOLD);    	
	(void) printw("\nToday - %s", c_time_string);
	refresh();
        attroff(A_BOLD);
    	//exit(EXIT_SUCCESS);

	printw("\n\n\t\t\t");
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        attron(A_BOLD);
        printw("%s %d\n", monthname[month - 1], year);
	refresh(); 
	attroff(A_BOLD);
        attroff(COLOR_PAIR(1));

	if(check_LeapYear == 1){
		monthday[1] = 29;
	}
	else
		monthday[1] = 28;

	attron(A_BOLD);
	printw("\n\n\t");
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	printw("SUN");
	refresh();
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(5));
	printw("	MON	TUE	WED	THU	FRI	SAT\n");
	refresh();
	attroff(COLOR_PAIR(5));
	attroff(A_BOLD);
	
	
		j = z;
		while( z != 1) {
			printw("\t-");
			z-- ;
		}
			
		k=0;

	start_color();
	attron(A_BOLD);
	for(i = 1; i<= monthday[month - 1]; i++){
		k = j % 7 + 1;

		j++;
		if(k == 2){
			printw("\n\n\t");
			printw("%2d", i);
			refresh();
		}
		else{
			printw("	%2d",i);
			refresh();
		}
	
	}
	attroff(A_BOLD);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(4));
	mvprintw(22, 0, "#", row, col);
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(3));
	mvprintw(22, 3, "use LEFT & RIGHT arrow to change MONTH", row, col);
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
        mvprintw(23, 0, "#", row, col);
        attroff(COLOR_PAIR(4));
        attron(COLOR_PAIR(3));
        mvprintw(23, 3, "use UP & DOWN arrow to change YEAR", row, col);
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
        mvprintw(24, 0, "#", row, col);
        attroff(COLOR_PAIR(4));
        attron(COLOR_PAIR(3));
        mvprintw(24, 3, "press N for NEW INPUT ", row, col);
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
        mvprintw(25, 0, "#", row, col);
        attroff(COLOR_PAIR(4));
        attron(COLOR_PAIR(3));
        mvprintw(25, 3, "press A to ADD NOTES", row, col);
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
        mvprintw(26, 0, "#", row, col);
        attroff(COLOR_PAIR(4));
        attron(COLOR_PAIR(3));
        mvprintw(26, 3, "press S to SHOW NOTES", row, col);
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
        mvprintw(27, 0, "#", row, col);
        attroff(COLOR_PAIR(4));
        attron(COLOR_PAIR(3));
        mvprintw(27, 3, "press ESC to EXIT", row, col);
	attroff(COLOR_PAIR(3));



	keycode = getkey();
	if(keycode == 261){
		month++;
		if(month > 12){
			month = 1;
			year++;
		}
	}
	if(keycode == 260){
		month--;
		if(month < 1){
			month = 12;
			year--;
		}	
	}
	if(keycode == 259){
		year++;
	}
	if(keycode == 258){
		year--;	
	}
	if(keycode == 78){
		clear();
		echo();
		goto top;
	
	}
	if(keycode == 65){
		clear();	
		echo();
		Addnote();	
	}
	if(keycode == 83){
		showNote(month);

	}
	
	}
	exit(0);
	refresh();
	getch();
	endwin();
	return 0;
}


