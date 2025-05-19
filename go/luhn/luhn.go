package luhn

import (
	"strings"
)

func Valid(str string) bool {
	//remove white space
	str = strings.Join(strings.Fields(str), "")
	//initialize sum
	sum := 0
	//used to determine if string is na odd length. This determines whether even or odd numbers are doubled when itterating from left to right
	odd := len(str) % 2

	//Must have at least 2 digits
	if len(str) < 2 {
		return false
	}
	// for each number in the string...
	for i, r := range str {
		//cast the rune as an interger but subtract the rune value of 0 so it reflects the proper digit
		digit := int(r - '0')
		//if digit is a value that does not correspond to the ascii value of a digit, fail
		if digit > 9 {
			return false
		}
		//if number of digits is odd and if we're on an odd digit... (counting starts at 0)
		if i%2 == odd {
			//multiply number by 2
			digit *= 2
			//if the number is greater than 9...
			if digit > 9 {
				//subtract 9 from the number
				digit -= 9
			}
		}
		//add the digit to the sum
		sum += digit
	}
	//return true if the sum is evenly divisible by 10
	return sum%10 == 0
}
