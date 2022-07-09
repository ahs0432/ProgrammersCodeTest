package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func testing_92341() {
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	fmt.Fprintln(writer, solution_92341([]int{180, 5000, 10, 600}, []string{"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"}))
	fmt.Fprintln(writer, solution_92341([]int{120, 0, 60, 591}, []string{"16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN"}))
	fmt.Fprintln(writer, solution_92341([]int{1, 461, 1, 10}, []string{"00:00 1234 IN"}))
}

func solution_92341(fees []int, records []string) []int {
	carInOut := map[string][][2]string{}
	sortCarNum := []string{}

	for _, data := range records {
		dataSplit := strings.Split(data, " ")

		if sortCarNum == nil {
			sortCarNum = []string{dataSplit[1]}
		} else if listContains(sortCarNum, dataSplit[1]) {
			sortCarNum = append(sortCarNum, dataSplit[1])
		}

		if _, exist := carInOut[dataSplit[1]]; !exist {
			carInOut[dataSplit[1]] = [][2]string{{dataSplit[0], dataSplit[2]}}
		} else {
			carInOut[dataSplit[1]] = append(carInOut[dataSplit[1]], [2]string{dataSplit[0], dataSplit[2]})
		}
	}

	sort.Strings(sortCarNum)

	result := []int{}

	for _, carNum := range sortCarNum {
		carHistory := carInOut[carNum]

		if len(carHistory)%2 != 0 {
			carHistory = append(carHistory, [2]string{"23:59", "OUT"})
		}

		totalM := 0

		for i := len(carHistory) - 1; i >= 0; i -= 2 {
			endSplit := strings.Split(carHistory[i][0], ":")
			startSplit := strings.Split(carHistory[i-1][0], ":")

			endh, _ := strconv.Atoi(endSplit[0])
			endm, _ := strconv.Atoi(endSplit[1])
			starth, _ := strconv.Atoi(startSplit[0])
			startm, _ := strconv.Atoi(startSplit[1])

			totalM += (endm - startm) + ((endh - starth) * 60)
		}

		if totalM > fees[0] {
			totalM = fees[1] + int(math.Ceil(float64(totalM-fees[0])/float64(fees[2])))*fees[3]
		} else {
			totalM = fees[1]
		}

		if result == nil {
			result = []int{totalM}
		} else {
			result = append(result, totalM)
		}
	}

	return result
}

func listContains(s []string, condata string) bool {
	for _, v := range s {
		if v == condata {
			return false
		}
	}
	return true
}
