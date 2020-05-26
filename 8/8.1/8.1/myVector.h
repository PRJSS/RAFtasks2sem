#ifndef MYVECTOR_H_INCLUDED
#define MYVECTOR_H_INCLUDED

#include "Head.h"

using namespace std;

template<class U = int>
class myVector{
	int nowSize;
	U* v_array;
public:
	myVector(){
		nowSize = 10;
		v_array = new U [nowSize];
		for (int i = 0; i < nowSize; i++)
			v_array[i] = 0;
	}

	myVector(int n, U arr[]){
		nowSize = n;
		v_array = new U [nowSize];
		for (int i = 0; i < nowSize; i++){
			v_array[i] = arr[i];
		}
	}

	myVector(myVector &v){
		nowSize = v.nowSize;
		v_array = new U [nowSize];
		for (int i = 0; i < nowSize; i++)
			v_array[i] = v.v_array[i];
	}

	~myVector() {
        delete []v_array;
	};

	void newVectorSize(int newSize);

	void randomElements(int Max = 10, int Min = 0);

	int getSize();

	U& operator [] (int i);

	friend istream& operator >> (istream& in, myVector &v);

	friend ostream& operator << (ostream& out, myVector &v){
		for (int i = 0; i < v.getSize(); i++){
			out << v[i] << ' ';
		}
		out << '\n';
		return out;
	}
};

template<class U>
void myVector<U>::newVectorSize(int newSize){
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

template<class U>
void myVector<U>::randomElements(int Max, int Min){
	for (int i = 0; i < nowSize; i++){
		v_array[i] = rand() % (Max - Min)+ Min;
	}
}

template<class U>
int myVector<U>::getSize(){
	return nowSize;
}

template<class U>
U& myVector<U>::operator [] (int i){
	if (i < 0)
		i = 0;
	if (i >= nowSize)
		this->newVectorSize(2 * nowSize);
	return v_array[i];
}

//template<class U, int Size>
istream& operator >> (istream& in, myVector <> &v){
	cout << "Enter " << v.getSize() << " elements: ";
	for (int i = 0; i < v.getSize(); i++){
		in >> v[i];
	}
	return in;
}

#endif // MYVECTOR_H_INCLUDED
