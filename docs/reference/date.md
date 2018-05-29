Date
====

Date is used to retrieve current date and time. You can access this object simply by typing `Date`.

Example:

```
// What day is today?
object "Application"
{
    // show the day
	state "main"
	{
		today = Date.year + "-" + f(Date.month) + "-" + f(Date.day);
		Console.print("Today is " + today);
		Application.exit();
	}

    // add a leading zero
	fun f(x)
	{
		if(x >= 10)
			return x;
		else
			return "0" + x;
	}
}
```

*Available since:* SurgeScript 0.5.2

Properties
----------

* `year`: number. The current year.
* `month`: number. Month of the year (1-12).
* `day`: number. Day of the month (1-31).
* `hour`: number. Hours since midnight (0-23).
* `minute`: number. Minutes after the hour (0-59).
* `second`: number. Seconds after the minute (0-59).
* `weekday`: number. Days since Sunday (0-6).
* `unixtime`: number. Seconds since Jan 1st, 1970 00:00 UTC.

Functions
---------

#### timezoneOffset

`timezoneOffset()`

The difference, in minutes, from the Universal Coordinated Time (UTC) to the timezone of the host. Example: if your timezone is GMT-03:00, this function returns -180.

*Available since:* SurgeScript 0.5.2

*Returns*

The timezone difference in minutes.

#### toString

`toString()`

Converts the current date and time to a string. The string is formatted according to the ISO 8601 standard.

*Available since:* SurgeScript 0.5.2

*Returns*

The current date and time expressed according to ISO 8601.