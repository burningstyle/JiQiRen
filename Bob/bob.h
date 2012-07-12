/*
 * =====================================================================================
 *
 *       Filename:  bob.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/2/15 19:03:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  BurningStyle (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	"../Basic/basic.h"
//#include	"../Map/map.h"
#define		FACE_UP		30
#define		FACE_DOWN	31
#define		FACE_LEFT	17
#define		FACE_RIGHT	16


struct BOB{
	char 	direction;
	struct POINT 	localPoint;
};


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  turnLeft
 *  Description:  
 * =====================================================================================
 */
void turnLeft (struct BOB *localBob)
{
	struct BOB *bob=localBob;
	switch (bob->direction) {
		case FACE_LEFT:bob->direction=FACE_DOWN;	
			break;

		case FACE_RIGHT:bob->direction=FACE_UP;	
			break;

		case FACE_UP:bob->direction=FACE_LEFT;	
			break;
		case FACE_DOWN:bob->direction=FACE_RIGHT;
			break;
		default:	
			break;
	}
}	


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  initBob
 *  Description:  
 * =====================================================================================
 */
struct BOB CreateBob (char direction,unsigned int localPoint_x,unsigned int localPoint_y )
{
	struct BOB bob;
	bob.direction=direction;
	bob.localPoint.x=localPoint_x;
	bob.localPoint.y=localPoint_y;
	return bob;
}		



