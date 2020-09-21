// File name: ScopedArray.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 2
// Description: This template class defines a ScopedArray object of any data type.
// Honor statement: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.
// Last Changed: 9/20/20
#ifndef SCOPEDARRAY_H
#define SCOPEDARRAY_H

// Just include the special AllocationTracker class
#include "AllocationTracker.h"

template <typename T> class ScopedArray {
public:
    /**
     * @brief Overloaded bool operator
     * @details Overloaded bool operator
     * @author  Nishant Jain
     */
    explicit operator bool() const;

    /**
     * @brief Const [] operator
     * @details Overloaded const [] operator
     * @author  Nishant Jain
     */
    const T& operator[](std::size_t position) const;

    /**
     * @brief Non-Const [] operator
     * @details Overloaded non-const [] operator
     * @author  Nishant Jain
     */
    T& operator[](std::size_t position);

    /**
     * @brief   Creates a new ScopedArray object
     * @details Overloaded constructor
     * @author  Nishant Jain
     */
    explicit ScopedArray(T* arrayPtr = nullptr);

    /**
     * @brief   Creates a new ScopedArray object through another ScopedArray object.
     * @details Copy constructor
     * @author  Nishant Jain
     */
    ScopedArray(const ScopedArray<T>& rhs) = delete;

    /**
     * @brief   Creates a new ScopedArray object through assignment of another ScopedArray object.
     * @details Assignment operator
     * @author  Nishant Jain
     */
    const ScopedArray<T>& operator=(ScopedArray<T>& array) = delete;

    /**
     * @brief   Deallocates memory for the ScopedArray object.
     * @details Destructor
     * @author  Nishant Jain
     * @pre: ScopedArray object exists.
     * @post: ScopedArray object is destroyed.
     */
    ~ScopedArray();

    /**
     * @brief   Returns the mArray object for a ScopedArray
     * @details get() returns a pointer to the mArray for the ScopedArray object
     * @author  Nishant Jain
     * @pre: None
     * @post: Pointer to the memory occupied by ScopedArray is returned
     */
    T* get() const;

    /**
     * @brief   Resets the mArray pointer for a ScopedArray object to another object
     * @details Overloaded reset() resets the mArray pointer to the array param.
     * @author  Nishant Jain
     * @pre: The ScopedArray object is not reset.
     * @post: The ScopedArray object is reset to point to the new data.
     */
    void reset(T* array = nullptr);

    /**
     * @brief   Swaps the data fields for two ScopedArray objects.
     * @details swap()
     * @author  Nishant Jain
     * @pre: Two ScopedArray objects are not swapped.
     * @post: Two ScopedArray objects are swapped.
     */
    void swap(ScopedArray<T>&);

    /**
     * @brief   Releases the dynamic memory allocated by a SimpleArray object
     * @details release()
     * @author  Nishant Jain
     * @pre: ScopedArray object is not released
     * @post: ScopedArray memory is released.
     */
    T* release();

private:
    T* mArray;
};

#include "../src/ScopedArray.cpp"
#endif // SCOPEDARRAY_H