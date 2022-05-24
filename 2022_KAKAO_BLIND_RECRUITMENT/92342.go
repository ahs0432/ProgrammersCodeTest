package main

import (
	"bufio"
	"fmt"
	"os"
)

func testing_92342() {
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fprintln(writer, solution_92342(5, []int{2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}))
	fmt.Fprintln(writer, solution_92342(1, []int{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}))
	fmt.Fprintln(writer, solution_92342(9, []int{0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1}))
	fmt.Fprintln(writer, solution_92342(10, []int{0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3}))
}

func solution_92342(n int, info []int) []int {
	if n == 1 && info[0] == 1 {
		return []int{-1}
	}

	info = reverse(info)
	myInfo := make([]int, len(info))

	realScore := 0
	realInfo := make([]int, len(info))

	for i := len(myInfo) - 1; i >= 1; i-- {
		if info[i] < n {
			myInfo[i] = info[i] + 1
		}
	}

	for i := len(myInfo) - 1; i >= 1; i-- {
		myTmpCount := n
		tmpScore, tmpInfo := forInfo(info, myInfo, make([]int, len(info)), myTmpCount, i)

		if tmpScore > realScore {
			realScore = tmpScore
			copy(realInfo, tmpInfo)
		}
	}

	if realScore == 0 {
		return []int{-1}
	}

	myInfo = reverse(realInfo)
	return myInfo
}

func forInfo(info []int, myInfo []int, myTmpInfo []int, count int, num int) (int, []int) {
	if num == 0 {
		myTmpInfo[num] = count
		count = 0
	}

	if count == 0 {
		if num != 0 && myTmpInfo[0] != 0 {
			myTmpInfo[0] = 0
		}

		if calcScore(myTmpInfo, info)-calcScore(info, myTmpInfo) > 0 {
			myTmpInfo2 := make([]int, len(info))
			// Go의 경우 Copy를 사용하지 않는 경우 List, Map 등은 동일한 메모리를 사용하여 데이터 변경 시 복사한 곳도 변경됨
			copy(myTmpInfo2, myTmpInfo)
			return calcScore(myTmpInfo, info) - calcScore(info, myTmpInfo), myTmpInfo2
		}
		return 0, []int{-1}
	}

	tmpScore1, tmpScore2 := 0, 0
	var tmpInfo1, tmpInfo2 []int

	if myInfo[num] <= count {
		myTmpInfo[num] = myInfo[num]
		tmpScore1, tmpInfo1 = forInfo(info, myInfo, myTmpInfo, count-myInfo[num], num-1)
		myTmpInfo[num] = 0
	}

	tmpScore2, tmpInfo2 = forInfo(info, myInfo, myTmpInfo, count, num-1)

	if tmpScore2 == 0 && tmpScore1 == 0 {
		return 0, []int{-1}
	}

	if tmpScore1 > tmpScore2 {
		return tmpScore1, tmpInfo1
	} else if tmpScore1 == tmpScore2 {
		for i := 0; i < len(tmpInfo1); i++ {
			if tmpInfo1[i] > tmpInfo2[i] {
				return tmpScore1, tmpInfo1
			} else if tmpInfo1[i] < tmpInfo2[i] {
				return tmpScore2, tmpInfo2
			}
		}
	}

	return tmpScore2, tmpInfo2
}

func reverse(v []int) []int {
	for i := 0; i < len(v)/2; i++ {
		v[i], v[len(v)-1-i] = v[len(v)-1-i], v[i]
	}

	return v
}

func calcScore(info []int, diffinfo []int) int {
	score := 0
	for i := 0; i < len(info); i++ {
		if info[i] > diffinfo[i] {
			score += i
		}
	}
	return score
}
