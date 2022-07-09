package main

import (
	"bufio"
	"fmt"
	"os"
)

func testing_77484() {
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	fmt.Fprintln(writer, solution_77484([]int{44, 1, 0, 0, 31, 25}, []int{31, 10, 45, 1, 6, 19}))
	fmt.Fprintln(writer, solution_77484([]int{0, 0, 0, 0, 0, 0}, []int{38, 19, 20, 40, 15, 25}))
	fmt.Fprintln(writer, solution_77484([]int{45, 4, 35, 20, 3, 9}, []int{20, 9, 3, 45, 4, 35}))
}

func solution_77484(lottos []int, win_nums []int) []int {
	min := 0
	max := 0

	for _, lotto := range lottos {
		if lotto == 0 {
			max += 1
			continue
		}

		for _, win_num := range win_nums {
			if lotto == win_num {
				min += 1
			}
		}
	}

	max += min

	lotto_min := lottoGrade(min)
	lotto_max := lottoGrade(max)

	return []int{lotto_max, lotto_min}
}

func lottoGrade(score int) int {
	grade := 7 - score
	if grade >= 6 {
		grade = 6
	}
	return grade
}
