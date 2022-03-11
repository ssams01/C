/*
Jaylen Davis
email: jaylen2@g.clemson.edu
Stephen Sams
email: sams7@g.clemson.edu
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct
{
  int month;
  int day;
  int year;

}bday_t;

typedef struct Node
{
  char first[100];
  char last[100];
  char song[100];
  char pastTime[100];
  bday_t b;
  struct Node* next;

}node_t;

/* Parameters: New node double pointer and head of list double pointer
 * Return: Void       
 * This function is designed to add a node to the end of life
 */
void add(node_t** node, node_t** head);

/* Parameters: FILE* - our input file
 * Return: returns our new node       
 * This function is designed to read in the nodes information
 */
node_t* readNodeInfo(FILE* input);

/* Parameters: FILE* - our input file and Double pointer for Node
 * Return: returns the head of the new list       
 * This function is designed to create the linked list with all the new nodes
 */
node_t* createList(FILE*, node_t**);

/* Parameters: FILE* - our output file and pointer for our node
 * Return: returns Void    
 * This function is designed to prints out everything
 * 
 */
void printList(FILE*, node_t*);


/* Parameters: FILE* - our output file and pointer for our node
 * Return: returns Void    
 * This function is designed to prints out the names
 * 
 */
void printName(FILE*,node_t*);


/* Parameters: FILE* - our output file and pointer for our node
 * Return: returns Void    
 * This function is designed to prints out the birthdays
 * 
 */
void printBDay(FILE*,node_t*);


/* Parameters: FILE* - our output file and pointer for our node
 * Return: returns Void    
 * This function is designed to prints out the songs of nodes
 * 
 */
void printSong(FILE*,node_t*);


/* Parameters: FILE* - our output file and pointer for our node
 * Return: returns Void    
 * This function is designed to prints out the past time
 * 
 */
void printPastime(FILE*,node_t*);


/* Parameters: FILE* - our output file
 * Return: returns Void    
 * This function is designed to prints out 80 * characters as border
 * 
 */
void printBorder(FILE*);


/* Parameters: FILE* - our output file and pointer for our node
 * and it also takes in a function that has matching parameters
 * Return: returns Void    
 * This function is designed to prints out specified print functions
 * 
 */
void print(void (*fp)(FILE*,node_t*),FILE*, node_t*);


/* Parameters: Node pointer for the head of linked list
 * Return: returns Void    
 * This function deletes aloocated memory for linked list
 * 
 */
void deleteList(node_t*);


/* Parameters: takes in variable of type bday_t
 * Return: returns Bool    
 * This function is designed to make sure the birthday is valid
 * 
 */
bool checkDate(bday_t );

/* Parameters: integer value of year
 * Return: returns Bool    
 * This function is determines if the year is a leap year
 * 
 */
bool isLeapYear(int);

#endif
