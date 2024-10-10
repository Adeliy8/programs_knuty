// You can edit this code!
// Click here and start typing.
package main

import (
	"fmt"
	"sort"
)

func bin_search(arr []int, tar int) int {
	left := 0
	right := len(arr) - 1
	i := (left + right) / 2

	for left <= i && right >= i {
		fmt.Printf("Проверка элемента в массиве по индексу %d\n", i)

		if arr[i] == tar {
			fmt.Printf("%d == %d\n", arr[i], tar)
			return i
		} else if arr[i] < tar {
			fmt.Printf("%d < %d\n", arr[i], tar)
			i++
		} else {
			fmt.Printf("%d > %d\n", arr[i], tar)
			i--
		}
	}
	return -1
}

func main() {
	arr := []int{45, 34, 78, 52, 12, 88, 199, 1, 3}
	sort.Ints(arr)
	fmt.Println("Отсортированный массив:", arr)

	tar := 199
	result := bin_search(arr, tar)

	if result != -1 {
		fmt.Printf("Элемент найден: индекс в массиве %d, элемент %d\n", result, arr[result])
	} else {
		fmt.Println("Элемент не найден")
	}
}