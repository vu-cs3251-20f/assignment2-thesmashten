//
// Created by Nishant Jain on 9/19/20.
//

#ifndef ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H
#define ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H

// Just include the special AllocationTracker class
#include "AllocationTracker.h"

template <typename T> class ScopedArray {
public:
    operator bool() const;
    const T& operator[](std::size_t position) const;
    T& operator[](std::size_t position);
    /*
     * @brief   Creates a new SimpleArray object with an AllocationTracker pointer as a param
     * @details Overloaded constructor
     * @author  Nishant Jain
     */
    explicit ScopedArray(T* arrayPtr = nullptr);

    /*
     * @brief   Creates a new ScopedArray object through another ScopedArray object.
     * @details Copy constructor
     * @author  Nishant Jain
     */
    ScopedArray(const ScopedArray<T>& rhs) = delete;

    /**
     * @brief   Creates a new SimpleArray object through assignment of another SimpleArray object.
     * @details Assignment operator
     * @author  Nishant Jain
     */
    const ScopedArray<T>& operator=(ScopedArray<T>& array) = delete;

    /**
     * @brief   Deallocates memory for the SimpleArray object.
     * @details Destructor
     * @author  Nishant Jain
     * @pre: SimpleArray object exists.
     * @post: SimpleArray object is destroyed.
     */
    ~ScopedArray();

    /**
     * @brief   Returns the mArray AllocationTracker object for a SimpleArray
     * @details get() returns a pointer to an Allocation Tracker
     * @author  Nishant Jain
     * @pre: None
     * @post: AllocatioNTracker pointer of the SimpleArray is returned
     */
    T* get() const;

    /**
     * @brief   Resets the mArray pointer for a SimpleArray object to another object
     * @details Overloaded reset() resets the mArray pointer to the array param.
     * @author  Nishant Jain
     * @pre: The ScopedArray object is not reset.
     * @post: The SimpleArray object is reset to point to the new AllocationTracker.
     */
    void reset(T* array = nullptr);

    /**
     * @brief   Checks to see if the mArray is null or not.
     * @details isNonNull() returns true or false to see if mArray points to nullptr.
     * @author  Nishant Jain
     * @pre: none
     * @post: returns true or false depending on if SimpleArray mArray is nullptr.
     */
    bool isNonNull(ScopedArray<T> array = nullptr) const;

    /**
     * @brief   Swaps the data fields for two SimpleArray objects.
     * @details swap()
     * @author  Nishant Jain
     * @pre: Two SimpleArray objects are not swapped.
     * @post: Two SimpleArray objects are swapped.
     */
    void swap(ScopedArray<T>&);

    /**
     * @brief   Releases the dynamic memory allocated by a SimpleArray object
     * @details release()
     * @author  Nishant Jain
     * @pre: SimpleArray object is not released
     * @post: SimpleArray memory is released.
     */
    T* release();

private:
    T* mArray;
};

#endif // ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H
#include "../src/ScopedArray.cpp"
