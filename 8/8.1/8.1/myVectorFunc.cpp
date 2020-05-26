/*#include "myVector.h"

using namespace std;

template<class U, int Size>
void myVector<U, Size>::newVectorSize(int newSize){
    U* new_v_array = new U [newSize];

    for (int i = 0; i < newSize; i++)
        if (i < nowSize)
            new_v_array[i] = v_array[i];
        else
            new_v_array[i] = 0;

    delete []v_array;

    v_array = new_v_array;
    nowSize = newSize;
}

template<class U, int Size>
void myVector<U, Size>::randomElements(int Max, int Min){
	for (int i = 0; i < nowSize; i++){
		v_array[i] = rand() % (Max - Min)+ Min;
	}
}

template<class U, int Size>
int myVector<U, Size>::getSize(){
	return nowSize;
}

/*template<class U, int Size>
U& myVector<U, Size>::operator [] (int i){
	if (i < 0)
		i = 0;
	if (i >= nowSize)
		this->newVectorSize(2 * nowSize);
	return v_array[i];
}*/
