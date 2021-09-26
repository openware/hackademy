package cipher

import (
	"regexp"
	"strings"
)

type Cipher interface {
	Encode(string) string
	Decode(string) string
}

type caesar struct{}

type shift struct {
	offset int
}

type vigenere struct {
	s string
}

func NewCaesar() Cipher {
	return caesar{}
}

func NewShift(offset int) Cipher {
	if offset == 0 || offset > 25 || offset < -25 {
		return nil
	}
	return shift{offset: offset}
}

func NewVigenere(s string) Cipher {
	r, _ := regexp.Compile("^[a-z]+$")
	if !r.MatchString(s) {
		return nil
	}
	for _, v := range s {
		if v != 'a' {
			return vigenere{s: s}
		}
	}
	return nil
}

func (c caesar) Encode(s string) string {
	s = ToCleanAndLower(s)
	return string(shiftLetters([]byte(s), 3))
}

func (c caesar) Decode(s string) string {
	return string(shiftLetters([]byte(s), 26-3))
}

func (sh shift) Encode(s string) string {
	var offset byte
	s = ToCleanAndLower(s)
	if sh.offset < 0 {
		offset = byte(sh.offset + 26)
	} else {
		offset = byte(sh.offset)
	}
	return string(shiftLetters([]byte(s), offset))
}

func (sh shift) Decode(s string) string {
	var offset byte
	if sh.offset > 0 {
		offset = byte(26 - sh.offset)
	} else {
		offset = byte(-sh.offset)
	}
	return string(shiftLetters([]byte(s), offset))
}

func (v vigenere) Encode(s string) string {
	s = ToCleanAndLower(s)
	return string(translateLetters([]byte(s), []byte(v.s)))
}

func (v vigenere) Decode(s string) string {
	keys := reverseKeys([]byte(v.s))
	return string(translateLetters([]byte(s), keys))
}

func ToCleanAndLower(s string) string {
	r, _ := regexp.Compile("[^A-z]+")
	letterChunks := r.Split(s, -1)
	cleanS := strings.Join(letterChunks, "")
	newS := strings.ToLower(cleanS)
	return newS
}

func shiftLetters(bytes []byte, offset byte) []byte {
	for i := range bytes {
		bytes[i] += offset
		if bytes[i] > 'z' {
			bytes[i] -= 26
		}
	}
	return bytes
}

func translateLetters(bytes []byte, keys []byte) []byte {
	key_num := len(keys)
	for i := range bytes {
		key := byte(keys[i%key_num] - 'a')
		bytes[i] += key
		if bytes[i] > 'z' {
			bytes[i] -= 26
		}
	}
	return bytes
}

func reverseKeys(bytes []byte) []byte {
	for i := range bytes {
		bytes[i] -= 'a'
		bytes[i] = 26 - bytes[i]
		bytes[i] += 'a'
	}
	return bytes
}
