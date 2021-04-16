//	 Author	: Feven Essa
//
//	 Programming	Assignment	Number 4
//
//	 Spring	2021 - CS 3358-253
//
//	 Due Date : 3/31/2021
//
//	 Instructor: Husain	Gholoom.
//
/*  The program create 4 linked list of characters. 
    link_1 and link_2 are created by randomly generating 
    characters from A to Z. list_3 is created by appending 
    elements from list_1 and list_2. The first element 
    from list_1 and the second from list_2 and continue alternatively. 
    list_4 is created by removing all duplicate characters from list_3*/

#include <iostream>
#include <ctime>
#include<cassert>
#include <stdlib.h>

using namespace std;

class CharList
{
private:
    struct ListNode     // the node data type
    {
        char value;        // data
        ListNode *next;    // ptr to next node
    };
    ListNode *head;     // the list head
public:
    CharList();
    ~CharList();
    
    void appendNode(char);
    void appendNodeFront(char);
    char getNthNode(int);
    int countDuplicateNode(char);
    int countNumberOfNode();
    void displayList();
    void deleteNode(char);
};

CharList::CharList()
{
    head = NULL;
}
CharList::~CharList() 
{
    ListNode *nodePtr;              // traversal ptr
    ListNode *nextNode;             // saves the next node
    nodePtr = head;                 //start at head of list
    while (nodePtr) 
    {
        nextNode = nodePtr->next;   // save the next
        delete nodePtr;             // delete current
        nodePtr = nextNode;         // advance ptr
    }
}
void CharList::appendNode(char c) 
{
    ListNode *newNode;                 // To point to the new node

    // Create a new node and store the data in it
    newNode = new ListNode;
    newNode->value = c;
    newNode->next = NULL;

    // If list is empty, make head point to new node
    if (!head)
        head = newNode;
    else 
    {
        ListNode *nodePtr; // To move through the list
        nodePtr = head; // initialize to start of list
        
        // traverse list to find last node
        while (nodePtr->next)           //it’s not last
            nodePtr = nodePtr->next; //make it pt to next
            // now nodePtr pts to last node
            // make last node point to newNode
        nodePtr->next = newNode;
    }
}
void CharList::appendNodeFront(char c) 
{
    ListNode *newNode;                 // To point to the new node

    // Create a new node and store the data in it
    newNode = new ListNode;
    newNode->value = c;

    // If list is empty, make head point to new node
    if (!head)
    {
        head = newNode;
        newNode->next=NULL;
    }
    else 
    {
       newNode->next=head;
       head = newNode; 
    }
}

void CharList::displayList() 
{
    ListNode *nodePtr; //ptr to traverse the list

    // start nodePtr at the head of the list
    nodePtr = head;

    // while nodePtr pts to something (not NULL), continue
    while (nodePtr)
    {
        //Display the value in the current node
        cout << nodePtr->value << " ";
        //Move to the next node
        nodePtr = nodePtr->next;
    }
    cout<<endl;
}

char CharList::getNthNode(int index)
{
    ListNode *nodePtr = head; //create a node and poit it to head

    int count = 0;
    while (nodePtr) 
    {
        if (count == index)             //when count equals index 
            return (nodePtr->value);    //retern the value of the ll at that position
        count++;
        nodePtr = nodePtr->next;
    }
    assert(0);
}

int CharList::countDuplicateNode(char c) 
{
    int count = 0; 
    if (!head) // empty list, return 0 ( head == NULL )
        return count;
    ListNode *nodePtr;          // to traverse the list
    ListNode *previousNode;     // trailing node pointer
    nodePtr = head; // traversal ptr, set to first node
        
    // skip nodes not equal to c, stop at last
    while (nodePtr) 
        {
            if(nodePtr->value == c)
                count++;
            previousNode = nodePtr;     // save it!
            nodePtr = nodePtr->next;    // advance it
        }
    return count;
}
int CharList::countNumberOfNode() 
{
    int count = 0; 
    if (!head) // empty list, return 0 ( head == NULL )
        return count;
    ListNode *nodePtr;          // to traverse the list
    ListNode *previousNode;     // trailing node pointer
    nodePtr = head; // traversal ptr, set to first node

    while (nodePtr) 
        {
            count++;                //increase count 
            previousNode = nodePtr;     // save node!
            nodePtr = nodePtr->next;    // advance it
        }
    return count;
}

