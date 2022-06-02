package main

import (
	"bufio"
	"fmt"
	"os"
)

func testing_92345() {
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fprintln(writer, solution_92345([][]int{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, []int{1, 0}, []int{1, 2}))
	fmt.Fprintln(writer, solution_92345([][]int{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, []int{1, 0}, []int{1, 2}))
	fmt.Fprintln(writer, solution_92345([][]int{{1, 1, 1, 1, 1}}, []int{0, 0}, []int{0, 4}))
	fmt.Fprintln(writer, solution_92345([][]int{{1}}, []int{0, 0}, []int{0, 0}))
	fmt.Fprintln(writer, solution_92345([][]int{{1, 1, 1, 1}, {1, 1, 1, 1}}, []int{1, 0}, []int{1, 3}))
	fmt.Fprintln(writer, solution_92345([][]int{{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}}, []int{2, 0}, []int{2, 4}))
}

func solution_92345(board [][]int, aloc []int, bloc []int) int {
	if aloc[0] >= len(board) || aloc[1] >= len(board[0]) || bloc[0] >= len(board) || bloc[1] >= len(board[0]) {
		return 0
	}
	//count, _, _ := playerLocation(board, true, aloc, bloc, counter{0, 0, 0})
	playerLocation(board, true, aloc, bloc)
	return 0
}

// 패배 조건
// 1. 이동 가능한 경로가 없는 경우 나의 패배
// 2. 나와 상대가 같은 경로에 있는 경우 내가 이동 시 상대 패배
// 3. 내가 상대의 경로로 이동할 시 상대가 이동할 경로가 없을 경우 제외 패배
// 3-1. 만약 내가 이동할 경로가 없는 경우 대상 경로로 이동하여 턴을 하나 벌어감

// 고려가 필요한 것
// 자신이 승리할 레이팅이 높은 곳으로 향하게끔 해야함
// 이때 모든 곳이 레이팅이 더 높을 경우

func playerLocation(board [][]int, turn bool, myloc []int, oploc []int) (bool, int) {
	ableLoc := ableLocCalc(board, myloc)
	if ableLoc == nil {
		return false, 1
	}

	if myloc[0] == oploc[0] && myloc[1] == oploc[1] {
		return true, 1
	}

	tmpOpLoc := make([]int, 2)
	copy(tmpOpLoc, oploc)

	for _, loc := range ableLoc {
		boardTmp := make([][]int, len(board), len(board[0]))
		for i := 0; i < len(board); i++ {
			boardTmp[i] = make([]int, len(board[i]))
			copy(boardTmp[i], board[i])
		}

		boardTmp[loc[0]][loc[1]] = 0
		canWin, _ := playerLocation(boardTmp, !turn, tmpOpLoc, loc)
		boardTmp[loc[0]][loc[1]] = 1

		if !canWin {

		} else {

		}
	}

	return !turn, 0
}

func ableLocCalc(board [][]int, loc []int) [][]int {
	var ableLoc [][]int

	if loc[0] != 0 && board[loc[0]-1][loc[1]] != 0 {
		ableLoc = locAddList(ableLoc, []int{loc[0] - 1, loc[1]})
	}
	if loc[0] != len(board)-1 && board[loc[0]+1][loc[1]] != 0 {
		ableLoc = locAddList(ableLoc, []int{loc[0] + 1, loc[1]})
	}
	if loc[1] != 0 && board[loc[0]][loc[1]-1] != 0 {
		ableLoc = locAddList(ableLoc, []int{loc[0], loc[1] - 1})
	}
	if loc[1] != len(board[0])-1 && board[loc[0]][loc[1]+1] != 0 {
		ableLoc = locAddList(ableLoc, []int{loc[0], loc[1] + 1})
	}

	return ableLoc
}

func locAddList(ableLoc [][]int, loc []int) [][]int {
	if ableLoc == nil {
		ableLoc = [][]int{loc}
	} else {
		ableLoc = append(ableLoc, loc)
	}

	return ableLoc
}

/*func playerLocation(board [][]int, turn bool, myloc []int, oploc []int, count counter) (counter, int, int) {
	myLocTmp := make([]int, 2)
	opLocTmp := make([]int, 2)

	copy(myLocTmp, myloc)
	copy(opLocTmp, oploc)

	ableLoc := locAdd(board, myLocTmp)

	if ableLoc == nil {
		if turn {
			count.winner = 2
		} else {
			count.winner = 1
		}
		return count, 0, 1
	}

	if myLocTmp[0] == opLocTmp[0] && myLocTmp[1] == opLocTmp[1] {
		if turn {
			count.aCount++
			count.winner = 1
		} else {
			count.bCount++
			count.winner = 2
		}
		return count, 1, 0
	}

	var tmpCountList []counter
	var tmpRateList []int
	winMyRate := 0
	winOpRate := 0

	for _, loc := range ableLoc {
		boardTmp := make([][]int, len(board), len(board[0]))
		for i := 0; i < len(board); i++ {
			boardTmp[i] = make([]int, len(board[i]))
			copy(boardTmp[i], board[i])
		}

		boardTmp[myLocTmp[0]][myLocTmp[1]] = 0
		if loc[0] == opLocTmp[0] && loc[1] == opLocTmp[1] {
			ableOpLoc := locAdd(boardTmp, opLocTmp)

			if ableOpLoc == nil {
				if turn {
					count.winner = 1
					count.aCount++
				} else {
					count.winner = 2
					count.bCount++
				}
				return count, 1, 0
			} else {
				if len(ableLoc) != 1 {
					continue
				}
			}
		}

		ableLocReCheck := locAdd(boardTmp, loc)
		if ableLocReCheck == nil && len(ableLoc) != 1 {
			continue
		} else {
			if len(ableLocReCheck) == 1 && ableLocReCheck[0][0] == opLocTmp[0] && ableLocReCheck[0][1] == opLocTmp[1] && len(ableLoc) != 1 {
				continue
			}
		}

		if turn {
			count.aCount++
		} else {
			count.bCount++
		}

		tmpCount, tmpOpRate, tmpMyRate := playerLocation(boardTmp, !turn, oploc, loc, count)
		winMyRate += tmpMyRate
		winOpRate += tmpOpRate
		boardTmp[myLocTmp[0]][myLocTmp[1]] = 1

		if turn {
			count.aCount--
		} else {
			count.bCount--
		}

		if tmpCount.winner != 0 {
			if tmpCountList == nil {
				tmpCountList = []counter{tmpCount}
				tmpRateList = []int{100 / (tmpMyRate + tmpOpRate) * tmpMyRate}
			} else {
				tmpCountList = append(tmpCountList, tmpCount)
				tmpRateList = append(tmpRateList, 100/(tmpMyRate+tmpOpRate)*tmpMyRate)
			}
		}
	}

	var nowCount counter
	imWin := false
	topRate := 0

	for i, tmpRate := range tmpRateList {
		if winMyRate > winOpRate {
			if tmpRate > topRate {
				topRate = i
			}
		}

		if tmpRate != 0 {
			imWin = true
		}
	}

	if !imWin {
		for i, tmpCount := range tmpCountList {
			if nowCount.winner == 0 {
				nowCount = tmpCount
				topRate = tmpRateList[i]
			} else {
				if tmpCount.winner != 0 {
					if topRate < tmpRateList[i] {
						nowCount = tmpCount
					} else if nowCount.aCount+nowCount.bCount > tmpCount.aCount+tmpCount.bCount {
						nowCount = tmpCount
					}
				}
			}
		}
	} else {
		nowCount = tmpCountList[topRate]
	}

	return nowCount, winMyRate, winOpRate
}

func locAdd(board [][]int, loc []int) [][]int {
	var ableLoc [][]int

	if loc[0] != 0 && board[loc[0]-1][loc[1]] != 0 {
		ableLoc = locAddList(ableLoc, []int{loc[0] - 1, loc[1]})
	}
	if loc[0] != len(board)-1 && board[loc[0]+1][loc[1]] != 0 {
		ableLoc = locAddList(ableLoc, []int{loc[0] + 1, loc[1]})
	}
	if loc[1] != 0 && board[loc[0]][loc[1]-1] != 0 {
		ableLoc = locAddList(ableLoc, []int{loc[0], loc[1] - 1})
	}
	if loc[1] != len(board[0])-1 && board[loc[0]][loc[1]+1] != 0 {
		ableLoc = locAddList(ableLoc, []int{loc[0], loc[1] + 1})
	}

	return ableLoc
}

func locAddList(ableLoc [][]int, loc []int) [][]int {
	if ableLoc == nil {
		ableLoc = [][]int{loc}
	} else {
		ableLoc = append(ableLoc, loc)
	}

	return ableLoc
}
*/
