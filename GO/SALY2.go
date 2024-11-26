// Метод Крамера
package main

import (
	"errors"
	"fmt"
)

// Функция для вычисления определителя матрицы 3x3
func determinant(matrix [][]int) int {
	if len(matrix) != 3 || len(matrix[0]) != 3 {
		panic("Определитель рассчитан только для 3x3 матрицы")
	}
	return matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1]) -
		matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0]) +
		matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0])
}

// Функция для решения системы уравнений методом Крамера
func kramer(A [][]int, b []int) ([]int, error) {
	n := len(A)
	if len(b) != n {
		return nil, errors.New("Размеры матрицы и вектора не совпадают")
	}

	detA := determinant(A)
	if detA == 0 {
		return nil, errors.New("Определитель матрицы равен нулю. Решения не существует или их бесконечно много.")
	}

	x := make([]int, n)
	for i := 0; i < n; i++ {
		Ai := make([][]int, n)
		for j := range A {
			Ai[j] = make([]int, n)
			copy(Ai[j], A[j])
			Ai[j][i] = b[j]
		}
		x[i] = determinant(Ai) / detA
	}

	return x, nil
}

func main() {
	A := [][]int{
		{2, -1, -3},
		{3, 4, -5},
		{0, 2, 7},
	}
	b := []int{3, -8, 17}

	x, err := kramer(A, b)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Print("Решение системы уравнений: ")
	for _, val := range x {
		fmt.Printf("%d ", val)
	}
	fmt.Println()
}
