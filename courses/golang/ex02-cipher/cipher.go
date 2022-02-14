package cipher

type Cipher interface {
	Encode(string) string
	Decode(string) string
}


type caesar struct{}

type shift struct {
	move int
}

type vigenere struct {
	str string
}



func NewCaesar() Cipher { return caesar{} }

func NewShift(move int) Cipher {
	if move == 0 || move > 25 || move < (-25) {
		return nil
	} else {
		return shift{move: move}
	}
}

func NewVigenere(str string) Cipher {
	if str == "" {
		return nil
	}
	temp := str
	str = ""
	if temp == "a" || temp == "aa" {
		return nil
	}
	for _, i := range temp {

		if i > 96 && i < 123 {
			str += string(i)
		}
	}
	if temp == str {
		return vigenere{str: str}
	}
	return nil

}

func (one caesar) Encode(s string) (codStr string) {
	for _, i := range s {
		if i >= 65 && i <= 90 {
			codStr += string(i + 32)
		} else if i > 96 && i < 123 {
			codStr += string(i)
		}
	}
	//codStr = s
	temp := codStr
	codStr = ""
	for _, k := range temp {
		if k+3 > 'z' {
			codStr += string(k + 3 - 26)
		} else {
			codStr += string(k + 3)
		}
	}

	return codStr
}

func (one caesar) Decode(s string) (message string) {
	for _, k := range s {
		if k-3 >= 'a' {
			message += string(k - 3)
		} else {
			message += string(k - 3 + 26)
		}
	}
	return message
}

func (two shift) Encode(s string) (codStr string) {
	for _, i := range s {
		if i >= 65 && i <= 90 {
			codStr += string(i + 32)
		} else if i > 96 && i < 123 {
			codStr += string(i)
		}
	}
	temp := codStr
	codStr = ""
	move := int(two.move)
	if two.move > 0 {

		for _, k := range temp {
			if k+rune(move) > 'z' || k+rune(move) < 'a' {
				codStr += string(k + rune(move) - 26)
			} else {
				codStr += string(k + rune(move))
			}
		}
	} else {
		for _, k := range temp {
			if k+26+rune(move) > 'z' || k+26+rune(move) < 'a' {
				codStr += string(k + 26 + rune(move) - 26)
				//codStr += string(k - 26)
			} else {
				codStr += string(k + 26 + rune(move))
				//codStr += string(k)
			}
		}
	}
	return codStr
}

func (two shift) Decode(s string) (message string) {
	if two.move > 0 {
		for _, k := range s {
			if k-rune(two.move) >= 'a' {
				message += string(k - rune(two.move))
			} else {
				message += string(k + 26 - rune(two.move))
			}
			//message += string(k - rune(two.move))
		}
	} else {
		for _, k := range s {
			if k-26-rune(two.move) >= 'a' && k-26-rune(two.move) <= 'z' {
				message += string(k - 26 - rune(two.move))
			} else {
				message += string(k - rune(two.move))
			}
			//message += string(k - 26 - rune(two.move))
		}
	}
	return message
}
func (key vigenere) Encode(s string) (codStr string) {
	for _, i := range s {
		if i >= 65 && i <= 90 {
			codStr += string(i + 32)
		} else if i > 96 && i < 123 {
			codStr += string(i)
		}
	}
	key_num := len(key.str)
	temp := codStr
	codStr = ""

	for k, i := range temp {
		key := string(rune(((int(key.str[k%key_num]) + int(i) - 64) % 26) + 97))
		codStr += key

	}
	return codStr
}
func (key vigenere) Decode(s string) (message string) {

	key_num := len(key.str)

	//temp := message
	message = ""
	for k := 0; k < len(s); k++ {
		key := string(rune((int(s[k])+26-int(key.str[k%key_num]))%26 + 97))
		message += key
	}

	return message
}
