/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Aug 5 2022          
   Workshop: 10 part - 1 
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
  

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
	//Find with 3 parameters/
	/**
	 * \brief checks if a key value matches an array item at a provided index
	 * \tparam T the same type as the Collection type
	 * \tparam K key type
	 * \param arr An array of template objects
	 * \param index An integer variable that represents the index to use in the comparison
	 * \param key value to search for
	 * \return if the element at index i of the array equals the key or not
	 */
	template<typename T, typename K>
	bool find(T arr, const int index, const K key)
	{
		return arr[index] == key;
	}

	//Find with 4 parameters
	/**
	 * \brief The find function template returns an int that represents the index of a found item that matches the 2 search keys
	 * \tparam T the same type as the Collection type
	 * \tparam K first key type
	 * \tparam P second key type
	 * \param arr An array of objects
	 * \param numElements An integer represents the number of elements in the array of objects
	 * \param key1 a key value as one of our search parameters
	 * \param key2 a key value as our second search parameter
	 * \return returns an int that represents the index of a found item that matches the 2 search keys, and returns -1 if no successful matches were found
	 */
	template<typename T, typename K, typename P>
	int find(Collection<T> arr, const int numElements, const K key1, const P key2)
	{
		for(int i = 0; i < numElements; ++i)
		{
			if(arr[i] == key1 && arr[i] == key2)
				return i;
		}
		return -1;
	}

	//Insertion operator
	/**
	 * \brief Lists all the elements of an array
	 * \tparam T the same type as the Collection type
	 * \param out a reference to an ostream object
	 * \param arr An array of objects
	 * \return a reference to an ostream object
	 */
	template<typename T>
	std::ostream& operator<<(std::ostream& out, Collection<T> arr)
	{
		for(int i = 0; i < arr.size(); ++i)
		{
			out << arr[i] << std::endl;
		}
		return out;
	}

	//Load Collection
	/**
	 * \brief It will add the new item to the collection
	 * \tparam T the same type as the Collection type
	 * \param arr An array of objects
	 * \param object object of the same type as the Collection which we want to add to collection
	 * \return a constant collection reference
	 */
	template<typename T>
	const Collection<T>& loadCollection(Collection<T>& arr, T object)
	{
		arr += object;
		return arr;
	}

}
#endif // !SDDS_SEARCH_H_

