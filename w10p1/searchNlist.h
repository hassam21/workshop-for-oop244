/*******************************************************************
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 03rd August,2024
WORKSHOP     : 10


I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments.
*********************************************************************/

#ifndef SENECA_SEARCHNLIST_H_
#define SENECA_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"

using namespace std;
namespace seneca {
    template <typename T1,typename T2>
    bool search(Collection<T1>& C,const T1* arr,int arr_size,T2 key){
        bool ret{};
        for (int i = 0; i < arr_size; ++i) {
            if(arr[i] == key){
                C.add(arr[i]);
                ret = true;
            }
        }
        return ret;
    }
    template <typename T>
    void listArrayElements(const char* title,const T* arr,int arr_size){
        cout << title << endl;
        for (int i = 0; i < arr_size; ++i) {
            cout << i+1 << ": ";
            cout << arr[i] << endl;
        }


    }
}

#endif // !SENECA_SEARCHNLIST_H_