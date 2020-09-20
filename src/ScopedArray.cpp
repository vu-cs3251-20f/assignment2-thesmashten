//
// Created by Nishant Jain on 9/19/20.
//

#ifndef SCOPEDARRAY_CPP
#define SCOPEDARRAY_CPP

template <typename T> ScopedArray<T>::operator bool() const
{
    return mArray != nullptr;
}

template <typename T>
const T& ScopedArray<T> :: operator[](size_t position) const{
    return mArray[position];
}

template <typename T>
T& ScopedArray<T> :: operator[](std::size_t position){
    return mArray[position];
}

/**
 * @brief   Creates a new SimpleArray object with an AllocationTracker pointer as a param
 * @details Overloaded constructor
 * @author  Nishant Jain
 */
template <typename T>
ScopedArray<T>::ScopedArray(T* arrayPtr)
    : mArray(arrayPtr)
{
}

/**
 * @brief   Deallocates memory for the SimpleArray object.
 * @details Destructor
 * @author  Nishant Jain
 * @pre: SimpleArray object exists.
 * @post: SimpleArray object is destroyed.
 */
template <typename T> ScopedArray<T>::~ScopedArray<T>()
{
    delete[] mArray;
}

/**
 * @brief   Returns the mArray AllocationTracker object for a SimpleArray
 * @details get() returns a pointer to an Allocation Tracker
 * @author  Nishant Jain
 * @pre: None
 * @post: AllocatioNTracker pointer of the SimpleArray is returned
 */
template <typename T> T* ScopedArray<T>::get() const
{
    return mArray;
}

/**
 * @brief   Resets the mArray pointer for a SimpleArray object to another object
 * @details Overloaded reset() resets the mArray pointer to the array param.
 * @author  Nishant Jain
 * @pre: The SimpleArray oject is not reset.
 * @post: The SimpleArray object is reset to point to the new AllocationTracker.
 */
template <typename T> void ScopedArray<T>::reset(T* array)
{
    delete mArray;
    mArray = array;
}

/**
 * @brief   Swaps the data fields for two SimpleArray objects.
 * @details swap()
 * @author  Nishant Jain
 * @pre: Two SimpleArray objects are not swapped.
 * @post: Two SimpleArray objects are swapped.
 */
template <typename T> void ScopedArray<T>::swap(ScopedArray<T>& rhs)
{
    std :: swap(mArray, rhs.mArray);
}

/**
 * @brief   Releases the dynamic memory allocated by a SimpleArray object
 * @details release()
 * @author  Nishant Jain
 * @pre: SimpleArray object is not released
 * @post: SimpleArray memory is released.
 */
template <typename T> T* ScopedArray<T>::release()
{
    T* tracker(mArray);
    mArray = nullptr;
    return tracker;
}

#endif
