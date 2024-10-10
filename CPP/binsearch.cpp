#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bin_search(const vector<int>& arr, int tar) {
  int left = 0;
  int right = arr.size() - 1;
  int i = (left + right) / 2;

  while (left <= i && right >= i) {
    cout << "Проверка элемента в массиве по индексу " << i << endl;

    if (arr[i] == tar) {
      cout << arr[i] << " == " << tar << endl;
      return i;
    } else if (arr[i] < tar) {
      cout << arr[i] << " < " << tar << endl;
      i++;
    } else {
      cout << arr[i] << " > " << tar << endl;
      i--;
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {45, 34, 78, 52, 12, 88, 199, 1, 3};
  sort(arr.begin(), arr.end());
  cout << "Отсортированный массив: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  int tar = 199;
  int result = bin_search(arr, tar);

  if (result != -1) {
    cout << "Элемент найден: индекс в массиве " << result << ", элемент " << arr[result] << endl;
  } else {
    cout << "Элемент не найден" << endl;
  }
  cin;
  return 0;
  
}

