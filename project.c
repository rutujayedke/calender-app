#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"project.h"					

int check_leapYear(int year){
	if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){
		return 1;
	}	
	return 0;

}


void increase_month(int *mm, int *yy){
	++*mm;
	if(*mm > 12){
		++*yy;
		*mm = *mm - 12;
	}
}


void decrease_month(int *mm, int *yy){
	--*mm;
	if(*mm < 1){
		--*yy;
		if(*yy < 1500){
			printf("No record available");
			return;
		}
		*mm = *mm + 12;
	}
}


int getNumberOfDays(int month, int year){
	switch(month){
		case 1 : return(31);
		case 2 : if(check_leapYear(year) == 1){
				return(29);
			 }
			 else
				return(28);
		case 3  : return(31);
		case 4  : return(30);
		case 5  : return(31);
		case 6  : return(30);
		case 7  : return(31);
		case 8  : return(31);
		case 9  : return(30);
		case 10 : return(31);
		case 11 : return(30);
		case 12 : return(31);
		default : return(-1);
	}	
}


char *getName(int day){
	switch(day){
		case 0 : return("Sunday");
		case 1 : return("Monday");
		case 2 : return("Tuesday");
                case 3 : return("Wednesday");
                case 4 : return("Thursday");
                case 5 : return("Friday");
                case 6 : return("Saturday");
		default: return("Error in getName()");
	}
}


void print_date(int mm, int yy){
	printf("---------------------\n");

	switch(mm){
		case 1 : printf("January");
			 break;
		case 2 : printf("February");
                         break;
		case 3 : printf("March");
                         break;
		case 4 : printf("April");
                         break;
		case 5 : printf("May");
                         break;
		case 6 : printf("June");
                         break;
		case 7 : printf("July");
                         break;
		case 8 : printf("August");
                         break;
		case 9 : printf("September");
                         break;
		case 10 : printf("October");
                         break;
		case 11 : printf("Novenber");
                         break;
		case 12 : printf("December");
                         break;
	}
	printf("%d", yy);
	
	printf("---------------------");
}


int getDayNumber(int day, int mon, int year){
	int res = 0, d1, d2, y = year;
	year = year - 1500;
	while(year >= 100){
		res = res + 5;
		year = year - 100;
	}
	res = (res % 7);
	d1 = ((year - 1) / 4);
	d2 = (year - 1) - d1;
	d1 = (d1 * 2) + d2;
	d1 = (d1 % 7);
	res = res + d1;
	res = res % 7;
	d2 = 0;
	for(d1 = 1; d1 < mon; d1++){
		d2 += getNumberOfDays(d1, y);
	}
	d2 = d2 + day;
	d2 = d2 % 7;
	res = res + d2;
	res = res % 7;
	if(y > 2000){
		res = res + 1;
	}
	res = res % 7;
	return res;
}


char *getDay(int dd, int mm, int yy){
	int day;
	if(!(mm >= 1 && mm <= 12)){
		return("Invalid month value");
	}
	if(!(dd >= 1 && dd <= getNumberOfDays(mm, yy))){
		return("Invalid date");
	}
	if(yy >= 1500){
		day = getDayNumber(dd, mm, yy);
		day = day % 7;
		return(getName(day));
	}else{
		return("Please give year more than 1500");
	}
}


int checkNote(int dd, int mm){
	FILE *fp;
	fp = fopen("note.txt", "r");
	if(fp == NULL){
		printf("Error in Opening the file");
	}
	while(fread(&R, sizeof(R), 1, fp)){
		if(R.dd == dd && R.mm == mm){
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}	

void printMonth(int mon, int year, int x, int y){
	int nod, day, cnt, d = 1, x1 = x, y1 = y, isnote = 0;
	if(!(mon >= 1 && mon <= 12)){
		printf("INVALID MONTH");
		return;
	}
	if(!(year >= 1500)){
		printf("INVALID YEAR");
		return;
	}
	move(20,y);
	print_date(mon, year);
	y += 3;
	move(x,y);

	printf("S   M   T   W   T   F   S   \n");
	y++;
	nod = getNumberOfDays(mon, year);
	day = getDayNumber(d, mon, year);
	
	switch(day){
		case 0:
			x = x;
			cnt = 1;
			break;
		case 1:
                        x = x+4;
                        cnt = 2;
                        break;
		case 2:
                        x = x+8;
                        cnt = 3;
                        break;
		case 3:
                        x = x+12;
                        cnt = 4;
                        break;
		case 4:
                        x = x+16;
                        cnt = 5;
                        break;
		case 5:
                        x = x+20;
                        cnt = 6;
                        break;
		case 6:
                        x = x+24;
                        cnt = 7;
                        break;
		default:
			printf("INVALID DATA");
			return;
	}
	move(x,y);
	printf("%d",d);
	for(d=2;d<=nod;d++){
		if(cnt%7 == 0){
			y++;
			cnt = 0;
			x = x1 - 4;	
		}
		x += 4;
		cnt++;
		move(x,y);
	        printf("%02d",d);
    	}
    move(8, y+2);
    printf("Press 'n'  to Next\n, Press 'p' to Previous\n 'q' to Quit\n");
    move(8,y+3);
    printf(" Press 's' to see note: ");

}


void AddNote(){
    FILE *fp;
    fp = fopen("note.txt","a");
    move(5,7);
    printf("Enter the date(DD/MM): ");
    scanf("%d%d",&R.dd, &R.mm);
    move(5,8);
    printf("Enter the Note(50 character max): ");
    fflush(stdin);
    scanf("%[^\n]",R.note);
    if(fwrite(&R,sizeof(R),1,fp)){
        move(5,12);
        puts("Note is saved sucessfully");
        fclose(fp);
    }else{
        move(5,12);
        puts("\aFail to save!!\a");
    }
    move(5,15);
    printf("Press any key............");
    fclose(fp);
}


void showNote(int mm){
    FILE *fp;
    int i = 0, isFound = 0;
    fp = fopen("note.dat","r");
    if(fp == NULL){
        printf("Error in opening the file");
    }
    while(fread(&R,sizeof(R),1,fp) == 1){
        if(R.mm == mm){
            move(10,5+i);
            printf("Note %d Day = %d: %s", i+1, R.dd,  R.note);
            isFound = 1;
            i++;
        }
    }
    if(isFound == 0){
        move(10,5);
        printf("This Month contains no note");
    }
    move(10,7+i);
    printf("Press any key to back.......");
}
