package main

import "fmt"

func searchInRotatedSortedArray(nums []int, target int) int {
	n := len(nums)
	low := 0
	high := n - 1

	for low <= high {
		mid := low + (high-low)/2

		if nums[mid] == target {
			return mid
		}

		// Left is sorted?
		if nums[low] <= nums[mid] {
			// Key exists in Left?
			if target >= nums[low] && target < nums[mid] {
				high = mid - 1
			} else {
				low = mid + 1
			}
		} else {
			// Key exists in Right?
			if target > nums[mid] && target <= nums[high] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		}
	}

	return -1
}

func main() {
	nums := []int{4, 5, 6, 7, 0, 1, 2}
	fmt.Println(searchInRotatedSortedArray(nums, 0))
	fmt.Println(searchInRotatedSortedArray(nums, 8))
	fmt.Println(searchInRotatedSortedArray(nums, 3))
}
