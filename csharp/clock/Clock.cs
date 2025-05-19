public class Clock
{
    private int minutes;
    private int hours;

    const int _minsPerHour = 60;
    const int _hoursPerDay = 24;

    public Clock(int hours, int minutes)
    {
        int total_minutes = minutes + (hours * _minsPerHour);

        int finalMinutes;
        int finalHours;

        if (total_minutes < 0)
        {
            finalHours = _hoursPerDay + (total_minutes / _minsPerHour % _hoursPerDay);
            finalMinutes = (_minsPerHour + (total_minutes % _minsPerHour)) % _minsPerHour;
            if (finalMinutes > 0)
            {
                finalHours--;
            }
        }
        else
        {
            finalHours = (total_minutes / _minsPerHour) % _hoursPerDay;
            finalMinutes = total_minutes % _minsPerHour;
        }

        this.minutes = finalMinutes;
        this.hours = finalHours;
    }

    public Clock Add(int minutesToAdd)
    {
        return new Clock(this.hours, this.minutes + minutesToAdd);
    }

    public Clock Subtract(int minutesToSubtract)
    {
        return new Clock(this.hours, this.minutes - minutesToSubtract);
    }

    public override string ToString()
    {
        return this.hours.ToString("00") + ":" + this.minutes.ToString("00");
    }

    public override bool Equals(object obj)
    {
        return String.Equals(this.ToString(), obj.ToString());
    }
}
