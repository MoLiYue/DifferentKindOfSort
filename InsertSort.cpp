#include <iostream>
/*
	time: 2021.1.24
	author: M.L.YUE
*/
using namespace std;

template<class T>
void InsertSort(T Array[], int n){	//Array为待排序数组，n为数组长度
	T temp;		//临时变量
	for(int i = 1; i < n; i++){		//依次插入第i个数据
		temp = Array[i];
		int j = i - 1;		//从第i个往前寻找第i个数据所在位置
		//将那些大于等于数据i的数据后移
		for(; j > -1 && (Array[j] > temp); j--){
			Array[j + 1] = Array[j];
		}
		//将第i个数据填入到他应该在的位置
		Array[j + 1] = temp;		
	}
}

template<class T>
void BinaryInsertSort(T Array[], int n){
	T temp;
	for(int i = 1; i < n; i++){
		int left = 0;
		int right = i - 1;
		temp = Array[i];
		while(left <= right){		//需要小于等于才能成立，第一轮运行时会用到等于的情况
			int middle = (left + right) / 2;
			if(temp > Array[middle])
				left = middle + 1;		//必须要加一
			else
				right = middle - 1;		//必须要减一
		}
		for(int j = i-1; j >= left; j--){	//必须是left
			Array[j+1] = Array[j];
		}
		Array[left] = temp;		//结束时left比right大一
	}
}

int main(){
	int i[5] = {3,1,2,4,5};
	BinaryInsertSort(i,5);
	for(int j = 0; j < 5; j++){
		cout<<i[j]<<"  ";
	}
	cout<<endl;
	return 0;
}