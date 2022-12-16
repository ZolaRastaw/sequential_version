#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int MIN_VALUE = -10;
const int MAX_VALUE = 10;

int main() {
  // Seed the random number generator
  srand(time(0));

  // Open the output file
  ofstream out("matrix.txt");

  // Generate the matrix
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      out << MIN_VALUE + static_cast<double>(rand()) / RAND_MAX * (MAX_VALUE - MIN_VALUE) << " ";
    }
    out << endl;
  }

  // Close the output file
  out.close();

  // Open the input file
  ifstream in("matrix.txt");

  // Read in the matrix
  double matrix[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      in >> matrix[i][j];
    }
  }

  // Close the input file
  in.close();

  // Determine the indices of the columns with twice as many negative elements as zeros
  vector<int> indices;
  for (int j = 0; j < 10; j++) {
    int neg_count = 0;
    int zero_count = 0;
    for (int i = 0; i < 10; i++) {
      if (matrix[i][j] < 0) {
        neg_count++;
      } else if (matrix[i][j] == 0) {
        zero_count++;
      }
    }
    if (neg_count == 2 * zero_count) {
      indices.push_back(j);
    }
  }

  // Print the indices of the columns
  cout << "Indices of columns with twice as many negative elements as zeros:" << endl;
  for (int index : indices) {
    cout << index << " ";
  }
  cout << endl;

  return 0;
}
