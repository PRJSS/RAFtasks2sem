//
//  main.cpp
//  5.4
//
//  Created by Danila Bernat on 2/10/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//


#include <iostream>


using namespace std;


void searchh(int *arr, int *max, int n){
    
    int i, j;
        int temp;
        // Сортировка массива пузырьком
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // меняем элементы местами
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        
        
        //кучкование массива
        
        int size=1;
        for (i=1; i<n; i++){
            if (arr[i]!=arr[i-1]){size++;}
        }
        //cout<<size;//кол-во разных чисел

        
        
        int matrix[2][size];
        matrix[0][0]=arr[0];
        matrix[1][0]=1;

        j=0;
        for (i=1; i<n; i++)
        {
            //if (i==n-1){matrix[j][1]++; break;}
            if (arr[i]!=arr[i+1] && i!=n-1){
                matrix[1][j]++;
                j++;
                matrix[1][j]=0;
                matrix[0][j]=arr[i+1];
            }else{
                matrix[1][j]++;
            }
        }

    //    for (i=0; i<size; i++){
    //        cout<<matrix[1][i]<<" ";
    //    }
    //СОРТИРОВКА ПУЗЫРЬКОМ
        
        for (int i = 0; i < size - 1; i++) {
               for (int j = 0; j < size - i - 1; j++) {
                   if (matrix[1][j] > matrix[1][j + 1]) {
                       // меняем элементы местами
                       temp = matrix[1][j];
                       matrix[1][j] = matrix[1][j + 1];
                       matrix[1][j + 1] = temp;
                       ///
                       temp = matrix[0][j];
                       matrix[0][j] = matrix[0][j + 1];
                       matrix[0][j + 1] = temp;
                   }
               }
           }
        
            for (i=0; i<size; i++){
                cout<<matrix[0][i]<<" ";
            }
        cout<<"\n";
        for (i=0; i<size; i++){
               cout<<matrix[1][i]<<" ";
           }
        
        
       //поиск максимального редкого
        *max=matrix[0][0];
        i=1;
        while(matrix[1][i]==matrix[1][i-1] || i==0){
            if (matrix[0][i]>*max){*max=matrix[0][i];}
            i++;
        }
}





int main() {
    
    int i, max=0;
    
    int n;
    
    cout<<"n=";
    cin>>n;
    
    int* arr;
    arr = new int[n];
   
    
    for (i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"//////////////////\n";
    
    searchh(arr, &max, n);
    
    cout<<"\n"<<max<<" <<<<< ответ\n";
    
    
    
    
}
