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

#ifndef SCOPEDARRAY_CPP
#define SCOPEDARRAY_CPP

template <typename T> ScopedArray<T>::operator bool() const
{
    return mArray != nullptr;
}

template <typename T> const T& ScopedArray<T>::operator[](size_t position) const
{
    return mArray[position];
}

template <typename T> T& ScopedArray<T>::operator[](std::size_t position)
{
    return const_cast<T&>(const_cast<const ScopedArray<T>&>(*this)[position]);
}

template <typename T>
ScopedArray<T>::ScopedArray(T* arrayPtr)
    : mArray(arrayPtr)
{
}

template <typename T> ScopedArray<T>::~ScopedArray<T>()
{
    delete[] mArray;
}

template <typename T> T* ScopedArray<T>::get() const
{
    return mArray;
}

template <typename T> void ScopedArray<T>::reset(T* array)
{
    if (mArray != array) {
        delete[] mArray;
        mArray = array;
    }
}

template <typename T> void ScopedArray<T>::swap(ScopedArray<T>& rhs)
{
    std ::swap(mArray, rhs.mArray);
}

template <typename T> T* ScopedArray<T>::release()
{
    T* tracker(mArray);
    mArray = nullptr;
    return tracker;
}

#endif
