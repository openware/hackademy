package letter

import (
	"sync"
)

var wg = sync.WaitGroup{}
var mp = make(map[rune]int)
var mtx = &sync.Mutex{}

func Frequency(str string) map[rune]int {
	var mp = make(map[rune]int)
	for _, v := range str {
		mp[v] = mp[v] + 1
	}
	return mp
}

func concurrentFrequencyPartial(str string) {
	for _, v := range str {
		mtx.Lock()
		mp[v] = mp[v] + 1
		mtx.Unlock()
	}
	wg.Done()
}

func ConcurrentFrequency(strs []string) map[rune]int {
	mp = make(map[rune]int)
	wg.Add(len(strs))
	for _, v := range strs {
		go concurrentFrequencyPartial(v)
	}
	wg.Wait()
	return mp
}
