/*
Jaylen Davis
email: jaylen2@g.clemson.edu
Stephen Sams
email: sams7@g.clemson.edu
*/
#include "functions.h"

int main(int argc, char* argv[])
{
  FILE* in = fopen(argv[1], "r");
  FILE* out = fopen(argv[2], "w");
  node_t* head = createList(in,&head);

  print(printName,out,head);
  print(printBDay,out,head);
  print(printSong,out,head);
  print(printPastime,out,head);
  print(printList,out,head);

  deleteList(head);
  head = NULL;

  fclose(in);
  fclose(out);

  return 0;

}
