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
	//fmt.Fprintln(writer, solution_92345([][]int{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, []int{1, 0}, []int{1, 2}))
	//fmt.Fprintln(writer, solution_92345([][]int{{1, 1, 0}, {1, 0, 1}, {1, 0, 1}}, []int{1, 0}, []int{1, 2}))
	//fmt.Fprintln(writer, solution_92345([][]int{{1, 1, 1, 1, 1}}, []int{0, 0}, []int{0, 4}))
	//fmt.Fprintln(writer, solution_92345([][]int{{1}}, []int{0, 0}, []int{0, 0}))
}

func solution_92345(board [][]int, aloc []int, bloc []int) int {
	count := playerLocation(board, true, aloc, bloc, counter{0, 0, 0})
	//fmt.Println(count)
	return count.aCount + count.bCount
}

func playerLocation(board [][]int, turn bool, aloc []int, bloc []int, count counter) counter {
	var ableLoc [][]int
	var tmpCountList []counter
	//fmt.Println(board, count)

	if turn {
		ableLoc = locAdd(board, ableLoc, aloc)
		if ableLoc == nil {
			count.winner = 2
			return count
		}

		for _, loc := range ableLoc {
			boardTmp := make([][]int, len(board))
			for i := 0; i < len(board); i++ {
				boardTmp[i] = make([]int, len(board[i]))
				copy(boardTmp[i], board[i])
			}
			//copy(boardTmp, board)

			boardTmp[aloc[0]][aloc[1]] = 0
			if aloc[0] == bloc[0] && aloc[1] == bloc[1] {
				count.aCount++
				count.winner = 1
				return count
			}

			count.aCount++
			if tmpCountList == nil {
				tmpCountList = []counter{playerLocation(boardTmp, false, loc, bloc, count)}
			} else {
				tmpCountList = append(tmpCountList, playerLocation(boardTmp, false, loc, bloc, count))
			}
			count.aCount--
		}
	} else {
		ableLoc = locAdd(board, ableLoc, bloc)
		if ableLoc == nil {
			count.winner = 1
			return count
		}

		for _, loc := range ableLoc {
			boardTmp := make([][]int, len(board), len(board[0]))
			for i := 0; i < len(board); i++ {
				boardTmp[i] = make([]int, len(board[i]))
				copy(boardTmp[i], board[i])
			}
			//copy(boardTmp, board)
			boardTmp[bloc[0]][bloc[1]] = 0
			if bloc[0] == aloc[0] && bloc[1] == aloc[1] {
				count.bCount++
				count.winner = 2

				return count
			}

			count.bCount++
			if tmpCountList == nil {
				tmpCountList = []counter{playerLocation(boardTmp, true, aloc, loc, count)}
			} else {
				tmpCountList = append(tmpCountList, playerLocation(boardTmp, true, aloc, loc, count))
			}
			count.bCount--
		}
	}

	//fmt.Println(tmpCountList)
	var tmpCount counter

	for _, countL := range tmpCountList {
		if tmpCount.winner == 0 && countL.winner != 0 {
			tmpCount = countL
			continue
		}

		if countL.winner == 1 {
			if tmpCount.winner == 1 {
				if countL.aCount <= tmpCount.aCount {
					if countL.bCount >= tmpCount.bCount {
						tmpCount = countL
					}
				}
			} else {
				if countL.aCount <= tmpCount.bCount {
					if countL.bCount >= tmpCount.aCount {
						tmpCount = countL
					}
				}
			}
		} else {
			if tmpCount.winner == 1 {
				if countL.bCount <= tmpCount.aCount {
					if countL.aCount >= tmpCount.bCount {
						tmpCount = countL
					}
				}
			} else {
				if countL.bCount <= tmpCount.bCount {
					if countL.bCount >= tmpCount.aCount {
						tmpCount = countL
					}
				}
			}
		}
	}

	//fmt.Println(tmpCount)

	return tmpCount
}

func locAdd(board [][]int, ableLoc [][]int, loc []int) [][]int {
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
