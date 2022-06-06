package main

import (
	"bufio"
	"fmt"
	"os"
)

func testing_77485() {
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	fmt.Fprintln(writer, solution_77485(6, 6, [][]int{{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}}))
	fmt.Fprintln(writer, solution_77485(3, 3, [][]int{{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}}))
	fmt.Fprintln(writer, solution_77485(100, 97, [][]int{{1, 1, 100, 97}}))
}

func solution_77485(rows int, columns int, queries [][]int) []int {
	result := make([]int, len(queries))
	board := make([][]int, rows)

	for i := 0; i < rows; i++ {
		boardTmp := make([]int, columns)
		for j := 0; j < columns; j++ {
			boardTmp[j] = (i * columns) + (j + 1)
		}
		board[i] = boardTmp
	}

	for num, query := range queries {
		for i := range query {
			query[i] -= 1
		}

		tmpData := board[query[0]][query[1]]
		min := tmpData

		for i := query[1] + 1; i <= query[3]; i++ {
			tmpData, min = boardMove(board, query[0], i, tmpData, min)
		}
		for i := query[0] + 1; i <= query[2]; i++ {
			tmpData, min = boardMove(board, i, query[3], tmpData, min)
		}
		for i := query[3] - 1; i >= query[1]; i-- {
			tmpData, min = boardMove(board, query[2], i, tmpData, min)
		}
		for i := query[2] - 1; i >= query[0]; i-- {
			tmpData, min = boardMove(board, i, query[1], tmpData, min)
		}

		// 정상적인 알고리즘 (두번째 생각한거..)
		/*
			for i := query[0]; i < query[2]; i++ {
				val := board[i+1][query[1]]
				board[i][query[1]] = board[i+1][query[1]]
				if val < min {
					min = val
				}
			}
			for i := query[1]; i < query[3]; i++ {
				val := board[query[2]][i+1]
				board[query[2]][i] = board[query[2]][i+1]
				if val < min {
					min = val
				}
			}
			for i := query[2]; i > query[0]; i-- {
				val := board[i-1][query[3]]
				board[i][query[3]] = board[i-1][query[3]]
				if val < min {
					min = val
				}
			}
			for i := query[3]; i > query[1]; i-- {
				val := board[query[0]][i-1]
				board[query[0]][i] = board[query[0]][i-1]
				if val < min {
					min = val
				}
			}
			board[query[0]][query[1]+1] = tmpData
		*/

		result[num] = min
	}

	return result
}

func boardMove(board [][]int, q1 int, q2 int, tmpData int, min int) (int, int) {
	dummyData := board[q1][q2]
	board[q1][q2] = tmpData

	if dummyData < min {
		min = dummyData
	}

	return dummyData, min
}
