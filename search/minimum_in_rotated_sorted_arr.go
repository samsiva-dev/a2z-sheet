package main

import "fmt"

func minimumNumInSortedArr(nums []int) int {
	n := len(nums)
	left := 0
	right := n - 1

	for left < right {
		mid := left + (right-left)/2

		if nums[mid] > nums[right] {
			left = mid + 1
		} else {
			right = mid
		}
	}

	return nums[left]
}

func main() {
	nums := []int{4, 5, 6, 0, 1, 2, 3}
	nums1 := []int{4, 5, 6, 1, 2, 3}

	fmt.Println(minimumNumInSortedArr(nums))
	fmt.Println(minimumNumInSortedArr(nums1))
}
