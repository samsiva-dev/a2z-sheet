package main

import "fmt"

/*
 * Constraints given:
 * 2 <= nums.length <= 105
 * 1 <= | nums[i] | <= 104
 * nums.length is an even number.
 * Number of positive and negative numbers are equal.
 * The rearranged array begins with a positive integer.
 */

func rearrangeArray(nums []int) []int {
	n := len(nums)
	result := make([]int, n)
	pos_idx := 0
	neg_idx := 1

	for i := 0; i < n; i++ {
		num := nums[i]
		if num > 0 {
			result[pos_idx] = num
			pos_idx += 2
		} else {
			result[neg_idx] = num
			neg_idx += 2
		}
	}

	return result
}

func main() {
	nums := []int{2, 4, 5, -1, -3, -4}
	nums1 := []int{1, -1, -3, -4, 2, 3}

	fmt.Println(rearrangeArray(nums))
	fmt.Println(rearrangeArray(nums1))
}