void CharList::deleteNode(char c) 
{
    if (!head) // empty list, exit ( head == NULL )
        return;
    ListNode *nodePtr; // to traverse the list
    if (head->value == c) 
    { // if first node is c
        nodePtr = head;
        head = nodePtr->next;
        delete nodePtr;
    }
    else 
    {
        ListNode *previousNode; // trailing node pointer
        nodePtr = head; // traversal ptr, set to first node
        
        // skip nodes not equal to c, stop at last
        while (nodePtr && nodePtr->value != c) 
        {
            previousNode = nodePtr; // save it!
            nodePtr = nodePtr->next; // advance it
        }
        if (nodePtr) 
        { // c is found, set links + delete
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
        // else: end of list, c not found in list, do nothing
    }
}

int main() 
{
    cout<<"\n***********************************************************"<<endl;
    cout<<"\tPointer Implementation of Linked List "<<endl;
    cout<<"***********************************************************"<<endl<<endl;
    // Define list_1, list_2, list_3 and list_4
    CharList list_1;
    CharList list_2;
    CharList list_3;
    CharList list_4;
    char c;
    int r, i;

    srand (time(NULL));         // initialize the random number generator
    for (i=0; i<15; i++)
    {
        r = rand() % 26;        // generate a random number
        c = 'A' + r;            // Convert to a character from a-z
        if(c!='A' or c!='Z')
            list_1.appendNode(c);   // Append the randomely generated char to list_1
        else
            i--;
    }
    for (i=0; i<15; i++)
    {
        r = rand() % 26;        // generate a random number
        c = 'A' + r;            // Convert to a character from A-Z
        if(c!='A' or c!='Z')
            list_2.appendNode(c);   // Append the randomely generated char to list_2
        else
            i--;
    }

    cout<<"\n\tPart A:"<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"list_1 and list_2 each hold 15 randomly generated characters"<<endl;
    cout<<"\nlist_1: "<<endl;
    list_1.displayList();       // Display the values in the list_1.
    cout<<"\nlist_2: "<<endl;
    list_2.displayList();       // Display the values in the list_2.
    for(i=0; i<15; i++)
    {
        list_3.appendNode(list_1.getNthNode(i));    //append the char reterned from list_1.getNthNode(i) to list_3
        list_3.appendNode(list_2.getNthNode(i));    //append the char reterned from list_2.getNthNode(i) to list_3
    }

    cout<<"\n\tPart B: "<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"list_3 is created by appending elements from list_1 and list_2."<<endl;
    cout<<"The first element from list_1 and the second from list_2 "<<endl;
    cout<<"and continue alternatively."<<endl;
    cout<<"\nlist_3: "<<endl;
    list_3.displayList();       // Display the values in the list_3.
    
    cout<<"\n\tPart C: "<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"The first element in list_3: "<<list_3.getNthNode((0))<<endl<<endl;  //display the first element in list_3
         
    cout<<"The first element ( "<<list_3.getNthNode((0))<<" ) appears ";
    cout<<list_3.countDuplicateNode(list_3.getNthNode(0));    //print the number of occurrence of 
    cout<<" times in list_3." <<endl;                          //the firs element in list_3.
    cout<<"\n\tPart D: "<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"list_4 is created by removing all duplicate characters that are in list_3"<<endl;
    for(i=0; i<30; i++)
    {
        if(list_3.countDuplicateNode(list_3.getNthNode(i)) == 1)    //check if the ith element in list 3 
                                                                    //occures more than one 
            list_4.appendNode(list_3.getNthNode(i));                //if the ith element occures only once 
                                                                    //append that element to list_4
    }
    
    cout<<"\nThe number of elements in list_4: "<<list_4.countNumberOfNode()<<endl<<endl;              //count the number of nodes in list_4
    cout<<"list_4: "<<endl;
    list_4.displayList();       // Display the values in the list_4.
   
    cout<<"\n\tPart E: "<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"list_4 is updated by moving the last element of the list\n";
    cout<<"and placing it in the beginning: "<<endl;
    char last=list_4.getNthNode(list_4.countNumberOfNode()-1); //Save the the last element in list_4 in last
    list_4.deleteNode(last); //Delete the last element in list_4
    list_4.appendNodeFront(last); //append the value in the variable last in the begining of list_4
    cout<<"\nThe updated list_4: "<<endl;
    list_4.displayList();               //Display the updated list_4
    
    cout<<"\nThis LL program is implemented by: "<<endl;
    cout<<"Feven Essa - March 31, 2021"<<endl<<endl;
    cout<<"***********************************************************"<<endl;

    return 0;
}
