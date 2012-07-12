/*
 * =====================================================================================
 *
 *       Filename:  map.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/2/15 20:17:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  BurningStyle (), 
 *   Organization:  
 *
 * =====================================================================================
 */

//#include    "../Basic/basic.h"
#include	<stdlib.h>
#define		POSITION_BEGIN_H	0
#define		POSITION_BEGIN_W	0


void FreeArray(char ***mapArray,unsigned int maxH,unsigned int maxW);

struct MAP{
	char	  **mapArray;
	unsigned  int maxH;
	unsigned  int maxW;
};


struct MAP CreateMapStruct ( unsigned int  maxH, unsigned int maxW)
{
      char  **ppiHead = NULL;   //±£Žæ¶þÎ¬ÊýŸÝµÄÍ·ÖžÕë
      
      struct MAP map={NULL,0,0};

      unsigned int  h = 0;   
 
      unsigned int  w = 0;   
    
      ppiHead = (char **)malloc(sizeof(char *)*(maxH+1));  //ÎªÍ·ÖžÕë¿ª±ÙÒ»žöÊýŸÝ¿ÕŒä
     
      for(h=0;h<maxH+1;h++){   //ŒÓ1ÊÇÒòÎªÒªÏÔÊŸºá×Ý×ø±êÒªž÷ÕŒÒ»ÐÐÓëÒ»ÁÐ	
	
      	      ppiHead[h]=(char *)malloc(sizeof(char)*(maxW+1));  //Ã¿Ò»ÐÐµ¥¶À·ÖÅä¿ÕŒä
      
      }
     
     map.mapArray=ppiHead;
     //其含义是将ppiHead的值（开辟的内存空间的首地址），赋给map.mapArray，后面map.mapArray的值就是动态内存空间的首地址。
      
     map.maxH=maxH+1;

     map.maxW=maxW+1;

//    FreeArray(&ppiHead,map.maxH,map.maxW);
//    这里不用释放ppiHead，因为这样会将内存空间释放掉，ppiHead只是一个装着动态内存首地址的临时变量
     
     return  map;   //·µ»ØÍ·ÖžÕë
}


void FreeArray(char ***mapArray,unsigned int maxH,unsigned int maxW)
//其中三双重指针是取二重指针的地址
{  
       
       unsigned int h=0;
       unsigned int w=0;
    	for(h=0;h<maxH;h++){
        	if((*mapArray)[h]!=NULL){
		//*mapArray表示申请内存空间的首地址
			(*mapArray)[h]=NULL;
			free((*mapArray)[h]);  //Ã¿ÐÐœøÐÐÊÍ·Å
		}else{
			printf("%3d",h);
		}
	}

	if((*mapArray)!=NULL){
		*mapArray=NULL;
		free(*mapArray);
	}
	else
		printf("map->mapArray==NULL");

	
   

}


