#include<stdio.h> 
#include<stdlib.h>
typedef struct stack//definition of structure
{
  int Roll;
  char *Name;  
  struct stack *next;
}stack;

  
int main()
{
  int choice1, sub_ch , *stack_arr, *rev_stack, Top , Top2, Size, x , i;//declaration of int type variables and pointers

  stack *top, *p;//declaration of stack type pointers

  top=NULL;//storing NULL to top initially

  Top=-1;//Top used for main stack using array
  Top2=-1;//Top2 used for the reversed stack

  char ch, control, character, *arr;//declaration of char type variables 
 
  control='y';//storing y initilally

  //prototype of functions
  int main_menu(int *);
  int sub_menu1(int *);
  int Push_arr(int [],int *,int ,int );
  int Pop_arr(int [],int *,int *);
  int display_arr(int [],int );
  int PUSH_sll(stack * ,stack **);
  int POP_sll(stack *,stack **);
  int display_sll(stack *);
    
  while(1)
  {
    lebel:
    system("clear");
    
    
    main_menu(&choice1);//calling function to display original menu list

    switch(choice1)
    {
       case 1://dynamic allocation of memory for stack using array
       stack_arr=(int*)calloc(10,sizeof(int));
     
       Size=10;//maximum number element that can be stored in the stack using array

       ch='y';
         
       while(1)
       {
          sub_menu1(&sub_ch);//calling function to display sub_menu list
         
          switch(sub_ch)
          {
            case 1: 
            printf("\nEnter element to be inserted to the stack:");
            scanf("%d",&x);//taking input of elements to be inserted

            Push_arr(stack_arr, &Top, Size, x);//calling function to push element in the stack using array

            printf("\nElement %d has been pushed in the stack",x);
            break;
            
            case 2: Pop_arr(stack_arr,&Top, &x);//calling function to delete element from the stack using array

            if(Top>=-1)
            {
              printf("\nPopped element is %d", x);
            }
            break;

            case 3:i=Top;//initialising i to Top
 
            rev_stack=(int*)calloc(10,sizeof(int));//dynamically allocating memory for reversed stack array  

            while(i>=0)
            {
               
               Push_arr(rev_stack, &Top2,10,*(stack_arr+i));//pushing elements from original stack to reversed stack
               i=i-1;
            }
            printf("\nThe reversed stack is:\n");

            display_arr( rev_stack, Top2);//displaying the reversed stack

            break;
            case 4:

            display_arr( stack_arr, Top);//calling function to display the original stack

            break;

            case 5:goto lebel;
            break;
             
            default: printf("\nInvalid choice!!");
          }
         
          getchar();

          printf("\n\n press y to continue:");//asking user whether he wants to continue thwn to press y 

          ch=getchar();   
          if(ch!='y')//checking whether user pressed any other character other than y
          {
            break;//then break from the loop structure
          }
            
       }
       break;

       case 2:ch='y';//case 2 stack using linked list
         
       while(1)
       {
          sub_menu2(&sub_ch);//calling function to display sub_menu list
         
          switch(sub_ch)
          {
            case 1: 
            p=(stack*)malloc(sizeof(stack));//allocating memory in p for the node of stack type

            p->Name=(char*)malloc(50*sizeof(char));//allocating array dynamically

            printf("\nEnter the name : ");

            character='a';

            i=0;

            getchar();
            while(character!='\n')
            {
              character=getchar();//taking name input character by character

              if(character=='\n')
              {
                 *(p->Name+i)='\0';
              }
              else
              {
                 *(p->Name+i)=character;
              }
              
              i=i+1;
           }
 
            
           printf("\nEnter the roll :");

           scanf("%d",&p->Roll);//taking input of roll no.
           p->next=NULL;
           
           PUSH_sll(p ,&top);//calling function to push the node in the stack

           printf("\nRoll |%d| is inserted in the stack....",p->Roll);
 
           break;
 
           case 2: POP_sll(p ,&top);//calling function to pop  node from the stack

           break;

           case 3:display_sll(top);//calling function to display the original stack
           break;
           
           case 4: goto lebel;

           break;
             
           default: printf("\nInvalid choice!!");
          
          }
          
          getchar();

          printf("\n\n press y to continue:");//asking user whether he wants to continue thwn to press y 

          ch=getchar();   
          if(ch!='y')//checking whether user pressed any other character other than y
          {
            printf("\nOperations on unordered list is discontinued");
            break;//then break from the loop structure
          }
            
       }
 
       break;
 
       case 3: printf("\nTerminating code.....");

       return(1);
          
           
    }
  }
  return(1);
}
int main_menu(int *choice1)
{

  printf("\t\tThe main menu of operations are listed below ");//showing menu

  printf("\n1.Stack using array.\n2.Stack using linked list.\n3.EXIT");

  printf("\n\nEnter choice:");
  scanf("%d",&*choice1);//taking choice of user as input
  return(1);
}

