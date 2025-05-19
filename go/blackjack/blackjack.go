package blackjack

// ParseCard returns the integer value of a card following blackjack ruleset.
func ParseCard(card string) int {
	switch card {
	case "two":
		return 2
	case "three":
		return 3
	case "four":
		return 4
	case "five":
		return 5
	case "six":
		return 6
	case "seven":
		return 7
	case "eight":
		return 8
	case "nine":
		return 9
	case "ace":
		return 11
	case "joker":
		return 0
	default:
		return 10
	}
}

// FirstTurn returns the decision for the first turn, given two cards of the
// player and one card of the dealer.
func FirstTurn(card1, card2, dealerCard string) string {
	p1 := ParseCard(card1)
	p2 := ParseCard(card2)
	pd := ParseCard(dealerCard)
	switch {
	case card1 == "ace" && card2 == card1:
		return "P"
	case p1+p2 == 21:
		if pd > 9 {
			return "S"
		}
		return "W"
	case p1+p2 >= 17:
		return "S"
	case p1+p2 > 11:
		if pd > 6 {
			return "H"
		}
		return "S"
	default:
		return "H"
	}
}
