using System;
using System.Globalization;
public enum Location
{
    NewYork,
    London,
    Paris
}

public enum AlertLevel
{
    Early,
    Standard,
    Late
}

public static class Appointment
{
    private static bool winOS = OperatingSystem.IsWindows();
    public static DateTime ShowLocalTime(DateTime dtUtc) => dtUtc.ToLocalTime();

    public static DateTime Schedule(string appointmentDateDescription, Location location)
    {
        var parsedDate = DateTime.Parse(appointmentDateDescription);
        var timeZone = GetTimeZoneInfo(location);
        return TimeZoneInfo.ConvertTimeToUtc(parsedDate, timeZone);
    }

    public static DateTime GetAlertTime(DateTime appointment, AlertLevel alertLevel)
    {
        var alert = alertLevel switch
        {
            AlertLevel.Early => appointment.AddDays(-1),
            AlertLevel.Standard => appointment.AddHours(-1.75),
            AlertLevel.Late => appointment.AddMinutes(-30),
            _ => throw new Exception()
        };
        return alert;
    }

    public static bool HasDaylightSavingChanged(DateTime dt, Location location)
    {
        var timeZoneInfo = GetTimeZoneInfo(location);
        var sevenDaysEarlier = dt.AddDays(-7);
        return (timeZoneInfo.IsDaylightSavingTime(dt) != timeZoneInfo.IsDaylightSavingTime(sevenDaysEarlier));
    }

    public static DateTime NormalizeDateTime(string dtStr, Location location)
    {
        var cultureInfo = GetCultureInfo(location);
        var isSuccess = DateTime.TryParse(dtStr, cultureInfo, DateTimeStyles.None, out var dt);
        return isSuccess ? dt : new(1, 1, 1);
    }

    private static DateTimeFormatInfo GetDateTimeFormatInfo(Location location) => GetCultureInfo(location).DateTimeFormat;
    private static TimeZoneInfo GetTimeZoneInfo(Location location)
    {
        var timeZoneID = GetTimeZoneId(location);
        return TimeZoneInfo.FindSystemTimeZoneById(timeZoneID);
    }
    private static CultureInfo GetCultureInfo(Location location)
    {
        var culInfo = location switch
        {
            Location.NewYork => "en-US",
            Location.London => "en-GB",
            Location.Paris => "fr-FR",
            _ => throw new ArgumentOutOfRangeException(),
        };
        return CultureInfo.GetCultureInfo(culInfo);
    }

    private static string GetTimeZoneId(Location location)
    {
        var tzId = location switch
        {
            Location.NewYork => winOS ? "Eastern Standard Time" : "America/New_York",
            Location.London => winOS ? "GMT Standard Time" : "Europe/London",
            Location.Paris => winOS ? "W. Europe Standard Time" : "Europe/Paris",
            _ => throw new ArgumentOutOfRangeException(),
        };
        return tzId;
    }
}
