// Provided by:   ____________(Mariano Augusto Jalif)__________
// Lab:           ____________(#3)________
// Course number: ____________(CIS-221-82A)________
// FILE: sequence.cpp

// This program creates a sequence class via a linked list.
// It has many functions for the purpose of its use.

// I haven't neither shown nor copied code from/to anybody.
// I also state that I typed everything in this code on my own.
// I haven't watched anyone's code.

#include "sequence.h"
#include "node.h" // Provides node class
#include <cassert>
#include <cstdlib>

namespace main_savitch_5
{
// CONSTRUCTOR
// Postcondition: The sequence has been initialized as an empty sequence.
sequence::sequence()
{
    head_ptr_ = NULL;
    tail_ptr_ = NULL;
    cursor_ = NULL;
    precursor_ = NULL;
    node_count_ = 0;
}

// COPY CONSTRUCTOR
// Postcondition: The sequence has been initialized to the sequence
//   passed in.
sequence::sequence(const sequence& source)
{
    node_count_ = source.node_count_;
    list_copy(source.head_ptr_, head_ptr_, tail_ptr_);
    node* funny_ptr = source.head_ptr_;
    precursor_ = head_ptr_;

    // Checking all the cases for cursor and precursor.
    if (source.cursor_ == NULL)
    {
        if (source.precursor_ == NULL)
        {
            cursor_ = NULL;
            precursor_ = NULL;
        }
        else
        {
            cursor_ = NULL;
            precursor_ = tail_ptr_;
        }
    }
    else
    {
        if (source.precursor_ == NULL)
        {
            cursor_ = head_ptr_;
            precursor_ = NULL;
        }
        else
        {
            while (funny_ptr != source.precursor_)
            {
                funny_ptr = funny_ptr->link();
                precursor_ = precursor_->link();
            }
            cursor_ = precursor_->link();
        }
    }
}

// DESTRUCTOR
// Postcondition: The memory allocated for the object has been released.
sequence::~sequence()
{
    list_clear(head_ptr_);
    node_count_ = 0;
}

// MODIFICATION MEMBER FUNCTIONS

// Postcondition: The first item on the sequence becomes the current item
//   (but if the sequence is empty, then there is no current item).
void sequence::start()
{
    cursor_ = head_ptr_;
    precursor_ = NULL;
}

// Precondition: is_item returns true.
// Postcondition: If the current item was already the last item in the
//   sequence, then there is no longer any current item. Otherwise, the new
//   current item is the item immediately after the original current item.
void sequence::advance()
{
    assert(is_item());
    // Checking if the cursor is the last element in the sequence.
    // If so, then there is no current item.
    if (cursor_ == tail_ptr_)
    {
        precursor_ = NULL;
        cursor_ = NULL;
    }
    // If not, then it advances both cursors.
    else
    {
        precursor_ = cursor_;
        cursor_ = cursor_->link();
    }
}

// Postcondition: A new copy of entry has been inserted in the sequence
//   before the current item. If there was no current item, then the new
//   entry has been inserted at the front of the sequence. In either case,
//   the newly inserted item is now the current item of the sequence.
void sequence::insert(const value_type& entry)
{
    // If there is no current item, then it adds
    // the element to the head of the sequence.
    if (!is_item())
    {
        list_head_insert(head_ptr_, entry);
        cursor_ = head_ptr_;
        precursor_ = NULL;
        if (node_count_ == 0)
        {
            tail_ptr_ = head_ptr_;
        }
    }
    else
    {
        // If the current item is the head node
        // then it adds the item after
        if (precursor_ == NULL)
        {
            list_head_insert(head_ptr_, entry);
            cursor_ = head_ptr_;
            precursor_ = NULL;
        }
        else
        {
            list_insert(precursor_, entry);
            cursor_ = precursor_->link();
        }
    }
    node_count_++;
}

// Postcondition: A new copy of entry has been inserted in the sequence
//   after the current item. If there was no current item, then the new
//   entry has been attached to the end of the sequence. In either case,
//   the newly inserted item is now the current item of the sequence.
void sequence::attach(const value_type& entry)
{
    // Checking all the cases for cursor and precursor.
    if (is_item())
    {
        if (cursor_->link() == NULL)
        {
            list_insert(cursor_, entry);
            precursor_ = cursor_;
            cursor_ = cursor_->link();
            tail_ptr_ = cursor_;
        }
        else
        {
            list_insert(cursor_, entry);
            precursor_ = cursor_;
            cursor_ = cursor_->link();
        }
    }
    else
    {
        if (node_count_ == 0)
        {
            list_head_insert(head_ptr_, entry);
            tail_ptr_ = head_ptr_;
            cursor_ = head_ptr_;
            precursor_ = NULL;
        }
        else
        {
            list_insert(tail_ptr_, entry);
            precursor_ = tail_ptr_;
            tail_ptr_ = tail_ptr_->link();
            cursor_ = tail_ptr_;
        }
    }
    node_count_++;
}

// Precondition: is_item returns true.
// Postcondition: The current item has been removed from the sequence,
//   and the item after this (if there is one) is now the new current item.
void sequence::remove_current()
{
    assert(is_item());
    // If there is just one item in the sequence, the only function
    // that can remove this element is list_head_remove since there
    // isn't precursor.
    if (cursor_ == head_ptr_ || size() == 1)
    {
        cursor_ = cursor_->link();
        list_head_remove(head_ptr_);
    }
    else
    {
        cursor_ = cursor_->link();
        list_remove(precursor_);
    }
    node_count_--;
}

// Postcondition: The current object is equivalent to the object passed
//   in.
void sequence::operator=(const sequence& source)
{
    // Checcking if both sequences are already equal.
    if (this == &source)
    {
        return;
    }
    list_clear(head_ptr_);
    node_count_ = source.node_count_;
    list_copy(source.head_ptr_, head_ptr_, tail_ptr_);
    node* funny_ptr = source.head_ptr_;
    precursor_ = head_ptr_;

    // Checking all the cases for cursor and precursor.
    if (source.cursor_ == NULL)
    {
        if (source.precursor_ == NULL)
        {
            cursor_ = NULL;
            precursor_ = NULL;
        }
        else
        {
            cursor_ = NULL;
            precursor_ = tail_ptr_;
        }
    }
    else
    {
        if (source.precursor_ == NULL)
        {
            cursor_ = head_ptr_;
            precursor_ = NULL;
        }
        else
        {
            while (funny_ptr != source.precursor_)
            {
                funny_ptr = funny_ptr->link();
                precursor_ = precursor_->link();
            }
            cursor_ = precursor_->link();
        }
    }
}

// CONSTANT MEMBER FUNCTIONS

// Postcondition: The return value is the number of items in the sequence.
sequence::size_type sequence::size() const
{
    return node_count_;
}

// Postcondition: A true return value indicates that there is a valid
//   "current" item that may be retrieved by activating the current
//   member function (listed below). A false return value indicates that
//   there is no valid current item.
bool sequence::is_item() const
{
    return (cursor_ != NULL);
}

//  Precondition: is_item( ) returns true.
//  Postcondition: The item returned is the current item in the sequence.
sequence::value_type sequence::current() const
{
    assert(is_item());
    return cursor_->data();
}

//  Postcondition: The return value is true if both sequences contain no
//    data items. Also, if the length is greater than zero, then the
//    sequences must contain the same number of items and the items at the
//    same location must be equal.
bool sequence::operator==(const sequence& other) const
{
    // If they both dont have elements so they are equal.
    if (node_count_ == 0 && other.node_count_ == 0)
    {
        return true;
    }
    // If they don't have the same amount of nodes, thet are not equal.
    if (node_count_ != other.node_count_)
    {
        return false;
    }
    // Comparing the data inside their nodes.
    node* ptr1 = other.head_ptr_;
    node* ptr2 = head_ptr_;

    while (ptr2 != NULL)
    {
        // As soon it finds a difference between their nodes
        // it returns false.
        if (ptr2->data() != ptr1->data())
        {
            return false;
        }
        // Else, it keeps looking.
        else
        {
            ptr1 = ptr1->link();
            ptr2 = ptr2->link();
        }
    }
    return true;
}

//  Postcondition: The return value is false if both sequences contain no
//    data items. Also, if the length is greater than zero, then the
//    sequences must not contain the same number of items or the items at
//    the same location must not be equal.
bool sequence::operator!=(const sequence& other) const
{
    return !(sequence::operator==(other));
}
}
