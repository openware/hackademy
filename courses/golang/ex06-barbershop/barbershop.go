package main

import (
	"fmt"
	"time"
)

func Barber(client_start chan byte, client_end chan bool) {
	for {
		select {
		case num := <-client_start:
			fmt.Printf("Start working with client %d.\n", num)
			time.Sleep(700 * time.Millisecond)
			client_end <- true
			fmt.Printf("End working with client %d.\n", num)
		default:
			fmt.Println("Sleeping...")
			fmt.Println()
			time.Sleep(100 * time.Millisecond)
		}
	}
}

func Barbershop(seats byte, passer_in chan byte, passer_out chan byte, done chan byte) {
	client_start := make(chan byte, seats)
	client_end := make(chan bool)
	emptySeats := seats
	go Barber(client_start, client_end)

	for {
		select {
		case num := <-passer_in:
			fmt.Printf("\nNew client: %d.\n", num)
			if emptySeats > 0 {
				client_start <- num
				fmt.Printf("Client %d took an empty seat.\n", num)
				emptySeats--
				fmt.Printf("Empty seats: %d.\n", emptySeats)
			} else {
				go func() {
					time.Sleep(600 * time.Millisecond)
					passer_out <- num
				}()
				fmt.Printf("Client %d will come back later.\n", num)
			}
		case <-client_end:
			emptySeats++
			fmt.Printf("Empty seats: %d.\n", emptySeats)
			done <- emptySeats
		}
	}
}

func main() {
	passer_in := make(chan byte)
	passer_out := make(chan byte)
	done := make(chan byte, 15)
	seats := byte(4)
	go Barbershop(seats, passer_in, passer_out, done)

	for i := byte(1); i < 16; {
		time.Sleep(300 * time.Millisecond)
		select {
		case num := <-passer_out:
			passer_in <- num
		default:
			passer_in <- i
			i++
		}
	}

	for {
		emptySeats := <-done
		if emptySeats == seats {
			break
		}
	}
}
