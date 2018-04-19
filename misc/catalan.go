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
        res += catalan(n - i) * catalan(i)
    }
    return res
}

func main() {
    n, _ := strconv.Atoi(os.Args[1])
    for i := 1; i <= n; i++ {
        fmt.Println(catalan(i))
    }
}
