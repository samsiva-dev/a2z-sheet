package main

import "fmt"

// Time Complexity: O(n) & Space Complexity: O(1)
func majorityElementOptimal(nums []int) int {
	candidate := 0
	count := 0

	for _, num := range nums {
		if count == 0 {
			candidate = num
		}

		if num == candidate {
			count++
		} else {
			count--
		}
	}

	return candidate
}

// Time Complexity: O(n) & Space Complexity: O(n)
func majorityElement(nums []int) int {
	count := make(map[int]int)
	nums_length := len(nums)

	for i := 0; i < nums_length; i++ {
		_, exists := count[nums[i]];

		if exists {
			count[nums[i]] += 1
		} else {
			count[nums[i]] = 1
		}
	}

	for num, cnt := range count {
		if cnt > nums_length/2 {
			return num
		}
	}

	return -1
}

func main() {
	nums := []int{1, 1, 1, 2, 2, 2, 2}
	nums1 := []int{7, 0, 0, 1, 7, 7, 2, 7, 7}

	fmt.Println(majorityElement(nums))
	fmt.Println(majorityElementOptimal(nums))

	fmt.Println()

	fmt.Println(majorityElement(nums1))
	fmt.Println(majorityElementOptimal(nums1))
}
