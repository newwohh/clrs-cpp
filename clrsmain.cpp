#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
typedef long long lld;
#define ROW_1 4
#define COL_1 4
#define ROW_2 4
#define COL_2 4
// Introduction to algorithms book problems and exercises also

// Chapter 1 (no practical problems)

// Chapter 2 - Getting Started

// Insertion sort 

void insertionSort(int A[],int n )
{
    for(int i = 1;i<n;i++){
        int current = A[i]; // current remains unchanged
        int previous = i - 1;
        // insert current[i] into the sorted sequence
        
        while(previous>=0 && A[previous] > current){
            A[previous+1] = A[previous];
            previous = previous - 1;
        }

        A[previous+1] = current;
    }

    int i;
    for (i = 0; i < n; i++)
        cout << A[i] << "\n"; // for outputting 
    cout << endl;
}


// Merge sort 

void merge(int A[],int lb, int mid,int ub){
    int subArrayOne = mid - lb + 1; // number for loop, (+ 1) because when the function calls the array parameter will be index based  
    int subArrayTwo = ub - mid; // number for loop

    auto *leftArray = new int[subArrayOne],
    *rightArray = new int[subArrayTwo];

    for(int i = 0; i<subArrayOne;i++){
        leftArray[i] = A[lb + i];// copying to dummy array
    }

    for(int j = 0;j<subArrayTwo;j++){
        rightArray[j] = A[mid + 1 + j];
    }


    int fromSubArrayOne = 0,
     fromSubArrayTwo = 0;

    int fromMergedArray = lb;

while(fromSubArrayOne < subArrayOne && fromSubArrayTwo < subArrayTwo){
    if(leftArray[fromSubArrayOne] <= rightArray[fromSubArrayTwo]){
        A[fromMergedArray] = leftArray[fromSubArrayOne];

        fromSubArrayOne++;
    }else{
        A[fromMergedArray] = rightArray[fromSubArrayTwo];

        fromSubArrayTwo++;
    }
    fromMergedArray++;
}

while(fromSubArrayOne < subArrayOne){ // for merging the elements left in the sub arrays
        A[fromMergedArray] = leftArray[fromSubArrayOne];
        fromMergedArray++;
        fromSubArrayOne++;   
}

while(fromSubArrayTwo < subArrayTwo){
       A[fromMergedArray] = rightArray[fromSubArrayTwo];
        fromMergedArray++;
        fromSubArrayTwo++; 
}

    delete[]leftArray;
    delete[]rightArray;

}


void mergeSort(int A[],int lb,int ub){
    if(lb>=ub)
        return;
    

    int mid = lb + (ub-lb)/2;
    mergeSort(A,lb,mid);// recursive function - function stops until the sub array has only one element
    mergeSort(A,mid+1,ub);
    merge(A,lb,mid,ub);
}

void printArray(int A[], int size) // For printing merge sort function 
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Bubble sort

void bubbleSort(int A[],int size){
int j,i,k;

for(i = 0;i<size - 1;i++){

    for(j=0;j<size-i-1;j++){
        if(A[j]>A[j+1]){
            swap(A[j],A[j+1]);
        }    
    }

}

for(k = 0;k<size;k++){
    cout << A[k] << "  ";
    cout << endl;
}

}

//Horner's rule for finding polynomials

void hornerRule(int A[],int n ,int x){
    int ans = A[0];

    for(int i = 1;i<n;i++){
        ans  = ans*x + A[i];
    }

    cout <<"\n"<< ans <<endl;
}

// finding maximum sub array

int max(int a, int b) { return (a > b) ? a : b; }
  
