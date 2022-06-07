package main

import (
	"bufio"
	"fmt"
	"os"
)

func testing_77486() {
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	fmt.Fprintln(writer, solution_77486(
		[]string{"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"},
		[]string{"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
		[]string{"young", "john", "tod", "emily", "mary"},
		[]int{12, 4, 2, 5, 10}))
	fmt.Fprintln(writer, solution_77486(
		[]string{"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"},
		[]string{"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
		[]string{"sam", "emily", "jaimie", "edward"},
		[]int{2, 3, 5, 4}))
}

func solution_77486(enroll []string, referral []string, seller []string, amount []int) []int {
	myParents := map[string]int{}
	userMoney := make([]int, len(enroll))

	for i, name := range referral {
		if name != "-" {
			for j, parentsName := range enroll {
				if parentsName == name {
					myParents[enroll[i]] = j
					break
				}
			}
		}
	}

	for i, user := range seller {
		oriMoney := amount[i] * 100
		userNum := 0

		for j, name := range enroll {
			if name == user {
				userNum = j
				break
			}
		}

		moneyDist(userNum, oriMoney, myParents, userMoney, enroll)
	}

	return userMoney
}

func moneyDist(num int, oriMoney int, myParents map[string]int, userMoney []int, enroll []string) {
	name := enroll[num]
	parents, exists := myParents[name]

	distMoney := oriMoney / 10
	myMoney := oriMoney - distMoney

	userMoney[num] += myMoney

	if exists {
		if distMoney != 0 {
			moneyDist(parents, distMoney, myParents, userMoney, enroll)
		}
	}
}
