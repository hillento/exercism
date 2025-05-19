// Package weather prints the basic status of the weather in a location based on location and condition inputs.
package weather

// CurrentCondition is a string used to inicate the condition of the weather.
var CurrentCondition string

// CurrentLocation is a string used to specify the place.
var CurrentLocation string

// Forecast outputs a string indicating the current condition and location indicated.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
