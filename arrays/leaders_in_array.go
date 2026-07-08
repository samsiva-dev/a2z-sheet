package main

import "fmt"

func leadersOptimal(nums []int) []int {
	n := len(nums)
	if n == 0 {
		return []int{}
	}

	result := make([]int, 0)

	// maxSoFar tracks the largest value seen so far, scanning from the right
	maxSoFar := nums[n-1]

	// rightmost element is always a leader
	result = append(result, maxSoFar)

	for i := n - 2; i >= 0; i-- {
		// strictly greater than everything to its right
		if nums[i] > maxSoFar {
			result = append(result, nums[i])
			maxSoFar = nums[i]
		}
	}

	// result was built right-to-left; reverse it to match nums' order
	for l, r := 0, len(result)-1; l < r; l, r = l+1, r-1 {
		result[l], result[r] = result[r], result[l]
	}
	return result
}

func leaders(nums []int) []int {
	stack := make([]int, 1)
	n := len(nums)

	if n <= 0 {
		return []int{}
	}

	stack[0] = nums[0]
	for i := 1; i < n; i++ {
		stk_len := len(stack)
		if stack[stk_len-1] >= nums[i] {
			// Consider current one also as a leader
			stack = append(stack, nums[i])
		} else {
			// Pop elements from stack until we found
			// a leader
			for stk_len != 0 && stack[stk_len-1] <= nums[i] {
				stack = stack[:stk_len-1]
				stk_len -= 1
			}
			// Consider current one as a leader
			stack = append(stack, nums[i])
		}
	}

	return stack
}

func main() {
	nums := []int{1, 2, 5, 3, 1, 2};
	nums1 := []int{-3, 4, 5, 1, -4, -5}

	fmt.Println(leaders(nums))
	fmt.Println(leadersOptimal(nums))
	fmt.Println()
	fmt.Println(leaders(nums1))
	fmt.Println(leadersOptimal(nums1))
}
