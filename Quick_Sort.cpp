#include<iostream>

int partition(int * tab, int start, int end){
	int pivot = tab[end];
	int i = start-1;
	for(int j = start; j < end; j++){
		if(tab[j] < pivot){
			i++;
			std::swap(tab[i], tab[j]);
		}
	}
	i++;
	std::swap(tab[i], tab[end]);

	return i;
}

void quick_sort(int *tab, int start, int end){
	if(end <= start){
		return;
	}
	int pivot = partition(tab, start, end);
	quick_sort(tab, start, pivot-1);
	quick_sort(tab, pivot+1, end);
}



int main(){

	int *tab, n;
    srand(time(NULL));

  	std::cout<< "How many random numbers to sort?: ";
  	std::cin >> n;

  	tab = new int [n];

  	for(int i = 0; i < n; i++)
    	tab[i] = rand() % 500 +1;

    std::cout << "Before:\n";

    for(int i = 0; i < n; i++)
          std::cout << tab[i] << " ";

  	quick_sort(tab, 0, n-1);

    std::cout << "\nAfter:\n";

  	for(int i = 0; i < n; i++)
          std::cout << tab[i] << " ";
          
    std::cout << std::endl;

	delete [] tab;
  	return 0;
}