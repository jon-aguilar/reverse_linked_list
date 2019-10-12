#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void reverse_list( struct node** head );

struct node* add_node( int temp_num );
void free_list( struct node* head );
void create_list( struct node** head, int size );
void print_list( struct node* head );

int main()
{
    struct node* head = NULL;

    create_list( &head, 5 );
    printf("original list ----------\n");
    print_list( head );

    printf("\nreverse list ----------\n");

    reverse_list( &head );
    print_list( head );

    free_list( head );

    return 0;
}

void reverse_list( struct node** head )
{
    struct node* rev_head = NULL;
    struct node* new_node;

    while( *head != NULL )
    {
        if( rev_head == NULL )   
        {
            rev_head = add_node( (*head)->num );
            *head = (*head)->next;
        }
        else
        {
            new_node = add_node( (*head)->num ); // isolated node not pointing to list
            new_node->next = rev_head;    // new_node node will point to head
            rev_head = new_node;         // the new node is now the head of reverse list

            *head = (*head)->next;  // move to the next node in original list
        }
    }

    *head = rev_head;
    //free( rev_head );
    //free( new_node );

}

struct node* add_node( int temp_num )
{
    struct node* temp = malloc( sizeof(struct node) );

    temp->num = temp_num;
    temp->next = NULL;

    return temp;
}

void create_list( struct node** head, int size )
{
    int count = 0;
    struct node* new_node = NULL;

    while( count < size )
    {
        // add first node to list
        if( *head == NULL )
        {
            new_node = add_node( count );
            *head = new_node;
        }
        else
        {
            new_node = add_node( count );
            new_node->next = *head;
            *head = new_node;
        }
        count += 1;
    }
}

void print_list( struct node* head )
{
    while( head != NULL )
    {
        printf("num: %d\n", head->num );
        head = head->next;
    }

}

void free_list( struct node* head )
{
    struct node* current;

    while( head != NULL )
    {
        current = head;
        head = head->next;
        free( current );
    }
}

