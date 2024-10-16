package main

import (
	"fmt"
)

func forwardElimination(a [][]float64, b []float64, n int, startRow, endRow int, ch chan<- [][]float64) {
	for k := 0; k < n-1; k++ {
		for i := startRow; i < endRow; i++ {
			if i > k {
				factor := a[i][k] / a[k][k]
				b[i] = (factor * b[k]) - b[i]

				for j := k; j < n; j++ {
					a[i][j] = (factor * a[k][j]) - a[i][j]
				}
			}
		}
	}
	ch <- a // отправляем обновленную матрицу в канал
}

func backSubstitution(a [][]float64, b []float64) []float64 {
	n := len(a)
	x := make([]float64, n)
	x[n-1] = b[n-1] / a[n-1][n-1]

	for i := n - 2; i >= 0; i-- {
		sum := b[i]
		for j := i + 1; j < n; j++ {
			sum -= a[i][j] * x[j]
		}
		x[i] = sum / a[i][i]
	}

	return x
}

func solveGauss(a [][]float64, b []float64) []float64 {
	n := len(a)
	ch := make(chan [][]float64)

	go forwardElimination(a, b, n, 1, n/2, ch)
	go forwardElimination(a, b, n, n/2, n, ch)

	// Ждем завершения обеих горутин и получаем обновленную матрицу
	a1 := <-ch

	// Объединяем результаты (в данном случае просто используем первую часть)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			a[i][j] = a1[i][j]
		}
	}

	return backSubstitution(a, b)
}

func main() {
	a := [][]float64{
		{2, 1, 1},
		{4, 3, 3},
		{8, 7, 9},
	}
	b := []float64{8, 20, 36}

	x := solveGauss(a, b)
	fmt.Println("Решение СЛАУ:")
	for i := 0; i < len(x); i++ {
		fmt.Printf("x%d = %.2f\n", i+1, x[i])
	}
}
