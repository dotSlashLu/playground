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
        go catalan(n - i, ch1)
        go catalan(i, ch1)
        res += <-ch1 * <-ch1
        close(ch1)
    }
    ch <- res
}

func main() {
    n, _ := strconv.Atoi(os.Args[1])
    q := make(chan int)
    for i := 1; i <= n; i++ {
        go catalan(i, q)
        fmt.Println(<-q)
    }
    close(q)
}
