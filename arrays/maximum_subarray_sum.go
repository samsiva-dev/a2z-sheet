package main

import "fmt"
import "math"

func maxSubArrayOptimal(nums []int) int {
	maximum := int(math.Inf(-1))
	sum := 0
	n := len(nums)

	for i := 0; i < n; i++ {
		sum += nums[i]

		if sum > maximum {
			maximum = sum
		}

		if sum < 0 {
			sum = 0
		}
	}

	return maximum
}

func main() {
	nums := []int{2, 3, 5, -2, 7, -4}
	nums1 := []int{-2, -3, -7, -2, -10, -4}

	fmt.Println(maxSubArrayOptimal(nums))
	fmt.Println()
	fmt.Println(maxSubArrayOptimal(nums1))
}
