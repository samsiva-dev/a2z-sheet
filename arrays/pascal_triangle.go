package main

import "fmt"

/*
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 * 1 5 10 10 5 1
 */

func generatePascalsTriangle(N int) [][]int {
	triangle := make([][]int, N)

	for i := 0; i < N; i++ {
		current_row := make([]int, i+1)
		for j := range i+1 {
			if j == 0 || j == i {
				current_row[j] = 1
			} else {
				current_row[j] = triangle[i-1][j-1] + triangle[i-1][j]
			}
		}
		triangle[i] = current_row
	}

	return triangle
}

func main() {
	N := 5
	N1 := 6

	fmt.Println(generatePascalsTriangle(N))
	fmt.Println(generatePascalsTriangle(N1))
}