int sub_menu1(int *sub_ch)
{
   printf("\n1.Push the element\n2.Pop the element\n3.Reverse the stack\n4.Display\n5.Back");

   printf("\n\nEnter the choice:");
   scanf("%d",&*sub_ch);//taking choice of user as input
   return(1);
}
int sub_menu2(int *sub_ch)
{
   printf("\n1.Push the element\n2.Pop the element\n3.Display\n4.Back");

   printf("\n\nEnter the choice:");
   scanf("%d",&*sub_ch);//taking choice of user as input
   return(1);
}
  
int Push_arr(int *stack_arr,int *Top,int Size,int x)
{
   
     
   if(*Top==Size-1)//condition checking  for stack overflow 
   {
      printf("\nStack Overflow!!");
   }
   else
   {
     
     *Top=*Top+1;//top incremented
     *(stack_arr+*Top)=x;//value inserted in the stack
   }
   return(1);
}
  
int Pop_arr(int *stack_arr,int *Top,int *x)
{
   if(*Top==-1)//condition checking  for stack underflow 
   {
     printf("\nStack Underflow!!");
   }
   else
   {
     *x=*(stack_arr+*Top);//value deleted from the stack
     *Top=*Top-1;//top decremented
   }

   return(1);
}

  
int display_arr(int *stack_arr,int Top)
{
   int i; //variable declaration

   i=Top;   
     
   if(Top==-1)//condition checking for stack underflow
   {
      printf("\nStack Underflow!!");
   }
   else
   {
      printf("\nElements present in the stack: \n");
      while(i>=0)
      {
         printf("\n%d ",*(stack_arr+i));//printing the stack
         i=i-1;
      }
   }
   return(1);
}


int PUSH_sll(stack *p ,stack **top)
{
	
   if(*top==NULL)//CONDITION checking if their is no node inserted yet 
   {
      *top=p;//then inserting the first node
      
   }
   else
   {
      p->next=*top;//inserting the new node
      *top=p;//updating top
   }
  
   return(1);
	
}


int POP_sll(stack *p ,stack **top)
{
   
   if(*top==NULL)//CONDITION checking if their is no node inserted yet 
   {
       printf("\nStack underflow......");
   }
   else
   {
     p=*top;//p pointing the node pointed by top
     *top=(p->next);//deleting node by updating the top

     printf("\n\nRoll |%d| is popped from the stack....",p->Roll);

     free(p);
   }

   return(1);
}



int display_sll(stack *top)
{
   stack *p;//declaration of stack type pointer 

   int i;//declaration of variable

   i=0;   

   if(top==NULL)//CONDITION checking if their is no node inserted yet
   {
      printf("Stack is Empty or underflow");
   }
   else
   {
      p=top;//p pointing the node pointed by top

      printf("\nElements of stack are:\n");
      while(p!=NULL)
      {
	 printf("\n |%d| %s",p->Roll,p->Name);//printing the nodes in the stack
       
	 p=p->next;//updating p
      }
   }

   return(1);
}

