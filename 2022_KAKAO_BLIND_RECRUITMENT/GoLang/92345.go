package main

import (
	"bufio"
	"fmt"
	"os"
)

type counter struct {
	aCount int
	bCount int
	winner int
}

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
	count, _, _ := playerLocation(board, true, aloc, bloc, counter{0, 0, 0})
	return count.aCount + count.bCount
}

func playerLocation(board [][]int, turn bool, myloc []int, oploc []int, count counter) (counter, int, int) {
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

		/*
			if nowCount.winner == 0 && tmpCount.winner != 0 {
				nowCount = tmpCount
			} else {
				if tmpCount.winner != 0 && nowCount.aCount+nowCount.bCount >= tmpCount.aCount+tmpCount.bCount {
					nowCount = tmpCount
				}

					if tmpCount.winner == 1 && nowCount.bCount < tmpCount.bCount {
						nowCount = tmpCount
					} else if tmpCount.winner == 2 && nowCount.aCount < tmpCount.aCount {
						nowCount = tmpCount
					}
			}
		*/

		if tmpCount.winner != 0 {
			if tmpCountList == nil {
				tmpCountList = []counter{tmpCount}
				tmpRateList = []int{tmpMyRate}
			} else {
				tmpCountList = append(tmpCountList, tmpCount)
				tmpRateList = append(tmpRateList, tmpMyRate)
			}
		}
	}

	var nowCount counter
	imWin := false
	topRate := 0

	for i, tmpRate := range tmpRateList {
		if tmpRate > topRate {
			topRate = i
		}

		if tmpRate != 0 {
			imWin = true
			break
		}
	}

	if !imWin {
		for _, tmpCount := range tmpCountList {
			if nowCount.winner == 0 {
				nowCount = tmpCount
			} else {
				if tmpCount.winner != 0 && nowCount.aCount+nowCount.bCount >= tmpCount.aCount+tmpCount.bCount {
					nowCount = tmpCount
				}
			}
		}
	} else {
		nowCount = tmpCountList[topRate]
	}

	/*
		for _, tmpCount := range tmpCountList {
			if nowCount.winner == 0 {
				nowCount = tmpCount
			} else {
				if !imWin {
					if nowCount.aCount+nowCount.bCount < tmpCount.aCount+tmpCount.bCount {
						nowCount = tmpCount
					}
				} else {

					if nowCount.aCount+nowCount.bCount > tmpCount.aCount+tmpCount.bCount {
						nowCount = tmpCount
					}
				}
			}
		}
	*/

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
