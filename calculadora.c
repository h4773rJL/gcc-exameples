/*
 * calculadora.c
 * Tuxes Team
 * 
 * Copyright 2015 intel trainnig <intel@Intel-BUAP>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <libintl.h>
#include <locale.h> 

#define _(cadena) gettext(cadena)

int print_menu()
{
	// vars for the screen size and position, i to rows
	
    int row, col, rrow = 0, acol=0, bcol=0, i=2, value=0;
    getmaxyx(stdscr,row,col);    
    acol=2; bcol=(col/2)+2;
    char *tit=_("Cientific Calculator");
    
    mvprintw (rrow, (col-strlen(tit))/2,"%s",tit);    
    mvprintw (rrow+i,acol,_("1.  add"));
    mvprintw (rrow+i,bcol,_("2.  Subtract"));
    i++; //3
    mvprintw (rrow+i,acol,_("3.  multiply") );
    mvprintw (rrow+i,bcol,_("4.  Divide"));
    i++; //4
    mvprintw (rrow+i,acol,_("5.  sine"));
    mvprintw (rrow+i,bcol,_("6.  cosine"));
    i++; //5
    mvprintw (rrow+i,acol,_("7.  tangent") );
    mvprintw (rrow+i,bcol,_("8.  absolute value of a floating"));
    i++; //6
    mvprintw (rrow+i,acol,_("9.  the floating remainder of x / y"));
    mvprintw (rrow+i,bcol,_("10. the cube root of"));
    i++; //7
    mvprintw (rrow+i,acol,_("11. the length of the hypotenuse x y"));
    mvprintw (rrow+i,bcol,_("12. square"));
    i++; //8
    mvprintw (rrow+i,acol,_("13. floor"));
    mvprintw (rrow+i,bcol,_("14. ceil"));
    i++; //9
    mvprintw (rrow+i,acol,_("15. frexp"));
    mvprintw (rrow+i,bcol,_("16. ldexp"));
    i++; //10
    mvprintw (rrow+i,acol,_("17. exp"));
    mvprintw (rrow+i,bcol,_("18. cosh"));
    i++; //11
    mvprintw (rrow+i,acol,_("19. sinh"));
    mvprintw (rrow+i,bcol,_("20. tanh"));
    i++; //12
    mvprintw (rrow+i,acol,_("21. acos"));
    mvprintw (rrow+i,bcol,_("22. asin"));
    i++; //13
    mvprintw (rrow+i,acol,_("23. atan"));
    mvprintw (rrow+i,bcol,_("24. atan2"));
    i++; //14
    mvprintw (rrow+i,acol,_("25. log"));
    mvprintw (rrow+i,bcol,_("26. log10"));
    i++; //15
    mvprintw (rrow+i,acol,_("27. pow"));
    mvprintw (rrow+i,bcol,_("28. isnan"));
    i++; //16
    mvprintw (rrow+i,acol,_("29. isinf"));
    mvprintw (rrow+i,bcol,_("30. isfinite"));
    i++; //17
    mvprintw (rrow+i,acol,_("31. copysign"));
    mvprintw (rrow+i,bcol,_("32. signbit"));
    i++; //18
    mvprintw (rrow+i,acol,_("33. fdim"));
    mvprintw (rrow+i,bcol,_("34. fma"));
    i++; //19
    mvprintw (rrow+i,acol,_("35. fmax"));
    mvprintw (rrow+i,bcol,_("36. fmin"));
    i++; //20
    mvprintw (rrow+i,acol,_("37. trunc"));
    mvprintw (rrow+i,bcol,_("38. round"));
    i++; //21
    mvprintw (rrow+i,acol,_("39. lround"));
    mvprintw (rrow+i,bcol,_("40. lrint"));
    mvprintw(row-2,0,_("select or 0. to Exit: "));
    scanw("%d", &value);
    refresh();
    
    return value;
}

int addf (float a, float b)
{
	float r;
	r = a + b;
	printf ("%f",r);
	return 0;
}


int selectv(int s)
{
	char *exmes=_("Do you really exit? ");
	char ex[]="n";
	int row,col;	
	
	getmaxyx(stdscr,row,col);
	
	if (s == 0) {
		clear();
		mvprintw(row/2,(col-strlen(exmes))/2,"%s",exmes);
		scanw("%c", &ex);
		refresh();
	
		}
	else {
		switch(s) {
			case 1:
			addf(3, 5);
		}
	}
	return 0;
}


int main(int argc, char **argv)
{
	int v;
	char *pelem=_("Give me the first number: ");
	char *selem=_("Give me the second number: ");
	char *elem=_("Give me the number: ");
	char *resul=_("the result is: ");
	
	bind_textdomain_codeset ("calculadora", "UTF-8");
    setlocale(LC_ALL, "");
    bindtextdomain("calculadora", "idioma");
    textdomain("calculadora");
    
    initscr();    
    v=print_menu();
    selectv(v);
    endwin();
    printf ("\n%d\n", v);
    
    return 0;
}
