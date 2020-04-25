#include <iostream>

const int MAX_ARRAY_SIZE = 1000000;

void input_array(double *array, int16_t n) {
	std::cout << "Loading random numbers" << '\n';
	
	for (int i = 0; i < n; i++) 
		array[i] = rand() % 1000;
}

void merge_sort(double *array, int16_t n) {
	
	if (n <= 1) return; // !!!
	
	int16_t middle = n / 2;
	
	double *left = array;
	double *right_ight = array + middle;
	
	int16_t left_n = middle;
	int16_t	right_ight_n = n - left_n;
	
	// recursion
	merge_sort(left, left_n);
	merge_sort(right_ight, right_ight_n);
	
	// merge
	double *buffer = new double[n];
	
	int16_t left_i = 0;
	int16_t right_i = 0;
	int16_t buffer_i = 0;
	
	while(left_i < left_n and right_i < right_ight_n) {
		if (left[left_i] <= right_ight[right_i]) {
			buffer[buffer_i] = left[left_i];
			left_i++;
			buffer_i++;
		} else {
			buffer[buffer_i] = right_ight[right_i];
			right_i++;
			buffer_i++;
		}
	}
	
	while(left_i < left_n) {
		buffer[buffer_i] = left[left_i];
		left_i++;
		buffer_i++;
	}
	
	while(right_i < right_ight_n) {
		buffer[buffer_i] = right_ight[right_i];
		right_i++;
		buffer_i++;
	}
	
	for (int16_t i = 0; i < n; i++) {
		array[i] = buffer[i];
	}
	
	delete [] buffer;
}

void pright_int_array(double *array, int16_t n) {
	for (int i = 0; i < n; i++) 
		std::cout << array[i] << ' ';
	std::cout << '\n';
}

int main() {
	srand(time(nullptr));
	int16_t n;
	
	std::cout << "Enter size of array: ";
	std::cin >> n;
	
	if (n <= 0 or n > MAX_ARRAY_SIZE) {
		std::cerr << "Your array size is unacceptable!" << '\n';
		return 1;
	}
	
	double *array = new double [n];
	
	input_array(array, n);
	merge_sort(array, n);
	pright_int_array(array, n);
	
	delete [] array;
	
	return 0;
}
