#include <time.h>
#include <string>
using namespace std;


/* COLOR constants (abckground is foreground+10) */
#define		COLOR_black			30
#define		COLOR_red			31
#define		COLOR_green			32
#define		COLOR_yellow		33
#define		COLOR_blue			34
#define		COLOR_magenta		35
#define		COLOR_cyan			36
#define		COLOR_white			37

#define		COLOR_normal		0
#define		COLOR_bold			1
#define		COLOR_underline		4
#define		COLOR_blink			5

#define		COLOR(FG,BG,FONT) "\033["#FONT";"#FG";"#BG"m"
#define		COLOR_reset "\033[0m"
#define		COLOR_strERR COLOR(30,41,0)"[ERROR]"COLOR(31,40,0)" "
#define		COLOR_strWAR COLOR(30,43,0)"[WARNING]"COLOR(33,40,0)" "

void COLOR_print(string str, short int FG=COLOR_white, short int BG=COLOR_black, short int FONT=COLOR_normal)
{
	printf("\033[%d;%d;%dm%s\033[0m", FONT,FG,BG+10, str.c_str());
}


void COLOR_log(string str, short int FG=COLOR_green, short int BG=COLOR_black, short int FONT=COLOR_normal)
{
	char buffer [80];
	time_t rawtime = time(0);
	struct tm * timeinfo = localtime ( &rawtime );
	strftime (buffer,80,"%H:%M:%S",timeinfo);

	printf("\n\033[0;%d;%dm[ %s ]\033[%d;%d;%dm %s\033[0m\n", BG,FG+10,buffer, FONT,FG,BG+10,str.c_str());
}

void COLOR_error( string msg )
{
	COLOR_print("[ ERROR ]", COLOR_black, COLOR_red);
	COLOR_print(" "+msg, COLOR_red, COLOR_black);
}