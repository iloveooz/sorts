#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void input_array(double *A, int16_t n) {
	for (int i = 0; i < n; i++) 
		std::cin >> A[i];
}

void merge_sort(double *A, int16_t n) {
	
	if (n <= 1) return; // !!!
	
	int16_t middle = n / 2;
	
	double *left = A;
	double *right = A + middle;
	
	int16_t left_n = middle;
	int16_t	right_n = n - left_n;
	
	// recursion
	merge_sort(left, left_n);
	merge_sort(right, right_n);
	
	// merge
	double *buffer = new double[n];
	
	int16_t li = 0;
	int16_t ri = 0;
	int16_t bi = 0;
	
	while(li < left_n and ri < right_n) {
		if (left[li] <= right[ri]) {
			buffer[bi] = left[li];
			li++;
			bi++;
		} else {
			buffer[bi] = right[ri];
			ri++;
			bi++;
		}
	}
	
	while(li < left_n) {
		buffer[bi] = left[li];
		li++;
		bi++;
	}
	
	while(ri < right_n) {
		buffer[bi] = right[ri];
		ri++;
		bi++;
	}
	
	for (int16_t i = 0; i < n; i++) {
		A[i] = buffer[i];
	}
	
	delete [] buffer;
}

void print_array(double *A, int16_t n) {
	for (int i = 0; i < n; i++) 
		std::cout << A[i] << ' ';
	std::cout << '\n';
}

int main() {
	int16_t n;
	
	std::cout << "Enter size of array: ";
	std::cin >> n;
	
	if (n <= 0 or n > MAX_ARRAY_SIZE) {
		std::cerr << "Your array size is unacceptable!" << '\n';
		return 1;
	}
	
	double *A = new double [n];
	
	input_array(A, n);
	merge_sort(A, n);
	print_array(A, n);
	
	delete [] A;
	
	return 0;
}
