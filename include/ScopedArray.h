//
// Created by Nishant Jain on 9/19/20.
//

#ifndef ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H
#define ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H

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
     * @brief   Deallocates memory for the ScopedAray object.
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
     * @brief   Resets the mArray pointer for a ScopedAray object to another object
     * @details Overloaded reset() resets the mArray pointer to the array param.
     * @author  Nishant Jain
     * @pre: The ScopedArray object is not reset.
     * @post: The ScopedArray object is reset to point to the new data.
     */
    void reset(T* array = nullptr);

    /**
     * @brief   Checks to see if the mArray is null or not.
     * @details isNonNull() returns true or false to see if mArray points to nullptr.
     * @author  Nishant Jain
     * @pre: none
     * @post: returns true or false depending on if ScopedArray is nullptr.
     */
    bool isNonNull(ScopedArray<T> array = nullptr) const;

    /**
     * @brief   Swaps the data fields for two SimpleArray objects.
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
     * @pre: SimpleArray object is not released
     * @post: SimpleArray memory is released.
     */
    T* release();

private:
    T* mArray;
};

#endif // ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H
#include "../src/ScopedArray.cpp"
