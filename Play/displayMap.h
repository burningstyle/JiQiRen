
#include    "../Bob/bob.h"
#include    "../Map/map.h"
#define		OUTPUT_PLACE_HOLDER_DEFAULT_SIZE		10
#define		INTTOCHAR					48
#define		BLANK						'.'

struct STRUCT_OUTPUT_FORMAT{
	char placeHolder[OUTPUT_PLACE_HOLDER_DEFAULT_SIZE];

	char mapPlaceHolder;
};

void showMap(struct MAP *map,struct BOB *bob){
//void showMap(struct MAP *map){
	int h=0,w=0,maxH=0,maxW=0;
	maxH=map->maxH;
	maxW=map->maxW;
	//printf("%c",map->maxH);

	
  	for(h=0;h<maxH;h++){
		for(w=0;w<maxW;w++){
			if(h==0){
				printf("%3d",w);
			}else if(h!=0 && w==0){
				printf("%3d",h);
			}
			else if(bob->localPoint.x==w && bob->localPoint.y==h){
				
				printf("%3c",bob->direction);
				
			}
			else
			{
			(*map->mapArray+h)[w]=BLANK;
			printf("%3c",((*map->mapArray+h)[w]));
			}
		}
		printf("\n");
	}
	FreeArray(&(map->mapArray),map->maxH,map->maxW);
}

struct STRUCT_OUTPUT_FORMAT CreateOutputFormat(
		int placeHolder,
		char type[],
		char mapPlaceHolder)
{
	struct STRUCT_OUTPUT_FORMAT s_outputFormat;
	if(placeHolder>=10){
		placeHolder=3;
	}
	s_outputFormat.placeHolder[0]='%';
	s_outputFormat.placeHolder[1]=placeHolder+INTTOCHAR;
	s_outputFormat.placeHolder[2]=type[0];
	s_outputFormat.mapPlaceHolder=mapPlaceHolder;

	return s_outputFormat;
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  showPlay
 *  Description:  
 * =====================================================================================
 */
/* void showPlay (struct MAP *map,struct BOB *bob)
{
	system("cls");
	
	showMap(map,bob);
}	
*/


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  move
 *  Description:  
 * =====================================================================================
 */
int move (struct MAP *map,struct BOB *bob)
{
	
	switch ( bob->direction ) {
		case FACE_LEFT:{
					if((bob->localPoint.x-1)<0) return 0;
					else
					bob->localPoint.x--;	
			       }
			break;

		case FACE_RIGHT:{
					if((bob->localPoint.x+1)>map->maxW) return 0;
					else
					bob->localPoint.x++;
				}
			break;

		case FACE_UP:{
			     		if((bob->localPoint.y+1)>map->maxH) return 0;
					else
					bob->localPoint.y++;
			     }
			break;
		case FACE_DOWN:{
			       		if((bob->localPoint.y-1)<0) return 0;
					else
					bob->localPoint.y--;
			       }
			break;
		default:	
			break;
	}

	return 1;

}		
