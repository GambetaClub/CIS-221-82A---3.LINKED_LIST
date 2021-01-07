// Provided by:   ____________(your name here)__________
// Lab:           ____________(the lab number here)________
// Course number: ____________(the course number here)________
// FILE: sequence.h
// CLASS PROVIDED: sequence (part of the namespace main_savitch_5) which uses
//                 a linked list implementation.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
//
// DYNAMIC MEMORY USAGE by the List
//   If there is insufficient dynamic memory, then the following functions
//   throw a BAD_ALLOC exception: The constructors, insert, attach. 


#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include "node.h"  // Provides node class

namespace main_savitch_5
{
  class sequence
  {
  public:
    // TYPEDEFS and MEMBER CONSTANTS for the sequence class:

    // sequence::value_type is the data type of the items in the sequence.
    // It may be any of the C++ built-in types (int, char, etc.), or a
    // class with a default constructor, an assignment operator, and a
    // copy constructor.
    typedef double value_type;

    // sequence::size_type is the data type of any variable that keeps
    // track of how many items are in a sequence.
    typedef std::size_t size_type;

    // CONSTRUCTORS and DESTRUCTOR

    // CONSTRUCTOR
    // Postcondition: The sequence has been initialized as an empty sequence.
    sequence( );

    // COPY CONSTRUCTOR
    // Postcondition: The sequence has been initialized to the sequence
    //   passed in.
    sequence(const sequence& source);

    // DESTRUCTOR
    // Postcondition: The memory allocated for the object has been released.
    ~sequence( );

    // MODIFICATION MEMBER FUNCTIONS

    // Postcondition: The first item on the sequence becomes the current item
    //   (but if the sequence is empty, then there is no current item).
    void start( );

    // Precondition: is_item returns true.
    // Postcondition: If the current item was already the last item in the
    //   sequence, then there is no longer any current item. Otherwise, the new
    //   current item is the item immediately after the original current item.
    void advance( );

    // Postcondition: A new copy of entry has been inserted in the sequence
    //   before the current item. If there was no current item, then the new
    //   entry has been inserted at the front of the sequence. In either case,
    //   the newly inserted item is now the current item of the sequence.
    void insert(const value_type& entry);

    // Postcondition: A new copy of entry has been inserted in the sequence
    //   after the current item. If there was no current item, then the new
    //   entry has been attached to the end of the sequence. In either case,
    //   the newly inserted item is now the current item of the sequence.
    void attach(const value_type& entry);

    // Precondition: is_item returns true.
    // Postcondition: The current item has been removed from the sequence,
    //   and the item after this (if there is one) is now the new current item.
    void remove_current( );

    // Postcondition: The current object is equivalent to the object passed
    //   in.
    void operator =(const sequence& source);

    // CONSTANT MEMBER FUNCTIONS

    // Postcondition: The return value is the number of items in the sequence.
    size_type size( ) const;

    // Postcondition: A true return value indicates that there is a valid
    //   "current" item that may be retrieved by activating the current
    //   member function (listed below). A false return value indicates that
    //   there is no valid current item.
    bool is_item( ) const;

    //  Precondition: is_item( ) returns true.
    //  Postcondition: The item returned is the current item in the sequence.
    value_type current( ) const;

    //  Postcondition: The return value is true if both sequences contain no
    //    data items. Also, if the length is greater than zero, then the
    //    sequences must contain the same number of items and the items at the
    //    same location must be equal.
    bool operator ==(const sequence& other) const;

    //  Postcondition: The return value is false if both sequences contain no
    //    data items. Also, if the length is greater than zero, then the
    //    sequences must not contain the same number of items or the items at
    //    the same location must not be equal.
    bool operator !=(const sequence& other) const;

  private:
    // DATA MEMBERS

    // Pointer to the first node in the list.
    node *head_ptr_;

    // Pointer to the last node in the list (as a convenience).
    node *tail_ptr_;

    // Pointer to the current node in the list.
    node *cursor_;

    // Pointer to the node previous to the current node (for convenience).
    node *precursor_;

    // Number of nodes in the linked list (as a convenience).
    size_type node_count_;
  };
}

#endif