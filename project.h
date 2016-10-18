struct Date{

	int dd;
	int mm;
	int yy;
};
struct Date date;

struct Remainder{
	int dd;
	int mm;
	char note[128];
};
struct Remainder R;

int check_leapYear(int year);
void increase_month(int *mm, int *yy);
void decrease_month(int *mm, int *yy);
int getNumberOfDays(int month, int year);
char *getName(int day);
void print_date(int mm, int yy);
int getDayNumber(int day, int mon, int year);
char *getDay(int dd, int mm, int yy);
int checkNote(int dd, int mm);
void printMonth(int mon,int year,int x,int y);
void Addnote();
void showNote(int mm);
