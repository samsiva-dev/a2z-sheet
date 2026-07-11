package main

import "fmt"

func searchInRotatedSortedArrayNew(nums []int, target int) bool {
	n := len(nums)
	low := 0
	high := n - 1

	for low <= high {
		mid := low + (high-low)/2

		if nums[mid] == target {
			return true
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

	return false
}

func main() {
	nums := []int{7, 8, 1, 2, 3, 3, 3, 4, 5, 6}
	fmt.Println(searchInRotatedSortedArrayNew(nums, 3))
	fmt.Println(searchInRotatedSortedArrayNew(nums, 10))
	fmt.Println(searchInRotatedSortedArrayNew(nums, 8))
}
