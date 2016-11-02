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



#define MAX 128
typedef struct Remainder{
	int dd;
	int mm;
	char note[MAX];
}Remainder;
struct Remainder R;


int check_LeapYear(int year);
int month_table(int date, int month, int year);
int firstday_month(int date, int month, int year);
int getkey();
void Addnote();
void showNote(int mm);
int checkNote(int dd, int mm);

