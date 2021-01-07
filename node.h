// FILE: node.h
// PROVIDES: A class for a node in a linked list, and list manipulation
// functions, all within the namespace main_savitch_5
//
// DYNAMIC MEMORY usage by the toolkit: 
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy,
//   list_piece.

#ifndef MAIN_SAVITCH_NODE_H
#define MAIN_SAVITCH_NODE_H
#include <cstdlib> // Provides size_t and NULL

namespace main_savitch_5
{
  class node
  {
  public:
    // TYPEDEF for the node class:
    //     Each node of the list contains a piece of data and a pointer to the
    //     next node. The type of the data is defined as node::value_type in a
    //     typedef statement. The value_type may be any
    //     of the built-in C++ classes (int, char, ...) or a class with a copy
    //     constructor, an assignment operator, and a test for equality (x == y).
    //
    typedef double value_type;
    
    // CONSTRUCTOR for the node class:
    //   node(
    //     const value_type& init_data = value_type(),
    //     node* init_link = NULL
    //   )
    //     Postcondition: The node contains the specified data and link.
    //     NOTE: The default value for the init_data is obtained from the default
    //     constructor of the value_type. In the ANSI/ISO standard, this notation
    //     is also allowed for the built-in types, providing a default value of
    //     zero. The init_link has a default value of NULL.
    //
    node(const value_type& init_data = value_type( ),
         node* init_link = NULL)
      : data_field_ (init_data),
        link_field_ (init_link)
    {
    }

    // MEMBER FUNCTIONS for the node class:
    // NOTE:
    //   Some of the functions have a return value which is a pointer to a node.
    //   Each of these  functions comes in two versions: a non-const version (where
    //   the return value is node*) and a const version (where the return value
    //   is const node*). 
    // EXAMPLES:
    //    const node *c;
    //    c->link( ) activates the const version of link
    //    list_search(c,... calls the const version of list_search
    //    node *p;
    //    p->link( ) activates the non-const version of link
    //    list_search(p,... calls the non-const version of list_search
    //
    //   const node* link( ) const <----- const version
    //   node* link( ) <----------------- non-const version
    //   See the note (above) about the const version and non-const versions:
    //     Postcondition: The return value is the link from this node.

    // Set the data of the node.
    //  Postcondition: The node now contains the specified new data.
    void set_data(const value_type& new_data)
    {
      data_field_ = new_data;
    }

    // Sets the link of the node. 
    //  Postcondition: The node now contains the specified new link.
    void set_link(node* new_link)
    {
      link_field_ = new_link;
    }

    // Retrieves the current data:
    //  Postcondition: The return value is the data from this node.
    value_type data( ) const
    {
      return data_field_;
    }

    // Two slightly different member functions to retreive
    // the current link. See the notes above.
    const node* link( ) const
    {
      return link_field_;
    }

    node* link( )
    {
      return link_field_;
    }
	
  private:
    // The data for the node
    value_type data_field_;

    // The link to the next node.
    node* link_field_;
  };

  // FUNCTIONS for the linked list toolkit

  //  Precondition: head_ptr is the head pointer of a linked list.
  //  Postcondition: The value returned is the number of nodes in the linked
  //     list.
  std::size_t list_length (const node* head_ptr);

  //
  //  Precondition: head_ptr is the head pointer of a linked list.
  //  Postcondition: A new node containing the given entry has been added at
  //     the head of the linked list; head_ptr now points to the head of the new,
  //     longer linked list.
  //
  void list_head_insert (node*& head_ptr,
                         const node::value_type& entry); 
  
  //  Precondition: previous_ptr points to a node in a linked list.
  //  Postcondition: A new node containing the given entry has been added
  //     after the node that previous_ptr points to.
  //
  void list_insert (node* previous_ptr,
                    const node::value_type& entry);  

  //  See the note (above) about the const version and non-const versions:
  //  Precondition: head_ptr is the head pointer of a linked list.
  //  Postcondition: The pointer returned points to the first node containing
  //     the specified target in its data member. If there is no such node, the
  //     null pointer is returned.
  //
  node* list_search (node* head_ptr,
                     const node::value_type& target);

  const node* list_search (const node* head_ptr,
                           const node::value_type& target);

  //  See the note (above) about the const version and non-const versions:
  //  Precondition: head_ptr is the head pointer of a linked list, and
  //     position > 0.
  //  Postcondition: The pointer returned points to the node at the specified
  //     position in the list. (The head node is position 1, the next node is
  //     position 2, and so on). If there is no such position, then the null
  //     pointer is returned.
  node* list_locate (node* head_ptr,
                     std::size_t position);

  const node* list_locate (const node* head_ptr,
                           std::size_t position);

  //  Precondition: head_ptr is the head pointer of a linked list, with at
  //     least one node.
  //  Postcondition: The head node has been removed and returned to the heap;
  //     head_ptr is now the head pointer of the new, shorter linked list.
  void list_head_remove (node*& head_ptr);

  //  Precondition: previous_ptr points to a node in a linked list, and this
  //     is not the tail node of the list.
  //  Postcondition: The node after previous_ptr has been removed from the
  //     linked list.
  void list_remove (node* previous_ptr);

  //  Precondition: head_ptr is the head pointer of a linked list.
  //  Postcondition: All nodes of the list have been returned to the heap,
  //     and the head_ptr is now NULL.
  void list_clear (node*& head_ptr);

  //  Precondition: source_ptr is the head pointer of a linked list.
  //  Postcondition: head_ptr and tail_ptr are the head and tail pointers for
  //     a new list that contains the same items as the list pointed to by
  //     source_ptr. The original list is unaltered.
  void list_copy (const node* source_ptr,
                  node*& head_ptr,
                  node*& tail_ptr);
}

#endif