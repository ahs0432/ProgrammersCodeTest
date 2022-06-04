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
	if len(board) < 1 || len(board[0]) < 1 || len(board) > 5 || len(board[0]) > 5 {
		return 0
	}
	if aloc[0] >= len(board) || aloc[1] >= len(board[0]) || bloc[0] >= len(board) || bloc[1] >= len(board[0]) {
		return 0
	}
	//count, _, _ := playerLocation(board, true, aloc, bloc, counter{0, 0, 0})
	_, count := playerLocation(board, true, aloc, bloc)
	return count
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
		return false, 0
	}

	if myloc[0] == oploc[0] && myloc[1] == oploc[1] {
		return true, 1
	}

	tmpOpLoc := make([]int, 2)
	copy(tmpOpLoc, oploc)

	totalRate := 0
	canWin := false

	for _, loc := range ableLoc {
		boardTmp := make([][]int, len(board), len(board[0]))
		for i := 0; i < len(board); i++ {
			boardTmp[i] = make([]int, len(board[i]))
			copy(boardTmp[i], board[i])
		}

		boardTmp[myloc[0]][myloc[1]] = 0
		winning, rate := playerLocation(boardTmp, !turn, tmpOpLoc, loc)
		boardTmp[myloc[0]][myloc[1]] = 1

		if !winning {
			if !canWin {
				totalRate = rate
				canWin = true
			} else {
				if rate < totalRate {
					totalRate = rate
				}
			}
		} else {
			if canWin {
				continue
			} else {
				if totalRate == 0 {
					totalRate = rate
				}

				if rate > totalRate {
					totalRate = rate
				}
			}
		}
	}
	totalRate += 1

	return canWin, totalRate
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
