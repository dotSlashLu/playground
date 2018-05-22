package main

import (
	"fmt"
)

type vertice struct {
	value	string
	visited	bool
	next	[]*vertice
}

func isDoge(v *vertice) bool {
	if v.value != "doge" {
		return false
	}
	return true
}

func examine(v *vertice, toExamine []*vertice) {
	fmt.Printf("examine %s queue %+v\n", v.value, toExamine)
	if isDoge(v) {
		fmt.Println("doge found")
		return
	}
	v.visited = true

	// add children to queue
	for _, n := range(v.next) {
		fmt.Printf("push child %p: %s into queue\n", n, n.value)
		if !n.visited  {
			toExamine = append(toExamine, n)
		}
	}
	for {
		if len(toExamine) == 0 {
			fmt.Println("queue empty")
			return
		}
		w, toExamine := toExamine[0], toExamine[1:]
		fmt.Println("poped", w, toExamine)
		examine(w, toExamine)
	}
}

func main() {
	centre := &vertice{
		"me",
		false,
		[]*vertice{&vertice{
				"dsl",
				false,
				[]*vertice{
					&vertice{
						"alice",
						false,
						[]*vertice{},
				}},
			},
			&vertice{
				"bob",
				false,
				[]*vertice{&vertice{
					"doge",
					false,
					[]*vertice{},
				}},
			},
			&vertice{
				"clair",
				false,
				[]*vertice{},
			},
		},
	}
	examine(centre, []*vertice{})
}
