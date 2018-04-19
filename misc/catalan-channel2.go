package main

import (
    "fmt"
    "os"
    "strconv"
)

func catalan(n int) int {
    if n == 1 {
        return 1
    }
    res := 0
    for i := 1; i < n; i++ {
        res += catalan(n-i) * catalan(i)
    }
    return res
}

func main() {
    n, _ := strconv.Atoi(os.Args[1])
    fmt.Println(n)
    q := make(chan int, n)
    res := make([]int, n)
    for i := 1; i <= n; i++ {
        go func(i int) { q <- catalan(i) }(i)
    }
    for i := 1; i <= n; i++ {
        res[i - 1] = <-q
    }
    fmt.Println(len(res), cap(res), res)
}

