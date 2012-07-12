/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/2/14 23:52:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  BurningStyle (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include	 <stdio.h>
#include	"Play/displayMap.h"
#ifdef _WIN32
       #define CLEAR_SCREEN "cls"
#endif
#ifdef _LINUX
       #define CLEAR_SCREEN "clear"
#endif 


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
	int temp=0;
	for(temp=0;temp<=15;temp++){	
		sleep(500);
		system(CLEAR_SCREEN);
		struct MAP map;
		struct BOB bob;
		map=CreateMapStruct(30,30);
		bob=CreateBob(FACE_RIGHT,temp-1,2);
		showMap(&map,&bob);
        
	}
	return 0;
}				
