#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>

#define INT32U unsigned int 
#define INT16U unsigned short
#define INT8U unsigned char

#pragma pack(push, 1)  /* push current alignment to stack */
typedef struct bit_field{
        INT16U a;
        INT16U b:1;
        union{
              INT16U c:15;
              INT16U d:15;
        };
        INT32U e;
        
}BIT_FIELD;

typedef struct bit_field3{
        INT16U a;
        union{
              struct{
              INT16U b:1;
              INT16U c:15;
              };
              struct{
              INT16U b1:1;
              INT16U d:15;
              };
        };
        INT32U e;
        
}BIT_FIELD3;


typedef struct bit_field2{
        INT16U a;
        INT16U b:1;
        INT16U c:15;
        INT32U e;
        
}BIT_FIELD2;

#pragma pack(pop)   /* restore original alignment from stack */

int main (int argc, char* argv[])
{

 INT32U arr[3] = {0xaaaaaaaa,0xbbbbbbbb,0xcccccccc};
 BIT_FIELD *ptr1 = (BIT_FIELD *)arr;
 BIT_FIELD2 *ptr2 = (BIT_FIELD2 *)arr;
  BIT_FIELD3 *ptr3 = (BIT_FIELD3 *)arr;
  
  printf("ptr1->b %x\n",ptr1->b);
 printf("ptr2->b %x\n",ptr2->b);
  printf("ptr3->b %x\n",ptr3->b);
   printf("ptr3->b1 %x\n",ptr3->b1);

 printf("ptr1->c 0x%x\n",ptr1->c);
 printf("ptr1->d 0x%x\n",ptr1->d);
 
  printf("ptr2->c 0x%x\n",ptr2->c);
  
  printf("ptr3->c 0x%x\n",ptr3->c);
 printf("ptr3->d 0x%x\n",ptr3->d);
 
 printf("ptr1->e 0x%x\n",ptr1->e);
 printf("ptr2->e 0x%x\n",ptr2->e);
  printf("ptr3->e 0x%x\n",ptr3->e);


 system("PAUSE");
 return 0; 
}
