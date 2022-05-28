package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func testing_92335() {
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	fmt.Fprintln(writer, solution_92335(437674, 3))
	fmt.Fprintln(writer, solution_92335(110011, 10))
}

func solution_92335(n int, k int) int {
	if k != 10 {
		n = numChange(n, k)
	}

	count := 0

	if n > 1 {
		nStr := strconv.Itoa(n)

		if !strings.Contains(nStr, "0") {
			count += isPrime(n)
		} else {
			for _, j := range strings.Split(nStr, "0") {
				if j != "1" && j != "" {
					num, _ := strconv.Atoi(j)
					count += isPrime(num)
				}
			}
		}
	}

	return count
}

func isPrime(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return 0
		}
	}
	return 1
}

func numChange(n int, k int) int {
	quotient := int(n / k)
	remainder := n % k

	if remainder == 0 && quotient < k {
		total, _ := strconv.Atoi(strconv.Itoa(quotient) + strconv.Itoa(remainder))
		return total
	}

	total, _ := strconv.Atoi(strconv.Itoa(numChange(quotient, k)) + strconv.Itoa(remainder))

	return total
}
