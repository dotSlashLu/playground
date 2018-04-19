package main

import "fmt"

func qsort(a []int) []int {
	fmt.Println("sorting", a)
	if len(a) < 2 {
		return a
	}
	pivot := a[0]
	var lesser, greater []int
	for _, e := range a[1:] {
		switch {
		case e <= pivot:
			lesser = append(lesser, e)
		case e > pivot:
			greater = append(greater, e)
		}
	}
	res := append(qsort(lesser), []int{pivot}...)
	res = append(res, qsort(greater)...)
	return res
}

func main() {
	to_sort := []int{12, 54, 34, 34, 5, 7, 8, 2, 45}
	fmt.Println("to sort:", to_sort)
	fmt.Println(qsort(to_sort))
}
