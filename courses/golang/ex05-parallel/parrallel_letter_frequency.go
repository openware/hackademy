package letter

func Frequency(s string) map[rune]uint64 {
	freq := make(map[rune]uint64)
	for _, l := range s {
		freq[l]++
	}
	return freq
}

func ConcurrentFrequency(ss []string) map[rune]uint64 {
	allFreq := make(map[rune]uint64)
	c := make(chan map[rune]uint64, len(ss))

	for _, s := range ss {
		go func(c chan map[rune]uint64, s string) {
			c <- Frequency(s)
		}(c, s)
	}

	for i := 0; i < len(ss); i++ {
		freq := <-c
		for k, v := range freq {
			allFreq[k] += v
		}
	}
	return allFreq
}
