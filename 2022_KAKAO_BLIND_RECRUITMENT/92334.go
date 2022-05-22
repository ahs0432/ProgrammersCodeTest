package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func testing_92334() {
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	fmt.Fprintln(writer, solution_92334([]string{"muzi", "frodo", "apeach", "neo"}, []string{"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2))
	fmt.Fprintln(writer, solution_92334([]string{"con", "ryan"}, []string{"ryan con", "ryan con", "ryan con", "ryan con"}, 3))
}

func solution_92334(id_list []string, report []string, k int) []int {
	reporter := map[string][]string{}
	reported := map[string]int{}
	var stoped []int

	for _, i := range report {
		slice := strings.Split(i, " ")
		if slice[0] == slice[1] {
			continue
		}

		if reporter[slice[0]] == nil {
			reporter[slice[0]] = ([]string{slice[1]})
			reported[slice[1]] += 1
		} else {
			checked := true
			for _, j := range reporter[slice[0]] {
				if j == slice[1] {
					checked = false
					break
				}
			}

			if checked {
				reporter[slice[0]] = append(reporter[slice[0]], slice[1])
				reported[slice[1]] += 1
			}
		}
	}

	for _, j := range id_list {
		count := 0

		for _, l := range reporter[j] {
			if reported[l] >= k {
				count += 1
			}
		}

		if stoped == nil {
			stoped = []int{count}
		} else {
			stoped = append(stoped, count)
		}
	}

	return stoped
}
