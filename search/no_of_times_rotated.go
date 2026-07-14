package main

import "fmt"

func findKRotationLinear(nums []int) int {
	length := len(nums)
	start := nums[0]

	for i := 1; i < length; i++ {
		if start > nums[i] {
			return i
		}
	}

	return 0
}

func findKRotation(nums []int) int {
	length := len(nums)
	left := 0
	right := length - 1

	for left <= right {
		mid := left + (right-left)/2

		// Check if mid+1 is the minimum
		if mid < right && nums[mid] > nums[mid+1] {
			return mid + 1
		}

		// Check if mid itself is the minimum
		if mid > left && nums[mid] < nums[mid-1] {
			return mid
		}

		// Left is sorted
		if nums[mid] >= nums[left] {
			left = mid + 1 // Search minimum in right
		} else {
			right = mid - 1 // Search minimum in left
		}
	}

	return 0
}

func main() {
	nums := []int{6, 7, 8, 9, 0, 1, 2, 3}

	fmt.Println(findKRotationLinear(nums))
	fmt.Println(findKRotation(nums))
}
