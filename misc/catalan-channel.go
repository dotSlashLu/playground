package main

import (
    "fmt"
    "os"
    "strconv"
)

func catalan(n int, ch chan int) {
    if n == 1 {
        ch <- 1
        return
    }
    res := 0
    for i := 1; i < n; i++ {
        ch1 := make(chan int)
        ch2 := make(chan int)
        go catalan(n - i, ch1)
        go catalan(i, ch2)
        res += <-ch1 * <-ch2
        close(ch1)
        close(ch2)
    }
    ch <- res
}

func main() {
    n, _ := strconv.Atoi(os.Args[1])
    for i := 1; i <= n; i++ {
        q := make(chan int)
        go catalan(i, q)
        fmt.Println(<-q)
        close(q)
    }
}
