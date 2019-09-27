// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : L_L-1.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Dr G. H. Zion
// Date : Fall 2019 (2191)
// Description : Fixed Linked-List with Four Elements
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    int data;
    struct node *next_ptr;
};

int main()
{
    node *head, *current, *n1, *n2, *n3, *n4, *tmp;

    // Build the Linked-List 12->23->34->45->56

    n1 = new(node);			// Create first node
    head = n1;				// Point head to the first node
    n1 -> data = 12; 		// Populate the data (12)
    n1 -> next_ptr = NULL;	// NULL the next_ptr

    n2 = new(node);			// Create second node
    n1 -> next_ptr = n2;	// Connect to first node
    n2 -> data = 23; 		// Populate the data (23)
    n2 -> next_ptr = NULL;	// NULL the next_ptr

    n3 = new(node);			// Create third node
    n2 -> next_ptr = n3;	// Connect to first node
    n3 -> data = 34; 		// Populate the data (34)
    n3 -> next_ptr = NULL;	// NULL the next_ptr

    n4 = new(node);			// Create fourth node
    n3 -> next_ptr = n4;	// Connect to first node
    n4 -> data = 45; 		// Populate the data (45)
    n4 -> next_ptr = NULL;	// NULL the next_ptr

    tmp = new(node);
    tmp -> next_ptr = head;
    head = tmp;
    tmp -> data = 5;


    current = head;		// make the head of the list the current node
	cout << "Data : ";
    do
    {
    	cout << current->data << "; ";		// traverse the list until
    	if ((current->next_ptr) == NULL)	// the next_ptr is null
    	{
    		cout << endl;
    		break;
    	}
    	else
    		current = current->next_ptr;
    }
    while(true);

    return(0);
}
