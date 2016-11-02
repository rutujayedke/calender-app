/**
* Calender program.
*
* Copyright(C) 2016 RBY_8079. rutujayedke1997@gmail.com
*
* This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by     * Free Software Foundation; either version 2 of the Lincense, or any later version.
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
#include"calender.h"
#include<ncurses.h>
int check_LeapYear(int year){
	if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){
		return 1;
	}
	return 0;
}

int month_table(int date, int month, int year){
	int Leap, nmonth;
	if(check_LeapYear == '1')
		Leap = 1;
	else
		Leap = 0;
	nmonth = 3 + (2 - Leap) * ((month + 2) / (2 * month)) + (5 * month + month / 9) / 2;
	nmonth = nmonth % 7;
	return nmonth;
}

int firstday_month(int date, int month, int year){
	int fday, y, century;
	century = year / 100;
	y = year % 100;
	fday = (5 * y) / 4 + month_table(date, month, year) + date - 2 * (century % 4);
	fday = fday % 7;
	return fday;
}

void printchar(char c){
	int i;
	printw("\n\t");
	for(i = 0; i<= 51; i++){
		printw("%c", c);
		printw("%c", c);
	}
	printw("\n");
}
int getkey(){
	int ch;
	keypad(stdscr, TRUE);
	ch = getch();
	noecho();
	if(ch == 27){
		endwin();
		exit(0);
		return 27; 	 //ESC
	}
	
	if(ch == 78)		
		return 78;	// new input 
	if(ch == 261)
		return 261; 	// right arrow 
	if(ch == 259)
		return 259; 	// up arrow 
	if(ch == 260)
		return 260;  	// left arrow
	if(ch == 258)
		return 258; 	// down arrow
	else 
 		return 0;
	if(ch == 65)			
		return 65;	//Add note
	if(ch == 83)		
		return 83;	//show note
}

void Addnote(){
	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;
	WINDOW *create_newwin(int height, int width, int starty, int startx);
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	height = 3;
	width = 10;
	starty = (LINES -height) / 2;
	startx = (COLS - width) / 2;
	printw("Press F1 to exit");
	refresh();
	//my_win = create_newwin(height, width, starty, startx);	
	FILE *fp;
	int x;
	int scr_dump
	(const char *fp);

	int scr_init
	(const char *fp);
	
	fp = fopen("Note.txt", "a");
	printw("Enter the DD-MM");
	scanw("%d %d", &R.dd, &R.mm);
	printw("%d %d", R.dd, R.mm);
	printw("Enter the Note:");
	fflush(stdin);
	scanw("%s", R.note);
	if(x = fwrite(&R, sizeof(R),1,fp)){
		printw("Note saved successfully");
		fclose(fp);
	}
	else
		printw("Fail to save");

	fclose(fp);
}

void showNote(int mm){
	int scr_restore
	(const char *fp);

	int scr_set
	(const char *fp);


	FILE *fp;
	int i = 0, isFound = 0;
	fp = fopen("note.txt","r");
    	if(fp == NULL){
        printw("Error in opening the file");
    	}
    	while(fread(&R,sizeof(R),1,fp) == 1){
        	if(R.mm == mm){
         	printw("Note %d Day = %d: %s", i+1, R.dd,  R.note);
            	isFound = 1;
            	i++;
        	}
    	}
    	if(isFound == 0){
        	printw("This Month contains no note");
    	}
}

