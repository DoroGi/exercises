package main

import (
	"fmt"
	"os"
	"strings"
	"time"
)

func printElapsedTimeSince(start time.Time) {
	fmt.Printf("%.9fs elapsed", time.Since(start).Seconds())
	fmt.Println()
}

func inefficient(args []string) {
	s, sep := "", ""
	for _, arg := range args {
		s += sep + arg
		sep = " "
	}
	fmt.Println(s)
}

func efficient(args []string) {
	fmt.Println(strings.Join(args, " "))
}

func main() {
	args := os.Args[1:]
	start := time.Now()
	inefficient(args)
	printElapsedTimeSince(start)

	start = time.Now()
	efficient(args)
	printElapsedTimeSince(start)
}
