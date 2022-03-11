/*
Jaylen Davis
email: jaylen2@g.clemson.edu
Stephen Sams
email: sams7@g.clemson.edu
*/
#include "functions.h"

void add(node_t** node, node_t** head)
{
  node_t *tempNode = *head;
  if(*head == NULL)
  {
    *head = *node;
    return;
  }
  while(tempNode->next != NULL) {
    tempNode = tempNode->next;
  }
  tempNode->next = *node;
  
    
}


bool isLeapYear(int year)
{
  if(year % 4 == 0)
  {
    if(year % 100 == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

void deleteList(node_t* head)
{
  node_t* curr = head;
  node_t* next;

  while(curr != NULL)
  {
    next = curr->next;
    free(curr);
    curr = next;
  }

  head = NULL;
}

void printBorder(FILE* outF)
{
  for(int i = 0; i < 80; i++)
  {
    fprintf(outF,"*");
  }
  fprintf(outF,"\n");
}

bool checkDate(bday_t b)
{
  //int i =0;
  if(b.year <= 2020 && b.year >= 1900)
  {
    if(b.month == 1 || b.month ==3 ||b.month == 5
    ||b.month == 7 || b.month == 8
    || b.month == 10  || b.month == 11)
    {
      if(b.day > 31)
      {
        return false;
      }
      else
      {
        return true;
      }
    }
    if(b.month == 4 || b.month == 6 || b.month == 9
    ||b.month == 12)
    {
      if(b.day > 30)
      {
        return false;
      }
      else
      {
        return true;
      }
    }
    if(b.month == 2 && isLeapYear(b.year) != true)
    {
      if(b.day > 28)
      {
        return false;
      }
      else
      {
        return true;
      }
    }
    else
    {
      if(b.day == 29)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    ///i++;
  }
  //printf("%d",i);
  }

  node_t *readNodeInfo(FILE* input)
  {
    node_t* person = (node_t*)malloc(sizeof(node_t));
    char tempMonth[50];
    char tempDay[50];
    char tempYear[50];

    fscanf(input,"%[^,]%*c",person->last);
    fscanf(input,"%[^,]%*c",person->first);
    fscanf(input,"%[^,]%*c", tempMonth);
    fscanf(input,"%[^,]%*c", tempDay);
    fscanf(input,"%[^,]%*c", tempYear);
    fscanf(input,"%[^,]%*c",person->song);
    fscanf(input,"%[^\n]%*c",person->pastTime);
    //printf("Bottom of read.\n");

    person->b.month = atoi(tempMonth);
    person->b.day = atoi(tempDay);
    person->b.year = atoi(tempYear);

    return person;
  }

  node_t* createList(FILE* in, node_t** head)
  {
    while(!feof(in))
    {
      node_t* newNode = readNodeInfo(in);
    
      if(checkDate(newNode->b)== true)
     {
      add(&newNode,head);
     }
    }
    return *head;
  }

  void printName(FILE* out,node_t* head)
  {
    if(head == NULL)
    {
      fprintf(stderr,"ERROR: List is empty.\n");
      exit(0);
    }
    printBorder(out);

    fprintf(out,"Names:\n");
    for(node_t *n = head; n!= NULL; n = n->next)
    {
      fprintf(out,"%s,%s\n",n->first,n->last);
    }
    printBorder(out);
  }

  void printBDay(FILE* out,node_t* head)
  {
    const char *array[13] ={" ","January","Febuaray", "March", "April",
    "June", "July", "August", "September", "October",
    "Novemeber", "December"};
     printBorder(out);
     for(node_t *n = head; n!= NULL; n = n->next)
     {
        fprintf(out,"%s %s's date of birth is %s %d, %d\n",n->first,n->last,
        array[n->b.month-1], n->b.day, n->b.year);
     }
     printBorder(out);
}

void printSong(FILE* out, node_t* head)
{
  printBorder(out);
  for(node_t *n = head; n!= NULL; n = n->next)
  {
     fprintf(out,"%s %s's favorite song is %s\n",n->first, n->last, n->song);
  }
  printBorder(out);
}

void printPastime(FILE *out, node_t* head)
{
  printBorder(out);
  for(node_t *n = head; n!= NULL; n = n->next)
  {
     fprintf(out,"%s %s's favorite past time is %s\n",n->first, n->last,
     n->pastTime);
  }
  printBorder(out);
}

  void printList(FILE* out, node_t* head)
  {
    const char *array[13] ={" ","January","Febuaray", "March", "April",
    "June", "July", "August", "September", "October",
    "Novemeber", "December"};

    if(head == NULL)
    {
      fprintf(stderr,"ERROR: List is empty.\n");
      exit(0);
    }
    printBorder(out);
    fprintf(out,"LIST INFO:\n");
    for(node_t *n = head; n != NULL; n = n->next)
    {
      fprintf(out,"%s, %s, %s %d, %d, %s, %s\n",n->last,n->first,
      array[n->b.month-1], n->b.day, n->b.year, n->song, n->pastTime);
    }
    printBorder(out);
  }

  void print(void (*fp)(FILE*,node_t*),FILE* file, node_t* head)
  {
    fp(file,head);
  }
