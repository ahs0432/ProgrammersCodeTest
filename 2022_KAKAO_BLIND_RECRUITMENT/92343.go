package main

import (
	"bufio"
	"fmt"
	"os"
)

func testing_92343() {
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fprintln(writer, solution_92343([]int{0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, [][]int{{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}}))
	fmt.Fprintln(writer, solution_92343([]int{0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0}, [][]int{{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 8}, {6, 9}, {9, 10}}))
}

func solution_92343(info []int, edges [][]int) int {
	if info[0] == 1 {
		return 0
	}

	backList := make([]int, len(info))
	goList := make([][]int, len(info))

	for _, i := range edges {
		if i[0] != 0 {
			backList[i[1]] = i[0]
		}

		if goList[i[0]] == nil {
			goList[i[0]] = []int{i[1]}
		} else {
			goList[i[0]] = append(goList[i[0]], i[1])
		}
	}

	alreadyInfo := make([]bool, len(info))
	alreadyInfo[0] = true

	var sheepList []int
	for idx, data := range info {
		if idx == 0 {
			continue
		}

		if data == 0 {
			if sheepList == nil {
				sheepList = []int{idx}
			} else {
				sheepList = append(sheepList, idx)
			}
		}
	}

	sheepTotal := len(sheepList) + 1
	sheepMove := map[int][]int{}

	for _, i := range sheepList {
		sheepMove[i] = append(reverse_92343(sheepBackCount([]int{}, backList, i)), i)
	}

	sheepCount := 1

	for i := 0; i < len(sheepList); i++ {
		alreadySheep := make([]bool, len(sheepList))
		alreadySheep[i] = true
		sheepCountTmp := moveMe(sheepMove, sheepList, sheepMove[sheepList[i]], info, alreadyInfo, sheepTotal, 1, 0, alreadySheep)
		if sheepCount < sheepCountTmp {
			sheepCount = sheepCountTmp
		}
	}

	return sheepCount
}

func moveMe(sheepMove map[int][]int, sheepList []int, sheepMoveNow []int, info []int, alreadyInfo []bool, sheepTotal int, sheepCount int, wolfCount int, alreadySheep []bool) int {
	ardySheep := make([]bool, len(alreadySheep))
	copy(ardySheep, alreadySheep)

	ardyInfo := make([]bool, len(alreadyInfo))
	copy(ardyInfo, alreadyInfo)

	for _, i := range sheepMoveNow {
		if !ardyInfo[i] {
			ardyInfo[i] = true
			if info[i] == 0 {
				sheepCount++
				if sheepTotal == sheepCount {
					return sheepCount
				}

				for j, k := range sheepList {
					if k == i {
						ardySheep[j] = true
					}
				}
			} else {
				if wolfCount+1 == sheepCount {
					return sheepCount
				}
				wolfCount++
			}
		}
	}

	finCount := sheepCount

	for i := 0; i < len(sheepList); i++ {
		if ardySheep[i] {
			continue
		}

		if ardyInfo[sheepList[i]] {
			continue
		}

		ardySheep[i] = true
		sheepCountTmp := moveMe(sheepMove, sheepList, sheepMove[sheepList[i]], info, ardyInfo, sheepTotal, sheepCount, wolfCount, ardySheep)
		ardySheep[i] = false

		if finCount < sheepCountTmp {
			finCount = sheepCountTmp
		}
	}

	return finCount
}

func sheepBackCount(sheepMove []int, backList []int, nowloc int) []int {
	if sheepMove == nil {
		sheepMove = []int{backList[nowloc]}
	} else {
		sheepMove = append(sheepMove, backList[nowloc])
	}

	nowloc = backList[nowloc]

	if nowloc == 0 {
		return sheepMove
	}

	sheepMove = sheepBackCount(sheepMove, backList, nowloc)
	return sheepMove
}

func reverse_92343(v []int) []int {
	for i := 0; i < len(v)/2; i++ {
		v[i], v[len(v)-1-i] = v[len(v)-1-i], v[i]
	}

	return v
}
