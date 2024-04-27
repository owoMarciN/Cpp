#include <iostream>
#include <vector>

int LomutoPartition(std::vector<int> &A, int start, int end){
	int pivot = A[end];
	int i = start-1;
	for(int j = start; j < end; j++){
		if(A[j] < pivot){
			i++;
			std::swap(A[i], A[j]);
		}
	}
	i++;
	std::swap(A[i], A[end]);
	return i;
	/* 
	Last 3 lines can be changed to: 
	1.	std::swap(A[i + 1], A[end]);
	2.	return i + 1;
	*/
}

void QuickSortLomuto(std::vector<int> &A, int start, int end){
	if(start < end){
		int pivot = LomutoPartition(A, start, end);
		QuickSortLomuto(A, start, pivot-1);		// Pivot - 1
		QuickSortLomuto(A, pivot+1, end);
	}
}

int HoarePartition(std::vector<int> &A, int start, int end){
	int x, i ,j;
	x = A[start];
	i = start - 1;
	j = end + 1;
	while(1){
		do{
			i++;
		}while(A[i] < x);
		do{
			j--;
		}while(A[j] > x);
		if(i >= j)	
			return j;
		std::swap(A[i], A[j]);
	}
		/* 
		Last 3 lines can be also:
		1.	if(i < j)
		2.		std::swap(A[i], A[j]);
		3.	else 
		4.		return j;
		*/
}

void QuickSortHoare(std::vector<int> &A, int start, int end){
	if(start < end){
		int pivot = HoarePartition(A, start, end);
		QuickSortHoare(A, start, pivot); 	// Here pivot is not the same as in Lomuto-Partition-QuickSort
		QuickSortHoare(A, pivot+1, end);
	}
}

void printVector(std::vector<int> A){
	for(int i = 0; i < A.size(); i++)
          std::cout << A.at(i) << " ";
	std::cout << std::endl;
}

int main(){
	int vectorSize;
	std::vector<int> A;
    srand(time(NULL));

  	std::cout<< "Provide the size of the array: ";
  	std::cin >> vectorSize;

	std::cout << "\nUsing Lomuto-Partition." << std::endl;

  	for(int i = 0; i < vectorSize; i++)
    	A.push_back(rand() % 200 + 1);

    std::cout << "Before:\n";
    printVector(A);

  	QuickSortLomuto(A, 0, A.size()-1);

    std::cout << "After:\n";
  	printVector(A);

	std::cout << "\nUsing Hoare-Partition." << std::endl;

	for(int i = 0; i < A.size(); i++)
    	A[i] = rand() % 200 + 1;

    std::cout << "Before:\n";
    printVector(A);

  	QuickSortHoare(A, 0, A.size()-1);

    std::cout << "After:\n";
  	printVector(A);

  	return 0;
}
