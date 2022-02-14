package main

import (
	"log"
	"sync"
	"time"
)

const maxWaiting = 5
const nCustomers = 10

func main() {
	var Wroom = make(chan chan int, maxWaiting)
	var wg = new(sync.WaitGroup)
	wg.Add(nCustomers)
	go func() {
		for {
			select {
			case client := <-Wroom:
				log.Println("Barber cuts the hair of Customer", <-client)
				time.Sleep(1000 * time.Millisecond)
				log.Println("Barber finishes cutting hair.")
				client <- 0
			default:
				log.Println("Barber is sleeping ... ZZZzzz....")
				time.Sleep(200 * time.Millisecond)
			}
		}
	}()

	for i := 0; i < nCustomers; i++ {
		if i > 3 && i < 6 {
			time.Sleep(2300 * time.Millisecond)
		} else {
			time.Sleep(300 * time.Millisecond)
		}

		go func(i int) {
			time.Sleep(100 * time.Millisecond)
			defer wg.Done()
			ch := make(chan int)
			log.Println("Customer", i, "enters the barbershop.")

			select {

			case Wroom <- ch:

				ch <- i
				<-ch

			default:
				log.Println("Customer", i, "decides today isn't a good day for a haircut.")
			}
		}(i)
	}
	wg.Wait()
}