int max(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(int arr[],int l,int m,int h){

    int sum = 0;
    int left_sum = INT_MIN;

    for(int i=m;i>=l;i--){
        sum = sum + arr[i];
        if(sum>left_sum)
        left_sum = sum;
    } 

    sum = 0;
    int right_sum = INT_MIN;
    for(int i = m;i<=h;i++){
        sum = sum + arr[i];
        if(sum>right_sum)
        right_sum = sum;
    }


    return max(left_sum + right_sum - arr[m],left_sum,right_sum);

}

int maxSubarraySum(int arr[],int l, int h){

    if(l>h)
        return INT_MIN;

    if(l==h)
        return arr[l];

    int m = (l+h)/2;

    return max(maxSubarraySum(arr,l,m-1),
        maxSubarraySum(arr,m+1,h),
        maxCrossingSum(arr,l,m,h));
}

// matrix multiplication

void print(string display, vector<vector<int> > matrix,
           int start_row, int start_column, int end_row,
           int end_column)
{
    cout << endl << display << " =>" << endl;
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            cout << setw(10);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void add_matrix(vector<vector <int> > matrix_A,vector<vector<int> > matrix_B,vector<vector <int> > & matrix_C,int split_index ){
    for(auto i = 0;i<split_index;i++){
        for(auto j = 0;j<split_index;j++){
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
}

vector <vector <int> > multiply_matrix(vector <vector <int> > matrix_A,vector <vector <int> > matrix_B){
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if(col_1 != row_2){
        cout << "ERROR" << "\n";
        return{};
    }

    vector<int> result_matrix_row(col_2,0);
    vector<vector <int> > result_matrix(row_1,result_matrix_row);


    if(col_1 ==1)
    result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else{
        int split_index = col_1/2;

        vector<int> row_vector(split_index,0);
        vector<vector <int> > result_matrix_00(split_index,row_vector);
        vector<vector <int> > result_matrix_01(split_index,row_vector);
        vector<vector <int> > result_matrix_10(split_index,row_vector);
        vector<vector <int> > result_matrix_11(split_index,row_vector);

        vector<vector <int> > a00(split_index,row_vector);
        vector<vector <int> > a01(split_index,row_vector);
        vector<vector <int> > a10(split_index,row_vector);
        vector<vector <int> > a11(split_index,row_vector);
        vector<vector <int> > b00(split_index,row_vector);
        vector<vector <int> > b01(split_index,row_vector);
        vector<vector <int> > b10(split_index,row_vector);
        vector<vector <int> > b11(split_index,row_vector);
    

        for(auto i = 0;i < split_index;i++)
            for(auto j = 0;j < split_index;j++){
            a00[i][j] = matrix_A[i][j];
            a01[i][j] = matrix_A[i][j + split_index];
            a10[i][j] = matrix_A[split_index + i][j];
            a11[i][j] = matrix_A[split_index + i][j + split_index];

            b00[i][j] = matrix_B[i][j];
            b01[i][j] = matrix_B[i][j + split_index];
            b10[i][j] = matrix_B[i + split_index][j];
            b11[i][j] = matrix_B[i + split_index][j + split_index];
    
        }

        add_matrix(multiply_matrix(a00,b00),
        multiply_matrix(a01,b10),result_matrix_00,split_index);

        add_matrix(multiply_matrix(a00,b01),
        multiply_matrix(a01,b11),result_matrix_01,split_index);

        add_matrix(multiply_matrix(a10,b00),
        multiply_matrix(a11,b10),result_matrix_10,split_index);

        add_matrix(multiply_matrix(a10,b01),
        multiply_matrix(a11,b11),result_matrix_11,split_index);
    

        for(auto i = 0;i < split_index;i++)
            for(auto j = 0;j < split_index;j++){
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[i + split_index][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }



        result_matrix_00.clear();    
        result_matrix_01.clear();    
        result_matrix_10.clear();    
        result_matrix_11.clear();    
    
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;
}

// strassen's method for matrix multiplication

void printStrassaen(string display,vector<vector<int> > matrix,int start_row,int start_column,int end_row,int end_column){

    cout << endl << display << "=>" << endl;
    for(int i = start_row;i<=end_row;i++){
        for( int j= start_column;j<=end_column;j++){
            cout << setw(10);
            cout << matrix[i][j];
        }
    cout << endl;
    }
    cout << endl;
    return;
}

vector<vector<int> > add_matrix_strassen(vector<vector<int> > matrix_A,vector<vector<int> > matrix_B,int split_index,int multiplier = 1){
    for(auto i = 0;i<split_index;i++){
        for(auto j=0;j<split_index;j++){
            matrix_A[i][j] = (matrix_A[i][j] + multiplier*matrix_B[i][j]);
        }
    }
    return matrix_A;
}

vector<vector <int> > multiply_matrix_strassen(vector<vector<int> > matrix_A,vector<vector<int> > matrix_B){
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if(col_1 != row_2){
        cout  << "Error" << endl;
        return {};
    }

    vector<int> result_matrix_row(col_2,0);
    vector<vector <int> > result_matrix(row_1,result_matrix_row);

    if(col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
        else{
            int split_index = col_1/2;
            vector<int> row_vector(split_index,0);

            vector<vector<int> > a00(split_index,row_vector);
            vector<vector<int> > a01(split_index,row_vector);
            vector<vector<int> > a10(split_index,row_vector);
            vector<vector<int> > a11(split_index,row_vector);
            vector<vector<int> > b00(split_index,row_vector);
            vector<vector<int> > b01(split_index,row_vector);
            vector<vector<int> > b10(split_index,row_vector);
            vector<vector<int> > b11(split_index,row_vector);

            for(auto i = 0;i<split_index;i++){
                for(auto j = 0;j<split_index;j++){
                    a00[i][j] = matrix_A[i][j];
                    a01[i][j] = matrix_A[i][j+split_index];
                    a10[i][j] = matrix_A[split_index + i][j];
                    a11[i][j] = matrix_A[split_index + i][split_index + j];

                    b00[i][j] = matrix_B[i][j];
                    b01[i][j] = matrix_B[i][j+split_index];
                    b10[i][j] = matrix_B[split_index + i][j];
                    b11[i][j] = matrix_B[split_index + i][split_index + j];

                }
            }

            vector<vector<int> > p(multiply_matrix_strassen(a00,add_matrix_strassen(b01,b11,split_index,-1)));
            vector<vector<int> > q(multiply_matrix_strassen(add_matrix_strassen(a00,a01,split_index),b11));
            vector<vector<int> > r(multiply_matrix(add_matrix_strassen(a10,a11,split_index),b00));
            vector<vector<int> > s(multiply_matrix_strassen(a11,add_matrix_strassen(b10,b00,split_index,-1)));
            vector<vector<int> > t(multiply_matrix_strassen(add_matrix_strassen(a00,a11,split_index),add_matrix_strassen(b00,b11,split_index)));
            vector<vector<int> > u(multiply_matrix_strassen(add_matrix_strassen(a01,a11,split_index,-1),add_matrix_strassen(b00,b01,split_index)));
            vector<vector<int> > v(multiply_matrix_strassen(add_matrix_strassen(a00,a10,split_index,-1),add_matrix_strassen(b00,b01,split_index)));

            vector<vector<int> > result_matrix_00(add_matrix_strassen(add_matrix_strassen(add_matrix_strassen(t,s,split_index),u,split_index),q,split_index,-1));
            vector<vector<int> > result_matrix_01(add_matrix_strassen(p,q,split_index));
            vector<vector<int> > result_matrix_10(add_matrix_strassen(r,s,split_index));
            vector<vector<int> > result_matrix_11(add_matrix_strassen(add_matrix_strassen(add_matrix_strassen(t,p,split_index),r,split_index,-1),v,split_index,-1));

            for(auto i=0;i<split_index;i++){
                for(auto j = 0;j<split_index;j++){
                    result_matrix[i][j] = result_matrix_00[i][j];
                    result_matrix[i][j+split_index] = result_matrix_01[i][j];
                    result_matrix[split_index+i][j] = result_matrix_10[i][j];
                    result_matrix[i+split_index][j+split_index] = result_matrix_11[i][j];
                }
            }

            a00.clear();
            a01.clear();
            a10.clear();
            a11.clear();
            b00.clear();
            b01.clear();
            b10.clear();
            b11.clear();

            p.clear();
            q.clear();
            r.clear();
            s.clear();
            t.clear();
            u.clear();
            v.clear();

            result_matrix_00.clear();
            result_matrix_01.clear();
            result_matrix_10.clear();
            result_matrix_11.clear();
        }
        return result_matrix;
}

int main() 
{
    
    int A[] = {1, 23, 4, 45};
    int N =4;
    cout << "Insertion sort \n";
    insertionSort(A, N);
    
    int arr[] = { 3, 41, 52, 26, 38, 57, 9, 49};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Merge Sort \n";
    mergeSort(arr, 0, arr_size - 1);
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);

    int bsArr[] = {1,2,3,6,5,4};
    int sizeOfBs = sizeof(bsArr) / sizeof(bsArr[0]); 
    cout << "\nBubble sort \n";
    bubbleSort(bsArr,sizeOfBs);

    int poly[] = {2, -6, 2, -1};
    int x = 3;
    int n = sizeof(poly)/sizeof(poly[0]);
    cout << "Horner's rule";
    hornerRule(poly,n,x);

    int maxArr[] =  {2, 3, 4, 5, 7 };
    int maxn = sizeof(maxArr) / sizeof(maxArr[0]);
    int max_sum = maxSubarraySum(maxArr, 0, maxn - 1);
    printf("Maximum contiguous sum is %d\n", max_sum);
    getchar();

    vector<vector<int> > matrix_A = { { 1, 1, 1, 1 },
                                      { 2, 2, 2, 2 },
                                      { 3, 3, 3, 3 },
                                      { 2, 2, 2, 2 } };
    print("Array A", matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);
    vector<vector<int> > matrix_B = { { 1, 1, 1, 1 },
                                      { 2, 2, 2, 2 },
                                      { 3, 3, 3, 3 },
                                      { 2, 2, 2, 2 } };
    print("Array B", matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);
    vector<vector<int> > result_matrix(multiply_matrix(matrix_A, matrix_B));
    print("Result Array", result_matrix, 0, 0, ROW_1 - 1,
          COL_2 - 1);

    vector<vector<int> > Strassen_matrix_A = { { 1, 1, 1, 1 },
                                      { 2, 2, 2, 2 },
                                      { 3, 3, 3, 3 },
                                      { 2, 2, 2, 2 } };
 
    printStrassaen("Array A", Strassen_matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);
 
    vector<vector<int> > Strassen_matrix_B = { { 1, 1, 1, 1 },
                                      { 2, 2, 2, 2 },
                                      { 3, 3, 3, 3 },
                                      { 2, 2, 2, 2 } };
 
    printStrassaen("Array B", Strassen_matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);
 
    vector<vector<int> > Strassen_result_matrix(
        multiply_matrix(Strassen_matrix_A, Strassen_matrix_B));
 
    print(" Strassen Result Array", Strassen_result_matrix, 0, 0, ROW_1 - 1,
          COL_2 - 1);

    return 0;

}